#include <QCoreApplication>
#include <qxexception.h>
#include <qxfatalexception.h>
#include <QDebug>
#include <stdexcept>

//using namespace vQtTools;
using namespace vToolKit;

int main(int argc, char *argv[])
{
    int test_count=0;
    bool pass=false;
    QString msg;
    QString test_name;
    QString actual;
    QString expected;
    int i_actual;
    int i_expected;

    QCoreApplication a(argc, argv);

    // Test test
    //========================================
    test_name="test";
    actual="dog";
    expected="dog";
    ++test_count;
    Q_ASSERT(actual==expected);

    // Test2 test
    //========================================
    test_name="test2";
    actual="cat";
    expected="cat";
    pass=actual==expected;
    msg="Expected: "+expected+" Actual: "+actual;
    ++test_count;
    Q_ASSERT_X(pass,test_name.toLocal8Bit(),msg.toLocal8Bit());


    //========================================
    // Test std::exception
    test_name="stdExeption";
    msg="exception not caught";
    pass=false;
    try{
        ++test_count;
        throw std::exception();
    }
    catch(std::exception &ex){
        pass=true;
    }
    catch(...){
        pass=false;
    }
    Q_ASSERT_X(pass,test_name.toLocal8Bit(),msg.toLocal8Bit());


    //========================================
    // Test runtime_error
    test_name="stdRuntimeError";
    msg="exception not caught";
    pass=false;
    try{
        ++test_count;
        throw runtime_error("runtime_error message");
    }
    catch(runtime_error &ex){
        pass=true;
    }
    catch(...){ pass=false; }

    Q_ASSERT_X(pass,test_name.toLocal8Bit(),msg.toLocal8Bit());


    //========================================
    // Test QxException
    test_name="QxException";
    msg="exception not caught";
    pass=false;
    try{
        ++test_count;
        throw QxException("method_name", 1, "test msg");
    }
    catch(QxException &ex){
        pass=true;
    }
    catch(...){ pass=false; }
    Q_ASSERT_X(pass,test_name.toLocal8Bit(),msg.toLocal8Bit());


    //========================================
    // Test QxException values
    msg="exception not caught";
    try{
        throw QxException("method_name", 1, "test msg");
    }
    catch(QxException &ex){
        // method
        ++test_count;
        test_name="QxExceptionMethod";
        actual=ex.method();
        expected="method_name";
        msg="Expected: "+expected+" Actual: "+actual;
        pass=expected==actual;
    Q_ASSERT_X(pass,test_name.toLocal8Bit(),msg.toLocal8Bit());

        // line
        ++test_count;
        test_name="QxExceptionLine";
        i_actual=ex.line();
        i_expected=1;
        msg="Expected: "+expected+" Actual: "+actual;
        pass=i_expected==i_actual;
    Q_ASSERT_X(pass,test_name.toLocal8Bit(),msg.toLocal8Bit());

        // what
        ++test_count;
        test_name="QxExceptionWhat";
        actual=ex.what();
        expected="test msg";
        msg="Expected: "+expected+" Actual: "+actual;
        pass=expected==actual;
    Q_ASSERT_X(pass,test_name.toLocal8Bit(),msg.toLocal8Bit());

    }

    //========================================
    // Test QxException cast to QxFatalException
    test_name="QxExceptionCast";
    msg="exception not caught";
    pass=false;
    try{
        ++test_count;
        throw QxException("fatal method name",34, "fatal message");
    }
    catch(QxFatalException &ex){
        pass=true;
    }
    catch(...){ pass=false; }
    Q_ASSERT_X(pass,test_name.toLocal8Bit(),msg.toLocal8Bit());

    //========================================
    // Test QxFatalException cast to QxException
    // Note: The casing order had been changed, this test is no longer valid.
    /*
    test_name="QxFatalExceptionCast";
    msg="fatal exception not caught";
    pass=false;
    try{
        ++test_count;
        throw QxFatalException("fatal method name",34, "fatal message");
    }
    catch(QxException &ex){
        pass=true;
    }
    catch(...){ pass=false; }
    Q_ASSERT_X(pass,test_name.toLocal8Bit(),msg.toLocal8Bit());
    */

    //========================================
    // Test QxFAtaException
    test_name="QxFatalException";
    msg="exception not caught";
    pass=false;
    try{
        ++test_count;
        throw QxFatalException("fatal method name",34, "fatal message");
    }
    catch(QxFatalException &ex){
        pass=true;
    }
    Q_ASSERT_X(pass,test_name.toLocal8Bit(),msg.toLocal8Bit());



    //========================================
    // Test QxFatalException values
    try{
        throw QxFatalException("method_name", 1, "test msg");
    }
    catch(QxFatalException &ex){
        // method
        ++test_count;
        test_name="QxFatalExceptionMethod";
        actual=ex.method();
        expected="method_name";
        msg="Expected: "+expected+" Actual: "+actual;
        pass=expected==actual;
    Q_ASSERT_X(pass,test_name.toLocal8Bit(),msg.toLocal8Bit());

        // line
        ++test_count;
        test_name="QxFatalExceptionLine";
        i_actual=ex.line();
        i_expected=1;
        msg="Expected: "+expected+" Actual: "+actual;
        pass=i_expected==i_actual;
    Q_ASSERT_X(pass,test_name.toLocal8Bit(),msg.toLocal8Bit());

        // what
        ++test_count;
        test_name="QxFatalExceptionWhat";
        actual=ex.what();
        expected="test msg";
        msg="Expected: "+expected+" Actual: "+actual;
        pass=expected==actual;
    Q_ASSERT_X(pass,test_name.toLocal8Bit(),msg.toLocal8Bit());

    }

    qDebug()<<"OK "<<test_count<<" tests PASSED.";



    return a.exec();
}
