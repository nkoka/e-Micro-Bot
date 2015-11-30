#ifndef CONFUSER_ROBOT_H
#define CONFUSER_ROBOT_H

/************************************************/
/*                                              */
/*           Définition des modules             */
/*                (hors taches)                 */
/*                                              */
/************************************************/
#define MOD_SERIE           0 // Activation du serveur de maintenance

/************************************************/
/* Définition associée au taches du robot       */
/************************************************/
/* Priorité des taches */
#define PRIO_TSK_MOTEUR     3
#define PRIO_TSK_BRAIN      2
#define PRIO_TSK_TELEMETRE  2
/* nombre de Cycle de sommeil des taches */
#define CYCLE_TSK_BRAIN     2
#define CYCLE_TSK_MOTEUR    2
#define CYCLE_TSK_TELEMETRE 2

/**************************************/
/* Définition associée                */ 
/* au pinning du robot                */
/**************************************/
/* Pin du servo droit */
#define PIN_SERVO_DROIT		3
/* Pin du servo gauche */
#define PIN_SERVO_GAUCHE	10
/* Pin etat robot */
#define PIN_ROBOT_OK		4
/* Pin Télémètre */
#define PIN_TELEMETRE		A0
/* Pin robot bloqué */
#define BLOCK_PIN	12

/***************************************/
/* Définition global du robot          */
/***************************************/
/* Nom du robot */
#define NOMDUROBOT  "My name is AUTOMOBOT"
/* Vitesse d'échange entre l'arduino et le PC */
#define BAUDRATE_SERIE  9600

/**************************************/
/* Définition associée au télémètre   */
/**************************************/
/* Valeur de démarrage associée au télémètre */
#define VAL_INIT_TELEMETRE      700

/**************************************/
/* Définition associée aux moteurs    */
/**************************************/

/**************************************/
/* Définition associée aux Brains     */
/**************************************/



#endif
