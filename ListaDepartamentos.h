#pragma once

#include "Departamento.h"
#include <string>
#include <vector>
using namespace std;

class ListaDepartamentos
{
    private:
        vector<Departamento*> LTDepartamentos;

    public:
        ListaDepartamentos();
        ~ListaDepartamentos();

        void incluaDepartamento(Departamento* pd);
        void limpaLista();

        void listeDepartamentos();
        void listeDepartamentosReverso();

        Departamento* localizar (string n);

        void graveDepartamentos();
        void recupereDepartamentos();
};
