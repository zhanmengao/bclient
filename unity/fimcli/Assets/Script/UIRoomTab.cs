using Forevernine.Midplat.Proto;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UIRoomTab : MonoBehaviour
{
    public UILabel mRoomLabel;
    public FORWARD_TYPE mFType;
    public string TargetID
    {
        get
        {
            return mRoomLabel.text;
        }
        set
        {
            mRoomLabel.text = value;
        }
    }

    public void OnClickRoomTab()
    {
        UIChatManager.Instance.OnClickPage(this);
    }
}
