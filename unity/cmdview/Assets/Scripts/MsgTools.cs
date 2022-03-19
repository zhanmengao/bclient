using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class MsgTools
{
    public static void SendMsg(params object[] objs)
    {
        string str = "";
        for (int i = 0; i < objs.Length; i++)
        {
            str += objs[i];
            str += ';';
        }
        IPCTools.WritePipe(IPCTools.ToByte(str));
    }

    public static void SendMsg(string str)
    {
        IPCTools.WritePipe(IPCTools.ToByte(str));
    }
    public static ushort GetPort(string port)
    {
        return Convert.ToUInt16(port);
    }
}


