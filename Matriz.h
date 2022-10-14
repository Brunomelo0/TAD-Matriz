#ifndef MATRIZ_H
#define MATRIZ_H

class Matriz {
private:
    int lin;     // numero de linhas da matriz
    int col;    // numero de colunas da matriz
    int **mat;   // ponteiro para matriz de inteiros
    
public:
    // Construtor: aloca matriz com m linhas e n colunas
    Matriz(int m, int n);

    // Destrutor: libera memoria alocada
    ~Matriz(); 

    // Retorna o numero de linhas da matriz
    int linhas();

    // Retorna o numero de colunas da matriz
    int colunas();  

    // Retorna o valor contido na celula [i][j] da matriz
    int getValor(int i, int j); 

    // Atribui o valor v a celula [i][j] da matriz
    void setValor(int v, int i, int j); 

    // Imprimir a matriz 
    void print();

    // Recebe uma referencia para o objeto B do tipo Matriz que possui
    // m linhas e n colunas e soma a matriz B com a matriz atual.
    // Se for possivel fazer a soma, um ponteiro para uma nova matriz C
    // contendo o resultado da soma deve ser retornado.
    // Caso contrario, retorna nullptr indicando que nao foi possivel 
    // fazer a soma das matrizes. 
    Matriz *soma(Matriz& B); 

    // Recebe uma referencia para o objeto B do tipo Matriz que possui
    // m linhas e n colunas e multiplica a matriz que chamar essa funcao-membro pela matriz B.
    // Se for possivel fazer a multiplicacao, um ponteiro para uma nova matriz C
    // contendo o resultado da multiplicacao deve ser retornado.
    // Caso contrario, retorna nullptr indicando que nao foi possivel 
    // fazer a multiplicacao das matrizes. 
    Matriz *multiplica(Matriz& B); 

    // Com a linha abaixo, eu estou dizendo para o C++ nao criar
    // o construtor de copia default. Ou seja, nao quero que seja possivel
    // instanciar uma matriz passando outra matriz como argumento pelo construtor.
    Matriz(const Matriz& m) = delete;  
};

#endif