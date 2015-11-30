/************************************************/
/* Author : N. Bianchi                          */
/* Name   : GraphicalEngine.h                   */
/* Brief  : Module logiciel du moteur graphique */
/************************************************/
#ifndef GraphicalEngine_h
#define GraphicalEngine_h
#include <stdio.h>
#include <string.h>
#include "EcranOled.h"
#include "ConfSys_Robot.h"
#include <stdlib.h>

Int StartGraphicalEngine;
Int NumWidgetGlobal;

/* Définition des versions du module EcranOled */
#define VERSION_MAJ     1
#define VERSION_MIN     0
#define REVISION        0
typedef enum ENUM_STATE_BOT
{
	State_Happy=0,
	State_Search,
	State_Hungry
}eStateBot;

typedef enum ENUM_TYP_WIDGET
{
	W_Texte=0,
	W_Form
}eTypeWidget;
typedef void(*ptFct)(char *Data,EcranOled *Oled,eStateBot Bot);
typedef enum ENUM_ETAT
{
	State_Unchanged=0,
	State_Changed
}eStateElement;

typedef struct STRUCT_WIDGET
{
	int numWidget;
	eTypeWidget etypeWidget;

	char* texte;
	int PosX;
	int PosY;
	eStateElement State;
	ptFct fct;
	UL * psHandleSuivWid;
}sWidget;
typedef struct STRUCT_FENETRE
{

	sWidget * ps16HandleWidget;
	int PosX;
	int PosY;
	eStateElement State;
	UL * psHandleSuivFen;
}sFenetre;
class GraphicalEngine
{
	private:
        /* Variables */

	public:
        /* Variables */
		sFenetre * Window;
		/* Fonction qui retourne la version du moteur graphique */
		CHAR* GraphicalEngineVersionEcranOled(char * strBuff);
		/* Initialisation du moteur graphique */
		void GraphicalEngineInitEngine(EcranOled *Oled);
		/* Méthode d'ajout de fenetre */
		void GraphicalEngineAddWindow(sFenetre * ps16HandleSuiv,
											int PosX,
											int PosY,
											eStateElement State);
		/* démarrage du moteur graphique */
		void GraphicalEngineSetEngine(Int stop);
		/* Méthode de réception d'état du robot */
		void GraphicalEngineProcessEngine(sFenetre * Window,EcranOled *Oled,eStateBot Bot);

};
#endif
