#pragma once

#include "ElAluno.h"
#include "Aluno.h"

class ListaAlunos
{
    private:
        int cont_alunos;
        int numero_alunos;
        char nome[150];

        ElAluno* pElAlunoPrim;
        ElAluno* pElAlunoAtual;

    public:
        ListaAlunos(int na, const char* n);
        ~ListaAlunos();

        void setNumeroAlunos(int na);
        int getNumeroAlunos();

        void setNome(char* n);
        char* getNome();

        void incluaAluno(Aluno* pa);
        void listeAlunos();
        void listeAlunosInverso();
};
