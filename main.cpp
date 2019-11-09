#include <iostream>
#include <vector>




/*
 * Permet de localiser ou sont les pions (de 0 a 9 pour le joueur 1)(de 10 a 19 pour le joueur 2) Par exemple, la position du deuxième pions du joueur 1 est l'élément 2 et 3'
 * @param plateau Etat du jeu
 * @return posPions un tableau des positions des pions
*/
std::vector<int> posPions(std::vector<std::vector<int>> plateau){
		std::vector<int> posPions;
		for(int i = 1; i<6; i++){
				for(int j = 0; j<7; j++){
					if (plateau[i][j] ==1){
							posPions.push_back(i);
							posPions.push_back(j);
						}
					}
			}
		for(int j = 1; j<6;j++){
			for(int i = 0; i<7; i++){
				if(plateau[i][j]==2){
					posPions.push_back(i);
					posPions.push_back(j);
					}
				}
			}
		return posPions;
	}

/*
 * Permet de bouger un jeton
 * @param plateau qui est l'état du jeu a un certain moment
 * @param joueur qui est le joueur a déplacer
 * @param noPion qui jeton qui est le jeton a déplacé (de haut en bas pour le joueur 1 et de gauche a droite pour le joueur 2)
 * @return plateau qui retourne l'état du jeu suite au déplacement.
 * */
 std::vector<std::vector<int>> deplace(std::vector<std::vector<int>> plateau, int joueur, int noPion ){
	 std::vector<int> pos = posPions(plateau);
		if(joueur == 1){
			
			
			int ptnMouvement = 0;
			if(noPion == 1)
				ptnMouvement= 1;
			else if(noPion == 2)
				ptnMouvement = 3;
			else if(noPion == 3)
				ptnMouvement = 2;
			else if(noPion == 4)
				ptnMouvement = 3;
			else if(noPion ==4)
				ptnMouvement = 1;
			
			
			int posy = pos[noPion * 2 - 2];
			int posx = pos[noPion * 2 -1];
			
			plateau[posy][posx] = 0;
			
			plateau[posy][posx+ptnMouvement] = 1;
			
			}
			if(joueur == 2){
				int ptnMouvement = 0;
				if(noPion == 1)
				ptnMouvement = 3;
			else if(noPion == 2)
				ptnMouvement = 1;
			else if(noPion == 3)
				ptnMouvement = 2;
			else if(noPion == 4)
				ptnMouvement = 1;
			else if(noPion ==4)
				ptnMouvement = 3;
			int posy = pos[10 + noPion * 2 - 2];
			int posx = pos[10 + noPion * 2 -1];
			plateau[posy][posx] = 0;
			
			plateau[posy-ptnMouvement][posx] = 2;
				}
		return plateau;
	 }


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

int main(){
    std::vector<std::vector<int>> plateau = creationPlateauInitial();
    plateau = deplace(plateau, 1, 2);
    plateau = deplace(plateau, 2, 1);
    affichePlateau(plateau);
	std::vector<int> pos = posPions(plateau);
	
	for(auto i : pos){
		std::cout << i << ";";
		}
    return 0;
}
