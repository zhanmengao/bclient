using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Net.Sockets;
using UnityEngine;
using NetFrame;
/// <summary>
/// 客户端网络连接：同步
/// </summary>
public class NetManager:MonoBehaviour
{
    private static NetManager _Instance = null;
    public static NetManager Instance
    {
        get
        {
            return _Instance;
        }
    }
    private const string ip = "127.0.0.1";
    private const int port = 9999;
    private Socket mSocket;

    private byte[] readbuff = new byte[1024];
    List<byte> mRecvBuf = new List<byte>();
    public List<PacketModel> messages = new List<PacketModel>();                       //消息体列表

    private bool isReading = false;
    private bool isWriting = false;
    void Awake()
    {
        _Instance = this;
        try
        {
            mSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            mSocket.Connect(ip, port);
            //开启异步消息接收 消息到达后会直接写入缓冲区 readbuff
            mSocket.BeginReceive(readbuff, 0, readbuff.Length, SocketFlags.None, ReceiveCallBack, readbuff);
        }
        catch (Exception ex)
        {
            Debug.LogError(ex.Message);
        }
    }
    void Update()
    {
        for(int i = 0;i<messages.Count;i++)
        {
            PlayerData.HandlePacket(messages[i]);
        }
        messages.Clear();
    }

    //收到消息的回调
    private void ReceiveCallBack(IAsyncResult response)
    {
        try
        {
            //获取当前收到的消息长度
            int length = mSocket.EndReceive(response);
            byte[] message = new byte[length];
            Buffer.BlockCopy(readbuff, 0, message, 0, length);
            mRecvBuf.AddRange(message);
            if (!isReading)
            {
                isReading = true;
                onData();
            }
            mSocket.BeginReceive(readbuff, 0, readbuff.Length, SocketFlags.None, ReceiveCallBack, readbuff);
        }
        catch (Exception ex)
        {
            Debug.Log("服务器主动断开连接" + ex.Message);
            mSocket.Close();
        }
    }

    void onData()
    {
        try
        {
            //长度解码返回空说明消息体不全，等待下条消息过来补全
            byte[] result = LengthEncoding.decode(ref mRecvBuf);
            if (result == null)
            {
                isReading = false;
                return;
            }
            PacketModel message = MessageEncoding.decode(result) as PacketModel;
            if (message == null)
            {
                isReading = false;
                return;
            }

            //进行消息的处理
            messages.Add(message);
            onData();
        }
        catch (Exception ex)
        {
            Debug.LogError(ex.Message);
        }
    }

    public void write(int type, object message)
    {
        PacketModel model = new PacketModel();
        model.msgID = type;
        model.message = message;
        byte[] msg = MessageEncoding.encode(model);
        //长度编码
        msg = LengthEncoding.encode(msg);
        mSocket.Send(msg);
    }
}
