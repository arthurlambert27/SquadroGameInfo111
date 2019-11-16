#include "affichage.h"


/*
* Affiche le plateau du jeu
* @param plateau Plateau du jeu a afficher
*/
void affichePlateau(std::vector<std::vector<int>> plateau){
    for(int i = 0; i< 7;i++){
        for(int j=0; j<7; j++){
            std::cout << plateau[i][j];
        }
        std::cout << std::endl;
    }
}


/*
* Affiche le plateau du jeu
* @param plateau Plateau du jeu a afficher
*/
void affichePlateauV2(std::vector<std::vector<int>> plateau){
	std::string affichage;
	affichage = "|----------------------------------|\n";

	for(int i = 0; i<7; i++){
		for(int j = 0; j<7; j++){
			if(plateau[i][j] == 1 or plateau[i][j] == 2){

				affichage = affichage + "|" + std::to_string(plateau[i][j]) + "   ";
			}
			else{
				affichage = affichage  + "|    "  ;
			}
		}

		affichage = affichage + "|\n";
		for(int a = 0; a<3; a++){
			for(int r = 0; r<7; r++){
				affichage = affichage + "|    ";
			}
			affichage = affichage + "|\n";
		}
		affichage = affichage + "|----------------------------------|\n";
	}
	std::cout << affichage;
}
