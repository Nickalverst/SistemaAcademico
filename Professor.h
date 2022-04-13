#pragma once

#include "Pessoa.h"
#include "Universidade.h"

class Professor : public Pessoa
{
    private:
        Universidade* pUnivFiliado;
        Departamento* pDepFiliado;

        float salario;
        float bolsa_projeto;
    public:
        Professor(int i = -1, int diaNa = 0, int mesNa = 0, int anoNa = 0, const char* nome = "");
        Professor();
        ~Professor();

        void setSalario(float s);
        float getSalario();

        void setBolsaProjeto(float s);
        float getBolsaProjeto();

        void informaProventos();

        void setUniversidade(Universidade* pu);
        void setDepartamento(Departamento* pd);
        void OndeTrabalho();
};
