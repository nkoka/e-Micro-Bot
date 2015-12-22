## Extrait spécification
Le but de ce document est d'expliquer le *comment allons nous réaliser ce robot 'e-Micro-Bot'*
Ce robot à pour unique but de faire découvrir la *robotique ludique*

## Interface
### Les obstacles
Le robot mesure la distance entre lui et un obstacle dans la direction de son mouvement.
Le robot mesure 10 centimètres de longeur sur 10 centimètre de largeur et 8 centimètre de hauteur. 
Il doit éviter un obstacle a 1.5 fois sa longueur soit 15 centimètre pour eviter les chocs

*Résumé :*

- Il doit eviter les obstacle [EXGN_E_MICRO_BOT_1_V1.0]
- distance d'évitement 15 cm [EXGN_E_MICRO_BOT_2_V1.0]
- mesure de distance devant lui [EXGN_E_MICRO_BOT_3_V1.0]
- compensation selon l'éclairage de la pièce (autotune est optionnel) [EXGN_E_MICRO_BOT_4_V1.0]

###Angle de rotation
Le robot doit connaître l'angle de rotation sur l'axe de sa hauteur. Afin de connaître cette axe, l'utilisation d'un accéléromètre et gyroscope est nécessaire.
La fréquence de mesure de cette axe doit être de 100 millisecondes pour évaluer la rotation précise.
L'algorthmie devra être étudiée dans ce sens afin de garantir ce temps cycle.
L'utilisation d'un accéléromètre et gyroscope introduit des biais dans la mesure, ils devront être compensés.

*Résumé :*

- temps cycle = 100ms [EXGN_E_MICRO_BOT_5_V1.0]
- mesure sur l'axe de la hauteur [EXGN_E_MICRO_BOT_6_V1.0]
- Compensation des biais de la mesure (statique ou dynamique) [EXGN_E_MICRO_BOT_7_V1.0]

###Distance parcourue
Le robot doit pouvoir mesurer la distance parcourue pour chaque roue afin de savoir la distance parcourue en ligne droite pour evalué le chemin parcourue et mettre en corrélation la mesure de distance d'un ou des obstacles.

*Résumé : *

- mesure du nombre de tour de la roue avec précision à définir (base 4 point par tour soit (2*pi*R/4)=~10 cm par point soit sa longeur) [EXGN_E_MICRO_BOT_8_V1.0]
- corréler sa distance d'un obstacle avec sa position [EXGN_E_MICRO_BOT_9_V1.0]

###Configuration
####Enregistrement de données
Le robot doit pouvoir enregistrer des données qu'il traite.
Il peut fournir aussi des données en temps réelle selon un mode défini dit DataRealtime
L'utilisateur peut enregistrer des données pour traitement
L'utilisateur peut agir sur les informations que traite le robot
Le robot doit indiquer quand sa configuration est terminé

*Résumé :*

- enregistement de données (EEPROM et/ou SD) [EXGN_E_MICRO_BOT_10_V1.0]
- envoi des données (media à définir (USB ou bluetooth) [EXGN_E_MICRO_BOT_11_V1.0]
- Modification des données [EXGN_E_MICRO_BOT_12_V1.0]
- Interaction utilisateur (LED et/ou bouton poussoir) [EXGN_E_MICRO_BOT_13_V1.0]
