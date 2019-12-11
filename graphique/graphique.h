#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H



#include <vector>
#include <tuple>

#include "../manip_fichier/manip_fichier.h"
#include "../affichage/affichage.h"
#include "../mouvement/mouvement.h"
#include "../deplacement/deplacement.h"
#include "../initialisation/initialisation.h"
#include "../ia/ia.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <chrono>
#include <thread>


/*
Cette fonction permet l'affichage en mode graphique. Elle utilise la libraire sfml
@ param choix; entier soit 1 soit 0. 1 correspond a une partie contre l'ia et 0 correspond a une partie humain contre humain
*/
void gui(int choix);

/*
Cette fonction permet de faire le menu d'une partie GRAPHIQUE_H
@param window qui est la fenetre ou doit etre le menu
*/
void menu(sf::RenderWindow &window);

/*
Cette fonction s'occupe d'afficher le joueur qui doit jouer en haut a gauche de la fenetre principale
Elle permet également d'afficher le nom du joueur qui a gagné
@param window qui est la fenetre ou afficher la pastille
@param tour qui permet de savoir le joueur qui doit jouer
@param score_j1 qui est le score du joueur 1
@param score_j2 qui est le score du joueur 2
*/
void pastilleCouleurJoueur(sf::RenderWindow &window, int tour, int score_j1, int score_j2);



#endif
