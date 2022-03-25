#include "Matriz.h"

namespace TP2 {

Matriz::Matriz(int qtdLinhas, int qtdColunas):
    qtdLinhas(0),
    qtdColunas(0),
    matriz(0)
{
    if ((qtdLinhas <= 1) || (qtdColunas <= 1)) throw QString ("Impossível criar matriz. Quantidade de linhas e colunas devem ser > 1.");
    try {
        this->qtdLinhas = qtdLinhas;
        this->qtdColunas = qtdColunas;
        matriz = new int[qtdLinhas * qtdColunas];
    }  catch (std::bad_alloc const&) {
        throw QString("Erro de memória");
    }
}
bool Matriz::eMesmaOrdem() const
{
    if(qtdLinhas != qtdColunas) throw QString ("A Matriz não é quadrada. Operação não pode prosseguir.");
    return true;
}

bool Matriz::eMesmaOrdem(const Matriz * const matriz) const
{
    if(qtdLinhas != qtdColunas) return false;
    if(qtdLinhas != matriz->qtdLinhas || qtdColunas != matriz->qtdColunas) return false;
    return true;
}

Matriz::Matriz():
    qtdLinhas(0),
    qtdColunas(0),
    matriz(0)
{

}

Matriz::~Matriz(){
    if (matriz) delete[] matriz;
}

int Matriz::getQtdLinhas() const
{
    return qtdLinhas;
}

void Matriz::setQtdLinhas(int newQtdLinhas)
{
    if (newQtdLinhas <= 1) throw QString ("Impossível criar matriz. Quantidade de linhas deve ser > 1.");
    qtdLinhas = newQtdLinhas;
}

int Matriz::getQtdColunas() const
{
    return qtdColunas;
}

void Matriz::setQtdColunas(int newQtdColunas)
{
    if (newQtdColunas <= 1) throw QString ("Impossível criar matriz. Quantidade de colunas deve ser > 1.");
    qtdColunas = newQtdColunas;
}

QString Matriz::getMatriz() const
{
    QString saida = "";
    for(int i = 0; i < getQtdLinhas(); i++){
        for(int j = 0; j < getQtdColunas(); j++){
            saida += QString::number(getElemento(i, j));
            saida += " ";
        }
        saida += "\n";
    }
    return saida;
}

int Matriz::getElemento(int linha, int coluna) const
{
    if((linha < 0) || (linha >= qtdLinhas)) throw QString ("Linha fora do intervalo");
    if((coluna < 0) || (coluna >= qtdColunas)) throw QString ("Coluna fora do intervalo");

    int pos = linha * qtdColunas + coluna;

    return *(matriz + pos);
}

void Matriz::inserirElemento(int elemento, int linha, int coluna) const
{
    if((linha < 0) || (linha >= qtdLinhas)) throw QString ("Linha fora do intervalo");
    if((coluna < 0) || (coluna >= qtdColunas)) throw QString ("Coluna fora do intervalo");

    int pos = linha * qtdColunas + coluna;
    *(matriz + pos) = elemento;
}

Matriz* Matriz::calcularTransposta() const
{
    try {
        Matriz *aux = new Matriz(qtdLinhas, qtdColunas);
        for (int i = 0; i < qtdLinhas; i++){
            for(int j = 0; j < qtdColunas; j++){
                int elemento = getElemento(i, j);
                aux->inserirElemento(elemento, j, i);
            }
        }
        return aux;
    }  catch (std::bad_alloc const&) {
        throw QString ("Erro de memória");
    }
}

Matriz* Matriz::calcularPotenciacao(int expoente) const
{
    if (expoente <= 0) throw QString ("O expoente não pode ser <= 0.");
    eMesmaOrdem();
    try {
        Matriz *aux = new Matriz(qtdLinhas, qtdColunas);
        aux->matriz = this->matriz;
        Matriz *multiplicacao = 0;
        for (int i = 1; i < expoente; i++){
            multiplicacao = *aux * this;
            aux = multiplicacao;
        }
        return aux;
    }  catch (std::bad_alloc const&) {
        throw QString ("Erro de memória");
    }
}

Matriz *Matriz::calcularMultiplicacaoPorK(int k) const
{
    try {
        Matriz *aux = new Matriz(qtdLinhas,qtdColunas);
        for (int i = 0; i < qtdLinhas; i++){
            for(int j = 0; j < qtdColunas; j++){
                aux->inserirElemento(getElemento(i, j) * k, i, j);
            }
        }
        return aux;
    }  catch (std::bad_alloc const&) {
        throw QString ("Erro de memória");
    }
}

bool Matriz::eTriangularSuperior() const //perguntar se tem try catch aqui!
{
    return (eMesmaOrdem());
    bool verificar = false;
    for (int i = 0; i < qtdLinhas; i++){
        for(int j = 0; j < qtdColunas; j++){
            if (i > j && getElemento(i, j) == 0) verificar = true;
        }
    }
    return verificar;
}

bool Matriz::eTriangularInferior() const
{
    return (eMesmaOrdem());
    bool verificar = false;
    for (int i = 0; i < qtdLinhas; i++){
        for(int j = 0; j < qtdColunas; j++){
            if (i < j && getElemento(i, j) == 0) verificar = true;
        }
    }
    return verificar;
}

bool Matriz::eSimetrica() const
{
    return (eMesmaOrdem());
    //se matriz == transposta é simetrica!
    return ( this == this->calcularTransposta());
}

bool Matriz::eIdentidade() const
{
    return (eTriangularInferior() == eTriangularSuperior());
}

Matriz* Matriz::operator +(const Matriz * const matriz) const
{
    if (eMesmaOrdem(matriz)) throw QString("Matrizes de ordem diferente. Operação não pode prosseguir.");
    try {
        Matriz *aux = new Matriz(qtdLinhas, qtdColunas);
        for (int i = 0; i < qtdLinhas; i++){
            for(int j = 0; j < qtdColunas; j++){
                int soma = getElemento(i, j) + matriz->getElemento(i, j);
                aux->inserirElemento(soma, i, j);
            }
        }
        return aux;
    }  catch (std::bad_alloc const&) {
        throw QString ("Erro de memória");
    }
}

Matriz* Matriz::operator -(Matriz const * const matriz) const
{
    if (eMesmaOrdem(matriz)) throw QString("Matrizes de ordem diferente. Operação não pode prosseguir.");
    try {
        Matriz *aux = new Matriz(qtdLinhas,qtdColunas);
        for (int i = 0; i < qtdLinhas; i++){
            for(int j = 0; j < qtdColunas; j++){
                int subtracao = getElemento(i, j) - matriz->getElemento(i, j);
                aux->inserirElemento(subtracao, i, j);
            }
        }
        return aux;
    }  catch (std::bad_alloc const&) {
        throw QString ("Erro de memória");
    }
}

Matriz* Matriz::operator *(Matriz const * const matriz) const
{
    if(this->qtdColunas != matriz->qtdLinhas) throw QString("O número "
                                                            "de colunas da primeira matriz é diferente do número de linhas da segunda matriz!");
    try {
        Matriz *aux = new Matriz(qtdLinhas, matriz->qtdColunas);
        for (int k = 0; k < qtdLinhas; k++){
            for(int i = 0; i < matriz->qtdColunas; i++){
                int valor = 0;
                for(int j = 0; j < matriz->qtdLinhas; j++){
                    valor += getElemento(k, j) * matriz->getElemento(j, i);
                }
                aux->inserirElemento(valor, k, i);
            }
        }
        return aux;
    }  catch (std::bad_alloc const&) {
        throw QString ("Erro de memória");
    }
}

bool Matriz::operator ==(Matriz const * const matriz) const
{
    try {
        if(!eMesmaOrdem(matriz)) return false;

        for(int i = 0; i < getQtdLinhas(); i++){
            for(int j = 0; j < getQtdColunas(); j++){
                if(!(this->getElemento(i, j) == matriz->getElemento(i, j))) return false;
            }
        }
        return true;
    }  catch (std::bad_alloc const&) {
        throw QString ("Erro de memória");
    }
}

bool Matriz::operator !=(Matriz const * const matriz) const
{
    try {
        return ( this == matriz);
    }  catch (std::bad_alloc const&) {
        throw QString ("Erro de memória");
    }
}

}
