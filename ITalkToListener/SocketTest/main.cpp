#include <QCoreApplication>
#include "synchronoussocketclient.h"
#include "fileLog.h"
#include "TextFile.h"
#include <QDebug>
#include <QByteArray>

using namespace vToolKit;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    try{

        TextFile log_file("test.log");
        fileLog log(&log_file);
        QHostAddress host("192.168.60.128");
        int port=502;
        int timeout=5000;
        SynchronousSocketClient ssc(&log,host,port,timeout);

        const char  MPRR[12]={'\0','\0','\0','\0','\0','\06','\0','\03','\0','\0','\0','\01'};

        QByteArray msg(MPRR,12);
        QByteArray response=ssc.sendAndReceive(msg);
        qDebug()<<response;
    }

    catch(const QxException &ex){
        qDebug()<<"Exception in: "<<ex.method()<<" line: "<<QString::number(ex.line())<<": "<<ex.what();
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);



    return a.exec();
}
