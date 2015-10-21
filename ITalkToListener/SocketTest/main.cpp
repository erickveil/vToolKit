#include <QCoreApplication>
#include "synchronoussocketclient.h"
#include "fileLog.h"
#include "TextFile.h"
#include <QDebug>

using namespace vToolKit;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    try{

        TextFile log_file("test.log");
        fileLog log(&log_file);
        SynchronousSocketClient ssc(&log);

        ssc.setConnectInfo("adsfee883.edwea:50503",5000000);
        QString msg="test transmission";
        QString response=ssc.sendAndReceive(msg);
        qDebug()<<response;
    }

    catch(const QxException &ex){
        qDebug()<<"Exception in: "<<ex.method()<<" line: "<<QString::number(ex.line())<<": "<<ex.what();
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);



    return a.exec();
}
