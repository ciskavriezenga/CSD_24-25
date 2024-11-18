# 1: Get JUCE'd
Download JUCE in de top level van je CSD Repo
```bash
git submodule add https://github.com/juce-framework/JUCE.git
```
Daarna even committen

# 2:  CMake Project inrichten

## A: Top level CMakeLists.txt
Maak op het zelfde niveau als je JUCE map een bestandje genaamd, `CMakeLists.txt`
Typ dit daar in:
```cmake
cmake_minimum_required(VERSION 3.20)
project(CSD LANGUAGES CXX)

add_subdirectory(JUCE)
add_subdirectory(csd2b)
#add_subdirectory(csd2c)
```
## B: Doorlinken naar je opdrachten
Nu even naar je csd2b mapje, zet daar ook een `CMakeLists.txt.  
Typ daar:
```cmake
add_subdirectory(JuceTest)
```
Dan maken we nu even JuceTest aan
```bash
mkdir JuceTest
cd JuceTest

# MACOS / LINUX
touch CMakeLists.txt

# WINDOWS
New-Item -ItemType File -Path "CMakeLists.txt"
```
# 3: Test Project maken
## A: Project level CMakeLists.txt
In de `CMakeLists.txt` die je net hebt gemaakt in de JuceTest folder gaan we dit schrijven:  
```cmake
project(JuceTest VERSION 0.0.1)
juce_add_console_app(JuceTest PRODUCT_NAME "JuceTest")
target_sources(JuceTest PRIVATE main.cpp)
target_compile_definitions(JuceTest PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(JuceTest
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(JuceTest PRIVATE cxx_std_20)
```

## B: Bestandjes even kopieren
kopieer de `audiocomponent.h` en de `main.cpp` vanuit de `JuceTest` map in de CSD2 repo naar je eigen `JuceTest` map.     
Je mag er in kijken als je wilt.   

# 4: Builden!
In de Terminal, **navigeer naar de Top Level van je repository (waar de JUCE map ook zit)** en genereer je build files met:

```bash
cmake -S . -B build
```
Hij gaat nu als het goed is ook de `Juceaide` bouwen. Dat is een helper tool voor het bouwen en configureren van projecten waar JUCE in gebruikt wordt. Hoef je je verder geen zorgen over te maken, zolang die maar succesvol gebouwd wordt.   
  
navigeer nu naar de JuceTest map BINNEN de build map  
```bash
cd build/csd2b/JuceTest
```

Hier kan je bouwen met:  
```bash
cmake --build .
```

Als dat succesvol is, zit je programma ergens in de `JuceTest_artefacts` folder!  

