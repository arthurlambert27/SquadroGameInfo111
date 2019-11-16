#include "mouvement.h"

/*
* Permet le nombre de point de mouvement d'une pièce
* @param noPion qui est le numéro du pion
* @param joueur qui est le numéro du joueur
* @param etatPions pour savoir si les pions sont dans la phase d'allé ou de retour.
* @return le nombre de point de mouvement d'une pièce, négatif si pour le retour
*/
int ptnDeMouvement(int noPion, int joueur, std::vector<int> etatPions){
  int ptnMouvement = 0;
  int etatPion = 0;

  if(joueur == 1){

    etatPion = etatPions[noPion - 1];



    if(etatPion == 0){
    if(noPion == 1)
      ptnMouvement= 1;
    else if(noPion == 2)
      ptnMouvement = 3;
    else if(noPion == 3)
      ptnMouvement = 2;
    else if(noPion == 4)
      ptnMouvement = 3;
    else if(noPion ==5)
      ptnMouvement = 1;
    }
    else{
      if(noPion == 1)
      ptnMouvement = -3;
    else if(noPion == 2)
      ptnMouvement = -1;
    else if(noPion == 3)
      ptnMouvement = -2;
    else if(noPion == 4)
      ptnMouvement = -1;
    else if(noPion ==5)
      ptnMouvement = -3;
    }
    }

    if(joueur == 2){


        etatPion = etatPions[ 4 + noPion ];

      if(etatPion == 0){
      if(noPion == 1)
      ptnMouvement = -3;
    else if(noPion == 2)
      ptnMouvement = -1;
    else if(noPion == 3)
      ptnMouvement = -2;
    else if(noPion == 4)
      ptnMouvement = -1;
    else if(noPion ==5)
      ptnMouvement = -3;

    }
    else{
      if(noPion == 1)
        ptnMouvement= 1;
      else if(noPion == 2)
        ptnMouvement = 3;
      else if(noPion == 3)
        ptnMouvement = 2;
      else if(noPion == 4)
        ptnMouvement = 3;
      else if(noPion ==5)
        ptnMouvement = 1;
    }
    }

    return ptnMouvement;
}
