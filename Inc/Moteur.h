/********************************************/
/* Author : N. Bianchi                      */
/* Name   : Moteur.h                     */
/* Brief  : Module logiciel pilotant  */
/* les servomoteurs          */
/********************************************/
#ifndef Moteur_h
#define Moteur_h
#include "ConfSys_Robot.h"
#include "Servo.h"
/**************************************/
/*D�finition : x.YZ */
/*		       x = version majeur */
/*			   incr�mentation si ajout d'un module logiciel */
/*			   Y = version mineure */
/*			   incr�mentation si modification de type ajout de fonction */
/*			   Z = version modification */
/*			   incr�mentation si modification du code existant */
/**************************************/
/* D�finition de la version du scheduler */
#define VERSION_MOTEUR	0.10
/* d�finition d'un �num�r� pour l'�tat des taches */
typedef enum eSTATE_MOTEUR
{
	STOP = 0,
	AVA,
	ARRI,
    NON_DISPO

}e_ENUM_STAT_MOTEUR;
/* D�finition de la structure des t�ches */
typedef struct
{
	/* data */
    Int Pin;
	Int Puissance;/* Data du moteur */
	e_ENUM_STAT_MOTEUR stateMoteur;
	/* Variable servomoteur */
	Servo serv;
}sMoteur;

class Mot
{
	private:
		Int bStartMoteur;

	public:
		/* tableau des ordres des moteurs */
		Int OrdreMoteur[2*NB_MOTEUR];
		/* Prototypes fonction */
		FLOAT MoteurVersionMoteur();
		Int MoteurInit(sMoteur * Moteurs,Int NumberMoteur);
		void MoteurAssignMoteur(sMoteur * Moteur,Int  Puissance,e_ENUM_STAT_MOTEUR stateMoteur,Int Pin);
		void MoteurStartMoteur();
		void MoteurStopMoteur();
		void MoteurOrdreMoteur(sMoteur*Moteur,Int NumberMoteur);
};
#endif

