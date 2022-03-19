using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*
 * 消息体内容编码工具
 */
namespace NetFrame
{
    public class MessageEncoding
    {
        /// <summary>
        /// 消息体序列化（应用层）
        /// </summary>
        /// <param name="value"></param>
        /// <returns></returns>
        public static byte[] encode(PacketModel model)
        {
            if (model == null)
            {
                return null;
            }
            ByteArray ba = new ByteArray();
            ba.write(model.msgID);

            if (model.message != null)
            {
                //序列化然后写入
                ba.write(SerializeUtil.encode(model.message));
            }
            byte[] result = ba.getBuff();
            ba.Close();
            return result;
        }

        /// <summary>
        /// 消息体反序列化（应用层）
        /// </summary>
        /// <param name="value"></param>
        /// <returns></returns>
        public static PacketModel decode(byte[] value)
        {
            ByteArray ba = new ByteArray(value);
            PacketModel model = new PacketModel();
            int type;
            ba.read(out type);
            model.msgID = type;
            if (ba.Readnable)
            {
                byte[] message;
                ba.read(out message, ba.Length - ba.Position);                                                  //将剩余数据全部读取出来
                model.message = SerializeUtil.decode(message);                                                  //反序列化剩余数据为消息体
            }
            ba.Close();
            return model;
        }
    }
}
