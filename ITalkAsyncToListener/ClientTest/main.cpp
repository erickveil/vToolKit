#include <QCoreApplication>

#include <asyncsocketclient.h>
#include <TextFile.h>
#include <fileLog.h>
#include <synchronoussocketclient.h>
#include "responsereader.h"


using namespace vToolKit;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    AsyncSocketClient ac;
    TextFile log_file("test.log");
    fileLog log(&log_file);
    SynchronousSocketClient worker(&log);
    worker.setConnectInfo("127.0.0.1:50503", 5000);
    //ac.initClient(&log, "my client", &worker, "This is a test.");
    ResponseReader rr(&ac);
    //ac.startWorker();
    qDebug()<<"Started worker. Printing from main thread.";

    return a.exec();
}
