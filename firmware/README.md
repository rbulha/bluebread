bluebread
=========

Firmware for Wireless prototype breadboard. 

Author
======
Rogerio Bulha Siqueira <www.esd-talk.com>

Platform
========

Intention is the main code to became free from platform.

Target-Platforms
================
1. MSP430

Souce code
==========
<pre>
-+CC4v2 - Code composer 4 project target to MSP430G2452
   |
   |-main.c - main file
   |-+source - platform independent code
   |    |
   |    |-atcmd.c - Custom AT commands interpreter
   |    |-atmachine.c - Custom AT state machine
   |   
   |-+include
   |    |
   |    |-atcmd.h - Custom AT commands header
   |    |-atmachine.h - Custom AT state machine header
   |   
   |-+platdep
   |    |
   |    |-+2452
   |    |    |
   |    |    |-gpio.c    - general I/O implementation for MAS430G2452 
   |    |    |-serial.c  - Software UART implementation for MAS430G2452
   |    |    |-pwm.c     - pwm for MAS430G2452
   |    |-+include
   |    |    |
   |    |    |-gpio.h    - general I/O implementation header
   |    |    |-serial.h  - Software UART implementation header
   |    |    |-pwm.h     - PWM implementation header

-+CC4 - Code composer 4 project target to MSP430G2211
   |
   |-suart.c - main file
   |-atcmd.c - Custom AT commands interpreter
   |-+include
        |
        |-atcmd.h - Custom AT commands header
        
-+src - platform independent code
   |-atcmd.c - AT custom commands parser. 
               use Preprocessor name=TESTING to evaluate this on gcc. 
               like "gcc -D TESTING atcmd.c"
</pre>
Notes
=====

CC4v2 - HOW TO USE

* merge the git cloned files with the local workspace. 
* in the future find a way to isolate the implementation from the code composer configuration files. (make file for instance)  

Changelog
=========

 * (2012/06/26) : First Issue.
 * (2012/06/28) : Code composer 4 project added
 * (2013/02/11) : Working on CC4 folder just after that i'll back to platform independent code.
 * (2013/02/14) : Working on CC4v2 folder adding patdep folder and support MSP430G2452 device.
 * (2013/02/14) : add PWM support for MSP430G2452 in the platdep.
