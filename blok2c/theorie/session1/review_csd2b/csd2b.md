# Assignment csd2b - Review and insights

## Opvallend
- Bij veel uitwerkingen zag ik dat er stap voor stap settings aan de gebruiker werden opgevraagd. 
Deze waarden werden ook stap voor stap doorgegeven aan de synths. Waarom niet eerst de settings verzamelen? 
Dan vervolgens op basis van de settings de synths aanmaken.   


- Subclass synths: meerdere uitwerkingen hadden een addOscillator functie. Hoe komen jullie hierbij? 
Beter is het om in de constructor de oscillatoren aan te maken op basis van meegegeven settings. 
 



## Tips

- Denk aan credits te geven / bron te vermelden wanneer je code van anderen gebruikt! 
_(laatste keer schappelijk, volgende keer gaan we hier strenger mee om)_ 


- Plaats geen global variabelen in een cpp file van een class,
maar breng ze onder in een class

  
- Initialisatie in je constructor. 
Moet dit ergens anders, bijv. in een prepare method om een goede reden? Plaats dan een comment erbij!!


- Fields die onder een class vallen en echt alleen daar horen, 
die horen enkel beheerd te worden door die class en nier daarbuiten


- In een eindopdracht hoort geen outcommented code te staan. 
Wanneer het om debug code gaat kun je hiervoor werken met een preprocessor if en macro


- Voer een methode in een subclass een aantal dezelfde stappen uit? 
Verplaats dit naar de base class


- Houd private wat private kan, dus niet alles in de base class op protected zetten


- Setters --> valideer de input. Bijv. 0 < frequentie < niquist freq.


- Veel berekeningen in 1 regel? Splits op voor de leesbaarheid. Onderstaande is bijv. onduidelijk leesbaar. 
  ```
  (tanh(oscillators[0]->getSample() * drive * envelopes[0]->getValue()) * amplitude);
  ```

- Gebruik niet static fields in een 'normale class' zonder goede reden hiervoor; 
en wanneer je zoiets gebruikt dan enkel als je static door en door begrijpt



- Schrijf in je comments niet wat er in de regel eronder gebeurt, maar vat meerdere regels samen, of 
leg uit waarom je iets zo aanpakt. 
Voorbeeld waarbij een comment niet iets toevoegt: 
    ```
    //devide the amplitude by numOscillators
    amp /= numOscillators 
    ``` 
    Duidelijker: 
    ```
    // scaling amplitude to prevent clipping, based on number of oscillotors
    ```

- Werk je met dynamisch aangemaakte objecten (keyword: new) --> vergeet delete niet! 



## Tot slot - ChatGPT is géén held in DSP!!! 
- Aan te raden; gebruik ChatGPT niet voor het genereren van C++ code en al helemaal niet 'klakkeloos' voor DSP zaken. 
- ChatGPT eventueel wel interessant om te gebruiken om code en bugs uit te laten leggen 
- _(Wees je a.u.b. bewust van het energie verbruik van dergelijke tools (vooral het trainen van natuurlijk))._




.