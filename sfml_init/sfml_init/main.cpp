#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace std;
using namespace sf; // para desbloquer as rotinas do SFML

int main() {

	//cout << "Hello from SFML" << endl;
	//system("pause");
	RenderWindow window(VideoMode(640, 480), "My first Game", Style::Titlebar | Style::Close); // Style::Titlebar permite a possibilidade de ter icones para fechar/minimizar etc | Style::Close->>> neste caso para fechar

	//O window � uma esp�cie de listener, isto �, mant�m o registo das coisas
	//Imagina tudo o que � clicar no rato, mexer no rato, teclado dentro l� da janela, vai tomando registo disto tudo!

	Event ev;

	//Game loop:

	while (window.isOpen()) {

		//Event polling
		while (window.pollEvent(ev)) {// enquanto estivermos a ir buscar eventos da window, vamos guardando dentro da vari�vel ev
			// depois esses eventos guardados no ev podem ser usados aqui dentro

			switch (ev.type) {// existem v�rios tipos de eventos: do rato, teclado etc...
				//Event:: vamos buscar v�rios eventos que se queira
			case Event::Closed:// quando ele sente que carregaste no bot�o para fechar,ele n�o fecha a janela, temos de a fechar com a instru��o "window.close()"
				window.close();
				break;

			case Event::KeyPressed:
				if (ev.key.code == Keyboard::Escape)
					window.close();
				break;

			}



		}
		 
		//Cada frame de um jogo funciona assim, fazemos o polling de events, faz-se update e depois faz-se o render
		//Por exemplo uma personagem move-se, faz-se update e depois o render.
		//update


		
		//Render
		window.clear(Color::Blue);//clear all the frame

		//Draw your game
		window.display(); // tell app that window is donw drawing

	}

	//End app




	return 0;
}