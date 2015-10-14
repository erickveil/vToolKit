#ifndef IFLATFILE_H
#define IFLATFILE_H

namespace vToolKit{

#include <QFileInfo>

//#include "iflatfilerecord.h"
#include "iflatfilefield.h"


    class IFlatFile
    {

    public:
        virtual IFlatFile() = 0;
        virtual IFlatFile(QFileInfo source_file) = 0;
        virtual IFlatFile(QString source_string) = 0;
        virtual ~IFlatFile() = 0;

        virtual void setSource(QFileInfo source_file) = 0;
        virtual void setSource(QString source_string) = 0;
        //virtual void addRecord(IFlatFileRecord record) = 0;
        //virtual void deleteRecord(IFlatFileRecord record) = 0;
        virtual void truncateFile() = 0;
        //virtual IFlatFileRecord * queryRecord(IFlatFileField index_field) = 0;
        virtual void editField(IFlatFileField index_field,
                               IFlatFileField new_field) = 0;
        virtual void saveFile() = 0;
        virtual void saveFile(QFileInfo destination_file) = 0;
    };

}

#endif // IFLATFILE_H
