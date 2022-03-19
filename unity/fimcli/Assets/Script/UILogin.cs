using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UILogin : MonoBehaviour
{
    public UIInput AddressLabel;
    public UIInput AccessTokenLabel;
    public void OnClickLogin()
    {
        UIChatManager.Instance.Chat.Connect("test",AddressLabel.value, AccessTokenLabel.value,"999");
        this.gameObject.SetActive(false);
    }
}
