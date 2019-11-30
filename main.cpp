#include <iostream>
#include <string>
#include <vector>
#include <tuple>


#include "affichage/affichage.h"
#include "mouvement/mouvement.h"
#include "deplacement/deplacement.h"
#include "initialisation/initialisation.h"
#include "graphique/graphique.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <chrono>
#include <thread>








int main(){
  int choix = 0;
    std::cout << "Bonjour, voici notre jeu Squadro pour le projet du semestre 1 d'info111. \n\n\n";
    std::cout << "Menu:\n";
    std::cout << "1. GUI\n";
    std::cout << "2. Console\n";
    std::cout << "3. GUI contre IA\n";
    std::cin >> choix;

    if(choix == 1){
      gui(0);
    }
    else if(choix == 2){
    std::vector<std::vector<int>> plateau = creationPlateauInitial();
		std::vector<int> etatPions;
		etatPions = std::vector<int>(10);
		for(int i =0; i<etatPions.size(); i++){
			etatPions[i] = 0;
		}
	jeu(plateau, etatPions);
    }
    if(choix ==3){
      gui(1);
    }
    return 0;
}
