# Checklist - duplicate code, 'bad pracice', etc. 

• English variable names, English comments
• allocate waveobject outside playback loop
• provide references, in case you use an unadapted snippet of example / library / ... code. 

- **too complex** to easily read? --> it probably can be simplified
  
 
- same lines with different variable names ? / do blocks of code look alike? --> probably **duplicate code**


- **mind the comments!** if you do something like:
    - append a first value to a list before appending 'stuff' in a forloop --> add a comment
    - use a calculation with e.g. a 0.25 seemingly out of nowhere --> add a comment
    - use random values and it is not instantly clear wherefor these are used --> add a comment
    - ...


 - put your functions in **seperate scripts**, e.g.
    - a script with functions to transform notes to time durations, timestamps and events
    - a script with all the UI functions




