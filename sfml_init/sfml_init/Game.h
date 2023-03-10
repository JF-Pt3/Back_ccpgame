#pragma once
#include <iostream>
#include <vector> // Para guardar enemies 
#include <ctime>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

//Estes includes estavam inicialmente declarados no main.cpp, foram movidos para estes Game.h,
//porque estes c?digos Graphis.hpp,...,Network.hpp t?m muito c?digo e se os estivermos a incluir no main.cpp, ao longo do tempo aumenta o tempo de compila??o
// Se estivermos a criar um grande jogo, complexo, existem os chamados pre-compiled headers

/*
	Class that acts as the game engine
	Basically is a class where we define all functions,functionalities of game	
*/




class Game
{
private:
	//Vari?veis:

	//Window:
	sf::RenderWindow* window; //? um apontador para a janela
	sf::VideoMode videoMode;
	sf::Event ev;// o ev tem uma inicializa??o deafault...

	//Mouse Positions:
	sf::Vector2i mousePosWindow;//Most of operations in SFML are done with float, so we will start to use Vector2f (two floats for mouse positions...)
	sf::Vector2f mousePosView;

	//Resources
	sf::Font font;

	//Text
	sf::Text uiText;

	//Game logic
	
	bool endGame;
	unsigned points; // only positive points :-)
	int health;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	bool mouseHeld;

	//Game Objects
	std::vector<sf::RectangleShape> enemies; // Estou a criar um vector que ir? guardar dados do tipo "sf::RectangleShape", que ? o tipo de dados dos enemies!
	sf::RectangleShape enemy;//


	//Cria??o de algumas fun??es que n?o pretendemos dar acesso...
	void initializeVariables();
	void initWindow();	
	void initFonts();
	void initText();
	void initEnemies();

public:
	//Contructors and Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;// enquanto a janela est? aberta.. ? porque a janela est? em "running"
	const bool getEndGame() const;

	//Our Functions:
	void spawnEnemy(); // para criar enemies ahahahah :-)
	void pollEvents();
	void updateMousePositions();
	void updateText();
	void updateEnemies();
	void update();
	void renderText(sf::RenderTarget& target);//Often we don't need to render to main window, sometimes we can render to a view...
	void renderEnemies(sf::RenderTarget& target);
	void render();
};

