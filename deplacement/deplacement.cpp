#include "deplacement.h"
#include <iostream>

/*
 * Permet de bouger un jeton
 * @param plateau qui est l'état du jeu a un certain moment
 * @param joueur qui est le joueur a déplacer
 * @param noPion qui jeton qui est le jeton a déplacé (de haut en bas pour le joueur 1 et de gauche a droite pour le joueur 2)
 * @return plateau qui retourne l'état du jeu suite au déplacement.
 * */
 std::tuple<std::vector<std::vector<int>>,std::vector<int>, int, int>  deplace(std::vector<std::vector<int>> plateau, std::vector<int> etatPions, int joueur, int noPion ){
   std::vector<int> PionsPris;
   PionsPris = std::vector<int>(0);
   std::vector<int> pos = posPions(plateau);
   int reste_pion_j1 = 5;
   int reste_pion_j2 = 5;
   int arrivee_j1 = 0;
   int arrivee_j2 = 6;


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
          arrivee_j1 = 6;

				}
				else{
					plateau[posy][posx+ptnMouvement] = 1;
          arrivee_j1 = posx+ptnMouvement;
				}
			}


			else{
				std::vector<int> pionsDev= pionsDevant(plateau, etatPions, joueur, noPion);
				int compteur = 0;
				int sauteSurAdversaire = 0;


				for(int i = 0; i<pionsDev.size(); i ++){
          if(pionsDev[i] == 1 and sauteSurAdversaire <= 1){
            PionsPris.push_back(i);

          }
					if(pionsDev[i] == 0 and sauteSurAdversaire == 1){
						i = 8;
						compteur = compteur + 1;
						if(etatPions[noPion - 1]== 0){//pion j1 dans la phase aller

							plateau[posy][posx + compteur] = 1;
              for(int k=0 ; k<PionsPris.size(); k++){



                std::cout << 5 + posx+PionsPris[k] << '\n';
                if(etatPions[5 + posx+PionsPris[k]]== 1){ // si le pion du j2 est sur le retour
                  if(PionsPris[k]==0){

                    plateau[posy][posx+1] = 0;
                    plateau[0][posx+1] = 2;
                  }
                  else{

                    plateau[posy][posx+PionsPris[k]] = 0;
                    plateau[0][posx+PionsPris[k]] = 2;
                  }  // si le pion du j2 est sur le retour
                   //on déplace le pion du joueur2


                }
                else if(etatPions[5 + posx+PionsPris[k]]== 0){// si j2 phase aller

                  if(PionsPris[k]==0){

                    plateau[posy][posx+1] = 0;
                    plateau[6][posx+1] = 2;
                  }
                  else{

                    plateau[posy][posx+PionsPris[k]+1] = 0;
                    plateau[6][posx+PionsPris[k]+1] = 2;
                  } // on effectue le déplacement
                }



              }
              if (posx+compteur == 6){ //si le pion va arriver au bord du plateau
                etatPions[noPion - 1] = 1;// on change son état
              }



						}
						else{ //si le pion du j2 est sur le retour
							plateau[posy][posx - compteur] = 1;

              for(int k=0 ; k<PionsPris.size(); k++){//distance entre notre pion et celui qui est pàris
                if(etatPions[3 + posx+PionsPris[k]]== 1){//si le pion du j2 est sur le retour

                  if(PionsPris[k]==0){

                    plateau[posy][posx-1] = 0;
                    plateau[0][posx-1] = 2;
                  }
                  else{

                    plateau[posy][posx-k] = 0;
                    plateau[0][posx-k] = 2;
                  }
                 //on place le pions pris au j2 en haut



                }
                else if(etatPions[4 + posx-PionsPris[k]]== 0){//si le pion du j2 est sur l'aller

                  if(PionsPris[k]==0){

                    plateau[posy][posx-1] = 0;
                    plateau[6][posx-1] = 2;
                  }
                  else{

                    plateau[posy][posx-PionsPris[k]] = 0;
                    plateau[6][posx-PionsPris[k]-1] = 2;
                  }
                   //on place le pions pris au j2 en bas
                }
              }


						}

}
					else if(pionsDev[i] == 1 and sauteSurAdversaire == 0){
						compteur = compteur + 1;
						sauteSurAdversaire = 1;
            PionsPris.push_back(i); //si il y a un pion devant, on l'ajoute à PionPris
            for(int k=0 ; k<PionsPris.size(); k++){
              std::cout << PionsPris[k] << '\n';
          }
					}
					else{
						compteur = compteur + 1;
					}
				}
			}
			plateau[posy][posx]=0;
      PionsPris.clear();
      PionsPris.resize(0);

}




		if(joueur == 2){
			int posy = 0;
			int posx = 0;
			int ptnMouvement = ptnDeMouvement(noPion, 2, etatPions);
      std::vector<int> pionsDev= pionsDevant(plateau, etatPions, joueur, noPion);
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
          arrivee_j2 = 0;
				}
				else{

					plateau[posy+ptnMouvement][posx] = 2;
          arrivee_j2 = posy+ptnMouvement;
				}
			}
			else{

					std::vector<int> pionsDev= pionsDevant(plateau, etatPions, joueur, noPion);
					int compteur = 0;
					int sauteSurAdversaire = 0;

					for(int i = 0; i<pionsDev.size(); i ++){
            if(pionsDev[i] == 1 and sauteSurAdversaire <= 1){
              PionsPris.push_back(i);

            }
            for(int i = 0; i<pionsDev.size(); i ++){
              std::cout << pionsDev[i] << '\n';

              }

            for(int i = 0; i<PionsPris.size(); i ++){
              std::cout << PionsPris[i] << '\n';

              }



						if(pionsDev[i] == 0 and sauteSurAdversaire == 1){
							i = 8;
							compteur = compteur + 1;
							if(etatPions[4 + noPion]== 0){// si pion j2 phase aller


                for(int k=0 ; k<PionsPris.size(); k++){

                  if(etatPions[posy-PionsPris[k]-2]== 1){// si j1 phase retour

                    if(PionsPris[k]==0){
                    plateau[posy-1][posx] = 0;
                    plateau[posy-1][6] = 1;
                  }
                  else{

                    plateau[posy-PionsPris[k]-1][posx] = 0;
                    plateau[posy-PionsPris[k]-1][6] = 1;
                  }

                    //1 1 3 1 1 1 2 3 3 3 5


                  }
                  else if (etatPions[posy-PionsPris[k]-2]== 0){//pion j1 phase aller




                    if(PionsPris[k]==0){

                    plateau[posy-1][posx] = 0;
                    plateau[posy-1][0] = 1;
                  }
                  else{

                    plateau[posy-PionsPris[k]-1][posx] = 0;
                    plateau[posy-PionsPris[k]-1][0] = 1;
                  }

                  }
                  plateau[posy - compteur][posx] = 2;
                }
                if (posy-compteur == 0){
                  etatPions[4 + noPion] = 1;
                }



							}
							else{// j2 phase retour
								plateau[posy + compteur][posx] = 2;
                for(int k=0 ; k<PionsPris.size(); k++){


                  if(etatPions[posy+PionsPris[k]+1] == 1){// si j1 phase retour

                    if(PionsPris[k]==0){
                      plateau[posy+1][posx] = 0;
                      plateau[posy+1][6] = 1;
                    }
                    else{
                      plateau[posy+PionsPris[k]+1][posx] = 0;
                      plateau[posy+PionsPris[k]+1][6] = 1;

                    }


                    //1 1 3 1 1 1 2 3 3 3 5


                  }
                  else if (etatPions[posy+PionsPris[k]+1]== 0){//pion j1 phase aller

                    if(PionsPris[k]==0){
                      plateau[posy+1][posx] = 0;
                      plateau[posy+1][0] = 1;
                    }
                    else{
                      plateau[posy+PionsPris[k]+1][posx] = 0;
                      plateau[posy+PionsPris[k]+1][0] = 1;
                    }





                }
              }




						}
          }
						else if(pionsDev[i] == 1 and sauteSurAdversaire == 0){
							compteur = compteur + 1;
							sauteSurAdversaire = 1;


          }
						else{
							compteur = compteur + 1;
						}
					}


			}


				plateau[posy][posx] = 0;


				}

        PionsPris.clear();
        PionsPris.resize(0);

