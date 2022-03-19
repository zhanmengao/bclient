using Forevernine.Midplat.Proto;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UIChatItem : MonoBehaviour
{
    public UISprite mIcon;
    public UILabel mSender;
    public UILabel mContent;
    public void Init(FIMChatMsg msg)
    {
        mSender.text = msg.SrcUID;
        mContent.text = msg.Content.ToStringUtf8();
    }
}
