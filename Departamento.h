#pragma once

class Universidade;
class Disciplina;
class ListaDisciplinas;

class Departamento
{
    private:
        char nome[130];
        Universidade* uniFiliada;
        ListaDisciplinas* pObjLDisciplinas;

    public:
        Departamento(const char* n = "");
        ~Departamento();

        void setNome(const char* n);
        char* getNome();

        void setUniversidade(Universidade* uni);
        Universidade* getUniversidade();

        void incluaDisciplina(Disciplina* pd); // incluir em ordem alfabética?
        // remova disciplina?

        void listeDisciplinas();
        void listeDisciplinasReverso();
};
