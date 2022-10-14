// Arquivo de Implementacao do TAD Matriz
#include <iostream>
#include <iomanip>
#include "Matriz.h"
using namespace std;

// Aloca espaco dinamicamente para matriz com m linhas e n colunas
Matriz::Matriz(int m, int n)
{
    lin = m;
    col = n;
    mat = new int *[lin];
    for (int i = 0; i < col; i++)
    {
        mat[i] = new int[col];
    }
}

// Destrutor: Libera a memoria que foi alocada dinamicamente no construtor
Matriz::~Matriz()
{
    for (int i = 0; i < lin; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;
}

// Retorna o numero de linhas da matriz
int Matriz::linhas()
{
    return lin;
}

// Retorna o numero de colunas da matriz
int Matriz::colunas()
{
    return col;
}

// Retorna o valor da celula [i][j] da matriz
int Matriz::getValor(int i, int j)
{
    return mat[i][j];
}

// Atribui valor a celula [i][j] da matriz
void Matriz::setValor(int valor, int i, int j)
{
    mat[i][j] = valor;
}

// Imprimir a matriz
void Matriz::print()
{
    for (int i = 0; i < lin; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            cout << setw(7) << mat[i][j];
        }
        cout << "\n";
    }
}

// Soma matrizes
Matriz *Matriz::soma(Matriz &B)
{
    if (B.linhas() == this->lin && B.colunas() == this->col)
    {
        Matriz *aux = new Matriz(lin, col);
        for (int i = 0; i < lin; i++)
        {
            for (int j = 0; j < col; j++)
            {
                aux->mat[i][j] = this->mat[i][j] + B.mat[i][j];
            }
        }
        return aux;
    }
    return nullptr;
}

// Multiplica matrizes
Matriz *Matriz::multiplica(Matriz &B)
{
    if (this->col == B.lin)
    {
        Matriz *aux = new Matriz(lin, B.col);
        int aux2 = 0;
        for (int i = 0; i < lin; i++)
        {
            for (int j = 0; j < B.col; j++)
            {
                aux->mat[i][j] = 0;
                for (int k = 0; k < B.lin; k++)
                {
                    aux2 += this->mat[i][k] * B.mat[k][j];
                }
                aux->mat[i][j] = aux2;
                aux2 = 0;
            }
        }
        return aux;
    }
    return nullptr;
}