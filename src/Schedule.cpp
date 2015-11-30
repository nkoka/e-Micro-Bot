/********************************************/
/* Author : N. Bianchi */
/* Name   : Schedule.c */
/* Brief  : Module logiciel faisant office */
/*          de scheduler selon une structure */
/*          représentant des tâches */
/********************************************/
#include <stdlib.h>
#include "Schedule.h"
#include <stdio.h>
float Version = VERSION_SCHEDULER;

float Schedule::ScheduleVersionScheduler()
{
	return Version;
}
/************************************************/
/* Name    : ScheduleInit */
/* Brief   : fonction d'initialisation */
/*             des structures de chaque taches */
/************************************************/
int Schedule::ScheduleInit(sTask * Task,int Numbertask)
{
	int EtatInit = 0;
    printf("- Allocation de %d octets total\n- Taille tache %d octets\n\n",Numbertask*sizeof(Task),sizeof(Task));
    Task = (sTask *)malloc(Numbertask*sizeof(Task));
    /* Si allocation OK */
    if(Task != 0)
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
/* Name    : ScheduleAssignTask */
/* Brief   : Assignation des valeurs de la structure */
/************************************************/
void Schedule::ScheduleAssignTask(sTask * Task,ptFct Fct,int * Data,int priorite,int compteur,int Max_Compteur,e_ENUM_STAT_TASK stateTask)
{
	Task->priorite = priorite;
	Task->stateTask = stateTask;
	Task->compteur = compteur;
	Task->MaxCompteur= Max_Compteur;
	Task->Fct = Fct;
	Task->Data = Data;
}
/************************************************/
/* Name    : ScheduleStartOS */
/* Brief   : Démarrage du SCheduler */
/************************************************/
void Schedule::ScheduleStartOS()
{
	bStartOS = 1;
}
/************************************************/
/* Name    : ScheduleStartOS */
/* Brief   : Arrêt du SCheduler */
/************************************************/
void Schedule::ScheduleStopOS()
{
	bStartOS = 0;
}
/************************************************/
/* Name    : ScheduleAssignTask */
/* Brief   : Assignation des valeurs de la structure */
/************************************************/
void Schedule::ScheduleLoop(sTask*Task,int Numbertask)
{
	int NumeroTaskaActive = 0;
	int IndexNumeroTask= 0;
	int prioMin = 100;
    int retTaskActive = -1;

    /* Scheduler Configuré et démarré */
    if(1 == bStartOS)
	{
	    /*printf("\nETAT DES TACHES:\n");
		for(IndexNumeroTask = 0;IndexNumeroTask<Numbertask;IndexNumeroTask++)
	    {
	        printf("NumTask %d : %d : %d\n",IndexNumeroTask,Task[IndexNumeroTask].stateTask,Task[IndexNumeroTask].compteur);
	    }
	    printf("\n");*/

		/* Faire la mise à jour de l'état des taches */
		for(IndexNumeroTask = 0;IndexNumeroTask<Numbertask;IndexNumeroTask++)
		{
			/* SI compteur SLEEP à 0 */
			if(0 == Task[IndexNumeroTask].compteur)
			{
				/* Passage en Préopérationnel et recharge du compteur */
				Task[IndexNumeroTask].stateTask = PREOP;
				//printf("NumTask %d PREOP\n",IndexNumeroTask);
				Task[IndexNumeroTask].compteur = Task[IndexNumeroTask].MaxCompteur;
			}
			/* SI tâche opérationnel */
			else if(Task[IndexNumeroTask].stateTask == OP)
			{
			    //printf("NumTask:%d:SLEEP\n",IndexNumeroTask);
				/* Passage en mode sleep */
				Task[IndexNumeroTask].stateTask = SLEEP;
			}
			/* SI mode Sleep */
			else if(Task[IndexNumeroTask].stateTask == SLEEP)
	        {
	            //printf("NumTask %d:%d:SLEEPDEC\n",IndexNumeroTask,Task[IndexNumeroTask].compteur);
	            /* décrémentation du compteur sleep */
	            Task[IndexNumeroTask].compteur--;
	        }
	        else
			{
				/* Cas d'une tâche en mode FINISHED */
				if(Task[NumeroTaskaActive].stateTask = KILL)
	            {
	                Task[NumeroTaskaActive].stateTask = FINISHED;
	            }
			}
		}
		IndexNumeroTask = 0;
		/* choix de la tache passant en opérationnel */
		for(IndexNumeroTask = 0;IndexNumeroTask<Numbertask;IndexNumeroTask++)
		{
			/* SI priorité tache inférieur à la priorité min courante */
			if(Task[IndexNumeroTask].priorite < prioMin && Task[IndexNumeroTask].stateTask == PREOP)
			{
				/* set la nouvelle priorité min */
				prioMin = Task[IndexNumeroTask].priorite;
				/* sauvegarde du numéro de tache ayant la plus faible priorité */
				NumeroTaskaActive = IndexNumeroTask;
			}
		}
		if(prioMin!=100)
	    {
	        //printf("NUMTaskActive %d\n",NumeroTaskaActive);
	        /* Activation de la tâche */
	        Task[NumeroTaskaActive].stateTask = OP;
	        retTaskActive = Task[NumeroTaskaActive].Fct(Task[NumeroTaskaActive].Data);
	        if(-1 == retTaskActive)
	        {
	            Task[NumeroTaskaActive].stateTask = KILL;

	        }
	    }
    }
}
