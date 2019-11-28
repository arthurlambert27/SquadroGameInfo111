#include "ia.h"

int fnErreur(std::vector<std::vector<int>> plateau, std::vector<int> etatPions){
  std::vector<int> etatPionsNul;
  etatPionsNul = std::vector<int>(10) ;
  for(int i =0; i<etatPionsNul.size(); i++){
    etatPionsNul[i] = 0;
  }
  float pointJ1 = 0;
  float pointJ2 = 0;
  std::vector<int> positionPions = posPions(plateau);
  int retour = 0;
  int posX = 0;
  int posY = 0;
  for(int y = 1; y<plateau.size() - 1; y++){
    posY = positionPions[(y-1)*2];
    posX = positionPions[(y-1)*2 + 1];
    retour = etatPions[y-1];
    if(retour == 0){
      /*
      std::cout << "ptn de mvt de: " << (float)ptnDeMouvement(posY,1,etatPions) << "\n";
      std::cout << "posx: " << posX << "\n";
      std::cout << "nb de point: " << (posX/(float)ptnDeMouvement(posY,1,etatPions)) << "\n";
      */
      pointJ1 = pointJ1 + (posX/(float)ptnDeMouvement(posY,1,etatPions));
    }
    if(retour == 1){
      pointJ1 = pointJ1 + ((6-posX)/abs(ptnDeMouvement(y,1,etatPions)) + 6/ptnDeMouvement(y,1,etatPionsNul));
    }
  }
  for(int y = 1; y<plateau.size() - 1; y++){
    posY = positionPions[10 + (y-1)*2];
    posX = positionPions[10 + (y-1)*2 + 1];
    retour = etatPions[ 5 + y-1];
    if(retour == 0){
      /*
      std::cout << "ptn de mvt de: " << (float)ptnDeMouvement(posX,2,etatPions) << "\n";
      std::cout << "posy: " << posY << "\n";
      std::cout << "nb de point: " << (posY/(float)ptnDeMouvement(posX,2,etatPions)) << "\n";
      */
      pointJ2 = pointJ2 + ((6-posY)/abs(ptnDeMouvement(posX,2,etatPions)) );
    }
    if(retour == 1){
        pointJ2 = pointJ2 + (posY/(float)abs(ptnDeMouvement(posX,2,etatPions)) + 6/abs(ptnDeMouvement(posX,2,etatPionsNul)));
    }
  }


std::cout << "J1 à:"<< pointJ1 << "\n";
std::cout << "J2 à:"<< pointJ2 << "\n";
return pointJ2 - pointJ1;
}
