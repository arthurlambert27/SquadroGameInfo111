#include "affichage.h"


/*
* Affiche le plateau du jeu
* @param plateau Plateau du jeu a afficher
*/
void affichePlateau(std::vector<std::vector<int>> plateau){
    for(int i = 0; i< 7;i++){
        for(int j=0; j<7; j++){
            std::cout << plateau[i][j];
        }
        std::cout << std::endl;
    }
}


/*
* Affiche le plateau du jeu
* @param plateau Plateau du jeu a afficher
* @param etatPions tableau qui contient l'etat des pions
*/

void affichePlateauV3(std::vector<std::vector<int>> plateau,std::vector<std::vector<std::string>> aff_plateau, std::vector<int> etatPions){
  std::vector<int> position = posPions(plateau);
  int PionX =0;
  int PionY = 0;
  for(int i = 0; i< 7;i++){
      for(int j=0; j<7; j++){
        if (plateau[i][j]==1 and etatPions[i-1]==0){
          aff_plateau[i][j] = ">";
        }
        else if (plateau[i][j]==1 and etatPions[i-1]==1){
          aff_plateau[i][j] = "<";
        }
        else if (plateau[i][j]==2 and etatPions[j+4]==0){
          aff_plateau[i][j] = "A";
        }
        else if (plateau[i][j]==2 and etatPions[j+4]==1){
          aff_plateau[i][j] = "V";

        }
        else if (plateau[i][j]!=2 or plateau[i][j]!=1){
          aff_plateau[i][j] = ".";
        }
        else if (plateau[i][j]==1 and etatPions[i-1]==0){
          aff_plateau[i][j] = "O";
        }
        else if (plateau[i][j]==2 and etatPions[j+4]==2){
          aff_plateau[i][j] = "O";

        }

      std::cout << std::endl;
  }
  }
  for(int k = 0; k<etatPions.size(); k++){
        std::cout << etatPions[k];
        std::cout << std::endl;
      }

      for(int i = 0; i< 7;i++){
                for(int j=0; j<7; j++){
                    std::cout << plateau[i][j];
                }
                std::cout << std::endl;
            }


          std::cout << fnErreur(plateau, etatPions) << "\n";


  std::cout << "-----------------------------" << '\n';
  std::cout << "| "<< aff_plateau[0][0] << " | "<<  aff_plateau[0][1] << " | "<< aff_plateau[0][2] << " | "<<  aff_plateau[0][3] << " | "<< aff_plateau[0][4] << " | "<< aff_plateau[0][5] << " | "<< aff_plateau[0][6] << " | "<<'\n';
  std::cout << "|   |   |   |   |   |   |   |" << '\n';
  std::cout << "-----------------------------" << '\n';
  std::cout << "| "<< aff_plateau[1][0] << " | "<<  aff_plateau[1][1] << " | "<< aff_plateau[1][2] << " | "<<  aff_plateau[1][3] << " | "<< aff_plateau[1][4] << " | "<< aff_plateau[1][5] << " | "<< aff_plateau[1][6] << " | "<<'\n';
  std::cout << "|   |   |   |   |   |   |   |" << '\n';
  std::cout << "-----------------------------" << '\n';
  std::cout << "| "<< aff_plateau[2][0] << " | "<<  aff_plateau[2][1] << " | "<< aff_plateau[2][2] << " | "<<  aff_plateau[2][3] << " | "<< aff_plateau[2][4] << " | "<< aff_plateau[2][5] << " | "<< aff_plateau[2][6] << " | "<<'\n';
  std::cout << "|   |   |   |   |   |   |   |" << '\n';
  std::cout << "-----------------------------" << '\n';
  std::cout << "| "<< aff_plateau[3][0] << " | "<<  aff_plateau[3][1] << " | "<< aff_plateau[3][2] << " | "<<  aff_plateau[3][3] << " | "<< aff_plateau[3][4] << " | "<< aff_plateau[3][5] << " | "<< aff_plateau[3][6] << " | "<<'\n';
  std::cout << "|   |   |   |   |   |   |   |" << '\n';
  std::cout << "-----------------------------" << '\n';
  std::cout << "| "<< aff_plateau[4][0] << " | "<<  aff_plateau[4][1] << " | "<< aff_plateau[4][2] << " | "<<  aff_plateau[4][3] << " | "<< aff_plateau[4][4] << " | "<< aff_plateau[4][5] << " | "<< aff_plateau[4][6] << " | "<<'\n';
  std::cout << "|   |   |   |   |   |   |   |" << '\n';
  std::cout << "-----------------------------" << '\n';
  std::cout << "| "<< aff_plateau[5][0] << " | "<<  aff_plateau[5][1] << " | "<< aff_plateau[5][2] << " | "<<  aff_plateau[5][3] << " | "<< aff_plateau[5][4] << " | "<< aff_plateau[5][5] << " | "<< aff_plateau[5][6] << " | "<<'\n';
  std::cout << "|   |   |   |   |   |   |   |" << '\n';
  std::cout << "-----------------------------" << '\n';
  std::cout << "| "<< aff_plateau[6][0] << " | "<<  aff_plateau[6][1] << " | "<< aff_plateau[6][2] << " | "<<  aff_plateau[6][3] << " | "<< aff_plateau[6][4] << " | "<< aff_plateau[6][5] << " | "<< aff_plateau[6][6] << " | "<<'\n';
  std::cout << "|   |   |   |   |   |   |   |" << '\n';
  std::cout << "-----------------------------" << '\n';
}
