using System.Collections.Generic;
using System.Threading;


class ThreadModel
{
    public uint tId;
    public ThreadBase routinue;
    public Thread thread;
    public readonly object mMsgLock = new object();
    public List<MsgBase> mMsgList = new List<MsgBase>();

    public ThreadModel(uint nTId, ThreadBase pLogic)
    {
        tId = nTId;
        routinue = pLogic;
        thread = new Thread(pLogic.ThreadMain);
    }
};
class ThreadManager
{
    public static void NewThread(ThreadBase pThread)
    {
        ThreadModel pModel = new ThreadModel(pThread.GetId(), pThread);
        mLogicThreadMap.Add(pThread.GetId(), pModel);
    }
    public static void Start()
    {
        var it = mLogicThreadMap.GetEnumerator();
        while (it.MoveNext())
        {
            it.Current.Value.thread.Start();
        }
    }
    public static ThreadModel GetRoutinue(uint tId)
    {
        ThreadModel oModel = null;
        if (mLogicThreadMap.TryGetValue(tId, out oModel))
        {
        }
        return oModel;
    }
    public static void SendMsg(uint threadId, MsgBase rMsg)
    {
        ThreadModel oModel = GetRoutinue(threadId);
        if(oModel!=null)
        {
            lock (oModel.mMsgLock)
            {
                oModel.mMsgList.Add(rMsg);
            }
        }
    }
    public static void Tick()
    {
        List<MsgBase> msgList = new List<MsgBase>();
        var it = mLogicThreadMap.GetEnumerator();
        while (it.MoveNext())
        {
            msgList.Clear();
            var pData = it.Current.Value;
            lock (pData.mMsgLock)
            {
                msgList.AddRange(pData.mMsgList);
                pData.mMsgList.Clear();
            }
            //把所有消息塞进线程的消息队列
            for (int i= 0;i< msgList.Count;i++)
            {
                var msg = msgList[i];
                pData.routinue.SendMsg(ref msg);
            }
        }
        Thread.Sleep(50);
    }

    public static void Destroy()
    {
        var it = mLogicThreadMap.GetEnumerator();
        while (it.MoveNext())
        {
            it.Current.Value.routinue.Destroy();
        }
    }
    private static Dictionary<uint, ThreadModel> mLogicThreadMap = new Dictionary<uint, ThreadModel>();
};