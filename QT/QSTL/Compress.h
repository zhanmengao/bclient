#ifndef COMPRESS_HPP
#define COMPRESS_HPP

#include<QFile>
#include<stdio.h>
void mainCompress()
{
    QFile file("ui_widget.h");
    if(file.exists())
    {
        printf("before qCompress file.size():%lld\n",file.size());
        bool ok = file.open(QIODevice::ReadOnly);
        if(ok)
        {
            QByteArray buffer = file.readAll();
            printf("before qCompress buffer.size():%d \n",buffer.size());
            //压缩
            buffer = qCompress(buffer,-1);//使用默认的zlib压缩
            printf("after qCompress buffer.size():%d \n",buffer.size());
            QFile writeFile("qCompress");
            ok = writeFile.open(QIODevice::WriteOnly);
            writeFile.write(buffer);
            printf("after qCompress writeFile.size():%lld\n",writeFile.size());
            if(ok)
            {
                //解压缩
                buffer = qUncompress(buffer);
                printf("after qUncompress buffer.size():%d\n",buffer.size());
                printf("fileData:%s",buffer.data());
            }
        }
    }
}
#endif // COMPRESS_HPP
