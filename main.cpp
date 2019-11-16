
#include <vector>
#include <tuple>


#include "affichage/affichage.h"
#include "mouvement/mouvement.h"
#include "deplacement/deplacement.h"
#include "initialisation/initialisation.h"











int main(){

    std::vector<std::vector<int>> plateau = creationPlateauInitial();
		std::vector<int> etatPions;
		etatPions = std::vector<int>(10);
		for(int i =0; i<etatPions.size(); i++){
			etatPions[i] = 0;
		}
    
	jeu(plateau, etatPions);



    return 0;
}
