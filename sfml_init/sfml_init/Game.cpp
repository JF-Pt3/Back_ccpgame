#include "Game.h"

void Game::initializeVariables()
{
	this->window = nullptr; // o window � do tipo apontador( ver as vari�veis do Game.h)
}

void Game::initWindow()
{
	this->videoMode.height = 600;// mais f�cil fazer o ajuste das dimens�es do ecr� assim...
	this->videoMode.width = 800;
	//this->videoMode.getDesktopMode; para ir buscar a resolu��o do ecr� do pc directamente...
	this->window = new sf::RenderWindow(this->videoMode, "Game One", sf::Style::Titlebar | sf::Style::Close);
}

Game::Game() {//Defini��o do construtor
	// Vai permitir chamar as fun��es que v�o fazer as "coisas" aparecer no ecr�!...
	/// � necess�rio ter esta ordem, porque n�o vamos pretender inicializar o ecr� e s� depois inicializar vari�veis....
	this->initializeVariables();
	this->initWindow();
}

Game::~Game() {//Defini��o do destructor
	delete this->window;// para evitar um grande memory leak...
}

const bool Game::running() const
{
	return this->window->isOpen();
}


//Functions
void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev)) {// quando se invoca o "this" estamos a ir buscar vari�veis,fun��es etc que pertencem � classe do objecto Game, que est� definida no Game.h
		
		switch (this->ev.type) {
		case sf::Event::Closed:
			this->window->close();			
			break;

		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;

		}

	}
}


void Game::update()
{
	this->pollEvents();// aqui dentro vamos chamar o pollEvents( � a tal fun��o que faz a mec�nica de tratamento de eventos no nosso jogo)
	

}

void Game::render()
{
	/*
		- clear the old frame;
		- render the objects;
		- display frame in our window;
		Renders the game objects
	*/
	this->window->clear(sf::Color(255,0,0,255));// 1� limpa-se a janela, pintado-a de vermelho...

	//Pintam-se os objectos na janelinha...
	this->window->display(); // 2� Faz-se o display
}




