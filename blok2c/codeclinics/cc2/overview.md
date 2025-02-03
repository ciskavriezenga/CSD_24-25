
# Code Clinic 2.

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


## CC2 - Interpolatie
* functionaliteit
  https://en.wikipedia.org/wiki/Interpolation
  https://en.wikipedia.org/wiki/Linear_interpolation
  _en zie afbeelding_
* wanneer nodig in M&T context?

## CC2 - Opdracht
Maak een static Interpolation class met de volgende functies, gebruik hierbij floats als datatype:
* `nnMap(value, low, high)`
  _returns the nearest-neighbour value of the passed value within the given range_
    * value: a normalized value within range [0, 1]
    * low: the lower bound of the range
    * high: the upper bound of the range

* `linMap(value, low, high)`
  _returns the linearly interpolated value of the passed value within the given range_
    * value: a normalized value within range [0, 1]
    * low: the lower bound of the range
    * high: the upper bound of the range

* `mapInRange(value, fromLow, fromHigh, toLow, toHigh)`
  _returns the mapped value from one range to another_
    * fromLow: the lower bound of the value’s current range.
    * fromHigh: the upper bound of the value’s current range.
    * toLow: the lower bound of the value’s target range.
    * toHigh: the upper bound of the value’s target range.


##### *Voor diehards*
* Maak een WavetableOscillator class die erft van Oscillator (blok2b) en 
een circular buffer bevat(losse class of functionaliteit) gevuld met 
samples voor de te genereren golfvorm. Je kunt hiervoor de static class 
WavetableGenerator gebruiken en aanvullen, zie map *wavetable*. 
Bij het genereren van waardes met je WavetableOscillator kun je de linMap 
interpolatie functie uit je static Interpolation class toepassen om waardes 
uit de wavetable te lezen.

* Werk met templates ipv float datatypes, zodat je ongeacht je data type 
(float, double, ...) de functies kunt gebruiken. 
https://en.cppreference.com/w/cpp/language/templates

##### *Voor die-...-diehards*
* `splineMap(value, ... )`
    *returns the interpolated value of the passed value within the given range, according to Cox-de Boor recursion. 
See: boorSplines.png, b i,3 (t) and https://en.wikipedia.org/wiki/De_Boor%27s_algorithm*
      Je kunt eventueel ook naar de _Boost_ library kijken, daar wordt ook spline interpolatie aangeboden _(=not verified yet)_
      * value: a normalized value within range [0, 1]
      * ...
