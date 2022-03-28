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

        /*Departamento DACOC_UTFPR; // Departamento Acadêmico de Construção Civil
        Departamento DADIN_UTFPR; // Departamento Acadêmico de Desenho Industrial
        Departamento DAEFI_UTFPR; // Departamento Acadêmico de Educação Física
        Departamento DAELN_UTFPR; // Departamento Acadêmico de Eletrônica
        Departamento DAELT_UTFPR; // Departamento Acadêmico de Eletrotécnica
        Departamento DAESO_UTFPR; // Departamento Acadêmico de Estudos Sociais
        Departamento DAEST_UTFPR; // Departamento Acadêmico de Estatística
        Departamento DAFIS_UTFPR; // Departamento Acadêmico de Física
        Departamento DAGEE_UTFPR; // Departamento Acadêmico de Gestão e Economia
        Departamento DAINF_UTFPR; // Departamento Acadêmico de Informática
        Departamento DALEM_UTFPR; // Departamento Acadêmico de Línguas Estrangeiras Modernas
        Departamento DALIC_UTFPR; // Departamento Acadêmico de Linguagem e Comunicação
        Departamento DAMAT_UTFPR; // Departamento Acadêmico de Matemática
        Departamento DAMEC_UTFPR; // Departamento Acadêmico de Mecânica
        Departamento DAQBI_UTFPR; // Departamento Acadêmico de Química e Biologia
        Departamento DEAAU_UTFPR; // Departamento Acadêmico de Arquitetura e Urbanismo*/

        int diaAtual;
        int mesAtual;
        int anoAtual;

    public:
        Principal();
        ~Principal();

        // Inicializações
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
