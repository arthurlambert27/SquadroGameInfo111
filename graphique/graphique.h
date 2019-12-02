#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H



#include <vector>
#include <tuple>


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



void gui(int choix);
void menu(sf::RenderWindow &window);
void pastilleCouleurJoueur(sf::RenderWindow &window, int tour, int score_j1, int score_j2);



#endif
