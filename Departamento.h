#pragma once

#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class Universidade;
class ListaDisciplinas;
class Disciplina;

class Departamento
{
    private:
        int id;
        string nome;
        int cont_disc;
        int numero_disc;
        Universidade* uniFiliada;
        //ListaDisciplinas ObjLDisciplinas;

    public:
        Departamento(int i = -1, string n = "");
        ~Departamento();

        void setNumeroDisciplinas(int i);
        int getNumeroDisciplinas();

        void setNome(string n);
        string getNome();

        void setId(int i);
        int getId();

        void setUniversidade(Universidade* uni);
        Universidade* getUniversidade();

        void incluaDisciplina(Disciplina* pd); // incluir em ordem alfabética?
        /// removaDisciplina()

        void listeDisciplinas();
        void listeDisciplinasReverso();
};
