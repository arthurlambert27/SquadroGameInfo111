#include "manip_fichier.h"
# include <fstream>

/*
* écrit l'état actuel du plateau dans un fichier
* @param aff_plateau le plateau d'affichage
* @return plateau qui retourne l'état du jeu suite au déplacement.
*/



void SauvegardeGUI(std::vector<std::vector<std::string>> aff_plateau,std::vector<int> etatPions, int choix, int joueur){
  if(choix == 0){
    if( remove( "sauvegarde.txt" ) != 0 )
      perror( "sauvegarde.txt n'existe pas" );
    else{
      puts( "sauvegarde.txt effacé" );
    std::ofstream fichier; // Déclaration
    fichier.open("sauvegarde.txt");
    // Ouverture
    for(int i = 0; i< 7;i++){
        for(int j=0; j<7; j++){
          fichier << aff_plateau[i][j]; // Écriture

          }
    fichier << std::endl;
  }
    fichier.close();
  }
    }


}

std::tuple<std::vector<std::vector<int>>,std::vector<int>>  LectureGUI(std::vector<std::vector<int>> plateau,std::vector<int>etatPions, int choix, int joueur){
  std::tuple<std::vector<std::vector<int>>,std::vector<int>> decodage (plateau, etatPions);
  if(choix == 0){
    std::string x;

    std::ifstream lecture_fichier;
    lecture_fichier.open("sauvegarde.txt");
    if (!lecture_fichier) {
      std::cerr << "Impossible d'ouvrir sauvegarde.txt";
      lecture_fichier.close();

    }
    else{
      for(int i = 0; i< 7;i++){
          for(int j=0; j<7; j++){
            if (lecture_fichier >> x) {

              if (x == "X"){
                plateau[i][j] = 9;
              }
              else if (x == ">"){
                plateau[i][j] = 1;
                etatPions[i-1] = 0;
              }

              else if (x == "<"){
                plateau[i][j] = 1;
                etatPions[i-1] = 1;
              }
              else if (x == "^"){
                plateau[i][j] = 2;
                etatPions[j+4] = 0;
              }
              else if (x == "V"){
                plateau[i][j] = 2;
                etatPions[j+4] = 1;
              }
              else if (x == "."){
                plateau[i][j] = 0;

              }

          }
        }
      }




        decodage = make_tuple(plateau, etatPions);



      lecture_fichier.close();

    }


  }


return decodage;

}

/*
* écrit le déplacement choisi dans un fichier
* @param meilleurCoup le coup choisi par l'IA
*/
void EcritDeplacement(int meilleurCoup){
  std::ofstream reponse;
  reponse.open("resultat.txt");
  reponse << meilleurCoup << ",";
}
