#pragma once

#include "Pessoa.h"
#include "Universidade.h"

class Professor : public Pessoa
{
    private:
        Universidade* pUnivFiliado;
        Departamento* pDepFiliado;
    public:
        Professor(int diaNa, int mesNa, int anoNa, const char* nome = "");
        Professor();
        ~Professor();

        void setUniversidade(Universidade* pu);
        void setDepartamento(Departamento* pd);
        void OndeTrabalho();
};
