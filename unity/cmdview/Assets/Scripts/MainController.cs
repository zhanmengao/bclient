using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Threading;

public class MainController : MonoBehaviour
{
    //连接ipc
    void Start()
    {
        bool bRet = IPCTools.ConnectPipe(GlobalDefine.WritePipeName);
        if (!bRet)
        {
            print("ConnectPipe Error!");
        }
        else
        {
            print("ConnectPipe Sec!");
        }

        bRet = IPCTools.CreatePipe(GlobalDefine.ReadPipeName);
        if (!bRet)
        {
            print("ConnectPipe Error!");
        }
        else
        {
            print("ConnectPipe Sec!");
        }
        GlobalData.mMsgCallBack += OnMsgListCall;
    }

    void OnDestroy()
    {
        GlobalData.mMsgCallBack -= OnMsgListCall;
    }


    void Update()
    {
        IPCTools.ReadPipe();
    }


    void OnMsgListCall(byte[] data)
    {
        NGUIDebug.Log("recv:"+IPCTools.ByteToString(data));
        //收到消息 做处理
        string str = IPCTools.ByteToString(data);
        string[] commandList = str.Split(';');
        if(commandList.Length<=0)
        {
            MsgTools.SendMsg("Error;Msg length error!");
            return;
        }
        str += '\0';
        if (str == "Clear")
        {
            GlobalData.ClearClient();
            if (UIController.Instance != null)
            {
                UIController.Instance.UpdateClientList();
            }
        }
        else if(commandList[0] == "Add")
        {
            GlobalData.NewClient(commandList[1],MsgTools.GetPort(commandList[2]));
            if(UIController.Instance!=null)
            {
                UIController.Instance.UpdateClientList();
            }
        }
        else if(commandList[0] == "Del")
        {
            GlobalData.DelClient(commandList[1], MsgTools.GetPort(commandList[2]));
            if (UIController.Instance != null)
            {
                UIController.Instance.UpdateClientList();
            }
        }
        else if(commandList[0] == "ClientSaid")
        {
            //加一条历史 
            var client = GlobalData.GetClient(commandList[1],MsgTools.GetPort(commandList[2]));
            if(client!=null)
            {
                client.AddHisrroy(commandList[3]);
                if(UIController.Instance!=null)
                {
                    UIController.Instance.UpdateHisLog();
                }
            }
        }
    }
}
