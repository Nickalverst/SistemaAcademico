#pragma once
#include "Departamento.h"
#include "ListaDepartamentos.h"
#include <vector>
using namespace std;

class Universidade
{
    private:
        char nome[100];
        ListaDepartamentos* ObjLDepartamentos;

    public:
        Universidade(const char* n = "");
        ~Universidade();

        void setNome(const char* n);
        char* getNome();

        void incluaDepartamento(Departamento* pdep);
        void listeDepartamentos();
        void listeDepartamentosReverso();
};
