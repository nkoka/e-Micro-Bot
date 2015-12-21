##Architecture

### Logiciel
Ce robot est défini sur n modules logiciels qui sont :
- Module Télémètre
- Module Moteur
- Module Angle
- Module Scheduler
- Module Service

Ses module logicielles représentent des tâches appelées si le robot a besoin d'effectuer leurs appels. Le besoin de ses appels sont à définir. Le module Service regroupe plusieurs service qui sont les suivants :
- Service enregistrement de donnée
- Service LED
- Service Bouton Poussoir

### Tâches Télémètre
TBC
### Tâches Moteur
TBC
### Tache Angle
TBC
### Tache Scheduler
TBC
### Tâche Service
TBC

###Ordonnancement
TBD

###Architecture hardware
#### Le robot
Le robot est constitué  d'une structure de type cubique, ouverte en haut. La structure se referme par la carte électronique ou sont placé l'ensemble des composant électronique. Le bloc batterie est situé dessous pour abaisser le centre graviter du robot. Un servomoteur est situé sur chaque coté de la structure.

#### La carte électronique
La carte est constitué d'une arduino pro mini cadencé à 16MHz de 4 jumpers pour déconnecter le MPU6050 qui s'occcupe de calculer les accélération linéaire et angulaire et les deux moteurs de l'arduino.
La carte est aussi constitué d'une LED orange et de sa résistance (10 K) associé et d'un bouton poussoir avec sa résistance (10K). Les trois jeux de plots pour connecter le télémètre et les servos moteurs.
Pour finir, un   bornier pour connecter l'alimentation.

#### Pinning
TBC