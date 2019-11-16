
#include <vector>
#include <tuple>


#include "affichage/affichage.h"

#include "deplacement/deplacement.h"
#include "initialisation/initialisation.h"











int main(){
    std::vector<std::vector<int>> plateau = creationPlateauInitial();
		std::vector<int> etatPions;
		etatPions = std::vector<int>(10);
		for(int i =0; i<etatPions.size(); i++){
			etatPions[i] = 0;
		}

		std::tuple<std::vector<std::vector<int>>, std::vector<int>> plateau1;







		plateau1 = deplace(plateau, etatPions, 2, 2);
		plateau = std::get<0>(plateau1);
		etatPions = std::get<1>(plateau1);
		plateau1 = deplace(plateau, etatPions, 2, 2);
		plateau = std::get<0>(plateau1);
		etatPions = std::get<1>(plateau1);
		plateau1 = deplace(plateau, etatPions, 1, 4);
		plateau = std::get<0>(plateau1);
		etatPions = std::get<1>(plateau1);




















		affichePlateauV2(plateau);


    return 0;
}
