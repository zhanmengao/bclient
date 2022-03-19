using System;
using BestHTTP.WebSocket;
using BestHTTP.WebSocket.Frames;
using UnityEngine;
using Forevernine.Midplat.Proto;
using Google.Protobuf;
using System.Text;
using System.Collections.Generic;
using System.Collections;

public class ChatManager : MonoBehaviour
{
    private string AccessToken = "";
    private string FIMAddr = "";
    private WebSocket ws;
    private Dictionary<ulong, FIMChatMsg> PrivateChatList = new Dictionary<ulong, FIMChatMsg>();          //私聊缓存。key = seqid
    private Dictionary<string, Room> RoomList = new Dictionary<string, Room>();                             //房间缓存.key = room id
    private Dictionary<ulong, FIMChatMsg> BroadcastChatList = new Dictionary<ulong, FIMChatMsg>();          //广播缓存

    private List<Packet> PacketList = new List<Packet>();
    private List<FIMChatMsg> AckList = new List<FIMChatMsg>();
    private int connCd = 0;

    public Encoding Enco { get; set; }
    public string Platform { get; set; }
    public string UID { get; set; }
    public Dictionary<ulong, FIMChatMsg> GetPrivateChatList()
    {
        return PrivateChatList;
    }
    public Dictionary<ulong, FIMChatMsg> GetPrivateChatList(string uid)
    {
        Dictionary<ulong, FIMChatMsg> msgList = new Dictionary<ulong, FIMChatMsg>();
        var it = PrivateChatList.GetEnumerator();
        while (it.MoveNext())
        {
            var msg = it.Current.Value;
            if(msg.SrcUID == uid || msg.Target == uid)
            {
                msgList.Add(msg.ID, msg);
            }
        }
        return msgList;
    }
    public Dictionary<ulong, FIMChatMsg> GetRoomChatList(string rid)
    {
        Room room;
        if (RoomList.TryGetValue(rid, out room))
        {
            return room.ChatMessage;
        }
        return null;
    }
    public Dictionary<ulong, FIMChatMsg> GetBroadcastChatList()
    {
        return BroadcastChatList;
    }

    public Action OnConnect { get; set; }                                //建立连接成功的回调
    public Action OnDisConnect { get; set; }                            //连接断开的回调

    public Action<string> OnEnter { get; set; }
    public Action<string> OnLeave { get; set; }
    public Action<List<FIMChatMsg>, Dictionary<ulong, FIMChatMsg>, Dictionary<string, Room>, Dictionary<ulong, FIMChatMsg>> OnMessage { get; set; }             //收到消息的回调
    public Action<List<FIMChatMsg>, Dictionary<ulong, FIMChatMsg>, Dictionary<string, Room>, Dictionary<ulong, FIMChatMsg>> OnUpdate { get; set; }                   //消息更新的回调

    private void Awake()
    {
        Enco = Encoding.UTF8;
    }
    //初始化，发登录请求
    public void Connect(string platform, string srvAddr, string accessToken,string UID)
    {
        AccessToken = accessToken;
        Platform = platform;
        FIMAddr = srvAddr;
        this.UID = UID;
        connCd = 0;
        PrivateChatList.Clear();
        RoomList.Clear();
        BroadcastChatList.Clear();
        PacketList.Clear();
        AckList.Clear();
        StartCoroutine(Reconn());
    }

    IEnumerator Reconn()
    {
        Debug.LogFormat("Try connect {0}", FIMAddr);
        try
        {
            ws = new WebSocket(new Uri(FIMAddr));
            ws.OnOpen += onOpen;
            ws.OnMessage += onMessage;
            ws.OnBinary += onBinary;
            ws.OnClosed += onClose;
            ws.OnError += onError;
            ws.OnIncompleteFrame += onIncompleteFrame;
#if !UNITY_WEBGL
            ws.StartPingThread = true;
#endif
        }
        catch (Exception ex)
        {
            Debug.LogError(ex);
        }
        if (connCd > 0)
        {
            yield return new WaitForSeconds(connCd);
        }
        Debug.LogFormat("try connect . cd : {0}", connCd);
        if (ws.IsOpen)
        {
            yield return null;
        }
        try
        {
            ws.Open();
            if (connCd == 0)
            {
                connCd = 1;
            }
            else if (connCd < 4)
            {
                connCd *= 2;
            }

        }
        catch (Exception e)
        {
            Debug.Log(e);
        }
    }


