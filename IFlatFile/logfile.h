#ifndef LOGFILE_H
#define LOGFILE_H

#include "iflatfile.h"
#include "logfilerecord.h"


namespace vToolKit{

    /**
     * WARNING: This class is not complete. Do not use.
     *
     * @brief The LogFile class
     */
    class LogFile : public IFlatFile
    {
    public:
        LogFile();
        LogFile(QString source_string);
        LogFile(IReadWriteFile &source_file);
        ~LogFile();

        void setSource(IReadWriteFile &source_file) override;
        void setSource(QString source_string) override;
        void addRecord(IFlatFileRecord &record) override;
        void deleteRecord(IFlatFileRecord &record) override;
        void truncateFile() override;
        IFlatFileRecord *queryRecord(QString index_name, QString index_value) override;
        void editField(QString field_name, QString query_value,
                       QString new_value) override;
        void saveFile() override;
        void saveFile(IReadWriteFile &destination_file) override;

    private:
        IReadWriteFile *_source_file;
        QString _source_string;
        QList<IFlatFileRecord*> _record_list;

        void _readyList();
        void _isListLoaded();
        void _setSourceStringFromFile();
        void _setRecordsFromString();

    };

}

#endif // LOGFILE_H
