/********************************************/
/* Author : N. Bianchi                      */
/* Name   : Schedule.h                      */
/* Brief  : Module logiciel faisant office
            de scheduler selon une structure
            représentant des tâches          */
/********************************************/
#ifndef Schedule_h
#define Schedule_h
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
/* Définition de la version du scheduler */
#define VERSION_SCHEDULER	1.00
/* Définition d'un pointeur de fonction pour le scheduler */
typedef Int(*ptFct)(Int *Data);
/* définition d'un énuméré pour l'état des taches */
typedef enum eSTATE_TASK
{
	SLEEP = 0,
	PREOP,
	OP,
	KILL,
	FINISHED

}e_ENUM_STAT_TASK;
/* Définition de la structure des tâches */
typedef struct
{
	/* data */
	Int priorite;
	Int compteur;
	Int MaxCompteur;
	Int * Data;
	e_ENUM_STAT_TASK stateTask;
	/* mettre un pointeur de fonction */
	ptFct Fct;
	/* fin pointeur de fonction */
}sTask;
class Schedule
{
	private:
		Int bStartOS;
	public:
		/* Prototypes fonction */
		FLOAT ScheduleVersionScheduler();
		Int ScheduleInit(sTask * Task,Int Numbertask);
		void ScheduleAssignTask(sTask * Task,ptFct Fct,Int * Data,Int priorite,Int compteur,Int Max_Compteur,e_ENUM_STAT_TASK stateTask);
		void ScheduleStartOS();
		void ScheduleStopOS();
		void ScheduleLoop(sTask*Task,Int Numbertask);
};
#endif
