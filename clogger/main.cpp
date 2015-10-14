#include <algorithm>

#include "clogCmd.h"

using namespace std;
using namespace clog;

int main(int argc, char * argv[]) {
    clogCmd logger;
    EntryData data=logger.getDataFromOptions(argc,argv);
    string msg = logger.getMessageFromStdIn();
    logger.writeToLog(data, msg);
    exit(EXIT_SUCCESS);
}

