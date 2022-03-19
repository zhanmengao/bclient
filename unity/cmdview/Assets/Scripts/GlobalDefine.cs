using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using UnityEngine;


class GlobalDefine
{
    public const string WritePipeName = "\\\\.\\Pipe\\exeRead";
    public const string ReadPipeName = "\\\\.\\Pipe\\exeWrite";
}
public struct ClientKey
{
    public string mIpAddr;
    public ushort mPort;
}
public class ClientData
{
    public ClientKey key = new ClientKey();
    List<string> msgHistroy = new List<string>();
    public void AddHisrroy(string log)
    {
        msgHistroy.Add(log);
    }
    public List<string> GetHisrroy()
    {
        return msgHistroy;
    }
    public void CopyFrom(ClientData other)
    {
        key = other.key;
        foreach(var item in other.msgHistroy)
        {
            AddHisrroy(item);
        }
    }
}

class GlobalData
{
    public static IntPtr WritePipeHandle = new IntPtr();
    public static bool bCanWrite = false;
    public static IntPtr ReadPipeHandle = new IntPtr();
    public static bool bCanRead = false;
    public static Action<byte[]> mMsgCallBack = null;

    private static Dictionary<ClientKey, ClientData> mClientList = new Dictionary<ClientKey, ClientData>();
    public static Dictionary<ClientKey, ClientData> Clients
    {
        get
        {
            return mClientList;
        }
    }
    public static void DelClient(string ip,ushort port)
    {
        ClientKey key = new ClientKey();
        key.mIpAddr = ip;
        key.mPort = port;
        ClientData client;
        if(mClientList.TryGetValue(key, out client))
        {
            //存放到历史记录
            mHistList.Add(key, client);
            mClientList.Remove(key);
        }
    }
    public static ClientData GetClient(string ip,ushort port)
    {
        ClientKey key = new ClientKey();
        key.mIpAddr = ip;
        key.mPort = port;
        ClientData client;
        if (mClientList.TryGetValue(key, out client))
        {
        }
        return client;
    }
    public static void NewClient(string ip,ushort port)
    {
        ClientKey key = new ClientKey();
        key.mIpAddr = ip;
        key.mPort = port;
        ClientData client = TransHistroy(key);
        mClientList.Add(key, client);
    }

    public static void ClearClient()
    {
        //把全部都放到历史记录
        var it = Clients.GetEnumerator();
        while(it.MoveNext())
        {
            mHistList.Add(it.Current.Key, it.Current.Value);
            mClientList.Remove(it.Current.Key);
        }
    }

    private static Dictionary<ClientKey, ClientData> mHistList = new Dictionary<ClientKey, ClientData>();
    //不管怎么样，都会new一个出来
    private static ClientData TransHistroy(ClientKey key)
    {
        ClientData client;
        ClientData ret = new ClientData();
        if (mClientList.TryGetValue(key, out client))
        {
            ret.CopyFrom(client);
            mClientList.Remove(key);
        }
        ret.key = key;
        return ret;
    }

    public static void QuitGame()
    {

    }
    
}
