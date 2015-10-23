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

    TextFile log_file("test.log");
    fileLog log(&log_file);
    QHostAddress host("127.0.0.1");
    int port=50503;
    int timeout=5000;
    SynchronousSocketClient worker(&log,host,port,timeout);
    AsyncSocketClient ac(&log, "my client", &worker, "This is a test.");
    // The Response Reader allows me to connect it as an object with a slot
    // to the signal that receives the response from the socket.
    ResponseReader rr(&ac);
    ac.startWorker();
    qDebug()<<"Started worker. Printing from main thread.";

    return a.exec();
}
