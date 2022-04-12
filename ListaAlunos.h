#pragma once

#include "Aluno.h"
#include "Lista.h"

class ListaAlunos
{
    private:
        Lista<Aluno> LTAlunos;

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
