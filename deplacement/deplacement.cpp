#include "deplacement.h"

/*
 * Permet de bouger un jeton
 * @param plateau qui est l'état du jeu a un certain moment
 * @param joueur qui est le joueur a déplacer
 * @param noPion qui jeton qui est le jeton a déplacé (de haut en bas pour le joueur 1 et de gauche a droite pour le joueur 2)
 * @return plateau qui retourne l'état du jeu suite au déplacement.
 * */
 std::tuple<std::vector<std::vector<int>>,std::vector<int>> deplace(std::vector<std::vector<int>> plateau, std::vector<int> etatPions, int joueur, int noPion ){
   std::vector<int> PionsPris;
   PionsPris = std::vector<int>(1);
   std::vector<int> pos = posPions(plateau);
	 std::vector<int> pionDevantZoneMouvement = pionsDevantZoneMouvement(plateau, etatPions, joueur, noPion);
		if(joueur == 1){

			int posy = 0;
			int posx = 0;
			int ptnMouvement = ptnDeMouvement(noPion, 1, etatPions);
			for(int i = 0; i< 7; i++){
				if(plateau[noPion][i]==1){
					posy = noPion;
					posx = i;
				}
			}





			//Si il y a pas de pion dans la zone de mouvement devant moi
			if(tabIsNul(pionDevantZoneMouvement)){

				//Si il est au bout
				if(6 <= posx + ptnMouvement){

					plateau[posy][6] = 1;
					etatPions[noPion - 1 ] = 1;

				}
				else{
					plateau[posy][posx+ptnMouvement] = 1;
				}
			}


			else{
				std::vector<int> pionsDev= pionsDevant(plateau, etatPions, joueur, noPion);
				int compteur = 0;
				int sauteSurAdversaire = 0;

				for(int i = 0; i<pionsDev.size(); i ++){
					if(pionsDev[i] == 0 and sauteSurAdversaire == 1){
						i = 8;
						compteur = compteur + 1;
						if(etatPions[noPion - 1]== 0){

							plateau[posy][posx + compteur] = 1;
              for(int k=0 ; k<PionsPris.size(); k++){
                plateau[posy][posx+k] = 0;
                plateau[6][posx+k] = 2;
              }
              if (posx+compteur == 6){
                etatPions[noPion - 1] = 1;
              }


						}
						else{
							plateau[posy][posx - compteur] = 1;
              for(int k=0 ; k<PionsPris.size(); k++){
                plateau[posy][posx+k] = 0;
                plateau[6][posx+k] = 2;
              }

						}
            PionsPris.clear();

					}
					else if(pionsDev[i] == 1 and sauteSurAdversaire == 0){
						compteur = compteur + 1;
						sauteSurAdversaire = 1;
            PionsPris.push_back(i);
					}
					else{
						compteur = compteur + 1;
					}
				}
			}
			plateau[posy][posx]=0;

}




		if(joueur == 2){
			int posy = 0;
			int posx = 0;
			int ptnMouvement = ptnDeMouvement(noPion, 2, etatPions);

			for(auto i = 0; i< 7; i++){
				if(plateau[i][noPion]==2){
					posy = i;
					posx = noPion;
				}
			}

			if(tabIsNul(pionDevantZoneMouvement)){
				plateau[posy][posx] = 0;
				if(posy + ptnMouvement <= 0 ){
					plateau[0][posx] = 2;
					etatPions[4 + noPion] = 1;
				}
				else{

					plateau[posy+ptnMouvement][posx] = 2;
				}
			}
			else{

					std::vector<int> pionsDev= pionsDevant(plateau, etatPions, joueur, noPion);
					int compteur = 0;
					int sauteSurAdversaire = 0;

					for(int i = 0; i<pionsDev.size(); i ++){
						if(pionsDev[i] == 0 and sauteSurAdversaire == 1){
							i = 8;
							compteur = compteur + 1;
							if(etatPions[4 + noPion]== 0){
								plateau[posy - compteur][posx] = 2;
                for(int k=0 ; k<PionsPris.size(); k++){
                  plateau[posy+k][posx] = 0;
                  plateau[posy+k][0] = 1;
                }
                if (posy-compteur == 0){
                  etatPions[4 + noPion] = 1;
                }


							}
							else{
								plateau[posy + compteur][posx] = 2;
                for(int k=0 ; k<PionsPris.size(); k++){
                  plateau[posy+k][posx] = 0;
                  plateau[posy+k][0] = 1;
                }


							}

						}
						else if(pionsDev[i] == 1 and sauteSurAdversaire == 0){
							compteur = compteur + 1;
							sauteSurAdversaire = 1;
              PionsPris.push_back(i);
						}
						else{
							compteur = compteur + 1;
						}
					}


			}
				plateau[posy][posx] = 0;
        PionsPris.clear();

				}



			std::tuple<std::vector<std::vector<int>>,std::vector<int>> plateau1 (plateau, etatPions);

		return plateau1;
	 }
