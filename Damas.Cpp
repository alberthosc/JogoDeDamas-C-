// Autores: Albertho Costa e Enrico Luigi
// 29/05/2018
// Jogo de Damas com as possibilidades de Multiplayer e Single Player (I.A.) em c++ 

#include <iostream>

using namespace std;

bool validacao(char tabuleiro[8][8], char p, int lo, int co, int ld, int cd, int jogadordavez);
void imprimirtabuleiro(char t[8][8]);
int modomultiplayer(char tabuleiro[8][8]);
bool modosingleplayer(char tabuleiro[8][8]);
bool jogadadopc(char tabuleiro[8][8]);
void trocar(char tabuleiro[8][8], int lo, int co, int ld, int cd);
bool verificarganhador(char tabuleiro[8][8]);

int main()
{

    int escolhademodo, ganhador;
    char tabuleiro[8][8] =
        {
            {'p', 'x', 'p', 'x', 'p', 'x', 'p', 'x'},
            {'x', 'p', 'x', 'p', 'x', 'p', 'x', 'p'},
            {'p', 'x', 'p', 'x', 'p', 'x', 'p', 'x'},
            {' ', 'p', ' ', 'p', ' ', 'p', ' ', 'p'},
            {'p', ' ', 'p', ' ', 'p', ' ', 'p', ' '},
            {'o', 'p', 'o', 'p', 'o', 'p', 'o', 'p'},
            {'p', 'o', 'p', 'o', 'p', 'o', 'p', 'o'},
            {'o', 'p', 'o', 'p', 'o', 'p', 'o', 'p'},
        };
    imprimirtabuleiro(tabuleiro);
    cout << "Escolha o modo de jogo: " << endl;
    cout << "Single player - 1" << endl
         << "Multiplayer - 2" << endl
         << "Sair - 3" << endl;
    cin >> escolhademodo;
    if (escolhademodo == 2)
    {
        ganhador = modomultiplayer(tabuleiro);

        if (ganhador == 1)
        {
            cout << "o jogador 1 venceu" << endl;
            return 0;
        }
        else if (ganhador == 2)
        {
            cout << "o jogador 2 venceu" << endl;
            return 0;
        }
    }
    if (escolhademodo == 1)
    {

        ganhador = modosingleplayer(tabuleiro);
        if (ganhador == 1)
        {
            cout << "o jogador 1 venceu" << endl;
            return 0;
        }
        else if (ganhador == 0)
        {
            cout << "o Computador venceu" << endl;
            return 0;
        }
    }
    if (escolhademodo == 3)
    {
        return 0;
    }
}

