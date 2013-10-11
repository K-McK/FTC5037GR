FTC5037GR - The Got Robot? Source Code Repository
=================================================

1. - Coding Standards

1.1 - Header files (".h" files)
Header files should be used for declaring enumerations,
macros, structures and global constants to be used throughout multiple places
within the system.  Header files will also hold the function implementations.  In these cases, the file name should indicate the name of the function defined within it.

1.2 - Source files (".c" files)
Source files should ideally contian only a single function per file.
The name of the function is used to determine the name of the file.  In doing
this, it becomes easier to identify where specific pieces of functionality live
and the code become more modular and hence, more reusalbe.

1.3 - Global variables
Globlal variable names should be prefixed with "g_".

1.4 - Directory Structure

README.md
examples
  -lib (the directory containing all the header files to suppor the examples)
doc (project documentation)
src
  -lib (the directory containing all the header files)
