# SESSION 1


### Hoe gaat het? 
* rondje stand van zaken 
* csd2a
* git commits



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


### Classes in header, cpp files
--> zie 01_cmake
* opsplitsen van classes & cmake
* destructor

### Access specifiers
--> zie 02_oscillator, 02_oscillator_final, 02_oscillator_stepBstep
* Oscillator class: access specifiers, public, private and protected

### Basic inheritance
--> zie inheritance.pdf en 03_simpleInheritance, 03_simpleInhertance_final
* Basic inheritance: Pet, Cat, Dog


### Bonus ?     
* compile stappen
* compile with build script

