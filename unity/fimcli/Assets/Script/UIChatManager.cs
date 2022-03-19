using Forevernine.Midplat.Proto;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UIChatManager : MonoBehaviour
{
    public static UIChatManager Instance;
    public ChatManager Chat;

    public UIScrollView mChatListScroll;
    public UIScrollView mRoomListScroll;
    public GameObject mChatItemPrefab;
    public GameObject mRoomTabPrefab;
    public GameObject mLoginRoot;
    public GameObject mEnterRoot;

    private List<UIChatItem> mChatItemList = new List<UIChatItem>();
    private List<UIRoomTab> mRoomTabList = new List<UIRoomTab>();

    private UIRoomTab mCurrentPage;
    void Awake()
    {
        Instance = this;
        mCurrentPage = null;
        Chat = this.gameObject.AddComponent<ChatManager>();
        Chat.OnEnter = OnEnterRoom;
        Chat.OnLeave = DelRoomTab;
        Chat.OnMessage = OnRcvMessage;
    }


    void Start()
    {
        UpdatePage();
    }

    void OnDestroy()
    {
        Instance = null;
    }

    void UpdatePage()
    {
        var msgList = GetMessageList();
        for (int idx = 0; idx < mChatItemList.Count; idx++)
        {
            mChatItemList[idx].gameObject.SetActive(false);
        }
        if(msgList == null)
        {
            return;
        }
        var it = msgList.GetEnumerator();
        int i = 0;
        while (it.MoveNext())
        {
            if (i >= mChatItemList.Count)
            {
                AddMessageItem(it.Current.Value);
            }
            else
            {
                var item = mChatItemList[i];
                item.Init(it.Current.Value);
                item.gameObject.SetActive(true);
            }
            i++;
        }
        mChatListScroll.UpdateScrollbars();
    }

    Dictionary<ulong, FIMChatMsg> GetMessageList()
    {
        if(mCurrentPage == null)
        {
            return null;
        }
        if (mCurrentPage.mFType == FORWARD_TYPE.User)
        {
            return Chat.GetPrivateChatList(mCurrentPage.TargetID);
        }
        else
        {
            return Chat.GetRoomChatList(mCurrentPage.TargetID);
        }
    }

    void OnRcvMessage(List<FIMChatMsg> newMsg, Dictionary<ulong, FIMChatMsg> privateChat, Dictionary<string, Room> roomList, Dictionary<ulong, FIMChatMsg> broadcast)
    {
        for (int i = 0; i < newMsg.Count; i++)
        {
            var msg = newMsg[i];
            if (msg.FType == FORWARD_TYPE.User)
            {
                var other = msg.SrcUID == Chat.UID ? msg.Target : msg.SrcUID;
                //找到这个tab，若没有则新增一个tab，若有则添加消息
                var tab = GetTabItem(other);
                if(tab == null)
                {
                    tab = AddRoomTab(other);
                    tab.mFType = FORWARD_TYPE.User;
                }
                else if(tab == mCurrentPage)
                {
                    AddMessageItem(msg);
                }

            }
            else if (mCurrentPage!=null && mCurrentPage.mFType == FORWARD_TYPE.Room && mCurrentPage.TargetID == msg.Target)
            {
                AddMessageItem(msg);
            }
        }
        mChatListScroll.UpdateScrollbars();
    }

    UIRoomTab GetTabItem(string target)
    {
        for(int i = 0;i<mRoomTabList.Count;i++)
        {
            if(mRoomTabList[i].TargetID == target)
            {
                return mRoomTabList[i];
            }
        }
        return null;
    }

    public void OnEnterRoom(string rid)
    {
        var tab = AddRoomTab(rid);
        tab.mFType = FORWARD_TYPE.Room;
    }
    public UIRoomTab AddRoomTab(string rid)
    {
        var tab = NGUITools.AddChild(mRoomListScroll.gameObject, mRoomTabPrefab).GetComponent<UIRoomTab>();
        if (tab != null)
        {
            tab.TargetID = rid;
        }
        mRoomTabList.Add(tab);
        UpdateTabPosition();
        return tab;
    }

    public void DelRoomTab(string rid)
    {
        for (int i = 0; i < mRoomTabList.Count; i++)
        {
            if (mRoomTabList[i].TargetID == rid)
            {
                DestroyImmediate(mRoomTabList[i].gameObject);
                mRoomTabList.RemoveAt(i);
                break;
            }
        }
        UpdateTabPosition();
    }

    void UpdateTabPosition()
    {
        for(int i = 0;i< mRoomTabList.Count;i++)
        {
            mRoomTabList[i].transform.localPosition = new Vector3(i * 100-184, 0, 0);
        }
        mRoomListScroll.UpdateScrollbars();
    }

    void AddMessageItem(FIMChatMsg msg)
    {
        var item = NGUITools.AddChild(mChatListScroll.gameObject, mChatItemPrefab).GetComponent<UIChatItem>();
        item.transform.localPosition = new Vector3(0, 105 - mChatItemList.Count * 90, 0);
        mChatItemList.Add(item);
        item.Init(msg);
        item.gameObject.SetActive(true);
    }


    public void OnClickLogin()
    {
        mLoginRoot.SetActive(true);
    }

    public void OnClickPage(UIRoomTab page)
    {
        if (page != null)
        {
            mCurrentPage = page;
        }
        UpdatePage();
    }

    public void OnClickSend(string content)
    {
        if(mCurrentPage == null)
        {
            return;
        }
        if (mCurrentPage.mFType == FORWARD_TYPE.User)
        {
            Chat.SendPrivateMessage(mCurrentPage.TargetID, content, null);
        }
        else
        {
            Chat.SendRoomMessage(mCurrentPage.TargetID, content, null);
        }
    }

    public void OnClickEnter()
    {
        mEnterRoot.SetActive(true);
    }
}
