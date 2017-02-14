/**
 * symboltable.h
 * Erick Veil
 * 2017-01-30
 *
 * The SymbolTable class pulls a list of all symbols and their addresses from
 * the main program and any linked libraries in an ELF system.
 *
 * These symbols are method and function names. They can be looked up by
 * address during a stack trace, so we have method names in the trace.
 */

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <QByteArray>
#include <QCoreApplication>
#include <QDebug>
#include <QFileInfo>
#include <QList>
#include <QProcess>
#include <QString>
#include <QStringList>

#include "symbolrecord.h"

using namespace std;


namespace vToolKit {

class SymbolTable
{
    QString _program_name;
    QProcess *process = nullptr;
    QList<SymbolRecord> _symbol_record_list;

 public:
    /**
     * @brief SymbolTable
     *
     * @param program_name The name of the executable file. Can be a full path.
     * You can get this value from argv[0] or you can get it from
     * QFileInfo(QCoreApplication::applicationFilePath()).fileName();
     */
    SymbolTable(QString program_name);

    /**
     * @brief SymbolTable
     *
     * Default constructor used for class member instantiation without pointers.
     * (Because I'm lazy.)
     */
    SymbolTable();

    /**
     * @brief initSymbolTable
     *
     * Populates the symbol table with SymbolRecords.
     */
    void initSymbolTable();

    /**
     * @brief getSymbolRecord
     *
     * Returns the symbol record that has the highest address without being
     * greater than the provided address. That symbol record should represent
     * the method that the trace entry belongs to.
     *
     * @param address The trace address to look up.
     * @return
     */
    SymbolRecord getSymbolRecord(int address);

 private:
    void _buildSymbolList();
    bool _isOutputAvailable();
    void _assignCmdOutputToSymbolList(QStringList output_list);
    void _readCommandOutput();

};

}  // namespace vToolKit

#endif  // SYMBOLTABLE_H
