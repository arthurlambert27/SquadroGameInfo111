#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H

#include <tuple>
#include <vector>

#include "../manipulation_tableau/manipulation_tableau.h"
#include "../position/position.h"

std::tuple<std::vector<std::vector<int>>,std::vector<int>> deplace(std::vector<std::vector<int>> plateau, std::vector<int> etatPions, int joueur, int noPion );


#endif
