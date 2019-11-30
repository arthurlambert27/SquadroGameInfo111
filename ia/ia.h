#ifndef IA_H
#define IA_H

#include <cmath>
#include <iostream>
#include "../position/position.h"
#include "../mouvement/mouvement.h"
#include "../deplacement/deplacement.h"
#include "vector"
float fnErreur(std::vector<std::vector<int>> plateau, std::vector<int> etatPions);
std::vector<std::vector<float>> arbre2(std::vector<std::vector<int>> plateauSave, std::vector<int> etatPions);
int meilleurCoup2(std::vector<std::vector<float>> probabilite);

#endif
