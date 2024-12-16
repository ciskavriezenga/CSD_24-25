# Clean Your Repos!

## Wat ik niet wil zien >:- ()
### Build files <br> 
![buildfiles1.png](assets/buildfiles1.png)
### Executables <br>
![Executable1.png](assets/Executable1.png) <br>
![Executable2.png](assets/Executable2.png)
### audio files <br>
![audiofile.png](assets/audiofile.png)
### moeilijk te vinden eindopdracht <br>
![waarisjeeindopdracht.png](assets/waarisjeeindopdracht.png)
### .DS_Store



## Gebruik een .gitignore

```.gitignore
# extensions
*.wav 
*.jpg

# folders
# specifieke map in de root folder
/map1       
# elke map met de deze naam
map3/       

# build folders 
build/
cmake-build-debug/

# IDE 
.idea
.vscode

# OS-generated
.DS_Store

# cmake 
CMakeCache.txt
cmake_install.cmake
```

## N.B.
Als je deze dingen al in je repository hebt staan, moet je ze verwijderen voordat je een .gitignore aanmaakt, <br>
anders kan negeert git je bestand tijdens de `rm` opdracht. 

## Handige Tool
[.gitignore generator](https://www.toptal.com/developers/gitignore)
