using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UIEnter : MonoBehaviour
{
    public UIInput RoomLabel;
    public UILabel mFType;

    public void OnClickEnter()
    {
        if(mFType.text == "Room")
        {
            UIChatManager.Instance.Chat.EnterRoom(RoomLabel.value);
        }
        else
        {
            //私聊，直接创建一个tab即可
            var tab = UIChatManager.Instance.AddRoomTab(RoomLabel.value);
            tab.mFType = Forevernine.Midplat.Proto.FORWARD_TYPE.User;
        }
        this.gameObject.SetActive(false);
    }

    public void OnClickLeave()
    {
        if (mFType.text == "Room")
        {
            UIChatManager.Instance.Chat.LeaveRoom(RoomLabel.value);
        }
        else
        {
            UIChatManager.Instance.DelRoomTab(RoomLabel.value);
        }
        this.gameObject.SetActive(false);
    }
}
