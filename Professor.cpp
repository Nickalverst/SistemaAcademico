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
        salario = 0.0;
        bolsa_projeto = 0.0;
    }

Professor::~Professor()
{
    pUnivFiliado = NULL;
    pDepFiliado = NULL;
}

void Professor::setSalario(float s)
{
    salario = s;
}

float Professor::getSalario()
{
    return salario;
}

void Professor::setBolsaProjeto(float s)
{
    bolsa_projeto = s;
}

float Professor::getBolsaProjeto()
{
    return bolsa_projeto;
}

void Professor::informaProventos()
{
    cout << "O valor dos proventos do professor " << nome << " é " << (salario + bolsa_projeto) << "." << endl;
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
