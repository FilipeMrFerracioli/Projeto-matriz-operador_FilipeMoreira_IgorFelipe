#ifndef MATRIZ_H
#define MATRIZ_H

#include <QString>

namespace TP2 {

class Matriz
{
private:
    int qtdLinhas;
    int qtdColunas;
    int *matriz;

    bool eMesmaOrdem() const;
    bool eMesmaOrdem(Matriz const * const matriz) const;
public:
    Matriz();
    Matriz(int qtdLinhas, int qtdColunas);
    ~Matriz();


    int getQtdLinhas() const;
    void setQtdLinhas(int newQtdLinhas);
    int getQtdColunas() const;
    void setQtdColunas(int newQtdColunas);
    QString getMatriz() const;
    int getElemento(int linha, int coluna) const;


    void inserirElemento(int elemento, int linha, int coluna) const;

    Matriz* calcularTransposta() const;
    Matriz* calcularPotenciacao(int expoente) const;
    Matriz* calcularMultiplicacaoPorK(int k) const;

    bool eTriangularSuperior() const;
    bool eTriangularInferior() const;
    bool eSimetrica() const;
    bool eIdentidade() const;

    // Sobrecargas de operadores
    Matriz* operator +(Matriz const * const matriz) const;
    Matriz* operator -(Matriz const * const matriz) const;
    Matriz* operator *(Matriz const * const matriz) const;
    bool operator ==(Matriz const * const matriz) const;
    bool operator !=(Matriz const * const matriz) const;
};

}
#endif // MATRIZ_H
