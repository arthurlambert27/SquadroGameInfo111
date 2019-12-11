#ifndef INITISIALISATION_H
#define INITISIALISATION_H
#include <vector>
#include "../ia/ia.h"


/*
Fonction permettant la création du plateau initial
*/
std::vector<std::vector<int>> creationPlateauInitial();



/*
Fonction qui permet le jeu en console
@param plateau qui est l'état du plateau
@param etatPions qui est l'état des pions
*/
int jeu(std::vector<std::vector<int>> plateau, std::vector<int> etatPions);

#endif
