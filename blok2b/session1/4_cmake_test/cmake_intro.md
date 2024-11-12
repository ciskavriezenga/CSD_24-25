# Cmake

run in de terminal 
```cmake -S . -B build```
```cd build```
```cmake --build . ```

Wanneer je niet nieuwe bestanden toevoegt hoef je maar één keer cmake -S . -B  build te runnen. Bij wijzigingen in je code hoef je enkel in de build directory ```cmake --build .``` te runnen.  


| Terminal                  | Toelichting                                          |
|---------------------------|------------------------------------------------------|
| ```cmake -S . -B build``` | Build files genereren                                |
| ```-S```                  | Waar de source te vinden is                          |
| ```-B```                  | Waar je de build files wilt plaatsen                 |
| -jX                       | om meerdere cores te gebruiken --> X is aantal cores |
| ```cd build```            | Navigeer naar je build directory                     |
| ```cmake --build .```     | Run make in je directory                             |                            |
| ```cd ..```               | Navigeer weer een directory 'hoger'.                 |
