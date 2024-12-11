// TrabalhoATC.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.

/*

**TIPOS DE DADOS DO PDCURSES**

WINDOW *  pointer to screen representation
SCREEN *  pointer to terminal descriptor
bool      boolean data type
chtype    representation of a character in a window
cchar_t   the wide-character equivalent of chtype
attr_t    for WA_-style attributes

*/

#include <iostream>
#include <curses.h>
#include "RenderRegion.h"
#include <Windows.h>
#include "Game.h"
#include "GameLogic.h"

int main()
{
	initscr();
	start_color();
	noecho();
	cbreak();
	curs_set(0);

	init_pair(1, COLOR_YELLOW, COLOR_BLACK); // Par 1: Cor de fundo preta, cor de texto amarela
	init_pair(2, COLOR_BLUE, COLOR_BLACK);   // Par 2: Cor de fundo preta, cor de texto azul
	init_pair(3, COLOR_CYAN, COLOR_BLACK);   // Par 3: Cor de fundo preta, cor de texto ciano

	//Game* game = new Game();
	GameLogic game_new;

	/*int MaxX, MaxY;
	getmaxyx(stdscr, MaxY, MaxX);

	RenderRegion ui = RenderRegion({ MaxX, 2 }, { 0,0 });
	RenderRegion gameScreen = RenderRegion({ MaxX, MaxY - 2 }, { 0,2 });*/

	//game->addRegion(&ui);
	//game->addRegion(&gameScreen);

	//game->Run();

	//refresh();

	game_new.initGame();

	while (true) {

		game_new.updateGame();
		timeout(128);
		int ch = getch();
		switch (ch) {
		case 'q': // Sair do jogo
			game_new.endGame(true);
			return 0;

		case KEY_UP:
			game_new.movePacman(0, -1);
			break;

		case KEY_DOWN:
			game_new.movePacman(0, 1);
			break;

		case KEY_LEFT:
			game_new.movePacman(-1, 0);
			break;

		case KEY_RIGHT:
			game_new.movePacman(1, 0);
			break;
		}
	}
		system("pause");
		return 0;
}
// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
