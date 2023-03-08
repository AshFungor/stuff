# Vangrind summary

## Vangrind core

Invoke vangrind with this command:
```
valgrind [valgrind-options] your-prog [your-prog-options]
```
The most important tools is _--tool_, which describes a tool that 
vangrind should run, memcheck is default and therefore can be omitted:
```
valgrind your-prog
```
To properly analyze executable, option -g should be used when compiling one. 
Otherwise, output from vangrind is mostly useless.

Table of useful options.
| option | description |
| :----: | :---------: |
| --gen-suppressions=yes | Vangrind handles not only program's errors, but also ones that belong to linked libraries (graphics, C libraries and so on), which makes some error messages obsolete. This option helps to write suppressions file to ignore such messages. |




