#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H



#include <vector>
#include <tuple>


#include "../affichage/affichage.h"
#include "../mouvement/mouvement.h"
#include "../deplacement/deplacement.h"
#include "../initialisation/initialisation.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <chrono>
#include <thread>



void gui();
void menu(sf::RenderWindow &window);



#endif
