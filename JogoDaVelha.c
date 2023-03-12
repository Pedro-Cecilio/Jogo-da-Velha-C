#include <stdio.h>
#include <stdlib.h>

#define TAM 3

int vencedor;

void limpar_velha(char mat[][TAM]);
void mostrar_velha(char mat[][TAM]);
void menu(char mat[][TAM]);
int checaHori(char mat[][TAM], int linha);
int checaVert(char mat[][TAM], int coluna);
int checaDiag1(char mat[][TAM]);
int checaDiag2(char mat[][TAM]);
int ganhou(char mat[][TAM]);
int jogada(char mat[][TAM], int jogador, int *ponteiro);
int main()
{
    char velha[TAM][TAM], jogador1, jogador2;
    int newgame;
    do
    {

        limpar_velha(velha);
        menu(velha);
        do
        {
            jogador1 = jogada(velha, 1, &vencedor);
            if (vencedor == 1)
            {
                printf("Parabens, jogador 1 venceu.\n");
                break;
            }
            if(jogador1 == 0){
                break;
            }
            jogador2 = jogada(velha, 2, &vencedor);
            if (vencedor == 2)
            {
                printf("Parabens, jogador 2 venceu.\n");
                break;
            }

        } while (jogador1 && jogador2);

        printf("Jogar novamente?\n0 - Nao\n1 - Sim\n");
        scanf("%d", &newgame);
        system("cls || clear");
    } while (newgame);
}
// Função que limpa todos indices da matriz velha
void limpar_velha(char mat[][TAM])
{
    int i, j;
    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            mat[i][j] = ' ';
        }
    }
}
// Função que mostra o jogo da velha no estado atual que ele estiver
void mostrar_velha(char mat[][TAM])
{
    int i, j;
    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            if (i != TAM - 1)
            {
                if (j == TAM - 1)
                {
                    printf("_%c_", mat[i][j]);
                }
                else
                {
                    printf("_%c_|", mat[i][j]);
                }
            }
            else
            {
                if (j == TAM - 1)
                {
                    printf(" %c ", mat[i][j]);
                }
                else
                {
                    printf(" %c |", mat[i][j]);
                }
            }
        }
        printf("\n");
    }
}
// Função que apresenta e explica como jogar
void menu(char mat[][TAM])
{
    printf("=============== Jogo Da Velha ===============\n");
    printf("Insira a posicao(linha e coluna) de onde deseja marcar\n");
    printf("Exemplo: 1 3 ---> Significa: Linha 1, coluna 3\n");
    mostrar_velha(mat);
}
// Funções que checam se o X ou o O aparecem 3 vezes em sequencia:
int checaHori(char mat[][TAM], int linha)
{
    int i, x = 0, o = 0;
    for (i = 0; i < TAM; i++)
    {
        if (mat[linha][i] == 88)
        {
            x++;
        }
        if (mat[linha][i] == 79)
        {
            o++;
        }
    }
    if (x == 3)
    {
        return 1;
    }
    if (o == 3)
    {
        return 2;
    }
    return 0;
}
int checaVert(char mat[][TAM], int coluna)
{
    int i, x = 0, o = 0;
    for (i = 0; i < TAM; i++)
    {
        if (mat[i][coluna] == 88)
        {
            x++;
        }
        if (mat[i][coluna] == 79)
        {
            o++;
        }
    }
    if (x == 3)
    {
        return 1;
    }
    if (o == 3)
    {
        return 2;
    }
    return 0;
}
int checaDiag1(char mat[][TAM])
{
    int i, j, x = 0, o = 0;

    for (i = 0; i < TAM; i++, j--)
    {

        if (mat[i][i] == 88)
        {
            x++;
        }
        if (mat[i][i] == 79)
        {
            o++;
        }
    }
    if (x == 3)
    {
        return 1;
    }
    if (o == 3)
    {
        return 2;
    }
    return 0;
}
int checaDiag2(char mat[][TAM])
{
    int i, j, x = 0, o = 0;

    for (i = 0, j = TAM - 1; i < TAM; i++, j--)
    {

        if (mat[i][j] == 88)
        {
            x++;
        }
        if (mat[i][j] == 79)
        {
            o++;
        }
    }
    if (x == 3)
    {
        return 1;
    }
    if (o == 3)
    {
        return 2;
    }
    return 0;
}

// Função que utiliza as checagens e retorna o vencedor, caso tenha.
int ganhou(char mat[][TAM])
{
    int vencedor = 0;
    // Checa todas horizontais
    vencedor = checaHori(mat, 0);
    if (vencedor != 0)
    {
        return vencedor;
    }
    vencedor = checaHori(mat, 1);
    if (vencedor != 0)
    {
        return vencedor;
    }
    vencedor = checaHori(mat, 2);
    if (vencedor != 0)
    {
        return vencedor;
    }

    // Checa todas verticais
    vencedor = checaVert(mat, 0);
    if (vencedor != 0)
    {
        return vencedor;
    }
    vencedor = checaVert(mat, 1);
    if (vencedor != 0)
    {
        return vencedor;
    }
    vencedor = checaVert(mat, 2);
    if (vencedor != 0)
    {
        return vencedor;
    }

    // Checa a vertical Principal
    vencedor = checaDiag1(mat);
    if (vencedor != 0)
    {
        return vencedor;
    }
    vencedor = checaDiag2(mat);
    if (vencedor != 0)
    {
        return vencedor;
    }
    return 0;
}
// Função que pega a jogada do usuário, testa a posição é valida, se valida adiciona X ou O de acordo com o jogador.
int jogada(char mat[][TAM], int jogador, int *ponteiro)
{
    int l, c, i, j, control = 0, espaco = 0;
    do
    {

        printf("Jogador %d\n", jogador);
        printf("Insira a posicao desejada:\n");
        scanf("%d %d", &l, &c);
        l--;
        c--;
        system("cls || clear");
        for (i = 0; i < TAM; i++)
        {
            for (j = 0; j < TAM; j++)
            {
                if (i == l && j == c)
                {
                    if (mat[l][c] == ' ')
                    {
                        int i, j;
                        if (jogador == 1)
                        {
                            mat[l][c] = 'X';
                            control = 0;
                        }
                        else
                        {
                            mat[l][c] = 'O';
                            control = 0;
                        }
                        *ponteiro = ganhou(mat);
                        if (*ponteiro == 0)
                        {
                            for (i = 0; i < TAM; i++)
                            {
                                for (j = 0; j < TAM; j++)
                                {
                                    if (mat[i][j] == ' ')
                                    {
                                        espaco++;
                                    }
                                }
                            }
                            if (espaco == 0)
                            {
                                printf("Seu jogo deu velha :(.\n");
                                return 0;
                            }
                        }
                    }
                    else
                    {

                        printf("Espaco ocupado. Tente novamente:\n\n");
                        mostrar_velha(mat);
                        control = 1;
                    }
                }
            }
        }
    } while (control);
    mostrar_velha(mat);
    return 1;
}
