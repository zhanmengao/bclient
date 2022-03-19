using System;



enum IPCMSG_ID
{
    LOGIN_REQ,
    LOGIN_RET,
    REGISTER_REQ,
    REGISTER_RET,
}
[Serializable]
public class SD_LOGIN_REQ
{
    public IntPtr nSocket;
    public CG_LOGIN mData;
}
[Serializable]
public class SD_REGISTER_REQ
{
    public IntPtr nSocket;
    public CG_REGISTER mData;
}
[Serializable]
public class DS_LOGIN_RET
{
    public IntPtr nSocket;
    public GC_LOGIN_RET rData = new GC_LOGIN_RET();
}