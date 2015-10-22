#ifndef IFLATFILE_H
#define IFLATFILE_H

#include "iflatfilerecord.h"
#include "IReadWriteFile.h"


namespace vToolKit{

    class IFlatFile
    {

    public:
        virtual ~IFlatFile() = 0;

        virtual void setSource(IReadWriteFile &source_file) = 0;
        virtual void setSource(QString source_string) = 0;
        virtual void addRecord(IFlatFileRecord &record) = 0;
        virtual void deleteRecord(IFlatFileRecord &record) = 0;
        virtual void truncateFile() = 0;
        virtual IFlatFileRecord * queryRecord(QString index_name,
                                              QString index_value) = 0;
        virtual void editField(QString field_name, QString query_value,
                               QString new_value) = 0;
        virtual void saveFile() = 0;
        virtual void saveFile(IReadWriteFile &destination_file) = 0;
    };

}

#endif // IFLATFILE_H
