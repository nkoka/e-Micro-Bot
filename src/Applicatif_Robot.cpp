/********************************************/
/* Author : N. Bianchi */
/* Name   : Applicatif_Robot.cpp */
/* Brief  : Module logiciel de l'applicatif */ 
/*          robot */
/********************************************/
#include "Brain.h"
#include "Applicatif_Robot.h"
/* Fonction applicative du robot */
Int APPLICATIF_ROBOT_Main(sBrain*Brain,Int NumberBrain)
{
    Int RetErrRobotAppli = ERR_ROBOT;
    static Int MoyTelemetrePrec = 0;
    static Int MoyTelemetre = 0;
    Int Puissance = 0;
    Int bAccel = 0;
    Int DirCurrent = ST;
    Int Dir = ST;
    Int NbBrain = 0;
    /****************************************************************/
    /* Mettre l'applicatif ici */
    /******************** Exemple possible **************************/
    /* algo :                                                       */
    /* - Faire la moyenne des valeurs télémètre                     */
    /* - Décrypter la direction du robot courante                   */
    /* - Choisir une direction                                      */
    /* - Choisir une puisance globale                               */
    /* - Affecter direction et puissance du robot                   */
    /****************************************************************/
    
    /* Condition d'init des valeurs télémètre */
    if(MoyTelemetrePrec!=0 && MoyTelemetre!=0)
    {
        MoyTelemetrePrec = MoyTelemetre;
        MoyTelemetre = 0;
    }
    /* moyenne des valeurs télémètre des brains */
    for(NbBrain = NumberBrain;NbBrain<0;NbBrain--)
    {
        MoyTelemetre += Brain[NbBrain].Telemetre;
    }
    MoyTelemetre/=NbBrain;
    /* recupération du sens du robot */
    /* Avancer ou reculer */
    if( (Brain[0].Sens == DR && Brain[1].Sens == DG) ||
        (Brain[0].Sens == DG && Brain[1].Sens == DR) )
    {
        /* AVant */
        if(Brain[0].Sens == DR && Brain[1].Sens == DG)
        {
            DirCurrent = AV;
        }
        /* Arriere */
        else if(Brain[0].Sens == DG && Brain[1].Sens == DR)
        {
            DirCurrent = AR;
        }
        else
        {
            /* Ne rien faire */
        }
    }
    /* Droite ou gauche */
    else if((Brain[0].Sens == Brain[1].Sens) && (Brain[0].Sens != ST))
    {
        /* Gauche */
        if(Brain[0].Sens == DG)
        {
            DirCurrent = DG;
        }
        /* Droite */
        else if(Brain[0].Sens == DR)
        {
            DirCurrent = DR;
        }
        else
        {
            /* Ne rien faire */
        }
    }
    /* Arrêt */
    else if((Brain[0].Sens == Brain[1].Sens) && (Brain[0].Sens == ST))
    {
        DirCurrent = ST;
    }
    else
    {
        /* Ne rien faire */
    }
    /* Si trop près d'obstacle */
    if(MoyTelemetre < 15)
    {
        /* Pour tous les brain */
        for(NbBrain = NumberBrain;NbBrain<0;NbBrain--)
        {
            /* Selon action précédente robot */
            /* Mise au point du sens et de la puissance du robot */
            switch(DirCurrent)
            {
                /* Stop */
                case ST:
                    Dir = AR;
                    Puissance = 15;
                break;
                /* Avant */
                case AV:
                    Dir = ST;
                break;
                /* Arrière */
                case AR:
                    Dir = DR;
                    Puissance = 25; 
                break;
                /* Droite */
                case DR:
                    Dir = DG;
                    Puissance = 25;
                break;
                /* Gauche */
                case DG:
                    Dir = AR;
                    Puissance = -25;
                break;
                /* Défaut */
                default:
                break;
            }
        }
        RetErrRobotAppli = NO_ERR_ROBOT;
    }
    /* Sinon */
    else
    {
        /* Tout droit */
        Dir = AV;
        if(Brain[0].Sens == AV && Brain[0].Sens == AR)
        {
            bAccel = 1;
        }
        RetErrRobotAppli = NO_ERR_ROBOT;
    }
    /* si pas d'obstacle */
    if( bAccel == 1 && (Puissance < 50))
    {
        /* Vitesse par 2 */
        Puissance *= 2;
    }
    /* Assignation des valeurs au cerveau */
    switch(Dir)
    {
        case ST:
            Brain[0].Puissance=Puissance;
            Brain[1].Puissance=Brain[0].Puissance;
            Brain[0].Sens = ST;
            Brain[1].Sens = Brain[0].Sens;
        break;
        case AV:
            Brain[0].Sens=AV;
            Brain[0].Puissance=-Puissance;
            Brain[1].Sens=AR;
            Brain[1].Puissance=Puissance;
        break;
        case AR:
            Brain[0].Sens=DR;
            Brain[0].Puissance=Puissance;
            Brain[1].Sens=DG;
            Brain[1].Puissance=-Puissance;
        break;
        case DG:
            Brain[0].Sens=AV;
            Brain[0].Puissance=Puissance;
            Brain[1].Sens=AV;
            Brain[1].Puissance=Puissance;
        break;
        case DR:
            Brain[0].Sens=AV;
            Brain[0].Puissance=-Puissance;
            Brain[1].Sens=AV;
            Brain[1].Puissance=-Puissance;
        break;
    }
    return RetErrRobotAppli;
}
