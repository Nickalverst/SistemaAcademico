#pragma once

#include "Disciplina.h"

class ElDisciplina
{
    private:
        Disciplina* pDisc;
        ElDisciplina* pProx;
        ElDisciplina* pAnter;
    public:
        ElDisciplina();
        ~ElDisciplina();

        void setDisciplina(Disciplina* d);
        Disciplina* getDisciplina();

        ElDisciplina* getProxDisciplina();
        void setProxDisciplina(ElDisciplina* d);
        ElDisciplina* getDisciplinaAnterior();
        void setDisciplinaAnterior(ElDisciplina* d);

        char* getNome();
        void setNome(const char* nm);
};
