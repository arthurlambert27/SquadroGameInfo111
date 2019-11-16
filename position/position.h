#ifndef POSITION_H
#define POSITION_H

#include <vector>
#include <math.h>

#include "../manipulation_tableau/manipulation_tableau.h"
#include "../mouvement/mouvement.h"

std::vector<int> posPions(std::vector<std::vector<int>> plateau);
std::vector<int> pionsDevant(std::vector<std::vector<int>> plateau, std::vector<int> etatPions, int joueur, int noPion);
std::vector<int> pionsDevantZoneMouvement(std::vector<std::vector<int>> plateau, std::vector<int> etatPions, int joueur, int noPion);


#endif
