#ifndef AFFICHAGE_H
#define TEST_HPP_H

#include <vector>
#include <string>
#include <iostream>
#include "../position/position.h"
#include "../ia/ia.h"

/*
* Affiche le plateau du jeu
* @param plateau Plateau du jeu a afficher
* O(n^2)
*/


void affichePlateau(std::vector<std::vector<int>> plateau);

/*
* Affiche le plateau du jeu
* @param plateau Plateau du jeu a afficher
* @param etatPions tableau qui contient l'etat des pions
* O(n^2)
*/

void affichePlateauV3(std::vector<std::vector<int>> plateau,std::vector<std::vector<std::string>> aff_plateau, std::vector<int> etatPions);


#endif
