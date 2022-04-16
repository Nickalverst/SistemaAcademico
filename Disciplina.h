#pragma once

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

#include "ListaAlunos.h"

class Departamento;

class Disciplina
{
    private:
        int id;
        int cont_alunos;
        int numero_alunos;
        string nome;
        string area_conhecimento;

        Departamento* pDepAssociado;

        ListaAlunos ObjLAlunos;

    public:
        Disciplina(int i = -1, string n = "", string ac = "", int na = 45);
        ~Disciplina();

        void setNumeroAlunos(int na);
        int getNumeroAlunos() const;

        void setId(int n);
        int getId() const;

        void setNome(string n);
        string getNome() const;

        void setDepartamento(Departamento* pdpto);
        Departamento* getDepartamento() const;

        void incluirAluno(Aluno* al); // Ordem alfabética
        ///void removerAluno(Aluno* al);

        void listaAlunos();
        void listaAlunosReverso();
};
