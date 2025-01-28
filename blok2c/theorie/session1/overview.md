
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


## Introductie - a.d.h.v. slides


## Terugblik


## Tremelo Effect




## Opdrachten komende 3 weken - overzicht
- **week 1.** Effect (base class), Delay, Tremolo classes=
- **week 2.** WaveShaper, presentatie voorbereiden
- **week 3.** StereoChorus

## Opdracht - week 1
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
