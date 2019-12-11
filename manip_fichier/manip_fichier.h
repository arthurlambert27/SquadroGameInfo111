#include <vector>
#include <string>
#include <iostream>
#include "../initialisation/initialisation.h"
#include "../ia/ia.h"
#include "../position/position.h"

void SauvegardeGUI(std::vector<std::vector<std::string>> aff_plateau,std::vector<int> etatPions, int choix, int joueur);

std::tuple<std::vector<std::vector<int>>,std::vector<int>> LectureGUI(std::vector<std::vector<int>> plateau,std::vector<int> etatPions, int choix, int joueur);
/*
* écrit le déplacement choisi dans un fichier
* @param meilleurCoup le coup choisi par l'IA
*/
void EcritDeplacement(int meilleurCoup);
