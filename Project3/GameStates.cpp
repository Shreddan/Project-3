#include "GameStates.h"



GameStates::GameStates()
{
	this->GameState = MainMenu;
	
	
	
}


GameStates::~GameStates()
{
}



sf::View GameStates::updateView(sf::View& view1, sf::Sprite sprite1)
{
	view1.setCenter(sprite1.getPosition());

	return view1;
}
void GameStates::GameLoop(Input& input, sf::Sprite& sprite1, sf::RenderWindow& window, TileMap& map, sf::Font font1,  AnimationManager& animMan, sf::View& defview, int height, int width)
{

	defview = window.getDefaultView();

	pCameraWidth = 200.f;
	pCameraHeight = pCameraWidth * 9 / 16;

	sf::View view1(sf::FloatRect(pCameraWidth, pCameraHeight, width, height));
	view1.zoom(0.5f);


	animMan.addFrames1(animMan.frames, sf::IntRect(32, 32, 32, 32), sf::IntRect(0, 64, 32, 32), sf::IntRect(32, 64, 32, 32), sf::IntRect(0, 0, 32, 32), sf::IntRect(32, 0, 32, 32), sf::IntRect(0, 32, 32, 32), sf::IntRect(0, 128, 32, 32), sf::IntRect(32, 128, 32, 32), sf::IntRect(0, 96, 32, 32), sf::IntRect(32, 96, 32, 32));
	animMan.addFrames1(animMan.frames1, sf::IntRect(32, 512, 32, 32), sf::IntRect(0, 544, 32, 32), sf::IntRect(32, 544, 32, 32), sf::IntRect(0, 480, 32, 32), sf::IntRect(0, 512, 32, 32), sf::IntRect(32, 480, 32, 32), sf::IntRect(0, 576, 32, 32), sf::IntRect(32, 576, 32, 32), sf::IntRect(0, 608, 32, 32), sf::IntRect(32, 608, 32, 32));


	while (window.isOpen())
	{
		sf::Event event;



		while (window.pollEvent(event))
		{
			
			if (GameState == MainMenu)
			{
				input.MenuInput(input.startSelected, input.loadSelected, input.optionsSelected);
			}
			else if (GameState == GameScreen)
			{
				input.Inputs(sprite1, window, input.dirX, input.dirY, height, width);
				updateView(view1, sprite1);
			}
			


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && GameState == MainMenu && input.startSelected)
			{
				GameState = GameScreen;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && GameState == GameScreen)
			{
				GameState = QuestScreen;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && GameState == QuestScreen)
			{
				GameState = GameScreen;
			}

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		DrawState(sprite1, input, window, map, font1, view1, defview);
		
		
		window.display();

	}

}


void GameStates::DrawState(sf::Sprite& sprite1, Input& input, sf::RenderWindow& window, TileMap map, sf::Font font1, sf::View view1, sf::View defview)
{


	switch (GameState)
	{

		case MainMenu:
		{
		

			sf::RectangleShape menuRect(sf::Vector2f(1200.f, 650.f));
			menuRect.setFillColor(sf::Color(160, 160, 160));
			menuRect.setPosition(175.f, 80.f);

			sf::RectangleShape startButton(sf::Vector2f(500.f, 100.f));
			startButton.setFillColor(sf::Color(100, 100, 100));
			startButton.setOutlineColor(sf::Color(sf::Color::Green));
			startButton.setOutlineThickness(3.f);
			startButton.setPosition(500.f, 200.f);

			sf::Text start;
			start.setFont(font1);
			start.setString("Start");
			start.setCharacterSize(60);
			start.setFillColor(sf::Color::Black);
			start.setPosition(700.f, 210.f);

			sf::RectangleShape loadButton(sf::Vector2f(500.f, 100.f));
			loadButton.setFillColor(sf::Color(100, 100, 100));
			loadButton.setOutlineColor(sf::Color(sf::Color::Green));
			loadButton.setPosition(500.f, 350.f);

			sf::Text load;
			load.setFont(font1);
			load.setString("Load");
			load.setCharacterSize(60);
			load.setFillColor(sf::Color::Black);
			load.setPosition(700.f, 360.f);

			sf::RectangleShape optionsButton(sf::Vector2f(500.f, 100.f));
			optionsButton.setFillColor(sf::Color(100, 100, 100));
			optionsButton.setOutlineColor(sf::Color(sf::Color::Green));
			optionsButton.setPosition(500.f, 500.f);

			sf::Text options;
			options.setFont(font1);
			options.setString("Options");
			options.setCharacterSize(60);
			options.setFillColor(sf::Color::Black);
			options.setPosition(685.f, 510.f);

			
			if (input.startSelected)
			{
				startButton.setOutlineThickness(3.f);
			}
			else if (input.loadSelected)
			{
				startButton.setOutlineThickness(0);
				loadButton.setOutlineThickness(3.f);
			}
			else if (input.optionsSelected)
			{
				startButton.setOutlineThickness(0);
				loadButton.setOutlineThickness(0);
				optionsButton.setOutlineThickness(3.f);	
			}
			



			window.clear();
			window.draw(menuRect);
			window.draw(startButton);
			window.draw(loadButton);
			window.draw(optionsButton);
			window.draw(start);
			window.draw(load);
			window.draw(options);

			break;
		}

		case ThroneRoom:
		{

		}

		case GameScreen:
		{
			

			
			window.setView(view1);
			window.clear();
			window.draw(map);
			window.draw(sprite1);
			
			break;
		}

		case QuestScreen:
		{
			sf::Text quest;
			quest.setFont(font1);
			quest.setFillColor(sf::Color(sf::Color(212, 175, 55)));
			quest.setString("Quest Log");
			quest.setCharacterSize(70);
			quest.setPosition(600.f, 10.f);

			sf::Text inprog;
			inprog.setFont(font1);
			inprog.setFillColor(sf::Color(sf::Color(0, 100, 0)));
			inprog.setString("In Progress");
			inprog.setCharacterSize(50);
			inprog.setPosition(100.f, 100.f);
			inprog.setStyle(sf::Text::Underlined);


			window.clear(sf::Color(sf::Color(220, 220, 220)));
			window.setView(defview);
			window.draw(quest);
			window.draw(inprog);

			break;
		}
	}
}



