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
  float posX = 0;
  float posY = 0;
  for(int y = 1; y<plateau.size() - 1; y++){
    posY = positionPions[(y-1)*2];
    posX = positionPions[(y-1)*2 + 1];
    retour = etatPions[y-1];
    if(retour == 0){

      pointJ1 = pointJ1 + (posX/(float)ptnDeMouvement(posY,1,etatPions));
    }
    else if(retour == 1){
      pointJ1 = pointJ1 + ((6.-posX)/((float)abs((float)(ptnDeMouvement(y,1,etatPions)))) + 6./((float)ptnDeMouvement(y,1,etatPionsNul)));
    }
    else if(retour == 2){
      pointJ1 = pointJ1 + 8.;
    }
  }
  for(int y = 1; y<plateau.size() - 1; y++){
    posY = positionPions[10 + (y-1)*2];
    posX = positionPions[10 + (y-1)*2 + 1];
    retour = etatPions[ 5 + y-1];
    if(retour == 0){

      pointJ2 = pointJ2 + ((6.-posY)/(float)abs((float)ptnDeMouvement(posX,2,etatPions)) );
    }
    else if(retour == 1){
        pointJ2 = pointJ2 + (posY/(float)abs(ptnDeMouvement(posX,2,etatPions)) + 6/abs((float)ptnDeMouvement(posX,2,etatPionsNul)));
    }
    else if(retour == 2){
      pointJ2 = pointJ2 + 8.;
    }
  }


return pointJ1 - pointJ2;
}


std::vector<std::vector<float>> arbre2(std::vector<std::vector<int>> plateauSave, std::vector<int> etatPions){
  std::vector<std::vector<int>> plateau = plateauSave;
  std::tuple<std::vector<std::vector<int>>, std::vector<int>, int, int> plateau1;
  std::tuple<std::vector<std::vector<int>>, std::vector<int>, int, int> plateau2;
  std::vector<std::vector<float>> probabilite;

  probabilite = std::vector<std::vector<float>>(5);

  for(int i = 0; i<5; i++){
    probabilite[i] = std::vector<float>(5);
  }

  for(int i = 0; i< 5; i++){

    if(etatPions[i] <2){
      plateau1 = deplace(plateau, etatPions,1,i + 1);


    for(int j = 0; j<5; j++){
      if(std::get<1>(plateau1)[5 + j]<2){
        plateau2 = deplace(std::get<0>(plateau1), std::get<1>(plateau1), 2, j+1);
        probabilite[i][j] = (fnErreur(std::get<0>(plateau2), std::get<1>(plateau2) ));
      }


    }
    }

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
    if(compteur/(float)probabilite[i].size() > moyenne ){
      moyenne = compteur/(float)probabilite[i].size();
      meilleurCoup = i+1;
    }

    compteur = 0;
  }
  return meilleurCoup;
}


