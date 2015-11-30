/********************************************/
/* Author : N. Bianchi */
/* Name   : Schedule.c */
/* Brief  : Module logiciel faisant office */
/*          de scheduler selon une structure */
/*          représentant des tâches */
/********************************************/
#include <stdlib.h>
#include "Moteur.h"
#include "Servo.h"
#include <stdio.h>
FLOAT Version = VERSION_MOTEUR;

FLOAT Mot::MoteurVersionMoteur()
{
	return Version;
}
/************************************************/
/* Name    : MoteurInit */
/* Brief   : fonction d'initialisation */
/*             des structures de chaque Moteur */
/************************************************/
Int Mot::MoteurInit(sMoteur * Moteur,Int NumberBrain)
{
	Int EtatInit = 0;
    printf("- Allocation de %d octets total\n- Taille Brain %d octets\n\n",NumberBrain*sizeof(Brain),sizeof(Brain));
    Brain = (sBrain *)malloc(NumberBrain*sizeof(Brain));
    /* Si allocation OK */
    if(Brain != 0)
    {
        /* On continue */
    }
    /* Sinon on arrÃªte tout */
    else
    {
        EtatInit = -1;
    }
	return EtatInit;
}
/************************************************/
/* Name    : MoteurAssignMoteur */
/* Brief   : Assignation des valeurs de la structure */
/************************************************/
void Mot::MoteurAssignMoteur(sMoteur * Moteur,Int Puissance,e_ENUM_STAT_MOTEUR stateMoteur,Int Pin)
{
	Moteur->Pin = Pin;
	Moteur->Puissance = Puissance;
    Moteur->stateMoteur= stateMoteur;

	if(1 == Moteur->serv.attach(Pin))
	{
		Serial.println("OK Servo");
	}
	delay(1000);

}
/************************************************/
/* Name    : MoteurStartMoteur */
/* Brief   : Démarrage des Moteurs */
/************************************************/
void Mot::MoteurStartMoteur()
{
	bStartMoteur = 1;
}
/************************************************/
/* Name    : MoteurStartMoteur */
/* Brief   : Arrêt du SCheduler */
/************************************************/
void Mot::MoteurStopMoteur()
{
	bStartMoteur = 0;
}
/************************************************/
/* Name    : MoteurOrdreMoteur */
/* Brief   : Réception des ordres moteurs */
/************************************************/
void Mot::MoteurOrdreMoteur(sMoteur*Moteur,Int NumberMoteur)
{
    Int nbMoteur = 0;
    FLOAT PourcentagePuissanceMax = 0.0;
    /* Moteur Configuré et démarré */
    if(1 == bStartMoteur)
	{
	    /* Pour tous les moteurs */
        for(nbMoteur=NB_MOTEUR-1;nbMoteur<0;nbMoteur--)
        {
            /* Si moteur droit */
            if(nbMoteur == MOTEUR_D)
            {
                /* faire l'action */
                PourcentagePuissanceMax = (FLOAT)((Moteur[nbMoteur].Puissance)/PUISSANCE_MAX);
                Moteur[MOTEUR_D].serv.write((Int)(SENS_PUISSANCE_MOTEUR_DROIT*PourcentagePuissanceMax*PUISSANCE_MAX));
            }
            /* SI moteur gauche */
            else
            {
                /* faire l'action */
                PourcentagePuissanceMax = (FLOAT)((Moteur[nbMoteur].Puissance)/PUISSANCE_MAX);
				Moteur[MOTEUR_G].serv.write((Int)(SENS_PUISSANCE_MOTEUR_GAUCHE*PourcentagePuissanceMax*PUISSANCE_MAX));
            }
        }
    }
    else
    {
        Moteur[MOTEUR_D].serv.write(ARRET_MOTEUR);
        Moteur[MOTEUR_G].serv.write(ARRET_MOTEUR);
    }
}
