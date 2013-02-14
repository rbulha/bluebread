bluebread
=========

Firmware for Wireless prototype breadboard. 

Author
======
Rogério Bulha Siqueira <www.esd-talk.com>

Platform
========

Intention is the main code to became free from platform.

Target-Platforms
================
1. MSP430G2452

Changelog
=========

07/08/2012 - Inicio deste projeto para msp430g2452

* criar estrutura de projeto mais definitiva
* isolar dependencias de plataforma
* a maquina atmachine.c foi apenas copiada mas ainda falta implementar com a mesma rotina que esta no suart.c

14/20/2013 - Testada na placa com UART via USB ok
* ja usa estrutura do platdep
