# SquadroGameInfo111


Installer sfml

Sur debian:
```sudo apt-get install libsfml-dev```

Commande pour compiler:

```g++ -std=c++11 -c affichage/affichage.cpp deplacement/deplacement.cpp initialisation/initialisation.cpp manipulation_tableau/manipulation_tableau.cpp mouvement/mouvement.cpp position/position.cpp  graphique/graphique.cpp main.cpp ia/ia.cpp```


```g++ -std=c++11 affichage.o deplacement.o initialisation.o manipulation_tableau.o mouvement.o position.o main.o ia.o graphique.o -o programme -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio```

Vous pouvez ensuite lancer le programme
