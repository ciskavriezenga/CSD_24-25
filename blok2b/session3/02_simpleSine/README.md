**NOTE**: jack2 needs to be installed 



#### Mac OS

"Intel 64bit Installer: JACK 1.9.21 macOS-intel" on https://jackaudio.org/downloads/

#### Linux
in terminal: 
```(sudo) apt install jackd2 libjack-jackd2-dev qjackctl```




### Run test project 
First start the audio server; `jackd` invokes the JACK audio server daemon.
https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)

On mac, you can start the jack audio server daemon in the terminal:

```jackd -d coreaudio```

