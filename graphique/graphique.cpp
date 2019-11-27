#include "graphique.h"

void gui(){
  int tour = 0;
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


   sf::Texture textureSoldat;
     if (!textureSoldat.loadFromFile("bleuEpee.png"));
     {
       //std::cout << "Erreur lors de l'ouverture de la texture";
     }

     sf::Texture textureSoldat1;
       if (!textureSoldat1.loadFromFile("orangeEpee.png"));
       {
         //std::cout << "Erreur lors de l'ouverture de la texture";
       }
       sf::Texture textureSoldat2;
         if (!textureSoldat2.loadFromFile("bleuArc.png"));
         {
           //std::cout << "Erreur lors de l'ouverture de la texture";
         }
         sf::Texture textureSoldat3;
           if (!textureSoldat3.loadFromFile("orangeArc.png"));
           {
             //std::cout << "Erreur lors de l'ouverture de la texture";
           }
           sf::Texture textureSoldat4;
             if (!textureSoldat4.loadFromFile("bleuCheval.png"));
             {
               //std::cout << "Erreur lors de l'ouverture de la texture";
             }

             sf::Texture textureSoldat5;
               if (!textureSoldat5.loadFromFile("orangeCheval.png"));
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

      pion1.scale(sf::Vector2f(0.3f, 0.3f));




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
      pion2.scale(sf::Vector2f(0.3f, 0.3f));





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
      pion3.scale(sf::Vector2f(0.3f, 0.3f));




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
      pion4.scale(sf::Vector2f(0.3f, 0.3f));




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
      pion5.scale(sf::Vector2f(0.3f, 0.3f));




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
      pion6.scale(sf::Vector2f(0.3f, 0.3f));

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
      pion7.scale(sf::Vector2f(0.3f, 0.3f));

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
      pion8.scale(sf::Vector2f(0.3f, 0.3f));

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
      pion9.scale(sf::Vector2f(0.3f, 0.3f));

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
      pion10.scale(sf::Vector2f(0.3f, 0.3f));


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

              pion1.setPosition(sf::Vector2f(  (x*width)/7   , (y*height)/7     ));
            }
            else if(y == 2){

              pion2.setPosition(sf::Vector2f( (x*width)/7   , (y*height)/7     ));
            }
            else if(y == 3){

              pion3.setPosition(sf::Vector2f( (x*width)/7   , (y*height)/7     ));
            }
            else if(y == 4){

              pion4.setPosition(sf::Vector2f( (x*width)/7   , (y*height)/7     ));
            }
            else if(y == 5){

              pion5.setPosition(sf::Vector2f( (x*width)/7   , (y*height)/7     ));
            }

          }
          else if (plateau[y][x]==2){
            if(x == 1){
              pion6.setPosition(sf::Vector2f( (x*width)/7   ,  (y*height)/7     ));
            }
            else if (x == 2){
              pion7.setPosition(sf::Vector2f( (x*width)/7   ,  (y*height)/7     ));
            }
            else if (x == 3){
              pion8.setPosition(sf::Vector2f( (x*width)/7   ,  (y*height)/7     ));
            }
            else if (x ==4){
              pion9.setPosition(sf::Vector2f( (x*width)/7   ,  (y*height)/7     ));
            }
            else if(x == 5){
              pion10.setPosition(sf::Vector2f( (x*width)/7   ,  (y*height)/7     ));
            }
          }
        }
      }

      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
      positionSouris = sf::Mouse::getPosition(window);

        {
          if(tour%2 == 0){
            if(positionSouris.y < ((height*2)/7)  ){
              plateau1 = deplace(plateau, etatPions, 1,1 );
      				plateau = std::get<0>(plateau1);
      				etatPions = std::get<1>(plateau1);
              tour = tour + 1;
            }
            else if(positionSouris.y < ((height*3)/7)){
              plateau1 = deplace(plateau, etatPions, 1,2 );
      				plateau = std::get<0>(plateau1);
      				etatPions = std::get<1>(plateau1);
              tour = tour + 1;
            }
            else if (positionSouris.y < ((height*4)/7)){
              plateau1 = deplace(plateau, etatPions, 1,3 );
      				plateau = std::get<0>(plateau1);
      				etatPions = std::get<1>(plateau1);
              tour = tour + 1;
            }
            else if (positionSouris.y < ((height*5)/7)){
              plateau1 = deplace(plateau, etatPions, 1,4 );
      				plateau = std::get<0>(plateau1);
      				etatPions = std::get<1>(plateau1);
              tour = tour + 1;
            }
            else if (positionSouris.y < ((height*6)/7)){
              plateau1 = deplace(plateau, etatPions, 1,5 );
      				plateau = std::get<0>(plateau1);
      				etatPions = std::get<1>(plateau1);
              tour = tour + 1;
            }
          }
          else if (tour % 2 == 1){


            if(positionSouris.x < ((width*2)/7)  ){
              plateau1 = deplace(plateau, etatPions, 2,1 );
      				plateau = std::get<0>(plateau1);
      				etatPions = std::get<1>(plateau1);
              tour = tour + 1;
            }
            else if(positionSouris.x < ((width*3)/7)){
              plateau1 = deplace(plateau, etatPions, 2,2 );
      				plateau = std::get<0>(plateau1);
      				etatPions = std::get<1>(plateau1);
              tour = tour + 1;
            }
            else if (positionSouris.x < ((width*4)/7)){
              plateau1 = deplace(plateau, etatPions, 2,3 );
      				plateau = std::get<0>(plateau1);
      				etatPions = std::get<1>(plateau1);
              tour = tour + 1;
            }
            else if (positionSouris.x < ((width*5)/7)){
              plateau1 = deplace(plateau, etatPions, 2,4 );
      				plateau = std::get<0>(plateau1);
      				etatPions = std::get<1>(plateau1);
              tour = tour + 1;
            }
            else if (positionSouris.x < ((width*6)/7)){
              plateau1 = deplace(plateau, etatPions, 2,5 );
      				plateau = std::get<0>(plateau1);
      				etatPions = std::get<1>(plateau1);
              tour = tour + 1;
            }








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
      window.display();





  }

	//jeu(plateau, etatPions);




}
