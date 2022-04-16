#include "Universidade.h"
#include <string.h>
#include <iostream>
using namespace std;

Universidade::Universidade(int i, const string n):
ObjLDepartamentos()
{
    id = i;
    nome = n;
}

Universidade::~Universidade()
{
}

void Universidade::setNome(const string n)
{
    nome = n;
}

string Universidade::getNome()
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
    ObjLDepartamentos.listeDepartamentos();
}
