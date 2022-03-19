

using Forevernine.Midplat.Proto;
using System.Collections.Generic;

public class Room
{
    public Dictionary<ulong, FIMChatMsg> ChatMessage = new Dictionary<ulong, FIMChatMsg>();          //消息缓存。key = seqid
}