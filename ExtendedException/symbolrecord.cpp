#include "symbolrecord.h"

namespace vToolKit {

SymbolRecord::SymbolRecord(QString symbol_record_string)
{
    _record_string = symbol_record_string;
}

int SymbolRecord::getIntAddress()
{
    if (_int_address == -1) { _initSymbolData(); }

    return _int_address;
}

QString SymbolRecord::getMethodName()
{
    if (_method_name.isEmpty() || _method_name.isNull())
    {
        _initSymbolData();
    }

    return _method_name;
}

void SymbolRecord::_initSymbolData()
{
    _parseHexAddress();
    _parseIntAddress();
    _parseMethodName();
}

void SymbolRecord::_parseHexAddress()
{
    _hex_address = _record_string.left(ADDY_LENGTH);
    bool is_no_address = _hex_address.trimmed() == "";
    if (is_no_address) { _hex_address = "0"; }
}

void SymbolRecord::_parseIntAddress()
{
    bool is_successful;
    _int_address = _hex_address.toUInt(&is_successful, 16);

    if (!is_successful) { _int_address = -1; }
}

void SymbolRecord::_parseMethodName()
{
    QStringRef name_substring(&_record_string);
    int string_length = _record_string.size() - START_NAME;
    _method_name = name_substring.mid(START_NAME, string_length).toString();
}

}  // namespace vToolKit
