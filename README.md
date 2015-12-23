# e-Micro-Bot 
Projet de creation d'une base logicielle robotique 
Utilisation : Pour comprendre et apprendre les bases logicielles associes  la robotique
Le projet est modulable et doit rest modulable afin d'utiliser que les modules ncessaire

## Fonctionnalités e-Micro-Bot
Ce robot a pour but de se déplacer dans une zone découverte.
La mot "découverte" signiife qu'il devra découvrir son environnement et principalement
la(les) pièce(s) où il évolue.
Attention, ce robot ne gère pas la montée/descente de marche. Il ne possède pas de fonction de détection de marche/escalier. Les chutes peuvent détruire le robot.
La navigation du robot sera aléatoire.

## Etape de réalisation
Le projet se déroulera en plusieurs phase de réalisation afin de pouvoir effectué une validation des réalisation par phase. Chaque phase devra être validé par des tests unitaires ou de validations

## Phases de développement
- Phase 1 : 
    La premiere phase de validation dot peut etre de lancer sur le robot des applicatifs qui permettent de valider le hardware soit :
        - Le module accéléromètre/gyroscope
        - Le module moteur
        - Le module lED
        - Le module Bouton poussoir
        - Le module télémètre
        - Le module SD
        - Le module Bluetooth de commande à distance
        - le mdoule Scheduler Robotique
        - Le module de charge du robot (optionnel)
- phase 2 : 
    La deuxième phase consiste a faire un mouvement d'accélération et de décélération du robot. cette phase permet de garantir la pérennité des servomoteurs.
- phase 2 bis :
    Cette phase permet de lire et d'écrire des données dans la carte SD et dans l'EEPROM. Cette interface doit etre générique.
    Elle permet aussi de valider l'ensemble des modules logiciels un par un 
- phase 3 : 
    La troisième phase permettra au robot "e-Micro-Bot" de pouvoir se déplacer selon des données (de taille de la surface à traverser) rentrées dans la mémoire EEPROM
- phase 4 : 
    Le robot pourra dans cette phase détecter son environnement et naviguer dans cette pièce, après cette détection de forme de la pièce
- phase 5 : (pahse finale)
    Cette phase permet d'avoir l'ensemble des fonctionnalités du robot. Il pourra détecter son environnement et se déplacer aléatoirement en évitant les obstacles
- phase 6 : (optionnel)
    Cette phase permet de valider le module de charge du robot. Il doit être capble de prévenir son utilisateur qu il arrive en fin de charge et retrouver sa base pour se recharger automatiquement.
    
## Arborescence projet

voir fichier Arbo.md
    
## Outils du projet
Afin de rendre le développement rapide, le projet utilisera les outils suivants:
- GitHub via Git (commiter ses sources)
- Ino (installation IDE Arduino officiel en prérequis)
- Librairie Arduino
- Logiciel pour récupérer l'USB Arduino comme Putty (console dans l'IDE arduino)
Ses outils ont été choisi pour rendre le développement "Custom", se rendre indépendant de l'environnement arduino sans pour autant s 'en éloigné de trop donc facilement utilisable avec un peu de recherche 