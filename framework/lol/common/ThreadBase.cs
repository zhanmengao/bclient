using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

public class ThreadBase
{
    public virtual uint TickTime()
    {
        return 1000;
    }
    //流程函数
    public virtual uint GetId()
    {
        return 0;
    }
    protected virtual void Init()
    {

    }
    public virtual bool Tick()
    {
        return false;
    }
    public virtual void Destroy()
    {

    }
    protected virtual void ProcessMsg(ref MsgBase rMsg)
    {

    }
    public ThreadBase()
    {
        mCurTickIdx = 0;
        for (int i = 0; i < 10; i++)
        {
            mTickRetQueue[i] = true;
        }
    }
    public void SendMsg(ref MsgBase pMsg)
    {
        lock (mMsgMutex)
        {
            mMsgQueue.Enqueue(pMsg);
        }
    }
    private bool ProcessMsg()
    {
        List<MsgBase> cpyList = new List<MsgBase>();
        {
            lock (mMsgMutex)
            {
                if (mMsgQueue.Count <= 0)
                {
                    return false;
                }
                cpyList.AddRange(mMsgQueue);
                mMsgQueue.Clear();
            }
        }
        for (int i = 0; i < cpyList.Count; i++)
        {
            var pData = cpyList[i];
            ProcessMsg(ref pData);
        }
        return true;
    }
    public void ThreadMain()
    {
        while (true)
        {
            bool bRet = Tick();           //线程自己的心跳
            bRet |= ProcessMsg();     //心跳：处理消息
            UpdateTickRet(bRet);
        }
    }
    private Queue<MsgBase> mMsgQueue = new Queue<MsgBase>();           //消息队列
    private readonly object mMsgMutex = new object();                               //锁

    //Sleep机制
    private void UpdateTickRet(bool ret)
    {
        mTickRetQueue[mCurTickIdx++] = ret;
        if (mCurTickIdx > 9)
        {
            mCurTickIdx = 0;
        }
        for (int i = 0; i < 10; i++)
        {
            if (mTickRetQueue[i] == true)
            {
                return;
            }
        }
        Thread.Sleep((int)TickTime());
    }
    bool[] mTickRetQueue = new bool[10];
    uint mCurTickIdx;

};
