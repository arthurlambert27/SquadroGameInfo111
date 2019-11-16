#include "initialisation.h"
#include "../mouvement/mouvement.h"
#include "../affichage/affichage.h"
#include "../deplacement/deplacement.h"


/*
* Permet de créer le plateau initial
* @return le plateau
*/
std::vector<std::vector<int>> creationPlateauInitial(){
    //Création d'un tableau représentant le plateau
    std::vector<std::vector<int>> plateau;
    plateau = std::vector<std::vector<int>>(7);
    for(int i = 0; i<7;i++){
        plateau[i] = std::vector<int>(7);
        for(int j = 0; j<7;j++){
            plateau[i][j] = 0;
        }
    }

    //Remove les bordures du plateau qui ne servent a rien pour le jeu. L'état 9 etant l'état ne servant a rien.. ;)
    plateau[0][0] = 9;
    plateau[6][6] = 9;
    plateau[0][6] = 9;
    plateau[6][0] = 9;

    //Ajout des pions de chaque joueur. A gauche ceux du joueur 1 dont l'état est 1 et en bas ceux du joueur 2 dont l'état est le.......????..... 2 bien sur..
    for(int i = 1; i<6; i ++){
        plateau[i][0]=1;
    }
    for(int i = 1; i<6; i++){
        plateau[6][i]=2;
    }
    return plateau;
}
/*
* Demande une action aux joueurs
* @param plateau Plateau du jeu
* @param etatPions tableau qui contient l'etat des pions
*/
void jeu(std::vector<std::vector<int>> plateau, std::vector<int> etatPions){
		int tour_joueur = 1;
		int choix_pion = 0;

		std::tuple<std::vector<std::vector<int>>, std::vector<int>> plateau1;

		affichePlateauV2(plateau, etatPions);
		while(true){
			 std::cout << "Entrez un coup" << std::endl;
			std::cin >> choix_pion;
			if(tour_joueur%2 == 1){ //si c'est le tour du j1 on effectue le deplacment
				plateau1 = deplace(plateau, etatPions, 1, choix_pion );
				plateau = std::get<0>(plateau1);
				etatPions = std::get<1>(plateau1);
				affichePlateauV2(plateau, etatPions);
				tour_joueur++;
			}
			else{ //sinon j2
				
				plateau1 = deplace(plateau, etatPions, 2, choix_pion );
				plateau = std::get<0>(plateau1);
				etatPions = std::get<1>(plateau1);
				affichePlateauV2(plateau, etatPions);
				tour_joueur++;
			}


		}

}
