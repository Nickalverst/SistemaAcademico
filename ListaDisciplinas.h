#pragma once

#include "Disciplina.h"
#include "Lista.h"

class ListaDisciplinas
{
    private:
        Lista<Disciplina> LTDisciplinas;

    public:
        ListaDisciplinas(int nd = 1000, const char* n = "");
        ~ListaDisciplinas();

        void incluaDisciplina(Disciplina* pd);
        void limpaLista();

        void listeDisciplinas();
        void listeDisciplinasReverso();

        void graveDisciplinas();
        void recupereDisciplinas();
};
