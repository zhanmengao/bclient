#ifndef COMPRESS_HPP
#define COMPRESS_HPP
#include<QByteArray>
class CompressTools
{
public:
    static void Zip(QByteArray& buffer)
    {
         buffer = qCompress(buffer,-1);             //使用默认的zlib压缩
    }
    static void UnZip(QByteArray& buffer)
    {
         buffer = qUncompress(buffer);              //使用默认的zlib压缩
    }
};

#endif // COMPRESS_HPP
