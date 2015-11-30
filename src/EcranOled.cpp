/********************************************/
/* Author : N. Bianchi                      */
/* Name   : EcranOled.cpp                   */
/* Brief  : Module logiciel EcranOled       */
/********************************************/
#include "EcranOled.h"
/********************/
/*      DEFINE      */
/********************/
#define OLED_SDA    PIN_SDA_I2C
#define OLED_SCL    PIN_SCL_I2C
IIC_without_ACK Oled(OLED_SDA, OLED_SCL);

/********************/
/*     VARIABLES    */
/*     GLOBALES     */
/********************/
char Version[6] = {"0.00"};

/************************************************/
/* Name    : EcranOledVersionEcranOled */
/* Brief   : Version du module EcranOled */
/************************************************/
char* EcranOled::EcranOledVersionEcranOled()
{
    (void*)sprintf(strBuff,"%d.%d%d",VERSION_MAJ,VERSION_MIN,REVISION);
	return strBuff;
}
/************************************************/
/* Name    : SetBuffer */
/* Brief   : ecriture buffer courant */
/************************************************/
void EcranOled::SetBuffer(char* strBuf)
{
    if( (strlen(strBuf) + strlen(strBuff)) <= MAX_BUFF )
    {
        strcat(strBuff,strBuf);
    }
    else
    {
        memset(strBuff,0,MAX_BUFF);
        strcpy(strBuff,"Error copy");
    }
}
/************************************************/
/* Name    : ResetBuffer */
/* Brief   : Reset du buffer courant */
/************************************************/
void EcranOled::ResetBuffer()
{
    memset(strBuff,0,MAX_BUFF);
}
/************************************************/
/* Name    : GetEcranOled */
/* Brief   : récupération buffer courant */
/************************************************/
char * EcranOled::GetBuffer()
{
    return strBuff;
}
/************************************************/
/* Name    : EcranOledStartEcranOled */
/* Brief   : Démarrage des EcranOleds */
/************************************************/
void EcranOled::EcranOledStartEcranOled()
{
	bStartEcranOled = 1;
}
/************************************************/
/* Name    : EcranOledStartEcranOled */
/* Brief   : Arrêt de l'EcranOled */
/************************************************/
void EcranOled::EcranOledStopEcranOled()
{
	bStartEcranOled = 0;
}
/************************************************/
/* Name    : EcranOledOrdreEcranOled */
/* Brief   : Calcul de l'heure */
/************************************************/
void EcranOled::EcranOledOrdreEcranOled(int PosX,int posY)
{
    if(1 == bStartEcranOled)
    {
       Oled.Char_F6x8(posX,posY,strBuff);
    }
    else
    {
        /* Misra C */
        Oled.Char_F6x8(1,0,"Screen no init");
    }
}
