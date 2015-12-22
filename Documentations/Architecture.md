##Architecture

### Logiciel
Ce robot est défini sur 5 modules logiciels qui sont :
- Module Télémètre
- Module Moteur
- Module Angle
- Module Scheduler
- Module Service

Ses module logicielles représentent des tâches appelées si le robot a besoin d'effectuer leurs appels. Le besoin de ses appels sont à définir. Le module Service regroupe plusieurs service qui sont les suivants :
- Service Initialisation
- Service enregistrement de donnée (optionnel)
- Service Transmission de donnée (optionnel)
- Service LED
- Service Bouton Poussoir

### Tâches Télémètre
Cette tâche a pour but de relevé la distance entre le robot et un obstacle. Elle a un comportement périodique. Elle est appelé toutes les 100 ms
Dans le cas oû le robot est proche d'un obstacle 25 cm. Cette tâche reste événementiel mais dont la période est 1 cycle du scheduleur.

### Tâches Moteur
La tâche moteur a pour but de piloter les servomteur droit et gauche selon une vitesse angulaire.Elle est uniquement de type evenementiel.

### Tache Angle
La tâche angle permet de connâitre l'angle de rotation du robot par rapport aux trois axes. Cette tâche est de type évenementiel (comportement du MPU6050). La récupération des angles raw/pitch/Roll est exécuté sur pooling d'une entré/sortie (IO)

### Tache Scheduler
Cette tâche est celle qui calcul quand les tâches doivent être appelée. Le principe utilisé est d'appelé les tâches évenmentiel lorsque les conditions d'appel sont réunies.
Ce choix se base sur la choix de l'appel (oui ou non) de la tâche et sa priorité d'appel(0 à 4). Ainsi l'algorithme se base sur la priorité d'appel puis de sa présence de l'appel.

### Tâche Service
Cette tâche se base sur l'appel de 4 services. Ses services sont appelés à partir d'un tableau d'appel linéaire sur la base d'une FIFO.
Ses service sont les suivants:

- Initialisation du robot
- Enregistrement de données
- Transmission de données
- Allumage/Extinction d'une LED
- Détection d'un appui sur le bouton poussoir

###Ordonnancement
Le principe d'ordonnancement des tâches du robot repose sur les priorités des tâches à effectuer pour les tâche événementiel. Une tâche de plus haute priorité prendra s'exécutera une fois la tâche précédente terminée. Les priorité des tâche svont de 0 à 4. 0 est la priorité la plus haute et 4 la plus basse.

Il est possible de n'avoir aucune tâche événementiel à réaliser. Dans ce cas, le robot effectuera uniquement les tâches périodiques.

*Cas Particulier :*

La tâche télémètre peut dans le cas oû le robot est proche de moins de 25 cm d'un obstacle passé à un appel par tour de scheduler.

###Architecture hardware
#### Le robot
Le robot est constitué  d'une structure de type cubique, ouverte en haut. La structure se referme par la carte électronique ou sont placé l'ensemble des composant électronique. Le bloc batterie est situé dessous pour abaisser le centre graviter du robot. Un servomoteur est situé sur chaque coté de la structure.

#### La carte électronique
La carte est constitué d'une arduino pro mini cadencé à 16MHz de 4 jumpers pour déconnecter le MPU6050 qui s'occcupe de calculer les accélération linéaire et angulaire et les deux moteurs de l'arduino.
La carte est aussi constitué d'une LED orange et de sa résistance (10 K) associé et d'un bouton poussoir avec sa résistance (10K). Les trois jeux de plots pour connecter le télémètre et les servos moteurs.
Pour finir, un   bornier pour connecter l'alimentation.

#### Pinning Arduino
- Arduino 2 -> codeur Droit
- Arduino 3 -> codeur Gauche
- Arduino 4 -> Servomoteur Droit
- Arduino 5 -> Servomoteur Gauche
- Arduino 8 -> LED + Résistance 10k
- Arduino 9 -> BP + Résistance 10k
- Arduino 10 -> CS SD
- Arduino 11 -> MOSI SD
- Arduino 12 -> MISO SD
- Arduino 13 -> SCK SD
- Arduino A0 -> Télémètre
- Arduino A4 -> SDA MPU6050
- Arduino A5 -> SCL MPU6050
- Arduino VCC -> VCC
- Arduino GND -> GND

Les autres pinning sont trouvés sur la datasheet des différents composants
