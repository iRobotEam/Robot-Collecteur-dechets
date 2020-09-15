# Framework:
## Recherches des différents frameworks existants :
#### Darknet: Réseau de neurones Open Source en C avec YOLO: Détection d'objets en temps réel
https://pjreddie.com/darknet/

https://github.com/pjreddie/darknet

langage de programmation : **C**

| +/- | description |
| ------------ | ------------ |
| avantages | précis, puissant |
| désavantages | pas adapté à de l'embarqué ; requiert beaucoup de puissance (GPUs) et beaucoup de temps pour la création des modèles personnalisés |
  

#### Tensorflow: Bibliothèque de logiciels pour le flux de données et la programmation différenciée pour différentes tâches.
https://www.tensorflow.org/

https://github.com/tensorflow

langage de programmation : **Python**

| +/- | description |
| ------------ | ------------ |
| avantages | facile de créer des modèles depuis une banque d'images ; beaucoup de contenu, code, tutoriels|
| désavantages | pas adapté à de l'embarqué, requiert beaucoup de puissance (GPUs) et beaucoup de temps pour la création des modèles personnalisés, requiert également du temps pour la création de modèle personnalisé (et du matériel (GPUs)) |

#### Tensorflow Lite: Déployez des modèles de machine learning sur des appareils mobiles et IoT
https://www.tensorflow.org/lite/
De même que Tensorflow mais optimisé pour de l'embarqué (mobile et objects connectés)

## Choix du framework :
Nous avons décidé de choisir **Tensoflow Lite** , du par le langage de programmation et son atout d'être optimisé pour l'embarqué
Voici une liste de modèle pré-entrainé et optimisé pour fonctionner avec TensorFlow Lite : https://www.tensorflow.org/lite/guide/hosted_models


# Carte embarquée
## Recherches :
Raspberry Pi 4, Nvidia Jetson Nano, dev board Coral.io

| Carte | + | - | bonus |
| ------------ | ------------ | ------------ | ------------ |
| RPi 4 | la moins chère,  | apprentissage par CPU seulement, FPS trs faible,  | ajout d'un accélérateur USB |
| Jetson Nano | très bonnes performances | pas la plus efficace | bonnes communauté & bibliothèques |
| Dev Board | nouveau, la plus efficace | Verrouillé dans TF Lite, plus cher | la plus adaptée à l'IOT |