    public void Close()
    {
        if (ws.IsOpen)
        {
            ws.Close();
        }
    }

    public bool EnterRoom(string RoomID)
    {
        FIMEnterRoomReq req = new FIMEnterRoomReq
        {
            Base = GetBase(),
            RID = RoomID,
        };
        SendPacket(CMD.FimCmdEnterRoomReq, req.ToByteString(), true);
        return true;
    }

    public bool LeaveRoom(string RoomID)
    {
        FIMLeaveRoomReq req = new FIMLeaveRoomReq
        {
            Base = GetBase(),
            RID = RoomID,
        };
        SendPacket(CMD.FimCmdLeaveRoomReq, req.ToByteString(), true);
        return true;
    }

    public bool SendPrivateMessage(string DstUID, string Content, byte[] ext)
    {
        if (Content == "")
        {
            return false;
        }
        FIMSendMsgReq req = new FIMSendMsgReq
        {
            Base = GetBase(),
            Msg = new FIMChatMsg
            {
                Content = ByteString.CopyFrom(Content, Enco),
                FType = FORWARD_TYPE.User,
                Type = MSG_TYPE.Txt,
                Target = DstUID,
            }
        };
        if(ext!=null)
        {
            req.Msg.Ext = ByteString.CopyFrom(ext);
        }

        SendPacket(CMD.FimCmdSendMsgReq, req.ToByteString(), true);
        return true;
    }
    public bool SendRoomMessage(string RoomID, string Content, byte[] ext)
    {
        if (Content == "")
        {
            return false;
        }
        FIMSendMsgReq req = new FIMSendMsgReq
        {
            Base = GetBase(),
            Msg = new FIMChatMsg
            {
                Content = ByteString.CopyFrom(Content, Enco),
                FType = FORWARD_TYPE.Room,
                Type = MSG_TYPE.Txt,
                Target = RoomID,
            }
        };
        if (ext != null)
        {
            req.Msg.Ext = ByteString.CopyFrom(ext);
        }
        SendPacket(CMD.FimCmdSendMsgReq, req.ToByteString(), true);
        return true;
    }

    IEnumerator HeartBeat()
    {
        while (ws != null && ws.IsOpen)
        {
            FIMHeartBeatReq req = new FIMHeartBeatReq
            {
                Base = GetBase(),
            };
            for (int i = 0; i < AckList.Count; i++)
            {
                FIMMsgAck ack = new FIMMsgAck
                {
                    FType = AckList[i].FType,
                    ID = AckList[i].ID,
                };
                if (ack.FType == FORWARD_TYPE.User)
                {
                    ack.Src = AckList[i].SrcUID;
                }
                else
                {
                    ack.Src = AckList[i].Target;
                }
                req.AckList.Add(ack);
            }
            SendPacket(CMD.FimCmdHeartbeatReq, req.ToByteString(), false);
            AckList.Clear();
            yield return new WaitForSeconds(5.0f);
        }
    }

    private FIMReqBase GetBase()
    {
        FIMReqBase Base = new FIMReqBase
        {
            AccessToken = AccessToken,
            Platform = Platform
        };
        return Base;
    }

    private void SendPacket(CMD cmd, ByteString data, bool mustSend)
    {
        Packet pak = new Packet
        {
            Body = data,
            Head = new PacketHead
            {
                Cmd = (int)cmd,
            }
        };
        if (ws != null && ws.IsOpen)
        {
            ws.Send(pak.ToByteArray());
        }
        else if (mustSend)
        {
            PacketList.Add(pak);
        }
    }


