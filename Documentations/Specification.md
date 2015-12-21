## Extrait spécification
Le but de se document est d'expliquer comment allons nous réaliser ce robot 'e-Micro-Bot'
Ce robot à pour unique but de faire découvrir la *robotique ludique*

## Interface
### Les obstacles
Le robot mesure la distance entre lui et un obstacle dans la direction de son mouvement.
Le robot mesure 10 centimètres de longeur sur 10 centimètre de largeur et 8 centimètre de hauteur. 
Il doit éviter un obstacle a 1.( fois sa langeur soit 15 centimètre pour eviter les chocs
*Résumé :*
- Il doit eviter les obstacle
- distance d'évitement 15 cm
- mesure de distance devant lui
- compensation s elon l'éclairage de la pièce (autotune)

###Angle de rotation
Le robot doit connaître l'angle de rotation sur l'axe de sa hauteur. Afin de connaître cette axe, l'utilisation d'un accéléromètre et gyroscope est nécessaire.
La fréquence de mesure de cette axe doit être de 100 millisecondes pour évaluer la rotation précise.
L'algorthmie devra être étudiée dans ce sens afin de garantir ce temps cycle.
L'utilisation d'un accéléromètre et gyroscope introduit des biais dans la mesure, ils devront être compensés.
*Résumé :*
- temps cycle = 100ms
- mesure sur l'axe de la hauteur
- Compensation des biais de la mesure (statique ou dynamique)

###Distance parcourue
Le robot doit pouvoir mesurer la distance parcourue pour chaque roue afin de savoir la distance parcourue en ligne droite pour evalué le chemin parcourue et mettre en corrélation la mesure de distance d'un ou des obstacles.
*Résumé : *
- mesure du nombre de tour de la roue avec précision à définir (base 4 point par tour soit (2*pi*R/4)=~10 cm par point soit sa longeur)
- corréler sa distance d'un obstacle avec sa position

###Configuration
####Enregistrement de données
Le robot doit pouvoir enregistrer des données qu'il traite.
Il peut fournir aussi des données en temps réelle selon un mode défini dit DataRealtime
L'utilisateur peut enregistrer des données pour traitement
L'utilisateur peut agir sur les informations que traite le robot
Le robot doit indiquer quand sa configuration est terminé
*Résumé :*
- enregistement de données (EEPROM et/ou SD)
- envoi des données (media à définir (USB ou bluetooth)
- Modification des données
- Interaction utilisateur (LED et/ou bouton poussoir)
