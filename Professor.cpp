#include "Professor.h"
#include<stdlib.h>
#include <iostream>
using namespace std;

Professor::Professor(int i, int diaNa, int mesNa, int anoNa, const char* nome):
    Pessoa(i, diaNa, mesNa, anoNa, nome)
    {
        pUnivFiliado = NULL;
        pDepFiliado = NULL;
    }

Professor::Professor():
    Pessoa()
    {
        pUnivFiliado = NULL;
        pDepFiliado = NULL;
    }

Professor::~Professor()
{
    pUnivFiliado = NULL;
    pDepFiliado = NULL;
}

void Professor::OndeTrabalho()
{
    cout << nome << " trabalha para o departamento de " << pDepFiliado->getNome() << " de " << pUnivFiliado->getNome() << "." << endl;
}

void Professor::setUniversidade(Universidade* pu)
{
    pUnivFiliado = pu;
}

void Professor::setDepartamento(Departamento* pd)
{
    pDepFiliado = pd;
}
