/************************************************/
/* Author : N. Bianchi                          */
/* Name   : GraphicalEngine.cpp                 */
/* Brief  : Module logiciel du moteur graphique */
/************************************************/

#include "GraphicalEngine.h"

/* Fonction qui retourne la version du moteur graphique */
CHAR* GraphicalEngineVersionEcranOled(char * strBuff)
{
	sprintf(strBuff,"%d.%d%d",VERSION_MAJ,VERSION_MIN,REVISION);
	return strBuff;
}
/* démarrage du moteur graphique */
void GraphicalEngineSetEngine(Int stop)
{
	StartGraphicalEngine = stop;
}
/* set le nombre de widget global */
static void GraphicalEngineSetNumWidget(Int NumWidget)
{
	StartGraphicalEngine = NumWidget;
}
/* get le nombre de widget global */
static Int GraphicalEngineGetNumWidget()
{
	return StartGraphicalEngine;
}
/* Initialisation du moteur graphique */
void GraphicalEngineInitEngine(EcranOled *Oled)
{
	GraphicalEngineSetEngine(0);
	GraphicalEngineSetNumWidget(0);
	Oled->EcranOledStartEcranOled();
	Oled->ResetBuffer();
}
/* Méthode d'ajout de fenetre */
void GraphicalEngineAddWindow(sFenetre * ps16HandleSuiv,
									int PosX,
									int PosY,
									eStateElement State)
{
	sFenetre * ps16Handle = NULL;
	ps16Handle  = (sFenetre*)malloc(sizeof(sFenetre));
	if(NULL != ps16Handle)
	{
		ps16Handle->PosX = PosX;
		ps16Handle->PosY = PosY;
		ps16Handle->State = State;
		ps16HandleSuiv = (sFenetre*)ps16Handle->psHandleSuivFen;
	}
	else
	{
		free((void*)ps16Handle);
	}
}
/* Méthodes d'ajout de widget */
void GraphicalEngineAddWidget(sWidget * Widget,
								eTypeWidget eTypeWidget,
								char* texte,
								char * form,
								int PosX,
								int PosY,
								eStateElement State,
								ptFct pfct)
{
	Int NumWidgetTemp = 0;
	sWidget * ps16Handle = NULL;
	ps16Handle  = (sWidget*)malloc(sizeof(sWidget));
	if(NULL != ps16Handle)
	{
		/* Remplissage du mayon de la liste */
		ps16Handle->PosX = PosX;
		ps16Handle->PosY = PosY;
		ps16Handle->State = State;
		ps16Handle->etypeWidget = eTypeWidget;
		ps16Handle->texte = texte;
		NumWidgetTemp = GraphicalEngineGetNumWidget();
		GraphicalEngineSetNumWidget(NumWidgetTemp + 1);
		ps16Handle->numWidget = GraphicalEngineGetNumWidget();
		ps16Handle->fct = pfct;
		Widget = ps16Handle;
	}
	else
	{
		free((void*)ps16Handle);
	}
}
/* Méthode de réception d'état du robot */
void GraphicalEngineProcessEngine(sFenetre * Window,EcranOled *Oled,eStateBot Bot)
{
	sFenetre *FenTemp = Window;
	sWidget *WidTemp = NULL;
	/* Si etat fenetre changé */
	while(State_Changed == FenTemp->State )
	{
		if(NULL == FenTemp)
		{
			break;
		}
		/* Mise à jour des widgets de la fenetre */
		else
		{
			WidTemp = FenTemp->ps16HandleWidget;
			/* Si etat widget changé */
			while(State_Changed == WidTemp->State)
			{
				if(NULL == WidTemp)
				{
					break;
				}
				else
				{
					/* Appel de la fonction de mise à jour du widget */
					WidTemp->fct(WidTemp->texte,Oled,Bot);
				}
				WidTemp++;
			}
		}
		FenTemp++;
	}
}

