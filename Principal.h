#pragma once
#include "Pessoa.h"
#include "Universidade.h"
#include "Professor.h"
#include "Aluno.h"
#include "Disciplina.h"
#include "ListaUniversidades.h"
#include "ListaDisciplinas.h"
#include "ListaAlunos.h"
#include "ListaPessoas.h"
#include "MinhaString.h"

class Principal
{
    private:
        int cont_idDisc;
        int cont_idDepart;
        int cont_idAluno;
        int cont_idUniv;

        ListaUniversidades LUniversidades;
        ListaDepartamentos LDepartamentos;
        ListaDisciplinas LDisciplinas;
        ListaAlunos LAlunos;
        ListaPessoas LPessoas;

        int diaAtual, mesAtual, anoAtual;

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

        // Menus de cadastramento
        void CadDisciplina();
        void CadDepartamento();
        void CadUniversidade();
        void CadAluno();

        // Gravação
        void GravarTudo();
        void GravarUniversidades();
        void GravarDepartamentos();
        void GravarDisciplinas();
        void GravarProfessores();
        void GravarAlunos();

        // Leitura
        void RecuperarTudo();
        void RecuperarUniversidades();
        void RecuperarDepartamentos();
        void RecuperarDisciplinas();
        void RecuperarProfessores();
        void RecuperarAlunos();

        // Interface
        void Menu();
        void MenuCad();
        void MenuExe();
        void MenuGravar();
        void MenuRecuperar();
        void Executar();
};
