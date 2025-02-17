


## Opdrachten komende 3 weken - overzicht
- **week 1.** Effect (base class), Delay, Tremolo classes=
- **week 2.** WaveShaper, presentatie voorbereiden
- **week 3.** StereoChorus



## Opdracht theorie - week 2

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
