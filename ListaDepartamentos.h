#pragma once

#include "ElDepartamento.h"
#include "Departamento.h"

class ListaDepartamentos
{
    private:
        int cont_dep;
        int numero_dep;
        char nome[150];

        ElDepartamento* pElDepartamentoPrim;
        ElDepartamento* pElDepartamentoAtual;

    public:
        ListaDepartamentos(int nd = 1000, const char* n = "");
        ~ListaDepartamentos();

        void setNome(const char* n);

        void incluaDepartamento(Departamento* pd);
        void listeDepartamentos();
        void listeDepartamentosReverso();
        Departamento* localizar (char* n);
};
