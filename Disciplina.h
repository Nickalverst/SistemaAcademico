#pragma once
#include <stdio.h>
#include <string.h>

#include "ListaAlunos.h"

class Departamento;

class Disciplina
{
    private:
        int id;
        int cont_alunos;
        int numero_alunos;
        char nome[150];
        char area_conhecimento[150];

        Departamento* pDepAssociado;

        ListaAlunos ObjLAlunos;

    public:
        Disciplina(int i = -1, const char* n = "", const char* ac = "", int na = 45);
        ~Disciplina();

        void setNumeroAlunos(int na);
        int getNumeroAlunos();

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
