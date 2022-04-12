#pragma once

class Universidade;
class ListaDisciplinas;
class Disciplina;

class Departamento
{
    private:
        int id;
        char nome[130];
        int cont_disc;
        int numero_disc;
        Universidade* uniFiliada;
        //ListaDisciplinas ObjLDisciplinas;

    public:
        Departamento(int i = -1, const char* n = "");
        ~Departamento();

        void setNumeroDisciplinas(int i);
        int getNumeroDisciplinas();

        void setNome(const char* n);
        char* getNome();

        void setId(int i);
        int getId();

        void setUniversidade(Universidade* uni);
        Universidade* getUniversidade();

        void incluaDisciplina(Disciplina* pd); // incluir em ordem alfabética?
        /// removaDisciplina()

        void listeDisciplinas();
        void listeDisciplinasReverso();
};
