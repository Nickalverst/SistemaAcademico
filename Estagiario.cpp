#include "Estagiario.h"
#include <iostream>
using namespace std;

Estagiario::Estagiario(int diaNa, int mesNa, int anoNa, const char* n):
Aluno()
{
    diaNasc = diaNa;
    mesNasc = mesNa;
    anoNasc = anoNa;
    inicializa();
}

Estagiario::Estagiario()
{
    inicializa();
}

Estagiario::~Estagiario()
{
}

void Estagiario::inicializa()
{
    bolsaEstudo = 0.0;
}

void Estagiario::setBolsaEstudo(float b)
{
    bolsaEstudo = b;
}

float Estagiario::getBolsaEstudo()
{
    return bolsaEstudo;
}

void Estagiario::informaProventos()
{
    cout << "O valor da bolsa de " << nome << " é " << bolsaEstudo << "." << endl;
}
