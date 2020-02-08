# SquadroGameInfo111


Rapport: https://docs.google.com/document/d/1HKawiv2AKhotdiu_aJtqxrrF2yUdUsJ9Jy1ZeOzcbsA/edit?usp=sharing

Adaptation du jeu Sqadro en c++.

Création d'une IA basé sur un arbre des possibilités.



# Installation

Installer sfml

Sur debian:
```sudo apt-get install libsfml-dev```

Commande pour compiler:

```g++ -std=c++11 -c affichage/affichage.cpp deplacement/deplacement.cpp initialisation/initialisation.cpp manipulation_tableau/manipulation_tableau.cpp mouvement/mouvement.cpp position/position.cpp  graphique/graphique.cpp main.cpp ia/ia.cpp manip_fichier/manip_fichier.cpp```


```g++ -std=c++11 affichage.o deplacement.o initialisation.o manipulation_tableau.o mouvement.o position.o main.o ia.o graphique.o manip_fichier.o -o programme -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio```

Vous pouvez ensuite lancer le programme
