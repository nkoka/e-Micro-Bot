/********************************************/
/* Author : N. Bianchi                      */
/* Name   : Bain.h                          */
/* Brief  : Module logiciel pilotant        */
/* le calcul pour l'action des servoBrains */
/********************************************/
#ifndef Brain_h
#define Brain_h
#include "Brain.h"
#include "ConfSys_Robot.h"
/**************************************/
/*Définition : x.YZ */
/*		       x = version majeur */
/*			   incrémentation si ajout d'un module logiciel */
/*			   Y = version mineure */
/*			   incrémentation si modification de type ajout de fonction */
/*			   Z = version modification */
/*			   incrémentation si modification du code existant */
/**************************************/
/* Définition de la version du calculateur d'action */
#define VERSION_BRAIN	0.10
/* définition d'un énuméré pour l'état des taches */
typedef enum eSTATE_BRAIN
{
	CALCUL = 0,
	RES,
	OFF

}e_ENUM_STAT_BRAIN;
/* Définition de la structure des tâches */
typedef struct
{
	/* data */
    Int Telemetre;
	Int Sens;
	Int Puissance;/* Data du Brain [-100;100]*/
	e_ENUM_STAT_BRAIN stateBrain;
}sBrain;

class Brain
{
	private:
		Int bStartBrain;
        /* tableau des ordres des Brains */
        Int BrainOrdreBrain[NB_BRAIN];
	public:
		/* Prototypes fonction */
		FLOAT BrainVersionBrain();
		Int BrainInit(sBrain * Brain,Int NumberBrain);
		void BrainAssignBrain(sBrain * Brain,Int Data,Int Puissance,e_ENUM_STAT_BRAIN stateBrain);
		void BrainStartBrain();
		void BrainStopBrain();
		Int BrainCalculBrain(sBrain*Brain,Int NumberBrain);
};
#endif
