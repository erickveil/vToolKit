#include "symboltable.h"

namespace vToolKit {

SymbolTable::SymbolTable(QString program_name)
{
    _program_name = program_name;
}

SymbolTable::SymbolTable()
{
    _program_name = QFileInfo( QCoreApplication::applicationFilePath() )
            .fileName();
}

void SymbolTable::initSymbolTable()
{
    _symbol_record_list.clear();
    _buildSymbolList();
}

SymbolRecord SymbolTable::getSymbolRecord(int address)
{
    bool is_table_initialized = _symbol_record_list.count() != 0;
    if (!is_table_initialized) { initSymbolTable(); }
    int best_address = 0;
    SymbolRecord best_record("");
    for(int i = 0; i < _symbol_record_list.size(); ++i) {
        auto record = _symbol_record_list[i];
        int record_addy = record.getIntAddress();
        bool is_same_address = record_addy == address;
        bool is_closer_than_best = record_addy > best_address;
        bool is_better_address = record_addy < address && is_closer_than_best;

        if (is_same_address) { return record; }
        if (is_better_address) {
            best_address = record_addy;
            best_record = record;
        }
    }
    return best_record;
}

void SymbolTable::_buildSymbolList()
{
    qDebug() << "program name: " << _program_name;

    QString cmd = "nm";
    QStringList args;
    args << "-C" << _program_name;
    process = new QProcess();
    process->start(cmd, args);

    _readCommandOutput();

    // sort the list here?
    // http://stackoverflow.com/a/38936796
    // The table is small enough, it's not necessary.
    // The table search, as written, is O(n²), but it's still small enough to be
    // adequate for most programs.
}

bool SymbolTable::_isOutputAvailable()
{
    process->waitForReadyRead(250);
    bool bytes_available = process->bytesAvailable();
    return bytes_available > 0;
}

void SymbolTable::_assignCmdOutputToSymbolList(QStringList output_list)
{
    for(int i = 0; i < output_list.size(); ++i) {
        SymbolRecord new_record(output_list[i]);

        /* Note: I do the following method call just to trigger the lazy class
         * init early. It isn't necessary, but it helped when debugging during
         * initial development.
         */
        new_record.getIntAddress();

        _symbol_record_list.append(new_record);
    }
}

void SymbolTable::_readCommandOutput()
{
    process->waitForStarted(250);

    while (_isOutputAvailable()) {
        QByteArray cmd_output = process->readAllStandardOutput();
        QStringList output_list = QString(cmd_output).split('\n');
        _assignCmdOutputToSymbolList(output_list);
    }

    process->waitForFinished(250);
}


}  // namespace vToolKit
