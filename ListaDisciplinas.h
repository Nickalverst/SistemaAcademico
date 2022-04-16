#pragma once

#include "Disciplina.h"
#include "Lista.h"
#include <string>
#include <vector>
using namespace std;

class ListaDisciplinas
{
    private:
        vector<Disciplina*> LTDisciplinas;

    public:
        ListaDisciplinas();
        ~ListaDisciplinas();

        void incluaDisciplina(Disciplina* pd);
        void limpaLista();

        void listeDisciplinas();
        void listeDisciplinasReverso();

        void graveDisciplinas();
        void recupereDisciplinas();
};
