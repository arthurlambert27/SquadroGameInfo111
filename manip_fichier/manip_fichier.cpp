#include "manip_fichier.h"
# include <fstream>

/*
* écrit l'état actuel du plateau dans un fichier
* @param aff_plateau le plateau d'affichage
* @return plateau qui retourne l'état du jeu suite au déplacement.
*/

void SauvegardeGUI(std::vector<std::vector<std::string>> aff_plateau,std::vector<int> etatPions, int choix){
  if(choix == 1){
    if( remove( "sauvegarde.txt" ) != 0 )
      perror( "le fichier n'existe pas" );
    else
      puts( "fichier effacé" );
    std::ofstream fichier; // Déclaration
    fichier.open("sauvegarde.txt");
    // Ouverture
    for(int i = 0; i< 7;i++){
        for(int j=0; j<7; j++){
          fichier << aff_plateau[i][j]; // Écriture;

          }
    fichier << std::endl;
  }
    fichier.close();
    }
  if(choix == 3){
    if( remove( "etat_jeu.txt" ) != 0 )
      perror( "le fichier n'existe pas" );
    else
      puts( "fichier effacé" );
      std::ofstream fichier1;
      fichier1.open("etat_jeu.txt");

      for(int i = 1; i<6; i++){
        fichier1 <<  ptnDeMouvement(i, 1, etatPions) << " ";

  		}
      fichier1 << std::endl;
      for(int i = 0; i< 7;i++){
          for(int j=0; j<7; j++){
            fichier1 << aff_plateau[i][j]; // Écriture;

            }
            fichier1 << std::endl;
          }
          fichier1.close();
        }


}

/*
* écrit le déplacement choisi dans un fichier
* @param meilleurCoup le coup choisi par l'IA
*/
void EcritDeplacement(int meilleurCoup){
  std::ofstream reponse; // Déclaration
  reponse.open("resultat.txt");
  reponse << meilleurCoup << ",";
}
