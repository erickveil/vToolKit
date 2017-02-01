#include "backtraceresultrecord.h"

namespace vToolKit {

BackTraceResultRecord::BackTraceResultRecord(QString trace_line,
                                             SymbolTable symbol_table)
{
    _trace_line = trace_line;
    _symbol_table = symbol_table;
}

QString BackTraceResultRecord::getProgramName()
{
    if(_program_name.isEmpty() || _program_name.isNull()) {
        _initParsedData();
    }

    return _program_name;
}

int BackTraceResultRecord::getRecordAddress()
{
    if (_record_address == -1) {
        _initParsedData();
    }

    return _record_address;
}

QString BackTraceResultRecord::getHexRecordAddress()
{
    if (_hex_address.isEmpty() || _hex_address.isNull()) {
        _initParsedData();
    }

    return _hex_address;
}

QString BackTraceResultRecord::getMethodName()
{
    if (_method_name.isEmpty() || _method_name.isNull()) {
        _initParsedData();
    }

    return _method_name;
}

void BackTraceResultRecord::_initParsedData()
{
    _parseProgramName();
    _parseRecordAddress();
    _parseMethodName();
}

void BackTraceResultRecord::_parseProgramName()
{
    QChar primary_delim = ' ';
    QChar path_delim = '/';
    QStringList primary_components = _trace_line.split(primary_delim);
    QString path_string = primary_components.first();
    QStringList path_components = path_string.split(path_delim);
    QString file_string = path_components.last();
    QChar method_delim = '(';
    QStringList method_components = file_string.split(method_delim);
    _program_name = method_components.first();
}

void BackTraceResultRecord::_parseRecordAddress()
{
    _parseHexAddress();
    _record_address = _hexAddressToIntAddress(_hex_address);
}

void BackTraceResultRecord::_parseHexAddress()
{
    QChar primary_delim = ' ';
    QStringList primary_components = _trace_line.split(primary_delim);
    QString full_hex_component = primary_components.last();
    QChar hex_delim = 'x';
    QStringList parsed_hex_components = full_hex_component.split(hex_delim);
    QString uncleaned_hex = parsed_hex_components.last();
    int hex_length = uncleaned_hex.length() - 1;
    QString hex_string = uncleaned_hex.left(hex_length);
    _hex_address = hex_string;
}

int BackTraceResultRecord::_hexAddressToIntAddress(QString hex_string)
{
    bool is_successful;
    int parsed_value = hex_string.toUInt(&is_successful, 16);

    if (!is_successful) {
        // libc.so.6 functions will be too big to parse and legit show error
        parsed_value = -1;
    }
    return parsed_value;
}

void BackTraceResultRecord::_parseMethodName()
{
    QChar primary_delim = ' ';
    QChar path_delim = '/';
    QStringList primary_components = _trace_line.split(primary_delim);
    QString path_string = primary_components.first();
    QStringList path_components = path_string.split(path_delim);
    QString file_string = path_components.last();
    QChar method_delim = '(';
    QStringList method_components = file_string.split(method_delim);
    QString uncleaned_method = method_components.last();
    int method_name_size = uncleaned_method.size() -1;
    _method_name = uncleaned_method.left(method_name_size);
    if (_method_name == "") { _determineMethodNameWithTable(); }
}

void BackTraceResultRecord::_determineMethodNameWithTable()
{
    SymbolRecord record("");
    record = _symbol_table.getSymbolRecord(_record_address);
    _method_name = record.getMethodName();
}

}  // namespace vToolKit