std::tuple<std::vector<std::vector<int>>,std::vector<int>, int, int> plateau1 (plateau, etatPions, reste_pion_j1, reste_pion_j2);
  std::cout << "do" << '\n';
  std::cout << arrivee_j1 << '\n';
  std::cout << etatPions[noPion-1] << '\n';
  std::cout << noPion-1 << '\n';
  std::cout << joueur << '\n';

        if(arrivee_j1 == 0 and etatPions[noPion-1]==1 and joueur == 1){
          etatPions[noPion-1] = 2 ;
          for(int k = 0; k<etatPions.size(); k++){
                std::cout << etatPions[k];
                std::cout << std::endl;
              }
              plateau1 = make_tuple(plateau, etatPions, reste_pion_j1, reste_pion_j2);
          std::cout << etatPions[noPion-1] << '\n';
          reste_pion_j1= reste_pion_j1-1;
        }


        if(arrivee_j2 == 6 and etatPions[noPion-1]==1 and joueur == 2){

          etatPions[noPion-1] = 2 ;
          for(int k = 0; k<etatPions.size(); k++){
                std::cout << etatPions[k];
                std::cout << std::endl;
              }
        plateau1 = make_tuple(plateau, etatPions, reste_pion_j1, reste_pion_j2);
          reste_pion_j2= reste_pion_j2-1;
        }


		return plateau1;
	 }
