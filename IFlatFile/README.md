IFlatFile
====

Interface for interacting wiht flat-file data sources.
Gives CRUD-like access to dealing with the data in these files.

IFlatFile is made up of multiple IFlatFileRecords.
Each IFlatFileRecord is made up of IFlatFileFields.

Extend IFlatFile classes for each type of flat file (CSV, etc.).

Example: LogFile is a ASCII text file. Each record is seperated with an "end of
record" character (ASCII 30). Each field is seperated with a " | ".

By providing IFlatFile as the file parameter to clogger, you can later choose
if logs get written to that LogFile format or CSV, or any other polymorphic
extention to the interface.

