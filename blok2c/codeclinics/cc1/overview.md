
# Code Clinic 1.

#### Overview CSD 2c
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




## CC1 - Circular Buffer
* functionaliteit
https://en.wikipedia.org/wiki/Circular_buffer
* wanneer nodig in M&T context?

  * ... zie ook uit boek Pirkle en .png:   
    "1. Read the output value, y(n), from the DDL and write it to the output buffer.
    2. Form the product fb * y(n).
    3. Write the input value, x(n) 1 fb * y(n), into the delay line." (W. Pirkle, 2013)


## CC1 - Opdracht
* Maak een CircBuffer class die voldoet aan de volgende voorwaarden:
  * De constructor format is:
    ```CircBuffer(int size, int numSamplesDelay)```
  * Het aantal samples verschil tussen de read head en write head is aan te passen
* Gebruik de CircBuffer met een signaal dat je invoert en uitleest,
schrijf de output weg naar een file met de WriteToFile class uit blok 2b. 
Gebruik hiervoor bijvoorbeeld een Sine object uit het vorige blok.


##### *Voor diehards*
* de class CircBuffer bevat een functie ```resetSize(int size)```, waarmee de buffer size aan te passen is.

##### *Voor die-diehards*
* bij het aanpassen van het aantal samples tussen de read en write head wordt de aanpassing over een gegeven 
aantal samples uitgesmeerd. In andere woorden, er wordt niet van de ene plek naar de andere plek 
in de buffer 'gesprongen' met de read head, maar de read head beweegt langzaam naar de nieuwe positie 
gedurende een gegeven aantal samples.


## References
* Pirkle, W. C. (2013). Designing Software Synthesizer Plug-ins in C++, 
With Digital Audio Signal Processing. Taylor and Francis Group (p.210)_
