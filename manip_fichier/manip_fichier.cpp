#include "manip_fichier.h"
# include <fstream>

/*
* écrit l'état actuel du plateau dans un fichier
* @param aff_plateau le plateau d'affichage
* @return plateau qui retourne l'état du jeu suite au déplacement.
*/

void SauvegardeGUI(std::vector<std::vector<std::string>> aff_plateau, int choix){
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
}
