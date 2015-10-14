Extended Exceptions
====

Exception classes that provide funcitonality for easily getting the method name
and line number of where the exception was thrown.

They are an extention of std::runtime_error.

All of the exceptions do the same thing, different classes are provided to
facilitate different catching levels.

Currently, the inheritance structure is:

std::exception -> std::runtime_error -> vQtTools::QxException ->
vQtTools::QxFatalException

vQttools is the namespace.

The exceptions depend on Qt, which will need to be installed on a system that
uses them.
