#pragma once

#include "ElDisciplina.h"
#include "Disciplina.h"

class ListaDisciplinas
{
    private:
        int cont_disc;
        int numero_disc;
        char nome[150];

        ElDisciplina* pElDisciplinaPrim;
        ElDisciplina* pElDisciplinaAtual;

    public:
        ListaDisciplinas(int nd = 1000, const char* n = "");
        ~ListaDisciplinas();

        void setNome(const char* n);

        void incluaDisciplina(Disciplina* pd);
        void listeDisciplinas();
        void listeDisciplinasReverso();
};
