# SESSION 1

### Install gpp, IDE & cmake 

### Introductie 
#### Slides
- Overzicht sessies
- Eindopdracht
#### Van Python over op C++ 
Interpreteren versus compileren
Wat is wat? 
Wanneer is wat handig? 
Zie ook https://dinkum.nl/software/cplusplus/doc/project_building/compiling_and_linking.html

#### Eerste stappen op gebied van C++ 
- Hello world --> zie 1_hello
- Class Note --> zie 2_note_class 
- Compile met g++ --> zie tabel hieronder, gebruik voor nu:
  
  ```g++ [file_name].cpp -o [executable_name]```
- Class Speaker en de _has a relationship_ --> zie 3_speaker

#### Eventueel, anders volgende week 
- cmake





### Over het compilen
| Terminal                         | Toelichting                                                                                                                                                                                                                                        |
|----------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| ```g++ hello.cpp```              | a.out is de applicatie                                                                                                                                                                                                                             |
| ```g++ hello.cpp -o hello_app``` | Met -o en daarna een naam geef je een `objective` mee                                                                                                                                                                                              |
| ```hexdump hello_app```          | 16 getallen → a b c d e f voor 11 12 13 14 15 16                                                                                                                                                                                                   |
| ```hexdump -C hello_app```       | hex + ASCII-weergave                                                                                                                                                                                                                               |
| ```man ascii```                  | ascii tabel weergeven --> kijk bij hexadecimal                                                                                                                                                                                                     |
| ```g++ -S hello.cpp```           | De assembly file hello.s wordt gegenereerd. Assembly is een low level programmeertaal en bevat instructies aan de processor. De assembly code is verschillend per processor architecture.                                                          |
| ```g++ -c hello.s```             | De object-file hello.o wordt gegenereerd. <br/>De compiler creëert object files voor elke source file, vooraf aan deze samen te linken in één executable. Een object file bevat de gecompileerde code, de machine code gecreëerd door de c++ compiler. |     
| ```g++ -c hello.cpp```           | De object file hello.o wordt in één stap gegeneerd, onder windows .obj, de gecompileerde versies van 1 c++ bestand                                                                                                                                 |
 | ```g++ hello.o```                | Maak van hello.o een executable --> a.out                                                                                                                                                                                                          |
| ```g++ hello.o -o hello```               | Maak van hello.o een executable genaamd hello                                                                                                                                                                                                      |

Zie ook https://dinkum.nl/software/cplusplus/doc/project_building/cpp_compiling_and_linking.html
