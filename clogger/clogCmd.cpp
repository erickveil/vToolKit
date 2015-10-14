//
// Created by fac on 8/21/15.
//

#include "clogCmd.h"
#include "StdFile.h"


void clog::clogCmd::usage()
{
     string help=
             " NAME\n"
        " ===\n"
        " clogger\n"
        " \n"
        " SYNOPSIS\n"
        " ===\n"
        " clogger [OPTION...] STRING\n"
        " \n"
        " DESCRIPTION:\n"
        " ===\n"
        " Clogger writes a log entry either to stderr or stdlog, depending on "
                     "the"
        " log level, or it writes to a file, if provided. The log entries "
                     "follow"
        " the log4Cxx format, without the insane Apache build and install"
        " requirements.\n"
        " OPTIONS\n"
        " ===\n"
        "\n"
        " -h   --help         Show this help.\n"
        " -v   --version      Print the version information.\n"
        "\n"
        " Log levels:\n"
        " ----\n"
        " If more than one level is provided, the entry will be entered into "
                     "the\n"
        " log multiple times: once at each requested level.\n"
        "\n"
        " -i   --info          Write an INFO level log entry.\n"
        " -d   --debug         Write a DEBUG level log entry.\n"
        " -w   --warn          Write a WARN level log entry.\n"
        " -e   --error         Write an ERROR level log entry.\n"
        " -f   --fatal         Write a FATAL level log entry.\n"
        "\n"
        " -o   --out <file>    Write log entry to a file at the path "
                     "provided.\n"
        " If this option is omitted, then the log entry will default to its"
        " output stream. Info and debug output to stdlog by default. Warn,"
        " error, and fatal level logs output to stderr.\n"
        "\n"
        " EXAMPLE:\n"
        " ---\n"
        "echo 'This is an info log entry.' | clogger -io /var/log/my_log.log\n";

    cout << help << endl;
}

int clog::clogCmd::stringToLineNumber(string number) {
    int result;
    if(stringstream(number) >> result){
        return result;
    }
    return -1;
}

clog::EntryData clog::clogCmd::getDataFromOptions(int argc, char * argv[]) {
    int short_option;
    EntryData data;
    while(true) { if(!_iterateOptions(short_option, argc, argv, data)) break; }
    return data;
}

bool clog::clogCmd::_iterateOptions(int &short_option, int argc, char **argv,
                                    EntryData &data) {

    string line="";

    static struct option long_options[] = {
        {"help",no_argument,0,0 },
        {"method",required_argument,0,0 },
        {"line",required_argument,0,0 },
        {"out",required_argument,0,0 },
        {"info",no_argument,0,0 },
        {"debug",no_argument,0,0 },
        {"warn",no_argument,0,0 },
        {"error",no_argument,0,0 },
        {"fatal",no_argument,0,0 },
        {"version",no_argument,0,0 },
        {0,0,0,0 }
    };
    int option_index = 0;
    short_option = getopt_long(argc, argv, "hm:l:o:idwefv", long_options,
                    &option_index);
    if(short_option == -1) return false;
    string no_file="";


    switch(short_option){
        case 0: {
            string name = long_options[option_index].name;
            if (name == "method") data.method = optarg;
            else if (name == "line") data.line = stringToLineNumber(optarg);
            else if (name == "out") data.out_file = optarg;
            else if (name == "help") {
                usage();
                exit(EXIT_SUCCESS);
            }
            else if (name == "info") data.level=INFO;
            else if(name == "debug") data.level=DEBUG;
            else if(name == "warn") data.level=WARN;
            else if(name == "error") data.level=ERROR;
            else if(name == "fatal") data.level=FATAL;
            else if(name == "version") {
                cout<<vVersion::getVersion()<<endl;
                exit(EXIT_SUCCESS);
            }
            else {
                usage();
                exit(EXIT_FAILURE+1);
            }
            break;
        }
        case 'h':
            usage();
            exit(EXIT_SUCCESS);
            break;
        case 'm':
            data.method=optarg;
            break;
        case 'l':
            data.line=stringToLineNumber(optarg);
            break;
        case 'o':
            data.out_file=optarg;
            break;
        case 'i':
            data.level=INFO;
            break;
        case 'd':
            data.level=DEBUG;
            break;
        case 'w':
            data.level=WARN;
            break;
        case 'e':
            data.level=ERROR;
            break;
        case 'f':
            data.level=FATAL;
            break;
        case 'v':
            cout<<vVersion::getVersion()<<endl;
            exit(EXIT_SUCCESS);
        default:
            break;
    }

    return true;
}

void clog::clogCmd::writeToLog(EntryData data, string msg) {
    StdFile log_file(data.out_file);
    fileLog log(&log_file);

    switch(data.level){
        case INFO:
            log.logInfo(data.method,data.line,msg);
            break;
        case DEBUG:
            log.logDebug(data.method,data.line,msg);
            break;
        case WARN:
            log.logWarn(data.method,data.line,msg);
            break;
        case ERROR:
            log.logError(data.method,data.line,msg);
            break;
        case FATAL:
            log.logFatal(data.method,data.line,msg);
        default:
            break;
    }
}

string clog::clogCmd::getMessageFromStdIn() {
    string msg="";
    string line;
    while(getline(cin, line)){
        msg+=line+"\n";
    };
    return msg;
}
