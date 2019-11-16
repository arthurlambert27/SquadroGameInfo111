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
* @param etatPions tableau qui contient l'etat des pions
*/
void affichePlateauV2(std::vector<std::vector<int>> plateau, std::vector<int> etatPions){
	int comptePion1 = 0;
	int comptePion2 = 0;
	std::string affichage;
	affichage = "|----------------------------------|\n";

	for(int i = 0; i<7; i++){
		for(int j = 0; j<7; j++){
			if(plateau[i][j] == 1 or plateau[i][j] == 2){

				if(etatPions[comptePion1]== 0 and  plateau[i][j] == 1){
					comptePion1++;
					affichage = affichage + "|" + ">" + "   ";
				//si le pion du j1 est dans la phase aller
				}

				else if (etatPions[comptePion1]== 1 and  plateau[i][j] == 1){
						comptePion1++;
						affichage = affichage + "|" + "<" + "   "; //phase retour

					}
				if(etatPions[comptePion2+5]== 0 and plateau[i][j] == 2 ){
					comptePion2++;
					affichage = affichage + "|" + "A" + "   "; //si le pion du j2 est dans la phase aller
				}
				else if (etatPions[comptePion2+5]== 1 and plateau[i][j] == 2 ){

					comptePion2++;
					affichage = affichage + "|" + "v" + "   ";//phase retour
          

				}
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
	comptePion1 = 0;
	comptePion2 = 0;

}
