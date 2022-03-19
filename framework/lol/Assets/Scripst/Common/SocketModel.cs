using System;


[Serializable]
public class PacketModel
{
    public Int32 msgID;
    public object message;
    public PacketModel() { }
    public PacketModel(Int32 t, object o)
    {
        this.msgID = t;
        this.message = o;
    }
    public T GetMessage<T>() where T : class
    {
        return message as T;
    }
}

