#ifndef IA_H
#define IA_H

#include <cmath>
#include <iostream>
#include "../position/position.h"
#include "../mouvement/mouvement.h"
#include "../deplacement/deplacement.h"
#include "vector"

/*
* Fonction principale de l'ia. Elle a pour but de calculer le nombre de tour qu'a un joueur1 par rapport au joueur2
* Pour cela, elle calcule le nombre de coup necessaire du joueur1 et du joueur2 pour atteindre l'état du plateau en parametre puis souhstrait les 2 valeurs.
* @param plateau est l'état du plateau
* @param etatPions qui est l'état des pions
* @return un float qui est la valeur de l'avance du j1 par rapport au J2
*/
float fnErreur(std::vector<std::vector<int>> plateau, std::vector<int> etatPions);


/*
* Les fonction arbres sont des fonctions qui vont créer les feuilles des arbres de la fnErreur de tout les coup possible.
* @param plateauSave qui est l'état du plateau
* @param etatPions qui est l'état des pions
* @return qui est l'arbre des probabilite
*/

std::vector<std::vector<float>> arbre2(std::vector<std::vector<int>> plateauSave, std::vector<int> etatPions);
std::vector<std::vector<float>> arbre6(std::vector<std::vector<int>> plateauSave, std::vector<int> etatPions);

/*
* Les fonctions meilleur coup permette de trouver le meilleur coup en fonction des probabilite
* @param probabilite qui sont les feuilles del'arbre de probabilite des coups
* @return un entier représentant le meilleur coup a faire
*/
int meilleurCoup2(std::vector<std::vector<float>> probabilite);
int meilleurCoup6(std::vector<std::vector<float>> probabilite);

#endif
