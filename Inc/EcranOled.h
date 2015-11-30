/********************************************/
/* Author : N. Bianchi                      */
/* Name   : EcranOled.h                       */
/* Brief  : Module logiciel EcranOled         */
/********************************************/
#ifndef EcranOled_h
#define EcranOled_h
#include <stdio.h>
#include "IIC_without_ACK.h"

/**************************************/
/*D�finition : x.YZ */
/*		       x = version majeur */
/*			   incr�mentation si ajout d'un module logiciel */
/*			   Y = version mineure */
/*			   incr�mentation si modification de type ajout de fonction */
/*			   Z = revision */
/*			   incr�mentation si modification du code existant */
/**************************************/
/* d�finition du pinning pseudo SPI */
#define PIN_SCL_I2C     7
#define PIN_SDA_I2C     5

/* D�finition des versions du module EcranOled */
#define VERSION_MAJ     1
#define VERSION_MIN     0
#define REVISION        0

#define MAX_BUFF    63    

class EcranOled
{
	private:
        /* Variables */
        char* strBuff[64];
	public:
        /* Variables */ 
        int bBuffHorlogeModified;
		/* Prototypes fonction */
		char* EcranOled::EcranOledVersionEcranOled();
		void EcranOled::SetBuffer(char* strBuf);
		void EcranOled::ResetBuffer();
        char * EcranOled::GetBuffer();
        void EcranOled::EcranOledStartEcranOled();
		void EcranOledStopEcranOled();
        void EcranOled::EcranOledOrdreEcranOled(int PosX,int posY);
};
#endif