    //cb
    private void onOpen(WebSocket ws)
    {
        Debug.Log("fimcli onOpen ");
        FIMLoginReq req = new FIMLoginReq
        {
            Base = GetBase()
        };
        SendPacket(CMD.FimCmdLoginReq, req.ToByteString(), true);

        List<Packet> FailList = new List<Packet>();
        //把累积的消息发出去
        for (int i = 0; i < PacketList.Count; i++)
        {
            if (ws != null && ws.IsOpen)
            {
                try
                {
                    ws.Send(PacketList[i].ToByteArray());
                }
                catch (Exception e)
                {
                    FailList.Add(PacketList[i]);
                    Debug.Log(e.Data);
                }
            }
            else
            {
                FailList.Add(PacketList[i]);
            }
        }
        PacketList = FailList;
        OnConnect?.Invoke();
        StartCoroutine(HeartBeat());
    }

    private void onMessage(WebSocket ws, string message)
    {
        Debug.Log(message);
    }
    private void onBinary(WebSocket ws, byte[] body)
    {
        Debug.Log("fimcli onBinary ");
        Packet pkt = Packet.Parser.ParseFrom(body);
        if (pkt.Head == null)
        {
            return;
        }
        switch (pkt.Head.Cmd)
        {
            case (int)CMD.FimCmdLoginRsp:
                FIMLoginRsp lgRsp = FIMLoginRsp.Parser.ParseFrom(pkt.Body);
                OnLoginRsp(lgRsp);
                break;
            case (int)CMD.FimCmdEnterRoomRsp:
                FIMEnterRoomRsp erRsp = FIMEnterRoomRsp.Parser.ParseFrom(pkt.Body);
                OnEnterRsp(erRsp);
                break;
            case (int)CMD.FimCmdLeaveRoomRsp:
                FIMLeaveRoomRsp lrRsp = FIMLeaveRoomRsp.Parser.ParseFrom(pkt.Body);
                OnLeaveRsp(lrRsp);
                break;
            case (int)CMD.FimCmdHeartbeatRsp:
                FIMHeartBeatRsp hbRsp = FIMHeartBeatRsp.Parser.ParseFrom(pkt.Body);
                OnHeartRsp(hbRsp);
                break;
            case (int)CMD.FimCmdSendMsgRsp:
                FIMSendMsgRsp seRsp = FIMSendMsgRsp.Parser.ParseFrom(pkt.Body);
                OnSendRsp(seRsp);
                break;
            case (int)CMD.FimCmdRecvMsgPacket:
                FIMRecvMsgPacket rcpkt = FIMRecvMsgPacket.Parser.ParseFrom(pkt.Body);
                OnRecvPacket(rcpkt);
                break;
        }
    }
    private void onClose(WebSocket ws, ushort code, string message)
    {
        Debug.Log(message);
        if (!ws.IsOpen)
        {
            OnDisConnect?.Invoke();
            StartCoroutine(Reconn());
        }
    }
    private void onError(WebSocket conn, string reason)
    {
        Debug.Log(reason);
    }
    private void onIncompleteFrame(WebSocket webSocket, WebSocketFrameReader frame)
    {
        Debug.Log("fimcli onIncompleteFrame ");
    }

    private void OnLoginRsp(FIMLoginRsp packet)
    {
        if (packet.MsgList == null)
        {
            return;
        }
        var msgList = new List<FIMChatMsg>();
        for (int i = 0; i < packet.MsgList.Count; i++)
        {
            msgList.Add(packet.MsgList[i]);
        }
        OnRcvMessage(msgList);
    }

