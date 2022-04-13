#pragma once

#include "Departamento.h"
#include "Lista.h"

class ListaDepartamentos
{
    private:
        Lista<Departamento> LTDepartamentos;

    public:
        ListaDepartamentos();
        ~ListaDepartamentos();

        void incluaDepartamento(Departamento* pd);
        void limpaLista();

        void listeDepartamentos();
        void listeDepartamentosReverso();

        Departamento* localizar (const char* n);

        void graveDepartamentos();
        void recupereDepartamentos();
};
