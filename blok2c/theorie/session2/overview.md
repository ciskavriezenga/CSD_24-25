
# Theorie - session 1

## Overview CSD 2c
|   | Theorie                                                                            | Code clinics                             |
|---|------------------------------------------------------------------------------------|------------------------------------------|
| 1 | Introductie, terugblik, tremolo                                                    | (C) Circular buffer                      |
| 2 | Effect base class & delay, Waveshaper start                                        | (C) Interpolatie                         |
| 3 | presentatie effect Delay & tremelo & Waveshaper, Multi-threading en synchronisatie | (D) Interleaved & stereo audio, diagrams |
| 4 | Computer Vision                                                                    | (D) filters                              |
| 5 | Presentatie Unventional control. herhaling tot nu toe                              | (C) Git branching, Agile development     |
| 6 | Trouble shooting, Music Information Retrieval (MIR)                                | (C) Feedback sessie /  STL               |
| 7 | Snippets en tests van eindopdracht                                                 | (D) JUCE Intro - quickstart              |
| 8 | Eindpresentatie                                                                    | (D) Juce 'my first project'              |


## Effect base class, delay

* Effect base class
  * Which methods and fields can we place in the effect base class?

    * for the sake of different styles and strategies; let's use 'pass by references' for the `processFrame`, 

          float processFrame(float input);        
          void processFrame(float* input, float* output);
          void processFrame(float& input, float& output);
  * question: 
    *  size a floating point 4 bytes
    * _"If the system is 16-bit, size of void pointer is 2 bytes. 
    If the system is 32-bit, size of void pointer is 4 bytes. If the system is 64-bit, size of void pointer is 8 bytes."_
    https://www.tutorialspoint.com/what-is-the-size-of-void-pointer-in-c-cplusplus
      
    _for more information about references vs pointers, see: https://www.agner.org/optimize/optimizing_cpp.pdf_

* Delay



## Opdrachten eerste 3 weken - overzicht
week 1. Effect (base class), Delay, Tremolo classes

week 2. WaveShaper, presentatie voworbereiden - *presentatie theorie sessie week 3*

week 3. StereoChorus - *aftekenen practicum week 4*


## Opdracht - week 2

STAPPENPLAN: 
1. start met de code uit theorie/session2/02_effect (prima  om die tremolo en delay te gebruiken)
2. voeg een header en cpp toe met subclass WaveShaper
3. Implementeer de basis functionaliteit (blanco shell --> returned de input sample)
4. pak de functie van de slides met de arctan en de k (gebruik math.h voor arctan functie)
5.... eerst lekker spelen! --> ga door met de demo apllicatie, zie hieronder
6. (pas dan werken met een wavetabel (buffer) + interpolatie

* Maak een waveshaper
  * maak gebruik van een wavetable
  * zie Pirkle page 497 voor een sigmoid functie

* Rond alle classes tot nu toe af - Effect base class en subclasses: Tremolo, Delay, Waveshaper en optioneel de losse class CircularBuffer.

* Creëer een demonstratie applicatie voor de console line, die deze effecten demonstreert met realtime audio input en output.

* Bereid een beknopte presentatie (max 4 min.) voor waarin je je demonstratie live
demonstreert. Gebruik hierbij een audio flow diagram om je effect chain inzichtelijk te maken en licht toe welke functionaliteiten wel / niet in je effecten verwerkt zijn (bijv. een smooth transition van de readhead in je Delay class wanneer de delay tijd wordt aangepast).
