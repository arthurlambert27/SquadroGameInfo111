#include "manipulation_tableau.h"

/*
 * Vérifie qu'un tableau est remplie de zéro ou non
 * Complexité de n. n étant la taille du tableau.
 * @param tab le tableau
 * @return true si le tableau est vide et false sinon
 * O(n)
 */
bool tabIsNul(std::vector<int> tab){
	for(auto i : tab){
		if(i != 0)
			return false;
		}
		return true;
	}
