## Conception

### Module Télémètre
#### Fonctionnement
Ce module permet la mesure d'une distance entre un objet/obstacle et le robot. Il prend une grandeur physique en entrée (distance) et fournit une valeur numérisée de la distance.La mesure est prise sur le front avant du robot (capteur fixe).
Le module permet de :
- Initialiser le module en chargeant la table de mesure à partir de l'EEPROM et d'associer la Pin du module ARDUINO
- Retourner la valeur (distance)

####Tableau de mesure
TBD

###Module Moteur
Ce module permet au robot de se déplacer. Une instance de ce module est nécessaire par roue. Il prend une consigne de vitesse en entrée via un tableau de conversion vitesse/angle et fournit une angle de rotation au servomoteur du robot.
Le module permet de :
- Initialiser le module en chargeant le tableau de conversion vitesse/angle

TBC
