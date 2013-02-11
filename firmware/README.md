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
-+CC4 - Code composer 4 project target to MSP430G2211
   |
   |-suart.c - main file
   |-atcmd.c - Custom AT commands interpreter
   |-+include
        |
        |-atcmd.h - Custom AT commands header
        
-+src - platform independent code
   |-atcmd.c - AT custom commands parser. use Preprocessor name=TESTING to evaluate this on gcc. like "gcc -D TESTING atcmd.c"

Changelog
=========

(2012/06/26) : First Issue.
(2012/06/28) : Code composer 4 project added
(2013/02/11) : Working on CC4 folder just after that i'll back to platform independent code.

