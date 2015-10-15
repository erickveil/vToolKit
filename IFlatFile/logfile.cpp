#include "logfile.h"

namespace vToolKit{

    LogFile::LogFile()
    {
        throw new QxException(__PRETTY_FUNCTION__,__LINE__,
                              "Class implementation not complete.");
        //TODO: need null IReadWriteFile class
        //_source_file=new NullFile;
    }

    LogFile::LogFile(QString source_string)
    {
        _source_string=source_string;
        //_source_file=new NullFile;
    }

    LogFile::LogFile(IReadWriteFile &source_file)
    {
        _source_file=&source_file;
    }

    LogFile::~LogFile()
    {
        //if(_source_file.isNull()) delete _source_file;
    }

    void LogFile::setSource(IReadWriteFile &source_file)
    {
        _source_file=&source_file;
    }

    void LogFile::setSource(QString source_string)
    {
        _source_string=source_string;
    }

    void LogFile::addRecord(IFlatFileRecord &record)
    {
        _readyList();
        _record_list.append(&record);
        saveFile();
    }

    void LogFile::deleteRecord(IFlatFileRecord &record)
    {
        _readyList();
        // logs do not have unique records to delete.
        // OR date line is unique id??
        // TODO: throw exception? log error?
    }

    void LogFile::truncateFile()
    {
        _record_list.clear();
        _source_string.clear();
        _source_file->overwriteFile("");
    }

    // TODO: queryRecords should also be an interface method.
    IFlatFileRecord *LogFile::queryRecord(IFlatFileField &index_field)
    {
        _readyList();

        if(_record_list.isEmpty()) return new LogFileRecord;

        // Just going to be lazy and linear search this list...
        int i;
        for(i=0; i<_record_list.size(); ++i){
            // TODO: This should be an == implementation of IFlatFileField/Record.
            /*
            IFlatFileRecord *record=&_record_list.at(i);
            IFlatFileField *field=record->getField(index_field.name());
            if(field->value()==index_field.value()) return record;
            */
        }

        return new LogFileRecord;
    }

    void LogFile::editField(IFlatFileField &index_field,
                            IFlatFileField &new_field)
    {

    }

    void LogFile::saveFile()
    {

    }

    void LogFile::saveFile(IReadWriteFile &destination_file)
    {

    }

}

