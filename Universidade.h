#pragma once
#include "Departamento.h"
#include "ListaDepartamentos.h"
#include <vector>
using namespace std;

class Universidade
{
    private:
        int id;
        char nome[100];
        ListaDepartamentos ObjLDepartamentos;

    public:
        Universidade(int i = -1, const char* n = "");
        ~Universidade();

        void setNome(const char* n);
        char* getNome();

        int getId();
        void setId(int i);

        void incluaDepartamento(Departamento* pdep);
        void listeDepartamentos();
        void listeDepartamentosReverso();
};
