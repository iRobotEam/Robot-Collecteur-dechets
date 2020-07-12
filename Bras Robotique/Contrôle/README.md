# Suivit du travail sur le contrôle des servomoteurs 

Ce README a pour obectif de présenter le travail technique réalisé sur le contrôle du bras robotique. Le travail est inachevé à cause du confinement du COVID-19. 
Vous trouverez donc l’historique du travail de la partie électronique du bras. Les parties en suspend seront expliquées afin de pouvoir continuer la réalisation technique à la rentrée de septembre 2020. 

Ce readme ne prend pas en compte la mécanique et l'assemblage des pièces 3D. 


## Première approche : RASPBERRY  
![alt text](https://wiki.zenk-security.com/lib/exe/fetch.php?w=200&media=rpi.png)

Cette approche n’est parvenue à aucun résultat, mais offre des possibilités poussées si les erreurs rencontrées sont surmontées. Cela permettrait notamment d’utiliser une seule et même carte pour contrôler la détection des déchets et les servomoteurs du bras. Raspberry offre notamment l’avantage d’utiliser des API déjà toutes faites par Dynamixel. 

### Liste du matériel utilisé   

* Une raspberry PI 
* Les [pièces](https://github.com/iRobotEam/Robot-Collecteur-dechets/tree/master/Bras%20Robotique/Modelisation) imprimées en 3D 
* 3 servomoteurs [XL320](https://emanual.robotis.com/docs/en/dxl/x/xl320/)
* 3 servomoteurs [XL430-W250](https://emanual.robotis.com/docs/en/dxl/x/xl430-w250/)
* Un [régulateur de tension](https://www.generationrobots.com/fr/401456-module-convertisseur-de-tension-continue.html) 
* Des cables / connecteurs 
* Breadboard 
* un [SN74LS241N](https://www.digikey.com/product-detail/en/texas-instruments/SN74LS241N/296-14887-5-ND/563034) 





## Deuxième approche : ARDUINO 
![alt text](https://www.mon-club-elec.fr/mes_images/clipart/ArduinoLogo.gif)




## Troisième approche DYNAMIXEL 

![alt text](https://tribotix.com/wp-content/uploads/2018/10/Robotis_2.png)



