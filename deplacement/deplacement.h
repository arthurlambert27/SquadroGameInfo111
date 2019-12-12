#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H

#include <tuple>
#include <vector>

#include "../manipulation_tableau/manipulation_tableau.h"
#include "../position/position.h"
#include "../affichage/affichage.h"

/*
 * Permet de bouger un jeton
 * @param plateau qui est l'état du jeu a un certain moment
 * @param joueur qui est le joueur a déplacer
 * @param noPion qui jeton qui est le jeton a déplacé (de haut en bas pour le joueur 1 et de gauche a droite pour le joueur 2)
 * @return plateau qui retourne l'état du jeu suite au déplacement.
 * */

std::tuple<std::vector<std::vector<int>>,std::vector<int>, int, int>  deplace(std::vector<std::vector<int>> plateau, std::vector<int> etatPions, int joueur, int noPion );


#endif
