#include "ia.h"

float fnErreur(std::vector<std::vector<int>> plateau, std::vector<int> etatPions){
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

/*
std::cout << "J1 à:"<< pointJ1 << "\n";
std::cout << "J2 à:"<< pointJ2 << "\n";
std::cout << "J1 - J2: " << pointJ1 - pointJ2 << "\n";
*/
return pointJ1 - pointJ2;
}


std::vector<std::vector<float>> arbre2(std::vector<std::vector<int>> plateauSave, std::vector<int> etatPions){
  std::vector<std::vector<int>> plateau = plateauSave;
  std::tuple<std::vector<std::vector<int>>, std::vector<int>, int, int> plateau1;
  std::tuple<std::vector<std::vector<int>>, std::vector<int>, int, int> plateau2;
  std::vector<std::vector<float>> probabilite;

  std::cout << "ici;\n";
  probabilite = std::vector<std::vector<float>>(5);

  for(int i = 0; i<5; i++){
    probabilite[i] = std::vector<float>(5);
  }
  for(int i = 0; i< 5; i++){
    if(etatPions[i] <2){
      plateau1 = deplace(plateau, etatPions,1,i + 1);
    }

    for(int j = 0; j<5; j++){
      if(etatPions[j]<2){
        plateau2 = deplace(std::get<0>(plateau1), std::get<1>(plateau1), 2, j+1);
      }

      probabilite[i][j] = (fnErreur(std::get<0>(plateau2), std::get<1>(plateau2) ));

    }

  }

  std::cout << "Affichage des probabilité:\n";
  for(int i = 0; i<5;i++){
    for(int j = 0; j<5;j++){
      std::cout <<probabilite[i][j] << ";";
    }
    std::cout << "\n";
  }
  return probabilite;
}

int meilleurCoup2(std::vector<std::vector<float>> probabilite){
  float moyenne = -100;
  float meilleurCoup = 0;
  float compteur = 0;
  for(int i = 0; i<probabilite.size();i++){

    for(int j= 0; j<probabilite[i].size(); j++){
      compteur = compteur + probabilite[i][j];
    }
    std::cout << std::endl << std::endl << "La moyenne est de: " << compteur/(float)probabilite[i].size() << "\n";
    if(compteur/(float)probabilite[i].size() > moyenne ){
      moyenne = compteur/(float)probabilite[i].size();
      meilleurCoup = i+1;
    }

    compteur = 0;
  }
  std::cout << "Le meilleur coup est le deplacement du pion: " << meilleurCoup << ".\n";
  return meilleurCoup;
}
