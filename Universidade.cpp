#include "Universidade.h"
#include <string.h>
#include <iostream>
using namespace std;

Universidade::Universidade(const char* n)
{
    strcpy(nome, n);

    ObjLDepartamentos = new ListaDepartamentos(100, "algor");
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

void Universidade::incluaDepartamento(Departamento* pdep)
{
    ObjLDepartamentos->incluaDepartamento(pdep);
}

void Universidade::listeDepartamentos()
{
    ObjLDepartamentos->listeDepartamentos();
}
