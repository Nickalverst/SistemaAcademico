#pragma once
#include "Pessoa.h"
#include "Universidade.h"
#include "Professor.h"
#include "Aluno.h"
#include "Disciplina.h"
#include "ListaUniversidades.h"
#include "ListaDisciplinas.h"

class Principal
{
    private:
        ListaUniversidades LUniversidades;
        ListaDepartamentos LDepartamentos;
        ListaDisciplinas LDisciplinas;

        // Universidades
        Universidade UTFPR;
        Universidade Princeton;
        Universidade Cambridge;

        // Departamentos
        Departamento Matematica;
        Departamento Informatica;
        Departamento Fisica;

        // Disciplinas
        Disciplina TecProg;
        Disciplina FundProg;
        Disciplina Calculo;

        // Professores
        Professor Simao;
        Professor Einstein;
        Professor Newton;

        // Alunos
        Aluno Nicolas;

        /*Departamento DACOC_UTFPR; // Departamento Acad�mico de Constru��o Civil
        Departamento DADIN_UTFPR; // Departamento Acad�mico de Desenho Industrial
        Departamento DAEFI_UTFPR; // Departamento Acad�mico de Educa��o F�sica
        Departamento DAELN_UTFPR; // Departamento Acad�mico de Eletr�nica
        Departamento DAELT_UTFPR; // Departamento Acad�mico de Eletrot�cnica
        Departamento DAESO_UTFPR; // Departamento Acad�mico de Estudos Sociais
        Departamento DAEST_UTFPR; // Departamento Acad�mico de Estat�stica
        Departamento DAFIS_UTFPR; // Departamento Acad�mico de F�sica
        Departamento DAGEE_UTFPR; // Departamento Acad�mico de Gest�o e Economia
        Departamento DAINF_UTFPR; // Departamento Acad�mico de Inform�tica
        Departamento DALEM_UTFPR; // Departamento Acad�mico de L�nguas Estrangeiras Modernas
        Departamento DALIC_UTFPR; // Departamento Acad�mico de Linguagem e Comunica��o
        Departamento DAMAT_UTFPR; // Departamento Acad�mico de Matem�tica
        Departamento DAMEC_UTFPR; // Departamento Acad�mico de Mec�nica
        Departamento DAQBI_UTFPR; // Departamento Acad�mico de Qu�mica e Biologia
        Departamento DEAAU_UTFPR; // Departamento Acad�mico de Arquitetura e Urbanismo*/

        int diaAtual;
        int mesAtual;
        int anoAtual;

    public:
        Principal();
        ~Principal();

        // Inicializa��es
        void Inicializa();
        void InicializaUniversidades();
        void InicializaDepartamentos();
        void InicializaProfessores();
        void InicializaDisciplinas();
        void InicializaAlunos();

        void CadDisciplina();
        void CadDepartamento();
        void CadUniversidade();

        void Menu();
        void MenuCad();
        void MenuExe();
        void Executar();
};