bool modosingleplayer(char tabuleiro[8][8])
{
    do
    {
        int re, situacao, nj1 = 0, jogadordavez = 0;
        cout << "Single Player" << endl;
        cout << "Vez do jogador 1" << endl;
        do // Jogada_player1
        {
            jogadordavez = 1;
            char p;
            int r, lo, ld, co, cd;
            cout << "Digite a linha da peca a ser movida: " << endl;
            cin >> lo;
            cout << "Digite a coluna da peca a ser movida: " << endl;
            cin >> co;
            cout << "Digite a linha para onde a peca serah movida: " << endl;
            cin >> ld;
            cout << "Digite a coluna para onde a peca serah movida: " << endl;
            cin >> cd;
            p = tabuleiro[lo - 1][co - 1];
            r = validacao(tabuleiro, p, lo - 1, co - 1, ld - 1, cd - 1, jogadordavez);
            if (r == 0)
            {
                cout << "Jogada invalida" << endl;
            }
            else
            {
                cout << "jogada valida" << endl;
                trocar(tabuleiro, lo - 1, co - 1, ld - 1, cd - 1);
                imprimirtabuleiro(tabuleiro);
                if (verificarganhador(tabuleiro) == 1)
                    return 1;
            }
            re = r;

        } while (re != 1);
        cout << "Vez do computador" << endl;
        jogadadopc(tabuleiro);
        imprimirtabuleiro(tabuleiro);
        if (verificarganhador(tabuleiro) == 1)
            return 0;
    } while (verificarganhador(tabuleiro) != 1);
}
int modomultiplayer(char tabuleiro[8][8])
{
    int bandeira = 0, jogadordavez = 0;
    do
    {

        int re;
        do // jogada_player1
        {
            jogadordavez = 1;
            cout << "Multiplayer" << endl;
            cout << "Vez do jogador 1" << endl;
            cout << "( o )" << endl;
            char p;
            int r, lo, ld, co, cd;
            cout << "Digite a linha da peca a ser movida: " << endl;
            cin >> lo;
            cout << "Digite a coluna da peca a ser movida: " << endl;
            cin >> co;
            cout << "Digite a linha para onde a peca serah movida: " << endl;
            cin >> ld;
            cout << "Digite a coluna para onde a peca serah movida: " << endl;
            cin >> cd;
            p = tabuleiro[lo - 1][co - 1];
            r = validacao(tabuleiro, p, lo - 1, co - 1, ld - 1, cd - 1, jogadordavez);
            if (r == 0)
            {
                cout << "Jogada invalida" << endl;
            }
            else
            {
                trocar(tabuleiro, lo - 1, co - 1, ld - 1, cd - 1);
                cout << "jogada valida" << endl;

                imprimirtabuleiro(tabuleiro);
            }
            re = r;
            if (verificarganhador(tabuleiro) == 1)
            {
                bandeira = 1;
            }

        } while (re == 0);

        if (bandeira == 0)
        {
            int re2;
            do // Jogada_player2
            {
                jogadordavez = 2;
                cout << "Vez do jogador 2" << endl;
                cout << "( x )" << endl;
                char p;
                int r, lo, ld, co, cd;
                cout << "Digite a linha da peca a ser movida: " << endl;
                cin >> lo;
                cout << "Digite a coluna da peca a ser movida: " << endl;
                cin >> co;
                cout << "Digite a linha para onde a peca serah movida: " << endl;
                cin >> ld;
                cout << "Digite a coluna para onde a peca serah movida: " << endl;
                cin >> cd;
                p = tabuleiro[lo - 1][co - 1];
                r = validacao(tabuleiro, p, lo - 1, co - 1, ld - 1, cd - 1, jogadordavez);
                if (r == 0)
                {
                    cout << "Jogada invalida" << endl;
                }
                else
                {
                    trocar(tabuleiro, lo - 1, co - 1, ld - 1, cd - 1);
                    cout << "jogada valida" << endl;
                    imprimirtabuleiro(tabuleiro);
                }
                re2 = r;
                if (verificarganhador(tabuleiro) == 1)
                {
                    bandeira = 2;
                }

            } while (re2 == 0);
        }

    } while (bandeira == 0);
    return bandeira;
}

