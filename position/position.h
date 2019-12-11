#ifndef POSITION_H
#define POSITION_H

#include <vector>
#include <math.h>

#include "../manipulation_tableau/manipulation_tableau.h"
#include "../mouvement/mouvement.h"



/*
 * Permet de localiser ou sont les pions (de 0 a 9 pour le joueur 1)(de 10 a 19 pour le joueur 2) Par exemple, la position du deuxième pions du joueur 1 est l'élément 2 et 3'
 * @param plateau Etat du jeu
 * @return posPions un tableau des positions des pions
*/
std::vector<int> posPions(std::vector<std::vector<int>> plateau);

/*
* Permet de voir si il y a un jeton dans les 3 cases devant une pièce.
* Les données de retour sont sur la zone d'un tableau de 3 entier qui reprèsente les 3 case devant le pion dans sa direction.
* @param plateau
* @param etatPions
* @param joueur
* @param pions
* @return un tableau de int avec 0 si pas de pion et 1 si un pion
*/
std::vector<int> pionsDevant(std::vector<std::vector<int>> plateau, std::vector<int> etatPions, int joueur, int noPion);

/*
* Permet de voir si il y a un pion devant la zone de mouvement d'un pion
* Utilise la fonction pionsDevant
* @param plateau
* @param etatPions
* @param joueur
* @param pions
* @return un tableau de int avec 0 si pas de pion et 1 si un pion
*/
std::vector<int> pionsDevantZoneMouvement(std::vector<std::vector<int>> plateau, std::vector<int> etatPions, int joueur, int noPion);


#endif