    private void OnEnterRsp(FIMEnterRoomRsp packet)
    {
        RoomList.Add(packet.RID, new Room());
        Room room;
        if (RoomList.TryGetValue(packet.RID, out room))
        {
            ulong maxID = 0;
            var rcvList = new List<FIMChatMsg>();
            for (int i = 0; i < packet.MsgList.Count; i++)
            {
                var msg = packet.MsgList[i];
                room.ChatMessage.Add(msg.ID, msg);
                if (msg.ID > maxID)
                {
                    maxID = msg.ID;
                }
                rcvList.Add(msg);
            }
            OnRcvMessage(rcvList);
        }
        OnEnter?.Invoke(packet.RID);
    }

    private void OnLeaveRsp(FIMLeaveRoomRsp packet)
    {
        RoomList.Remove(packet.RID);
        OnLeave?.Invoke(packet.RID);
    }

    private void OnHeartRsp(FIMHeartBeatRsp packet)
    {
        if (packet.MsgList != null)
        {
            var msgList = new List<FIMChatMsg>();
            var it = packet.MsgList.GetEnumerator();
            while (it.MoveNext())
            {
                msgList.Add(it.Current);
            }
            OnRcvMessage(msgList);
        }
        connCd = 0;
    }

    private void OnSendRsp(FIMSendMsgRsp packet)
    {
        if (packet.Msg != null)
        {
            OnRcvMessage(new List<FIMChatMsg> { packet.Msg });
        }
    }
    private void OnRecvPacket(FIMRecvMsgPacket packet)
    {
        if (packet.MsgList != null)
        {
            var msgList = new List<FIMChatMsg>();
            var it = packet.MsgList.GetEnumerator();
            while (it.MoveNext())
            {
                msgList.Add(it.Current);
            }
            OnRcvMessage(msgList);
        }
    }

    private void OnRcvMessage(List<FIMChatMsg> msgList)
    {
        List<FIMChatMsg> newMsgList = new List<FIMChatMsg>();
        List<FIMChatMsg> updateMsgList = new List<FIMChatMsg>();
        for (int i = 0; i < msgList.Count; i++)
        {
            var msg = msgList[i];
            FIMChatMsg oldMsg;
            switch (msg.FType)
            {
                case FORWARD_TYPE.User:
                    //不存在，是新发言  
                    if (!PrivateChatList.TryGetValue(msg.ID, out oldMsg))
                    {
                        newMsgList.Add(msg);
                        PrivateChatList.Add(msg.ID, msg);
                    }
                    //存在，是更新
                    else
                    {
                        oldMsg.MergeFrom(msg);
                        updateMsgList.Add(oldMsg);
                    }
                    break;
                case FORWARD_TYPE.Room:
                    Room room;
                    if (RoomList.TryGetValue(msg.Target, out room))
                    {
                        //不存在，是新发言  
                        if (!room.ChatMessage.TryGetValue(msg.ID, out oldMsg))
                        {
                            newMsgList.Add(msg);
                            room.ChatMessage.Add(msg.ID, msg);
                        }
                        //存在，是更新
                        else
                        {
                            oldMsg.MergeFrom(msg);
                            updateMsgList.Add(oldMsg);
                        }
                    }
                    break;
                case FORWARD_TYPE.Broadcast:
                    //不存在，是新发言  
                    if (!BroadcastChatList.TryGetValue(msg.ID, out oldMsg))
                    {
                        newMsgList.Add(msg);
                        BroadcastChatList.Add(msg.ID, msg);
                    }
                    //存在，是更新
                    else
                    {
                        oldMsg.MergeFrom(msg);
                        updateMsgList.Add(oldMsg);
                    }
                    break;
            }
        }
        if (newMsgList.Count > 0)
        {
            OnMessage?.Invoke(newMsgList, PrivateChatList, RoomList, BroadcastChatList);
        }
        if (updateMsgList.Count > 0)
        {
            OnUpdate?.Invoke(updateMsgList, PrivateChatList, RoomList, BroadcastChatList);
        }
        AckList.AddRange(newMsgList);
    }
}
