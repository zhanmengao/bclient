using System.Collections;
using System.Collections.Generic;
using System.Text;
using UnityEngine;

public class UIController : MonoBehaviour
{
    public static UIController Instance = null;
    public UIInput mInput;
    public GameObject mClientItemPrefab;
    public UITable mTable;

    public GameObject mShowObj;
    public GameObject mHisObj;
    public UILabel mHisLabel;
    public UIScrollView mScroll;
    private ClientData mData;

    void Awake()
    {
        Instance = this;
    }
    void Start()
    {
        mInput.onSubmit.Add(new EventDelegate(OnInputCommit));
        mShowObj.SetActive(true);
        mHisObj.SetActive(false);
    }
    void OnDisable()
    {
        Instance = null;
    }
    //直接发送命令
    void OnInputCommit()
    {
        if (mInput.value == "")
        {
            NGUIDebug.Log("mInput value is null");
            return;
        }
        //如果有选中，则对该客户端发送cmd
        if (mData == null)
        {
            IPCTools.WritePipe(IPCTools.ToByte(mInput.value));
        }
        else
        {
            string str = "";
            str += "Send;";
            str += mData.key.mIpAddr + ";";
            str += mData.key.mPort.ToString() + ";";
            str += mInput.value;
            IPCTools.WritePipe(IPCTools.ToByte(str));
        }
        mInput.value = "";
    }

    //更新client信息
    public void UpdateClientList()
    {
        var childList = mTable.GetChildList();
        for (int i = 0; i < childList.Count; i++)
        {
            childList[i].gameObject.SetActive(false);
        }
        var it = GlobalData.Clients.GetEnumerator();
        int cur = -1;
        while (it.MoveNext())
        {
            cur++;
            //激活
            if (cur < childList.Count)
            {
                var logic = childList[cur].GetComponent<UIClientItem>();
                if (logic != null)
                {
                    logic.Init(it.Current.Value);
                }
            }
            //新建
            else
            {
                var obj = NGUITools.AddChild(mTable.gameObject, mClientItemPrefab);
                var logic = obj.GetComponent<UIClientItem>();
                if (logic != null)
                {
                    logic.Init(it.Current.Value);
                }
            }
        }
        mTable.Reposition();
    }

    public void UpdateHisLog()
    {
       StringBuilder sb = new StringBuilder();
        mHisLabel.text = "";
        var hisList = mData.GetHisrroy();
        foreach (var hisItem in hisList)
        {
            sb.Append(hisItem);
            sb.Append("\n");
            //if (!string.IsNullOrEmpty(hisItem))
            //{
            //    string[] lines = hisItem.Split('\n');
            //    foreach (string st in lines)
            //    {
            //        AddLog(mData,st);
            //    }
            //    AddLog(mData, "\n");
            //}
        }
        mHisLabel.text = sb.ToString();
        //mHisLabel.Add(his);
    }

    public void AddLog(ClientData client,string str)
    {
        if(mData == null)
        {
            return;
        }
        if(client.key.mIpAddr == mData.key.mIpAddr)
        {
            if(client.key.mPort == mData.key.mPort)
            {
                mHisLabel.text += str;
                Debug.Log("str = " + str);
            }
        }
    }

    public void OnItemClick(UIClientItem item)
    {
        mData = item.mData;
        mShowObj.SetActive(false);
        mHisObj.SetActive(true);
        UpdateHisLog();
        mScroll.ResetPosition();
    }

    public void OnClickExitHis()
    {
        mHisObj.SetActive(false);
        mShowObj.SetActive(true);
        mData = null;
    }
}
