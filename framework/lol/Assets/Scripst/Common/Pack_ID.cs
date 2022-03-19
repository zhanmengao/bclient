using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;


enum Pack_ID
{
    LOGIN,
    LOGIN_RET,
    REGISTER,
}

[Serializable]
public class CG_LOGIN
{
    public string UserName = ("");
    public string PassWord = ("");
}
[Serializable]
public class CG_REGISTER
{
    public string UserName = ("");
    public string PassWord = ("");
}
[Serializable]
public class GC_LOGIN_RET
{
    public bool bSec;
    public string tips;
    public string mUserName;
}