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

int main()
{
	RenderRegion* renderRegion = new RenderRegion({20,20}, {0,0});

	initscr();
	cbreak();
	noecho();
	raw();

    while (true) {
		if (is_termresized()) {
			clear();
			resize_term(0, 0);
		}

		renderRegion->Update();
		int ch = getch();
		switch (ch)
		{
		default:
			mvprintw(2, 2,"Key: %c", ch);
			break;
		case 'q':
			clear();
			endwin();
			return 0;
			break;
		}
    }
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
