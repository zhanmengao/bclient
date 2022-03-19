using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using UnityEngine;


class PlayerData
{
    public static void HandlePacket(PacketModel rPacket)
    {
        if(rPacket.msgID == (int)Pack_ID.LOGIN_RET)
        {
            GC_LOGIN_RET packet = rPacket.GetMessage<GC_LOGIN_RET>();
            Debug.Log(packet.tips);
        }
    }
}

