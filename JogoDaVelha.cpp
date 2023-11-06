#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

char tabuleiro[3][3];
int numJogadas = 0;
char jogada;
char jogarNovamente;

#define COR_AZUL 9
#define COR_VERMELHA 12
#define COR_PADRAO 7

void inicializaTabuleiro() {
    tabuleiro[0][0] = '1';
    tabuleiro[0][1] = '2';
    tabuleiro[0][2] = '3';
    tabuleiro[1][0] = '4';
    tabuleiro[1][1] = '5';
    tabuleiro[1][2] = '6';
    tabuleiro[2][0] = '7';
    tabuleiro[2][1] = '8';
    tabuleiro[2][2] = '9';        
}

void imprimirCasaComCor(char conteudo) {
    if (conteudo == 'X') {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COR_AZUL);
    } else if (conteudo == 'O') {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COR_VERMELHA);
    } else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COR_PADRAO);
    }

    printf(" %c ", conteudo);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COR_PADRAO);
}

void montarTabuleiro() {
    system("cls");
    printf("\n");
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 3; c++) {
            imprimirCasaComCor(tabuleiro[l][c]);
            if (c < 2) {
                printf("|");
            }
        }
        if (l < 2) {
            printf("\n---+---+---\n");
        }
    }
    printf("\n");
}

bool verificarVitoria() {
    for (int l = 0; l < 3; l++) {
        if (tabuleiro[l][0] == tabuleiro[l][1] && tabuleiro[l][1] == tabuleiro[l][2] && tabuleiro[l][0] != ' ') {
            printf("\nVitória do jogador %c na linha %d\n", tabuleiro[l][0], l);
            return true;
        }
    }

    for (int c = 0; c < 3; c++) {
        if (tabuleiro[0][c] == tabuleiro[1][c] && tabuleiro[1][c] == tabuleiro[2][c] && tabuleiro[0][c] != ' ') {
            printf("\nVitória do jogador %c na coluna %d\n", tabuleiro[0][c], c);
            return true;
        }
    }

    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
        printf("\nVitória do jogador %c na diagonal principal\n", tabuleiro[0][0]);
        return true;
    }

    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
        printf("\nVitória do jogador %c na diagonal secundï¿½ria\n", tabuleiro[0][2]);
        return true;
    }

    return false;
}

void jogarDeNovo() {
    printf("\nDeseja jogar novamente? (s/n)");
    scanf(" %c", &jogarNovamente);
    if(jogarNovamente == 's') {
        inicializaTabuleiro();
        montarTabuleiro();
    } else {
        abort();
    }
}

void entrada() {
    while (numJogadas < 9) {
        printf("\nFaça sua jogada: ");
        scanf(" %c", &jogada);

        for (int l = 0; l < 3; l++) {
            for (int c = 0; c < 3; c++) {
                if (tabuleiro[l][c] == jogada && tabuleiro[l][c] != 'X' && tabuleiro[l][c] != 'O') {
                    if (numJogadas % 2 == 0) {
                        tabuleiro[l][c] = 'X';
                    } else {
                        tabuleiro[l][c] = 'O';
                    }
                    numJogadas++;
                }
            }
        }

        montarTabuleiro();
					
        if(numJogadas % 2 == 1) 
		    	printf("\nVez do O");
				else
					printf("\nVez do X");

        if (verificarVitoria()) {
            jogarDeNovo();
        }
    }

    printf("Empate!");
    jogarDeNovo();
}

int main() {
	setlocale(LC_ALL, "Portuguese");
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COR_PADRAO);
  inicializaTabuleiro();
  montarTabuleiro();
  entrada();
}

