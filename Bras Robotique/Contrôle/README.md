# Suivit du travail sur le contrôle des servomoteurs 

Ce README a pour obectif de présenter le travail technique réalisé sur le contrôle du bras robotique. Le travail est inachevé dû au confinement du COVID-19. 
Vous trouverez donc l’historique du travail de la partie électronique du bras. Les parties en suspend seront expliquées afin de pouvoir continuer la réalisation technique à la rentrée de septembre 2020. 

Ce readme ne prend pas en compte la mécanique et l'assemblage des pièces 3D. 

Au cours de l'année nous avons approché de 3 façons différentes le contrôle des servomoteurs. Ce README reprend les étapes principales de ces 3 approches. 


---

## Première approche : RASPBERRY  
![alt text](https://wiki.zenk-security.com/lib/exe/fetch.php?w=200&media=rpi.png)

Cette approche n’est parvenue à aucun résultat, mais offre des possibilités poussées si les erreurs rencontrées sont surmontées. Cela permettrait notamment d’utiliser une seule et même carte pour contrôler la détection des déchets et les servomoteurs du bras. Raspberry offre notamment l’avantage d’utiliser des API déjà toutes faites par Dynamixel. () 



### **Hardware** : 

#### Liste du matériel utilisé   

* Une raspberry PI 
* Les [pièces](https://github.com/iRobotEam/Robot-Collecteur-dechets/tree/master/Bras%20Robotique/Modelisation) imprimées en 3D 
* 3 servomoteurs [XL320](https://emanual.robotis.com/docs/en/dxl/x/xl320/)
* 3 servomoteurs [XL430-W250](https://emanual.robotis.com/docs/en/dxl/x/xl430-w250/)
* Un [régulateur de tension](https://www.generationrobots.com/fr/401456-module-convertisseur-de-tension-continue.html) 
* Des cables / connecteurs 
* Breadboard 
* un [SN74LS241N](https://www.digikey.com/product-detail/en/texas-instruments/SN74LS241N/296-14887-5-ND/563034)  

Dans une premier temps nous avons testé de contrôler les servomoteurs 1 à 1. 

#### Schéma de câblage :   
![alt text](https://github.com/iRobotEam/Robot-Collecteur-dechets/blob/master/Bras%20Robotique/Contr%C3%B4le/Raspberry/Shema_Raspberry.png?raw=true)
![alt text](https://github.com/iRobotEam/Robot-Collecteur-dechets/blob/master/Bras%20Robotique/Contr%C3%B4le/Raspberry/Photo-Raspberry-cablage.jpg?raw=true)

> Source du harware : https://github.com/jeremiedecock/pyax12

Pour le XL320 l'alimentation de 5V de la raspberry est suvisant. Pour le XL430 il est nécessaire d'y ajouter une **alimentation externe de 11V**

### **Software** :  

Nous avons utilisé [Dynamixel_SDK](https://github.com/ROBOTIS-GIT/DynamixelSDK), une API pour les servomoteurs dynamixel. 

Pour installer Dynamixel_SDK sur Raspberry Raspbian il faut suivre [cette méthode.](https://github.com/tonnesfn/DynamixelSDK/wiki/3.2.1.2-C-Linux-(or-Linux-for-SBCs)) Ou bien suivre [la vidéo](https://www.youtube.com/watch?v=zb8I05D-LGE&feature=youtu.be) située à la fin du [Emanual Dynamixel_SDK](https://emanual.robotis.com/docs/en/software/dynamixel/dynamixel_sdk/quick_start_video/)

Une fois les librairies et API installées, il est possible de se déplacer dans les répertoires. Nous avons cette [arborescence](https://emanual.robotis.com/docs/en/software/dynamixel/dynamixel_sdk/download/#repository). 

Nous avons le choix de lancer en python ou en C. Il faut ouvrir les examples et **modifier quelques lignes de code** pour que cela fonctionne avec nos servomoteurs.

* **ID** (1 à 255) initialisée à 1 par defaut 
> C'est l'ID du servomoteur à qui est envoyée l'information. 
* **Baudrate** (0 à 7 = 9600 à 4,5M) initialisé à 1 (57600) par défaut.
> C'est la vitesse de communication série. 
* **Serial Port**  ttyS0 correspond à la sortie GPIO 15 et 14. ttuUSB0 correspond à la sortie USB. ttyAMA0 correspond  à une autre sortie.
> C'est le port de sortie pour la communication UART. 

Nous avons donc mofifié ces lignes de codes. Nous restions bloqués sur l'erreur suivante. Aucune communication se réalisait. Aussi bien en python qu'en C.

![alt text](https://github.com/iRobotEam/Robot-Collecteur-dechets/blob/master/Bras%20Robotique/Contr%C3%B4le/Raspberry/erreur1_raspberry.png?raw=true)

>Le signal était pourtant bien délivré par la raspberry et amplifié par le SN74LS241N. (en bas 3.3V ce qui sort de la raspberry. En haut TTL en 5V , le fil des données entrantes dans le servomoteur) ![alt text](https://raw.githubusercontent.com/iRobotEam/Robot-Collecteur-dechets/master/Bras%20Robotique/Contr%C3%B4le/Raspberry/Mesure_data.jpg)



Nous nous sommes arrêtés ici pour dynamixel et avons cherchés d'autres approches tel que des librairies python et des exmples. Mais nous n'avions pas le moindre servomoteur qui bougeait. 

| Servomoteur   | Librairie | Exemple   |
| :------------ |:--------- |:----------|
| XL320         | [Python](https://pypi.org/project/pyxl320/)  | [GitHub](https://github.com/MultipedRobotics/pyxl320) |
| XL430         | [Python](https://pypi.org/project/dynamixel-helper/)  | [GitHub](https://github.com/ryul1206/easy-dynamixel-helper) |


##### Fin de l'approche Raspberry 

---
## Deuxième approche : ARDUINO 
![alt text](https://www.mon-club-elec.fr/mes_images/clipart/ArduinoLogo.gif)

Arduino est la seule approche qui amena à un résultat. 


### **Hardware** : 

#### Liste du matériel utilisé   

* Une Arduino uno ou méga 
* Les [pièces](https://github.com/iRobotEam/Robot-Collecteur-dechets/tree/master/Bras%20Robotique/Modelisation) imprimées en 3D 
* 3 servomoteurs [XL320](https://emanual.robotis.com/docs/en/dxl/x/xl320/)
* 3 servomoteurs [XL430-W250](https://emanual.robotis.com/docs/en/dxl/x/xl430-w250/)
* Un [régulateur de tension](https://www.generationrobots.com/fr/401456-module-convertisseur-de-tension-continue.html) 
* Des cables / connecteurs 
* Breadboard 
* un [SN74LS241N](https://www.digikey.com/product-detail/en/texas-instruments/SN74LS241N/296-14887-5-ND/563034)  

Dans une premier temps nous avons testé de contrôler les servomoteurs un à un. 

#### Schéma de câblage : 

![alt text](C:\Users\edoui\Documents\Club Robotique\2019-2020\iRobot'Eam\GitHub\Robot-Collecteur-dechets\Bras Robotique\Contrôle\Arduino\Shéma_arduino.jpg)



> Source du harware : 

Pour le XL320 l'alimentation de 5V de l'arduino est suvisant. Pour le XL430 il est nécessaire d'y ajouter une **alimentation externe de 11V**


### **Software** :

Nous avons utilisé les exmemples de [Dynamixel2Arduino](https://github.com/ROBOTIS-GIT/Dynamixel2Arduino) pour faire tourner les servomoteurs. 


## Troisième approche DYNAMIXEL 

![alt text](https://tribotix.com/wp-content/uploads/2018/10/Robotis_2.png)