bool jogadadopc(char tabuleiro[8][8])
{
    for (int i = 0; i < 8; i++) // verifica se tem pe�as para comer
    {
        for (int j = 0; j < 8; j++)
        {
            if (tabuleiro[i][j] == 'x') // Verifica se a pe�a a ser movida � realmente o x (computador)
            {
                if (tabuleiro[i + 1][j - 1] == 'o') // prioridade 1 = comer para esquerda (cima pra baixo)
                {
                    if (tabuleiro[i + 2][j - 2] == ' ')
                    {
                        trocar(tabuleiro, i, j, i + 2, j - 2);
                        return 0;
                    }
                }
                else if (tabuleiro[i + 1][j + 1] == 'o') // prioridade 2 = comer para direita (cima pra baixo)
                {
                    if (tabuleiro[i + 2][j + 2] == ' ')
                    {
                        trocar(tabuleiro, i, j, i + 2, j + 2);
                        return 0;
                    }
                }
                else if (tabuleiro[i - 1][j - 1] == 'o') // prioridade 3 = comer para esquerda (baixo pra cima)
                {
                    if (tabuleiro[i - 2][j - 2] == ' ')
                    {
                        trocar(tabuleiro, i, j, i - 2, j - 2);
                        return 0;
                    }
                }
                else if (tabuleiro[i - 1][j + 1] == 'o') // prioridade 4 = comer para direita (baixo pra cima)
                {
                    if (tabuleiro[i - 2][j + 2] == ' ')
                    {
                        trocar(tabuleiro, i, j, i - 2, j + 2);
                        return 0;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 8; i++) // caso � tenha pe�as para comer, ele entra aqui e verifica se tem pe�as para andar sem comer
    {
        for (int j = 0; j < 8; j++)
        {
            if (tabuleiro[i][j] == 'x') // Verifica se a pe�a a ser movida � realmente o x (computador)
            {
                if (tabuleiro[i + 1][j - 1] == ' ') // prioridade 5 = andar para esquerda
                {
                    trocar(tabuleiro, i, j, i + 1, j - 1);
                    return 0;
                }
                else if (tabuleiro[i + 1][j + 1] == ' ') // prioridade 6 = andar para direita
                {

                    trocar(tabuleiro, i, j, i + 1, j + 1);
                    return 0;
                }
            }
        }
    }
    return 0;
}

bool validacao(char tabuleiro[8][8], char p, int lo, int co, int ld, int cd, int jogadordavez)
{
    if (jogadordavez == 1)
    {
        if (p == 'o') // peça "o"
        {
            if (lo - ld == 1) // se for andar
            {
                if (tabuleiro[ld][cd] == ' ')
                {
                    return 1;
                }
            }
            else
            {
                if (lo - ld == 2) // se for comer
                {
                    if (lo > ld) // se for de baixo pra cima do tabuleiro
                    {
                        if (tabuleiro[ld][cd] == ' ')
                        {
                            if (cd < co) // se for comer pro lado esquerdo do tabuleiro
                            {
                                if (tabuleiro[lo - 1][co - 1] == 'x')
                                    return 1;
                            }
                            else
                            {
                                if (cd > co) // se for comer pro lado direito do tabuleiro
                                {
                                    if (tabuleiro[lo - 1][co + 1] == 'x')
                                        return 1;
                                }
                                else
                                {
                                    return 0;
                                }
                            }
                        }
                    }
                    else
                    {
                        if (lo < ld) // se for de cima pra baixo do tabuleiro
                        {
                            if (tabuleiro[ld][cd] == ' ')
                            {
                                if (cd < co) // se for comer pro lado esquerdo do tabuleiro
                                {
                                    if (tabuleiro[lo + 1][co - 1] == 'x')
                                        return 1;
                                }
                                else
                                {
                                    if (cd > co) // se for comer pro lado direito do tabuleiro
                                    {
                                        if (tabuleiro[lo + 1][co + 1] == 'x')
                                            return 1;
                                    }
                                    else
                                    {
                                        return 0;
                                    }
                                }
                            }
                        }
                        else
                        {
                            return 0;
                        }
                    }
                }
                else
                    return 0;
            }
        }
        else
            return 0;
    }
    if (jogadordavez == 2)
    {
        if (p == 'x') // pe�a x
        {
            if (lo - ld == -1) // se for andar
            {
                if (tabuleiro[ld][cd] == ' ')
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                if (lo - ld == -2) // se for comer
                {
                    if (lo < ld) // se for de cima pra baixo do tabuleiro
                    {
                        if (tabuleiro[ld][cd] == ' ')
                        {
                            if (cd < co) // se for comer pro lado esquerdo do tabuleiro
                            {
                                if (tabuleiro[lo + 1][co - 1] == 'o')
                                    return 1;
                            }
                            else
                            {
                                if (cd > co) // se for comer pro lado direito do tabuleiro
                                {
                                    if (tabuleiro[lo + 1][co + 1] == 'o')
                                        return 1;
                                }
                                else
                                {
                                    return 0;
                                }
                            }
                        }
                    }
                    else
                    {
                        if (lo > ld) // se for de baixo pra cima do tabuleiro
                        {
                            if (tabuleiro[ld][cd] == ' ')
                            {
                                if (cd < co) // se for comer pro lado esquerdo do tabuleiro
                                {
                                    if (tabuleiro[lo - 1][co - 1] == 'o')
                                        return 1;
                                }
                                else
                                {
                                    if (cd > co) // se for comer pro lado direito do tabuleiro
                                    {
                                        if (tabuleiro[lo - 1][co + 1] == 'o')
                                            return 1;
                                    }
                                    else
                                    {
                                        return 0;
                                    }
                                }
                            }
                        }
                        else
                        {
                            return 0;
                        }
                    }
                }
                else
                    return 0;
            }
        }
        else
            return 0;
    }
}

void imprimirtabuleiro(char t[8][8])
{
    cout << "     1   2   3   4   5   6   7   8    " << endl;
    cout << "   |---|---|---|---|---|---|---|---|" << endl;
    cout << "1  ||||| " << t[0][1] << " ||||| " << t[0][3] << " ||||| " << t[0][5] << " ||||| " << t[0][7] << " |" << endl;
    cout << "   |---|---|---|---|---|---|---|---|" << endl;
    cout << "2  | " << t[1][0] << " ||||| " << t[1][2] << " ||||| " << t[1][4] << " ||||| " << t[1][6] << " |||||" << endl;
    cout << "   |---|---|---|---|---|---|---|---|" << endl;
    cout << "3  ||||| " << t[2][1] << " ||||| " << t[2][3] << " ||||| " << t[2][5] << " ||||| " << t[2][7] << " |" << endl;
    cout << "   |---|---|---|---|---|---|---|---|" << endl;
    cout << "4  | " << t[3][0] << " ||||| " << t[3][2] << " ||||| " << t[3][4] << " ||||| " << t[3][6] << " |||||" << endl;
    cout << "   |---|---|---|---|---|---|---|---|" << endl;
    cout << "5  ||||| " << t[4][1] << " ||||| " << t[4][3] << " ||||| " << t[4][5] << " ||||| " << t[4][7] << " |" << endl;
    cout << "   |---|---|---|---|---|---|---|---|" << endl;
    cout << "6  | " << t[5][0] << " ||||| " << t[5][2] << " ||||| " << t[5][4] << " ||||| " << t[5][6] << " |||||" << endl;
    cout << "   |---|---|---|---|---|---|---|---|" << endl;
    cout << "7  ||||| " << t[6][1] << " ||||| " << t[6][3] << " ||||| " << t[6][5] << " ||||| " << t[6][7] << " |" << endl;
    cout << "   |---|---|---|---|---|---|---|---|" << endl;
    cout << "8  | " << t[7][0] << " ||||| " << t[7][2] << " ||||| " << t[7][4] << " ||||| " << t[7][6] << " |||||" << endl;
    cout << "   |---|---|---|---|---|---|---|---|" << endl;
}
void trocar(char tabuleiro[8][8], int lo, int co, int ld, int cd)
{
    if (ld - lo == 1 || ld - lo == -1)
    {
        char aux;
        aux = tabuleiro[ld][cd];
        tabuleiro[ld][cd] = tabuleiro[lo][co];
        tabuleiro[lo][co] = aux;
    }
    else if (ld - lo == 2 || ld - lo == -2)
    {
        if (lo > ld) // se for comer de baixo pra cima no tabuleiro(pode ser pra pe�a x ou o)
        {
            if (tabuleiro[lo][co] == 'o')
            {
                if (cd > co) // comer em dire��o a uma coluna � direita
                {
                    tabuleiro[lo][co] = ' ';
                    tabuleiro[lo - 1][co + 1] = ' ';
                    tabuleiro[ld][cd] = 'o';
                }
                else if (cd < co) // comer em dire��o a uma coluna � esquerda
                {
                    tabuleiro[lo][co] = ' ';
                    tabuleiro[lo - 1][co - 1] = ' ';
                    tabuleiro[ld][cd] = 'o';
                }
            }
            else if (tabuleiro[lo][co] == 'x')
            {
                if (cd > co) // comer em dire��o a uma coluna � direita
                {
                    tabuleiro[lo][co] = ' ';
                    tabuleiro[lo - 1][co + 1] = ' ';
                    tabuleiro[ld][cd] = 'x';
                }
                else if (cd < co) // comer em dire��o a uma coluna � esquerda
                {
                    tabuleiro[lo][co] = ' ';
                    tabuleiro[lo - 1][co - 1] = ' ';
                    tabuleiro[ld][cd] = 'x';
                }
            }
        }
        else if (lo < ld) // se for comer de cima pra baixo no tabuleiro(pode ser pra pe�a x ou o)
        {
            if (tabuleiro[lo][co] == 'x')
            {
                if (cd > co) // comer em dire��o a uma coluna � direita
                {
                    tabuleiro[lo][co] = ' ';
                    tabuleiro[lo + 1][co + 1] = ' ';
                    tabuleiro[ld][cd] = 'x';
                }
                else if (cd < co) // comer em dire��o a uma coluna � esquerda
                {
                    tabuleiro[lo][co] = ' ';
                    tabuleiro[lo + 1][co - 1] = ' ';
                    tabuleiro[ld][cd] = 'x';
                }
            }
            else if (tabuleiro[lo][co] == 'o')
            {
                if (cd > co) // comer em dire��o a uma coluna � direita
                {
                    tabuleiro[lo][co] = ' ';
                    tabuleiro[lo + 1][co + 1] = ' ';
                    tabuleiro[ld][cd] = 'o';
                }
                else if (cd < co) // comer em dire��o a uma coluna � esquerda
                {
                    tabuleiro[lo][co] = ' ';
                    tabuleiro[lo + 1][co - 1] = ' ';
                    tabuleiro[ld][cd] = 'o';
                }
            }
        }
    }
}
bool verificarganhador(char tabuleiro[8][8])
{
    int pecasx = 0, pecaso = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (tabuleiro[i][j] == 'x')
                pecasx++;
            else if (tabuleiro[i][j] == 'o')
                pecaso++;
        }
    }
    if (pecasx == 0 || pecaso == 0)
        return 1;
    else
        return 0;
}
