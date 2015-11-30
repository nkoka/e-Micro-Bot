#ifndef CONF_ROBOT_H
#define CONF_ROBOT_H

#include <Arduino.h>
#include "ConfUser_Robot.h"
/*********************************/
/* Définition des types généraux */
/*********************************/
/* Redéfinition du type CHAR pour portage */
#define CHAR    char
/* Redéfinition du type entier signé*/
#define Int     int 
/* Redéfinition du type entier non signé */
#define UInt    unsigned long
/* redéfinition dy type flottant */
#define FLOAT   float

/************************************************/
/*                                              */
/*           Définition des modules             */
/*                (hors taches)                 */
/*                                              */
/************************************************/
#define MOD_SCHEDULER       1 // Compilation du scheduler

/************************************************/
/*                                              */
/*        Définition des tâches robot           */
/*                                              */
/************************************************/
#define TSK_MOTEUR          1 // Compilation de la tache Moteur
#define TSK_TELEMETRE       1 // Compilation de la tache Télémètre 
#define TSK_BRAIN           1 // Compilation de la tache Calculatrice    
  
/***************************************/
/* Définition global du robot          */
/***************************************/
/* Définition du nombre de taches */
/* ATTENTION : le module SERIE n'est pas considéré comme une tache */
#define NB_TACHE  3
/* Définition du nombre de moteur du robot */
#define NB_MOTEUR   2
/* Définition du nombre de calculateur des moteurs */
#define NB_BRAIN    1
/* Définition d'une erreur*/
#define ERR_ROBOT    -1
/* Définition  d'absence d'erreur */
#define NO_ERR_ROBOT    0
/* Quantum de temporisation pour le démarrage du robot */
#define QUANTUM_INIT_ROBOT  250
/* Redéfinition du nom du robot */
#define NAMEBOT NOMDUROBOT
/* message de bienvenue du robot */
#define WELCOME       "Welcome"
#define BOOT          "Waiting for boot"
#define BOOTFINISHED  "Boot Terminated !!!"

/**************************************/
/* Définition associée aux moteurs    */
/**************************************/
/* Définition d'un moteur */
#define UN_MOTEUR   1
/* définition de l'arret d'un moteur */
#define ARRET_MOTEUR    90
/* Définition de l'indice dans la structure des moteurs du moteur droit */
#define MOTEUR_D    0
/* Définition de l'indice dans la structure des moteurs du moteur gauche */
#define MOTEUR_G    1
/* Définition d'un arrêt du robot */
#define ROBOT_ARRET 0
/* définition de l'indice du sens du moteur droit */
#define ROBOT_SENS_MOTEUR_D 0
/* définition de l'indice du sens du moteur gauche */
#define ROBOT_SENS_MOTEUR_G (0+UN_MOTEUR)
/* définition de l'indice de la puissance du moteur droit */
#define ROBOT_PUISSANCE_MOTEUR_D 1
/* définition de l'indice de la puissance du moteur gauche */
#define ROBOT_PUISSANCE_MOTEUR_G (1+UN_MOTEUR)
/* Définition de la marche arrière d'un moteur */
#define ARR  0
/* Définition de la marche avant d'un moteur */
#define AV  1
/* Définition de la puissance de la puissance max en valeur absolue*/
#define PUISSANCE_MAX   100.0
/* Définition du sens de la puissance du moteur droit */
#define SENS_PUISSANCE_MOTEUR_DROIT -1.0
/* Définition du sens de la puissance du moteur gauche */
#define SENS_PUISSANCE_MOTEUR_GAUCHE  1.0


/**************************************/
/* Définition associée aux Brains     */
/**************************************/
/* Définition d'un brain */
#define UN_BRAIN   1

#endif
