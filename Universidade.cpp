#include "Universidade.h"
#include <string.h>
#include <iostream>
using namespace std;

Universidade::Universidade(int i, const char* n):
ObjLDepartamentos()
{
    id = i;
    strcpy(nome, n);
}

Universidade::~Universidade()
{
}

void Universidade::setNome(const char* n)
{
    strcpy(nome, n);
}

char* Universidade::getNome()
{
    return nome;
}

void Universidade::setId(int i)
{
    id = i;
}

int Universidade::getId()
{
    return id;
}

void Universidade::incluaDepartamento(Departamento* pdep)
{
    ObjLDepartamentos.incluaDepartamento(pdep);
}

void Universidade::listeDepartamentos()
{
    //ObjLDepartamentos.listeInfos();
}
