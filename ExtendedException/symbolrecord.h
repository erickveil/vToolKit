/**
 * symbolrecord.h
 * Erick Veil
 * 2017-01-30
 *
 * Represents a single entry in a table of symbols from the compiled binary
 * file.
 *
 * Used to hold easily parseable symbol table data to match against addresses
 * in a stack trace.
 */
#ifndef SYMBOLRECORD_H
#define SYMBOLRECORD_H

#include <QString>
#include <QStringList>
#include <QStringRef>

namespace vToolKit {

class SymbolRecord
{
    // assumes first character is 1 and last is 16.
    int ADDY_LENGTH = 16;

    // assumes first character index is 0.
    int START_NAME = 19;

    /**
     * @brief _record_string
     *
     * Record strings are often in the form:
     * 00000000004035f8 T vToolKit::BackTraceResultRecord::getHexRecordAddress()
     *
     * But can also be in the form:
     *                  U QListData::shared_null@@Qt_5
     *
     * 3 Fields:
     * 1. Address in hex, or empty.
     * 2. Type of symbol.
     * 3. Method name.
     *
     * Each of these strings is parsed out of a line of
     * `nm filename | c++filt`
     * or
     * `nm -C filename`
     *
     */
    QString _record_string = "";
    QString _hex_address = "";
    QString _method_name = "";
    int _int_address = -1;

 public:
    /**
     * @brief SymbolRecord
     *
     * @param symbol_record_string The raw string that is a single line from
     * the output of the `nm` command.
     */
    SymbolRecord(QString symbol_record_string);

    /**
     * @brief getIntAddress
     *
     * @return The address of the symbol as an integer.
     */
    int getIntAddress();

    /**
     * @brief getMethodName
     *
     * @return The method name of the symbol.
     */
    QString getMethodName();

 private:
    void _initSymbolData();
    void _parseHexAddress();
    void _parseIntAddress();
    void _parseMethodName();
};

}  // namespace vToolKit

#endif  // SYMBOLRECORD_H
