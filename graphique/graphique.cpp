#include "graphique.h"

void gui(int choix){
  int meilleurCoup = 0;
  int tour = 0;
  int score_j1 = 5;
  int score_j2 = 5;

  std::vector<std::vector<std::string>> aff_plateau;
  aff_plateau = std::vector<std::vector<std::string>> (7);
  for ( int i = 0; i < 7; i++ ){
  aff_plateau[i] = std::vector<std::string>(7);




}

  sf::Vector2i positionSouris;
    int t = 0;
    std::vector<std::vector<int>> plateau = creationPlateauInitial();

		std::vector<int> etatPions;
		etatPions = std::vector<int>(10);
		for(int i =0; i<etatPions.size(); i++){
			etatPions[i] = 0;
		}

    std::tuple<std::vector<std::vector<int>>, std::vector<int>, int, int> plateau1;



   sf::RenderWindow window(sf::VideoMode(1000, 1000),  "SFML window" /*,sf::Style::Fullscreen*/);
   int height = window.getSize().y;
   int width = window.getSize().x;

//Joue la musique
   sf::Music music;
music.openFromFile("music.wav");
music.play();


plateau = std::get<0>(LectureGUI(plateau, etatPions, choix, 1));
etatPions = std::get<1>(LectureGUI(plateau, etatPions, choix, 1));






   sf::Texture textureSoldat;
     if (!textureSoldat.loadFromFile("bleuEpee.png"))
     {
       //std::cout << "Erreur lors de l'ouverture de la texture";
     }

     sf::Texture textureSoldat1;
       if (!textureSoldat1.loadFromFile("orangeEpee.png"))
       {
         //std::cout << "Erreur lors de l'ouverture de la texture";
       }
       sf::Texture textureSoldat2;
         if (!textureSoldat2.loadFromFile("bleuArc.png"))
         {
           //std::cout << "Erreur lors de l'ouverture de la texture";
         }
         sf::Texture textureSoldat3;
           if (!textureSoldat3.loadFromFile("orangeArc.png"))
           {
             //std::cout << "Erreur lors de l'ouverture de la texture";
           }
           sf::Texture textureSoldat4;
             if (!textureSoldat4.loadFromFile("bleuCheval.png"))
             {
               //std::cout << "Erreur lors de l'ouverture de la texture";
             }

             sf::Texture textureSoldat5;
               if (!textureSoldat5.loadFromFile("orangeCheval.png"))
               {
                 //std::cout << "Erreur lors de l'ouverture de la texture";
               }
   // Start the game loop
  while (window.isOpen())
  {
      // Process events
      sf::Event event;
      while (window.pollEvent(event))
      {
          // Close window: exit
          if (event.type == sf::Event::Closed)
              window.close();

      }

      //Si on appuie sur ESC
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
{
    menu(window);
}



      // Remplit la fen^etre de blancwindow.clear(Color::White);
      window.clear(sf::Color::White);


      t = t + 1;
      //sf::RectangleShape line(sf::Vector2f(120, 5));
      //line.rotate(45);
      //line.setFillColor(sf::Color(100, 250, 50));
      //window.draw(line);



      sf::Sprite pion1;
      if(abs(ptnDeMouvement(1, 1, etatPions)) == 1){
        pion1.setTexture(textureSoldat);
      }
      else if(abs(ptnDeMouvement(1, 1, etatPions)) == 2){
        pion1.setTexture(textureSoldat2);
      }
      else{
        pion1.setTexture(textureSoldat4);
      }

      pion1.scale(sf::Vector2f(0.5f, 0.5f));




      sf::Sprite pion2;
      if(abs(ptnDeMouvement(2, 1, etatPions)) == 1){
        pion2.setTexture(textureSoldat);
      }
      else if(abs(ptnDeMouvement(2, 1, etatPions)) == 2){
        pion2.setTexture(textureSoldat2);
      }
      else{
        pion2.setTexture(textureSoldat4);
      }
      pion2.scale(sf::Vector2f(0.5f, 0.5f));





      sf::Sprite pion3;
      if(abs(ptnDeMouvement(3, 1, etatPions)) == 1){
        pion3.setTexture(textureSoldat);
      }
      else if(abs(ptnDeMouvement(3, 1, etatPions)) == 2){
        pion3.setTexture(textureSoldat2);
      }
      else{
        pion3.setTexture(textureSoldat4);
      }
      pion3.scale(sf::Vector2f(0.5f, 0.5f));




      sf::Sprite pion4;
      if(abs(ptnDeMouvement(4, 1, etatPions)) == 1){
        pion4.setTexture(textureSoldat);
      }
      else if(abs(ptnDeMouvement(4, 1, etatPions)) == 2){
        pion4.setTexture(textureSoldat2);
      }
      else{
        pion4.setTexture(textureSoldat4);
      }
      pion4.scale(sf::Vector2f(0.5f, 0.5f));




      sf::Sprite pion5;
      if(abs(ptnDeMouvement(5, 1, etatPions)) == 1){
        pion5.setTexture(textureSoldat);
      }
      else if(abs(ptnDeMouvement(5, 1, etatPions)) == 2){
        pion5.setTexture(textureSoldat2);
      }
      else{
        pion5.setTexture(textureSoldat4);
      }
      pion5.scale(sf::Vector2f(0.5f, 0.5f));




      sf::Sprite pion6;
      if(abs(ptnDeMouvement(1, 2, etatPions)) == 1){
        pion6.setTexture(textureSoldat1);
      }
      else if(abs(ptnDeMouvement(1, 2, etatPions)) == 2){
        pion6.setTexture(textureSoldat3);
      }
      else{
        pion6.setTexture(textureSoldat5);
      }
      pion6.scale(sf::Vector2f(0.5f, 0.5f));

      sf::Sprite pion7;
      if(abs(ptnDeMouvement(2, 2, etatPions)) == 1){
        pion7.setTexture(textureSoldat1);
      }
      else if(abs(ptnDeMouvement(2, 2, etatPions)) == 2){
        pion7.setTexture(textureSoldat3);
      }
      else{
        pion7.setTexture(textureSoldat5);
      }
      pion7.scale(sf::Vector2f(0.5f, 0.5f));

      sf::Sprite pion8;
      if(abs(ptnDeMouvement(3, 2, etatPions)) == 1){
        pion8.setTexture(textureSoldat1);
      }
      else if(abs(ptnDeMouvement(3, 2, etatPions)) == 2){
        pion8.setTexture(textureSoldat3);
      }
      else{
        pion8.setTexture(textureSoldat5);
      }
      pion8.scale(sf::Vector2f(0.5f, 0.5f));

      sf::Sprite pion9;
      if(abs(ptnDeMouvement(4, 2, etatPions)) == 1){
        pion9.setTexture(textureSoldat1);
      }
      else if(abs(ptnDeMouvement(4, 2, etatPions)) == 2){
        pion9.setTexture(textureSoldat3);
      }
      else{
        pion9.setTexture(textureSoldat5);
      }
      pion9.scale(sf::Vector2f(0.5f, 0.5f));

      sf::Sprite pion10;
      if(abs(ptnDeMouvement(5, 2, etatPions)) == 1){
        pion10.setTexture(textureSoldat1);
      }
      else if(abs(ptnDeMouvement(5, 2, etatPions)) == 2){
        pion10.setTexture(textureSoldat3);
      }
      else{
        pion10.setTexture(textureSoldat5);
      }
      pion10.scale(sf::Vector2f(0.5f, 0.5f));


      sf::VertexArray lignesVerticale(sf::Lines, 14);



      int i = 0;
      while(i<14){
        lignesVerticale[i].position = sf::Vector2f(((i/2)*width)/7, 0);
        lignesVerticale[i + 1].position = sf::Vector2f(((i/2)*width)/7, height);
            lignesVerticale[i].color = sf::Color::Black;
                lignesVerticale[i+1].color = sf::Color::Black;
        i = i = i + 2;
      }
      sf::VertexArray lignesHorizontale(sf::Lines, 14);
      i = 0;
      while(i<14){
        lignesHorizontale[i].position = sf::Vector2f(0, ((i/2)*height)/7);
        lignesHorizontale[i + 1].position = sf::Vector2f(width, ((i/2)*height)/7);
            lignesHorizontale[i].color = sf::Color::Black;
                lignesHorizontale[i+1].color = sf::Color::Black;
        i = i = i + 2;
      }
      window.draw(lignesHorizontale);
      window.draw(lignesVerticale);

      for(int x = 0; x<plateau.size(); x++){
        for(int y = 0; y<plateau.size(); y++){
          if (plateau[y][x] == 1 ){
            if(y == 1){
              //Si il est sur l'allé
              if(etatPions[0] == 0){
                pion1.setPosition(sf::Vector2f(  (x*width)/7 +((width/7)*0.85)  , (y*height)/7  +((height/7)*0.15)    ));
                  pion1.scale(-1.f,1.f);
              }
              //Si il est sur le retour
              else{
                pion1.setPosition(sf::Vector2f(  (x*width)/7 +((width/7)*0.15)  , (y*height)/7  +((height/7)*0.15)    ));

              }

            }
            else if(y == 2){
              if(etatPions[1] == 0){
                pion2.setPosition(sf::Vector2f( (x*width)/7  +((width/7)*0.85)  , (y*height)/7  +((height/7)*0.15)    ));
                pion2.scale(-1.f,1.f);
              }
              else{
                pion2.setPosition(sf::Vector2f( (x*width)/7  +((width/7)*0.15)  , (y*height)/7  +((height/7)*0.15)    ));


              }

            }
            else if(y == 3){
              if(etatPions[2]==0){
                pion3.setPosition(sf::Vector2f( (x*width)/7 +((width/7)*0.85)  , (y*height)/7   +((height/7)*0.15)   ));
                pion3.scale(-1.f,1.f);
              }
              else{
                pion3.setPosition(sf::Vector2f( (x*width)/7 +((width/7)*0.15)  , (y*height)/7   +((height/7)*0.15)   ));
              }

            }
            else if(y == 4){
              if(etatPions[3]==0){
                pion4.setPosition(sf::Vector2f( (x*width)/7  +((width/7)*0.85) , (y*height)/7   +((height/7)*0.15)   ));
                pion4.scale(-1.f,1.f);
              }
              else{
                pion4.setPosition(sf::Vector2f( (x*width)/7  +((width/7)*0.15) , (y*height)/7   +((height/7)*0.15)   ));
              }

            }
            else if(y == 5){
              if(etatPions[4]==0){
                pion5.setPosition(sf::Vector2f( (x*width)/7  +((width/7)*0.85) , (y*height)/7   +((height/7)*0.15)   ));
                pion5.scale(-1.f,1.f);
              }
              else{
                pion5.setPosition(sf::Vector2f( (x*width)/7  +((width/7)*0.15) , (y*height)/7   +((height/7)*0.15)   ));
              }

            }

          }
          else if (plateau[y][x]==2){
            if(x == 1){
              if(etatPions[5]==0){
                pion6.setPosition(sf::Vector2f( (x*width)/7 +((width/7)*0.70)  ,  (y*height)/7  +((height/7)*0.10)     ));
                pion6.rotate(70);
                pion6.scale(0.8, 0.8);
              }
              else{
                pion6.setPosition(sf::Vector2f( (x*width)/7 +((width/7)*0.15)  ,  (y*height)/7  +((height/7)*0.15)     ));
              }

            }
            else if (x == 2){
              if(etatPions[6]==0){
                pion7.setPosition(sf::Vector2f( (x*width)/7  +((width/7)*0.70) ,  (y*height)/7   +((height/7)*0.10)    ));
                pion7.rotate(70);
                pion7.scale(0.8,0.8);
              }
              else{
                pion7.setPosition(sf::Vector2f( (x*width)/7  +((width/7)*0.15) ,  (y*height)/7   +((height/7)*0.15)    ));
              }

            }
            else if (x == 3){
              if(etatPions[7]==0){
                pion8.setPosition(sf::Vector2f( (x*width)/7  +((width/7)*0.70) ,  (y*height)/7  +((height/7)*0.10)     ));
                pion8.rotate(70);
                pion8.scale(0.8,0.8);
              }
              else{
                pion8.setPosition(sf::Vector2f( (x*width)/7  +((width/7)*0.15) ,  (y*height)/7  +((height/7)*0.15)     ));

              }
            }
            else if (x ==4){
              if(etatPions[8]==0){
                pion9.setPosition(sf::Vector2f( (x*width)/7  +((width/7)*0.70) ,  (y*height)/7  +((height/7)*0.10)     ));
                pion9.rotate(70);
                pion9.scale(0.8,0.8);
              }
              else{
                pion9.setPosition(sf::Vector2f( (x*width)/7  +((width/7)*0.15) ,  (y*height)/7  +((height/7)*0.15)     ));

              }
            }
            else if(x == 5){
              if(etatPions[9]==0){
                pion10.setPosition(sf::Vector2f( (x*width)/7  +((width/7)*0.70) ,  (y*height)/7  +((height/7)*0.10)     ));
                pion10.rotate(70);
                pion10.scale(0.8,0.8);
              }
              else{
                pion10.setPosition(sf::Vector2f( (x*width)/7  +((width/7)*0.15) ,  (y*height)/7  +((height/7)*0.15)     ));

              }
            }
          }
        }
      }

      //Si c'est au joueur 1 et qu'on est contre l'ia
      if(tour%2 == 0 and choix == 1) {

        meilleurCoup =  meilleurCoup6(arbre6(plateau,etatPions));

        plateau1 = deplace(plateau, etatPions, 1, meilleurCoup);

        plateau = std::get<0>(plateau1);
        etatPions = std::get<1>(plateau1);
        score_j1 = score_j1 - std::get<2>(plateau1);
        //SauvegardeGUI(aff_plateau, etatPions, 1, 1);
        EcritDeplacement(meilleurCoup);

        tour = tour + 1;
    }
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
      positionSouris = sf::Mouse::getPosition(window);

        {
          if(tour%2 == 0 and choix == 0){
            if(positionSouris.y < ((height*2)/7) and etatPions[0] < 2){

              plateau1 = deplace(plateau, etatPions, 1,1 );
      				plateau = std::get<0>(plateau1);
      				etatPions = std::get<1>(plateau1);
              score_j1 = score_j1 - std::get<2>(plateau1);
              SauvegardeGUI(aff_plateau, etatPions, 0, 1);
              tour = tour + 1;
            }
            else if(positionSouris.y < ((height*3)/7) and etatPions[1] < 2 ){

              plateau1 = deplace(plateau, etatPions, 1,2 );
      				plateau = std::get<0>(plateau1);
      				etatPions = std::get<1>(plateau1);
              score_j1 = score_j1 - std::get<2>(plateau1);
              SauvegardeGUI(aff_plateau, etatPions, 0, 1);
              tour = tour + 1;
            }
            else if (positionSouris.y < ((height*4)/7) and etatPions[2] < 2 ){

              plateau1 = deplace(plateau, etatPions, 1,3 );
      				plateau = std::get<0>(plateau1);
      				etatPions = std::get<1>(plateau1);
              score_j1 = score_j1 - std::get<2>(plateau1);
              SauvegardeGUI(aff_plateau, etatPions, 0, 1);
              tour = tour + 1;
            }
            else if (positionSouris.y < ((height*5)/7) and etatPions[3] < 2 ){

              plateau1 = deplace(plateau, etatPions, 1,4 );
      				plateau = std::get<0>(plateau1);
      				etatPions = std::get<1>(plateau1);
              score_j1 = score_j1 - std::get<2>(plateau1);
              SauvegardeGUI(aff_plateau, etatPions, 0, 1);
              tour = tour + 1;
            }
            else if (positionSouris.y < ((height*6)/7) and etatPions[4] < 2){

              plateau1 = deplace(plateau, etatPions, 1,5 );
      				plateau = std::get<0>(plateau1);
      				etatPions = std::get<1>(plateau1);
              score_j1 = score_j1 - std::get<2>(plateau1);
              SauvegardeGUI(aff_plateau, etatPions, 0, 1);
              tour = tour + 1;
            }
          }


          else if (tour % 2 == 1){


            if(positionSouris.x < ((width*2)/7) and etatPions[5] < 2 ){

              plateau1 = deplace(plateau, etatPions, 2,1 );

      				plateau = std::get<0>(plateau1);
      				etatPions = std::get<1>(plateau1);
              score_j2 = score_j2 - std::get<3>(plateau1);
              SauvegardeGUI(aff_plateau, etatPions, 0, 2);
              tour = tour + 1;
            }
            else if(positionSouris.x < ((width*3)/7) and etatPions[6] < 2){

              plateau1 = deplace(plateau, etatPions, 2,2 );
      				plateau = std::get<0>(plateau1);
      				etatPions = std::get<1>(plateau1);
              score_j2 = score_j2 - std::get<3>(plateau1);
              SauvegardeGUI(aff_plateau, etatPions, 0, 2);
              tour = tour + 1;
            }
            else if (positionSouris.x < ((width*4)/7) and etatPions[7] < 2){

              plateau1 = deplace(plateau, etatPions, 2,3 );
      				plateau = std::get<0>(plateau1);
      				etatPions = std::get<1>(plateau1);
              score_j2 = score_j2 - std::get<3>(plateau1);
              SauvegardeGUI(aff_plateau, etatPions, 0, 2);
              tour = tour + 1;
            }
            else if (positionSouris.x < ((width*5)/7) and etatPions[8] < 2){

              plateau1 = deplace(plateau, etatPions, 2,4 );
      				plateau = std::get<0>(plateau1);
      				etatPions = std::get<1>(plateau1);
              score_j2 = score_j2 - std::get<3>(plateau1);
              SauvegardeGUI(aff_plateau, etatPions, 0, 2);
              tour = tour + 1;
            }
            else if (positionSouris.x < ((width*6)/7) and etatPions[9] < 2){

              plateau1 = deplace(plateau, etatPions, 2,5 );
      				plateau = std::get<0>(plateau1);
      				etatPions = std::get<1>(plateau1);
              score_j2 = score_j2 - std::get<3>(plateau1);
              SauvegardeGUI(aff_plateau, etatPions, 0, 2);
              tour = tour + 1;
            }


                  std::cout << "score_j1" << '\n';
                  std::cout << score_j1 << '\n';
                  std::cout << "score_j2" << '\n';
                  std::cout << score_j2 << '\n';






                  std::cout << "Le joueur 1 a un scoring de:" << fnErreur(plateau, etatPions) << "\n";

          }
          std::this_thread::sleep_for(std::chrono::nanoseconds(200000000));
        }

      }
      //window.draw(soldat);
      window.draw(pion1);
      window.draw(pion2);
      window.draw(pion3);
      window.draw(pion4);
      window.draw(pion5);
      window.draw(pion6);
      window.draw(pion7);
      window.draw(pion8);
      window.draw(pion9);
      window.draw(pion10);

      pastilleCouleurJoueur(window, tour, score_j1, score_j2);
      for(int i = 0; i< 7;i++){
          for(int j=0; j<7; j++){
            if (plateau[i][j]==1 and etatPions[i-1]==0){
              aff_plateau[i][j] = "> ";
            }
            else if (plateau[i][j]==1 and etatPions[i-1]==1){
              aff_plateau[i][j] = "< ";
            }
            else if (plateau[i][j]==2 and etatPions[j+4]==0){
              aff_plateau[i][j] = "^ ";
            }
            else if (plateau[i][j]==2 and etatPions[j+4]==1){
              aff_plateau[i][j] = "V ";

            }
            else if (plateau[i][j]!=2 and plateau[i][j]!=1 and plateau[i][j]!= 9){
              aff_plateau[i][j] = ". ";
            }
            else if (plateau[i][j]==1 and etatPions[i-1]==2){
              aff_plateau[i][j] = "< ";
            }
            else if (plateau[i][j]==2 and etatPions[j+4]==2){
              aff_plateau[i][j] = "V ";

            }
            else if (plateau[i][j]== 9){
              aff_plateau[i][j] = "X ";

            }
          }
        }


      window.display();





  }

	//jeu(plateau, etatPions);




}

