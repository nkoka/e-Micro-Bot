#ifndef SERIE_H
#define SERIE_H

#include <Arduino.h>
//#include "EEPROM.h"

#include "ConfSys_Robot.h"

/* define de la taille des buffers */
#define SIZE_BUFF  1000


/* Divers */
//#define ASCIITOINT                  48
#define NB_CARACTERE_MAX_INTENSITE  4
#define MAX_TAILLE_SENS_ORDRE       8

class Series
{
    public:
        /* Méthodes */
        void Init();
        Int tskSerial(Int s16ActivRobot);
    private:
    	/* variable applicative*/
        char cCmd;
};

extern Series Serie;
#endif
