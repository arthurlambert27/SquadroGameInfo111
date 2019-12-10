#include <iostream>
#include <string>
#include <vector>
#include <tuple>


#include "affichage/affichage.h"
#include "mouvement/mouvement.h"
#include "deplacement/deplacement.h"
#include "initialisation/initialisation.h"
#include "graphique/graphique.h"
#include "ia/ia.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <chrono>
#include <thread>


int main(){
  std::tuple<std::vector<std::vector<int>>, std::vector<int>, int, int> plateau1;
  std::vector<std::vector<int>> plateau = creationPlateauInitial();
  std::vector<int> etatPions;
  etatPions = std::vector<int>(10);
  for(int i =0; i<etatPions.size(); i++){
    etatPions[i] = 0;
  }

  plateau1 = deplace(plateau, etatPions, 1, 1 );
  plateau = std::get<0>(plateau1);
  etatPions = std::get<1>(plateau1);
  plateau1 = deplace(plateau, etatPions, 2, 3 );
  plateau = std::get<0>(plateau1);
  etatPions = std::get<1>(plateau1);


  int coup;
  coup = meilleurCoup6(arbre6(plateau, etatPions));
  std::cout << coup;
  //std::cout <<"La fnErreur est de: " << fnErreur(plateau, etatPions) << "\n";

  return 0;
}
