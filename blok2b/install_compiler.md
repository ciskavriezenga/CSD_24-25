# Stappenplan C++ installeren g++ compiler

---

### MAC
##### Installeer g++ 
- run in de terminal: 

  ```xcode-select --install```

##### Installeer IDE
- run in de terminal: 

  ```brew install --cask vscodium```

  *(Of vraag een github studenten account aan en installeer clion 
  (dit hebben we nog niet getest mét de g++ install)).*


---

### WINDOWS
##### Installeer g++
- Windows start menu --> open windows power shell (zoek op 'power'), run daarin:

  ```winget install MSYS2.MSYS2```

  (https://www.msys2.org/)


- open msys2 terminal en run:

  ```pacman -S mingw-w64-ucrt-x86_64-gcc```


- open file explorer en navigeer naar c directory en selecteer map msys64, naar map ucrt64, map bin, zitten g++.exe en gcc.exe erin? (of g++ en gcc)
  - --> correcte locatie, kopier het pad.  

 
- zoek in windows menu naar environment variables en open (click ev. op environment variables)
  - dubbelclick onder user variables 'Path', click in het nieuwe venster op new en paste je gekopieerde path
  

-  open windows power shellen run
  ```gcc --version```
  <br>*wordt die gevonden?* 


- Installeer vscodium en run in windows power shell: 
 
  ```winget install VSCodium.VSCodium```

  *(Of vraag een github studenten account aan en installeer clion 
(dit hebben we nog niet getest mét de g++ install)).*


