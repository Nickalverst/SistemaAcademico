#pragma once

#include "Aluno.h"
#include "Lista.h"
#include <vector>
using namespace std;

class ListaAlunos
{
    private:
        vector<Aluno*> LTAlunos;

    public:
        ListaAlunos();
        ~ListaAlunos();

        void incluaAluno(Aluno* pa);
        void limpaLista();

        void listeAlunos();
        void listeAlunosInverso();

        void graveAlunos();
        void recupereAlunos();
};