std::vector<std::vector<float>> arbre6(std::vector<std::vector<int>> plateauSave, std::vector<int> etatPions){
  std::vector<std::vector<int>> plateau = plateauSave;
  std::tuple<std::vector<std::vector<int>>, std::vector<int>, int, int> plateau1;
  std::tuple<std::vector<std::vector<int>>, std::vector<int>, int, int> plateau2;
  std::tuple<std::vector<std::vector<int>>, std::vector<int>, int, int> plateau3;
  std::tuple<std::vector<std::vector<int>>, std::vector<int>, int, int> plateau4;
  std::tuple<std::vector<std::vector<int>>, std::vector<int>, int, int> plateau5;
  std::tuple<std::vector<std::vector<int>>, std::vector<int>, int, int> plateau6;

  std::tuple<std::vector<std::vector<int>>, std::vector<int>, int, int> plateauIntermediaire;
  std::vector<std::vector<float>> probabilite;
  probabilite = std::vector<std::vector<float>>(5);
  int nbDePointActuelle = 0;

  std::vector<int> analysePremierCoupJ2;
  std::vector<float> probabilitePremierCoupJ2;
  float meilleurValeurPremierCoupJ2 = 0;

  std::vector<int> analyseDeuxiemeCoupJ2;
  std::vector<float> probabiliteDeuxiemeCoupJ2;
  float meilleurValeurDeuxiemeCoupJ2 = 0;

  std::vector<int> analyseTroisiemeCoupJ2;
  std::vector<float> probabiliteTroisiemeCoupJ2;
  float meilleurValeurTroisiemeCoupJ2 = 0;



  for(int i = 0; i<5; i++){

    //On verifie que le coup peut être jouer.

    if(etatPions[i] <2){
      plateau1 = deplace(plateau, etatPions,1,i + 1);

      //Ici, on va essayer de determiner les coups du joueurs deux interessant.
      probabilitePremierCoupJ2 = std::vector<float>(5);
      analysePremierCoupJ2 = std::vector<int>(5);
      meilleurValeurPremierCoupJ2 = 10000.0;
      for(int a = 0; a<5;a++){
        if(std::get<1>(plateau1)[5+a] <2){
          probabilitePremierCoupJ2[a] = fnErreur(std::get<0>(deplace(std::get<0>(plateau1),std::get<1>(plateau1) , 2 , a + 1)),    std::get<1>(deplace(std::get<0>(plateau1),std::get<1>(plateau1) , 2 , a + 1)));
        }
        else{
          //Si le coup n'est pas jouable, on lui met une valeur très elevé pour qu'il ne soit pas joué
          probabilitePremierCoupJ2[a] = 10000;

        }

      }
      //On regarde la premiere valeur de coup le plus avantageux pour le J2
      for(int a = 0; a<5; a++){

        if(probabilitePremierCoupJ2[a]<meilleurValeurPremierCoupJ2)
          meilleurValeurPremierCoupJ2 = probabilitePremierCoupJ2[a];
      }
      for(int a = 0; a<5; a++){

        if(probabilitePremierCoupJ2[a] == meilleurValeurPremierCoupJ2){

          analysePremierCoupJ2[a] = 1;


        }
        else{

          analysePremierCoupJ2[a]=0;
        }


      }

      for(int j = 0; j<5; j++){

        //Si le coup du J2 est interessant
        if(analysePremierCoupJ2[j] == 1){
          plateau2 = deplace(std::get<0>(plateau1), std::get<1>(plateau1), 2, j+1);






          for(int k = 0; k<5; k++){

                if((std::get<1>(plateau2))[k] <2){

                plateau3 = deplace(std::get<0>(plateau2), std::get<1>(plateau2), 1, k+1);


                //Ici, on va essayer de determiner les coups du joueurs deux interessant.
                probabiliteTroisiemeCoupJ2 = std::vector<float>(5);
                analyseTroisiemeCoupJ2 = std::vector<int>(5);
                meilleurValeurTroisiemeCoupJ2 = 10000.0;
                for(int a = 0; a<5;a++){
                  if(std::get<1>(plateau3)[5+a] <2){
                    probabiliteTroisiemeCoupJ2[a] = fnErreur(std::get<0>(deplace(std::get<0>(plateau3),std::get<1>(plateau3) , 2 , a + 1)),    std::get<1>(deplace(std::get<0>(plateau3),std::get<1>(plateau3) , 2 , a + 1)));
                  }
                  else{
                      probabiliteTroisiemeCoupJ2[a] = 10000;

                  }

                }
                //On regarde la premiere valeur de coup le plus avantageux pour le J2
                for(int a = 0; a<5; a++){

                  if(probabiliteTroisiemeCoupJ2[a]<meilleurValeurTroisiemeCoupJ2)
                    meilleurValeurTroisiemeCoupJ2 = probabiliteTroisiemeCoupJ2[a];
                }
                for(int a = 0; a<5; a++){

                  if(probabiliteTroisiemeCoupJ2[a] == meilleurValeurTroisiemeCoupJ2){

                    analyseTroisiemeCoupJ2[a] = 1;



                  }
                  else{

                    analyseTroisiemeCoupJ2[a]=0;
                  }


                }








                for(int l = 0; l<5; l++){

                  if(analyseTroisiemeCoupJ2[l] == 1){
                    plateau4 = deplace(std::get<0>(plateau3), std::get<1>(plateau3), 2, l+1);

                    for(int m =0; m<5; m++){

                      if(std::get<1>(plateau4)[m] <2){


                      plateau5 = deplace(std::get<0>(plateau4), std::get<1>(plateau4), 1, m+1);





                      //Ici, on va essayer de determiner les coups du joueurs deux interessant.
                      probabiliteDeuxiemeCoupJ2 = std::vector<float>(5);
                      analyseDeuxiemeCoupJ2 = std::vector<int>(5);
                      meilleurValeurDeuxiemeCoupJ2 = 10000.0;
                      for(int a = 0; a<5;a++){

                        if(std::get<1>(plateau5)[5+a] <2){
                          probabiliteDeuxiemeCoupJ2[a] = fnErreur(std::get<0>(deplace(std::get<0>(plateau5),std::get<1>(plateau5) , 2 , a + 1)),    std::get<1>(deplace(std::get<0>(plateau5),std::get<1>(plateau5) , 2 , a + 1)));
                        }
                        else{
                          probabiliteDeuxiemeCoupJ2[a] = 10000;

                        }

                      }
                      //On regarde la premiere valeur de coup le plus avantageux pour le J2
                      for(int a = 0; a<5; a++){

                        if(probabiliteDeuxiemeCoupJ2[a]<meilleurValeurDeuxiemeCoupJ2)
                          meilleurValeurDeuxiemeCoupJ2 = probabiliteDeuxiemeCoupJ2[a];
                      }
                      for(int a = 0; a<5; a++){

                        if(probabiliteDeuxiemeCoupJ2[a] == meilleurValeurDeuxiemeCoupJ2){

                          analyseDeuxiemeCoupJ2[a] = 1;


                        }
                        else{

                          analyseDeuxiemeCoupJ2[a]=0;
                        }


                      }









                      for(int n = 0; n<5;n++){

                        if(analyseDeuxiemeCoupJ2[n]==1){
                          plateau6 = deplace(std::get<0>(plateau5), std::get<1>(plateau5), 2, n+1);

                          probabilite[i].push_back(fnErreur(std::get<0>(plateau6), std::get<1>(plateau6) ));
                        }


                      }
                    }
                  }

                }


          }
        }
        }



      }
    }

  }
}



  return probabilite;

}


int meilleurCoup6(std::vector<std::vector<float>> probabilite){
  float moyenne = -100;
  float meilleurCoup = 0;
  float compteur = 0;
  for(int i = 0; i<probabilite.size();i++){

    for(int j= 0; j<probabilite[i].size(); j++){
      compteur = compteur + probabilite[i][j];
    }

    if(compteur/(float)probabilite[i].size() > moyenne ){
      moyenne = compteur/(float)probabilite[i].size();
      meilleurCoup = i+1;
    }

    compteur = 0;
  }

  return meilleurCoup;
}
