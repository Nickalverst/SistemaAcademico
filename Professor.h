#pragma once

#include "Pessoa.h"
#include "Universidade.h"

class Professor : public Pessoa
{
    private:
        Universidade* pUnivFiliado;
        Departamento* pDepFiliado;
    public:
        Professor(int i = -1, int diaNa = 0, int mesNa = 0, int anoNa = 0, const char* nome = "");
        Professor();
        ~Professor();

        void setUniversidade(Universidade* pu);
        void setDepartamento(Departamento* pd);
        void OndeTrabalho();
};
