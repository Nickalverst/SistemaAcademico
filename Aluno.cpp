#include "Aluno.h"
#include "Departamento.h"
#include<stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

Aluno::Aluno(int diaNa, int mesNa, int anoNa, const char* nome):
    Pessoa(diaNa, mesNa, anoNa, nome)
    {
    }

Aluno::Aluno(int i):
    Pessoa()
    {
        RA = i;
    }

Aluno::~Aluno()
{
}

void Aluno::setRA(int ra)
{
    RA = ra;
}

int Aluno::getRA()
{
    return RA;
}

void Aluno::setDepartamento(Departamento* pd)
{
    pDeptoAssociado = pd;
}

Departamento* Aluno::getDepartamento()
{
    return pDeptoAssociado;
}
