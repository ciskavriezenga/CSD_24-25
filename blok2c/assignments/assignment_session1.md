


## Opdrachten komende 3 weken - overzicht
- **week 1.** Effect (base class), Delay, Tremolo classes=
- **week 2.** WaveShaper, presentatie voorbereiden
- **week 3.** StereoChorus



## Opdracht theorie - week 1
Werk de volgende classes uit
* Effect (base class)
* Effect subclasses:
    * Delay (met circular buffer als losse class _(has a relationship)_ of circular buffer functionaliteit rechtstreeks in de class zelf), met:
        * instelbare feedback signaal
        * met instelbare dry en wet
        * instelbare delay tijd in samples
        * instelbare delay tijd in (m)seconden

      ##### *Voor diehards*
        * bij het aanpassen van de delay tijd wordt de aanpassing over een gegeven aantal samples uitgesmeerd. In andere woorden, er wordt niet van de ene plek naar de andere plek in de buffer 'gesprongen' met de read head, maar de read head beweegt langzaam naar de nieuwe positie gedurende een gegeven aantal samples.

    * Tremolo
        * met modDepth



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
