#include "position.h"

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
  * Permet de voir si il y a un jeton dans les 3 cases devant une pièce.
  * Les données de retour sont sur la zone d'un tableau de 3 entier qui reprèsente les 3 case devant le pion dans sa direction.
  * @param plateau
  * @param etatPions
  * @param joueur
  * @param pions
  * @return
  */
  std::vector<int> pionsDevant(std::vector<std::vector<int>> plateau, std::vector<int> etatPions, int joueur, int noPion){
  	std::vector<int> pionsDevant;
  	int posPionX = 0;
  	int posPionY = 0;
  	if(joueur == 1){

  		//Determination du la position du pion
  		for(int j = 0; j<7;j++){
  			if(plateau[noPion][j]==1){
  				posPionY = noPion;
  				posPionX = j;
  			}
  		}

  		if(etatPions[noPion - 1]== 0){

  			for(int j= 0; j<7;j++){
  				if(j> posPionX){
  					if(plateau[noPion][j]==2){
  						pionsDevant.push_back(1);
  					}
  					else{
  						pionsDevant.push_back(0);
  					}
  				}
  			}


  }
  else{

  	for(int j = 6; j>=0; j = j - 1){

  		if(posPionX > j){


  			if(plateau[noPion][j]==2){

  				pionsDevant.push_back(1);
  			}
  			else{
  				pionsDevant.push_back(0);
  			}
  		}
  	}
  }

  	}

  	if(joueur == 2){

  		for(int j = 0; j<7;j++){
  			if(plateau[j][noPion]==2){
  				posPionY = j;
  				posPionX = noPion;
  			}
  		}

  		if(etatPions[4 + noPion]== 0){
  			for(int j= 6; j>=0;j = j - 1){

  				if(j< posPionY){

  					if(plateau[j][noPion]==1){
  						pionsDevant.push_back(1);
  					}
  					else{
  						pionsDevant.push_back(0);
  					}
  				}
  			}
  		}
  		else{
  			for(int j = 0; j<7; j++){
  				if(j>posPionY){
  					if(plateau[j][noPion]==1){
  						pionsDevant.push_back(1);
  					}
  					else{
  						pionsDevant.push_back(0);
  					}
  				}
  			}
  		}
  	}
  	return pionsDevant;
  }


  std::vector<int> pionsDevantZoneMouvement(std::vector<std::vector<int>> plateau, std::vector<int> etatPions, int joueur, int noPion){
  	std::vector<int> pionDevant = pionsDevant(plateau,etatPions,joueur,noPion);

  	int ptnMouvement = ptnDeMouvement(noPion, joueur, etatPions);
  	std::vector<int> pionDevantZoneMouvement;
  	for(int i = 0; i<std::abs(ptnMouvement); i++){
  		pionDevantZoneMouvement.push_back(pionDevant[i]);
  	}


  	return pionDevantZoneMouvement;
  }
