#pragma once

#include "Aluno.h"

class ElAluno
{
    private:
        Aluno* pAl;
        ElAluno* pProx;
        ElAluno* pAnter;
    public:
        ElAluno();
        ~ElAluno();

        void setAluno(Aluno* pa);
        Aluno* getAluno();

        ElAluno* getProxAluno();
        void setProxAluno(ElAluno* al);
        ElAluno* getAlunoAnterior();
        void setAlunoAnterior(ElAluno* al);

        char* getNome();
        void setNome(const char* nm);
};
