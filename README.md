FTC5037GR - The Got Robot? Source Code Repository
=================================================

1. - Coding Standards

1.1 - Header files (".h" files)
Header files should be used for declaring function prototypes, enumerations,
macros, structures and global constants to be used throughout multiple places
within the system.

1.2 - Source files (".c" files)
Source files should ideally contian only a single function per file.
The name of the function is used to determine the name of the file.  In doing
this, it becomes easier to identify where specific pieces of functionality live
and the code become more modular and hence, more reusalbe.


Directory Structure

README.md
lib (the directory containing all the header files)
