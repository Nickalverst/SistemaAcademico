#pragma once

#include "Aluno.h"
#include "ElAluno.h"
#include "ListaAlunos.h"
#include "Departamento.h"

class Departamento;

class Disciplina
{
    private:
        int id;
        char nome[150];
        char area_conhecimento[150];

        Departamento* pDepAssociado;

        ListaAlunos* ObjAlunos;

    public:
        Disciplina(const char* n = "", const char* ac = "", int na = 45);
        ~Disciplina();

        void setProxDisciplina(Disciplina* prox);
        Disciplina* getProxDisciplina();

        void setDisciplinaAnter(Disciplina* anter);
        Disciplina* getDisciplinaAnter();

        void setId(int n);
        int getId();

        void setNome(const char* n);
        char* getNome();

        void setDepartamento(Departamento* pdpto);
        Departamento* getDepartamento();

        void incluirAluno(Aluno* al); // Ordem alfabética
        ///void removerAluno(Aluno* al);

        void listaAlunos();
        void listaAlunosReverso();
};
