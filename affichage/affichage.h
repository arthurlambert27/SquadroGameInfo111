#ifndef AFFICHAGE_H
#define TEST_HPP_H

#include <vector>
#include <string>
#include <iostream>
#include "../position/position.h"
void affichePlateau(std::vector<std::vector<int>> plateau);
void affichePlateauV2(std::vector<std::vector<int>> plateau, std::vector<int> etatPions, int choix_pion);
void affichePlateauV3(std::vector<std::vector<int>> plateau,std::vector<std::vector<std::string>> aff_plateau, std::vector<int> etatPions, int choix_pion);


#endif
