#pragma once

#include "Pessoa.h"
#include "Universidade.h"

class Departamento;

class Aluno : public Pessoa
{
    private:
        char nome[150];
        int RA;
        Departamento* pDeptoAssociado;

    public:
        Aluno(int diaNa, int mesNa, int anoNa, const char* nome = "");
        Aluno(int i = -1);
        ~Aluno();

        void setRA(int ra);
        int getRA();

        void setDepartamento(Departamento* pd);
        Departamento* getDepartamento();
};
