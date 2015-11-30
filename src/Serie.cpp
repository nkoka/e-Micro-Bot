/******************************/
/************ SERIE ***********/
/******************************/
#include "Serie.h"
#include "ConfSys_Robot.h"
#include <string.h>
/* MENU PRINCIPAL */
/*
s ou S : Demarrage systeme                    -> START
o ou O : Arret systeme                        -> STOP
h ou H : aide commande                        -> HELP
q ou Q : Quitter                              -> QUIT
*/
void Series::Init()
{
    cCmd ='\0';
}


/* Tache de debug des releves des capteurs et des ordres de mouvement moteur */
Int Series::tskSerial(Int s16ActivRobot)
{

    /* tache de buffering des informations vers le PC */
    static Int Reset = 0;
    static bool bDemSerMaintenance = false;
    static short sQuit = 0;

    if(false == bDemSerMaintenance)
    { 
        Serial.println("Serveur de maintenance\n");
        Serial.println("s ou S : Demarrage systeme -> START");
        Serial.println("o ou O : Arret systeme     -> STOP");
        Serial.println("e ou E : Etat systeme      -> ETAT");
        Serial.println("h ou H : aide commande     -> HELP");
        Serial.println("q ou Q : Quitter           -> QUIT");
        bDemSerMaintenance = true;
    }
    while (Serial.available() > 0) 
    {   
        char inChar = (char)Serial.read();
        if( ((Int)inChar != 13) && ((Int)inChar != 10))
        {
            cCmd = inChar;
        }
        else
        {
            /* Ne rien faire (on vide le buffer hardware) */
        }
    }
    
    if( (cCmd == 'h') || (cCmd == 'H'))
    {
        Serial.println("Serveur de maintenance\n");
        Serial.println("s ou S : Demarrage systeme -> START");
        Serial.println("o ou O : Arret systeme     -> STOP");
        Serial.println("e ou E : Etat systeme      -> ETAT");
        Serial.println("h ou H : aide commande     -> HELP");
        Serial.println("q ou Q : Quitter           -> QUIT");
        Reset = 1;
    }
    else if( ('s' == cCmd) || ('S' == cCmd))
    {
        /* Démarrage du robot */
        s16ActivRobot = 1;
        Reset = 1;
    }
    else if(('o' == cCmd) || ('O' == cCmd))
    {
        /* Arrêt du robot */
        s16ActivRobot = 0;
        Reset = 1;
    }
    else if(('e' == cCmd) || ('E' == cCmd))
    {
        if(1 == s16ActivRobot)
        {
            Serial.println("Systeme : Actif");
        }
        else
        {
            Serial.println("Systeme : Inactif");
        }
    }
    else if('q' == cCmd)
    {
        /* ne rien faire (le menu va être quitté) */
        Reset = 1;
    }
    else
    {
        /* Ne rien faire */
        Reset = 1;
    }
    if(1 == Reset)
    {
        cCmd = '\0';
        Reset = 0;
    }

    return s16ActivRobot;
}

Series Serie;
