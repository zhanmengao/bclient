using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UIClientItem : MonoBehaviour 
{
    public UILabel ipLabel;
    public ClientData mData;

    public void Init(ClientData data)
    {
        this.gameObject.SetActive(true);
        mData = data;
        ipLabel.text = mData.key.mIpAddr+":"+data.key.mPort.ToString();
    }

    public void OnClick()
    {
        if(UIController.Instance!=null)
        {
            UIController.Instance.OnItemClick(this);
        }
    }
}