void menu(sf::RenderWindow &window){
  sf::Font font;
if (!font.loadFromFile("font.ttf"))
{
  // error...
}
    window.clear(sf::Color::White);
  sf::Text text;
  text.setFont(font);
  text.setCharacterSize(24);
  text.setFillColor(sf::Color::Red);
  text.setStyle(sf::Text::Bold | sf::Text::Underlined);
  text.setString("Esc: Quitter\nFleche gauche: Retour");
  text.setPosition(sf::Vector2f(  window.getSize().x/2   , window.getSize().y/2    ));
  window.draw(text);
  window.display();
  std::this_thread::sleep_for(std::chrono::nanoseconds(400000000));
  int decision = 0;
  while(decision == 0){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
{
    decision = 1;
    window.close();
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
{
decision = 1;
}
  }

}


void pastilleCouleurJoueur(sf::RenderWindow &window, int tour, int score_j1, int score_j2){
  sf::Font font;
if (!font.loadFromFile("font.ttf"))
{
  // error...
}
  sf::Text text;
  text.setFont(font);
  text.setCharacterSize(15);
  text.setFillColor(sf::Color::Red);
  text.setStyle(sf::Text::Bold | sf::Text::Underlined);
  if(tour%2 == 0 and score_j1 > 1){
    text.setString("Joueur 1");
  }
  else if(tour%2 == 1 and score_j2 > 1){
    text.setString("Joueur 2");

  }
  else if(score_j1 == 1){
    text.setString("Joueur 1 a gagné");
  }
  else if(score_j2 == 1){
    text.setString("Joueur 2 a gagné");
  }
  text.setPosition(sf::Vector2f(  0   , 10   ));
  window.draw(text);

}
