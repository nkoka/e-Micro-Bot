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
/*D�finition : x.YZ */
/*		       x = version majeur */
/*			   incr�mentation si ajout d'un module logiciel */
/*			   Y = version mineure */
/*			   incr�mentation si modification de type ajout de fonction */
/*			   Z = version modification */
/*			   incr�mentation si modification du code existant */
/**************************************/
/* D�finition de la version du calculateur d'action */
#define VERSION_BRAIN	0.10
/* d�finition d'un �num�r� pour l'�tat des taches */
typedef enum eSTATE_BRAIN
{
	CALCUL = 0,
	RES,
	OFF

}e_ENUM_STAT_BRAIN;
/* D�finition de la structure des t�ches */
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
