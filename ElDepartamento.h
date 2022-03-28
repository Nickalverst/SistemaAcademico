#pragma once

#include "Departamento.h"

class ElDepartamento
{
    private:
        Departamento* pDep;
        ElDepartamento* pProx;
        ElDepartamento* pAnter;
    public:
        ElDepartamento();
        ~ElDepartamento();

        void setDepartamento(Departamento* dep);
        Departamento* getDepartamento();

        ElDepartamento* getProxDepartamento();
        void setProxDepartamento(ElDepartamento* dep);
        ElDepartamento* getDepartamentoAnterior();
        void setDepartamentoAnterior(ElDepartamento* dep);

        char* getNome();
        void setNome(const char* nm);
};
