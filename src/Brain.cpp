/********************************************/
/* Author : N. Bianchi */
/* Name   : Brain.cpp */
/* Brief  : Module logiciel faisant office */
/*          de calculateur d'action selon */
/*          une structure */
/*          représentant des tâches */
/********************************************/
#include <stdlib.h>
#include "Brain.h"
#include "Applicatif_Robot.h"
#include <stdio.h>
FLOAT Version = VERSION_BRAIN;

FLOAT Brain::BrainVersionBrain()
{
	return Version;
}
/************************************************/
/* Name    : BrainInit */
/* Brief   : fonction d'initialisation */
/*             des structures de chaque Brain */
/************************************************/
Int Brain::BrainInit(sBrain * Brain,Int NumberBrain)
{
	Int EtatInit = 0;
    printf("- Allocation de %d octets total\n- Taille Brain %d octets\n\n",NumberBrain*sizeof(Brain),sizeof(Brain));
    Brain = (sBrain *)malloc(NumberBrain*sizeof(Brain));
    /* Si allocation OK */
    if(Brain != 0)
    {
        /* On continue */
    }
    /* Sinon on arrête tout */
    else
    {
        EtatInit = -1;
    }
	return EtatInit;
}
/************************************************/
/* Name    : BrainAssignBrain */
/* Brief   : Assignation des valeurs de la structure */
/************************************************/
void Brain::BrainAssignBrain(sBrain * Brain,Int Data,Int Puissance,e_ENUM_STAT_BRAIN stateBrain)
{
	Brain->Telemetre = Data;
	Brain->Sens = ST;
	Brain->Puissance = Puissance;
    Brain->stateBrain = stateBrain;
}
/************************************************/
/* Name    : BrainStartBrain */
/* Brief   : Démarrage des Brains */
/************************************************/
void Brain::BrainStartBrain()
{
	bStartBrain = 1;
}
/************************************************/
/* Name    : BrainStartBrain */
/* Brief   : Arrêt du SCheduler */
/************************************************/
void Brain::BrainStopBrain()
{
	bStartBrain = 0;
}
/************************************************/
/* Name    : BrainOrdreBrain */
/* Brief   : Réception des ordres Brains */
/************************************************/
Int Brain::BrainCalculBrain(sBrain*Brain,Int NumberBrain)
{
    Int retStatBrain = ERR_ROBOT;
    /* Brain Configuré et démarré */
    if(1 == bStartBrain)
	{
	    /* TBC */
    	retStatBrain = APPLICATIF_ROBOT_Main(Brain,NumberBrain);
    }
    else
    {
        /* Aucune action */
        retStatBrain = NO_ERR_ROBOT;
    }
    return retStatBrain;
}
