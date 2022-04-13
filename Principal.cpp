#include "Principal.h"
#include "Universidade.h"
#include "ListaAlunos.h"
#include "ListaDepartamentos.h"
#include "ListaDisciplinas.h"
#include <iostream>
using namespace std;
#include <time.h>

Principal::Principal():
// Geradores de identificação
cont_idAluno (0),
cont_idDepart(0),
cont_idDisc  (0),
cont_idUniv  (0)
{
    // Obtenção da data atual
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Determinação da data atual
    diaAtual = tm.tm_mday;
    mesAtual = tm.tm_mon + 1;
    anoAtual = tm.tm_year + 1900;

    Inicializa();
    Executar();
}

Principal::~Principal()
{
}

void Principal::Inicializa()
{
    InicializaUniversidades();
    InicializaDepartamentos();
    InicializaProfessores();
    InicializaDisciplinas();
    InicializaAlunos();
}

void Principal::InicializaUniversidades()
{
}

void Principal::InicializaDepartamentos()
{
}

void Principal::InicializaProfessores()
{
}

void Principal::InicializaDisciplinas()
{
}

void Principal::InicializaAlunos()
{
}

void Principal::Executar()
{
    Menu();
}

void Principal::Menu()
{
    int op = -1;

    while (op != 5)
    {
        system("cls");
        cout << " Informe sua opção:   " << endl;
        cout << "1 - Cadastrar.        " << endl;
        cout << "2 - Executar.         " << endl;
        cout << "3 - Gravar.           " << endl;
        cout << "4 - Recuperar.        " << endl;
        cout << "5 - Sair.             " << endl;
        cin >> op;

        switch (op)
        {
            case 1: {  MenuCad(); }
                break;
            case 2: { MenuExe(); }
                break;
            case 3: { MenuGravar(); }
                break;
            case 4: { MenuRecuperar(); }
                break;
            case 5: { cout << "FIM" << endl; }
                return;
            default: { cout << "Opção inválida." << endl;
                        system("Pause"); }
        }
    }
}

void Principal::MenuCad()
{
    int op = -1;

    while (op!= 5)
    {
        system("cls");
        cout << "Informe sua opção:           " << endl;
        cout << "1 - Cadastrar disciplina.    " << endl;
        cout << "2 - Cadastrar departamento.  " << endl;
        cout << "3 - Cadastrar universidade.  " << endl;
        cout << "4 - Cadastrar alunos.        " << endl;
        cout << "5 - Voltar.                  " << endl;
        cin >> op;

        switch (op)
        {
        case 1:
            {
                CadDisciplina();
            } break;
        case 2:
            {
                CadDepartamento();
            } break;
        case 3:
            {
                CadUniversidade();
            } break;
        case 4:
            {
                CadAluno();
            } break;
        case 5:
            {
            } break;
        default:
            {
                cout << "Opção inválida" << endl;
                getchar();
            } break;
        }
    }
}

void Principal::MenuExe()
{
    int op = -1;

    while (op != 6)
    {
        system("cls");
        cout << "Informe sua opção:       " << endl;
        cout << "1 - Listar disciplinas   " << endl;
        cout << "2 - Listar departamentos " << endl;
        cout << "3 - Listar universidades " << endl;
        cout << "4 - Listar alunos        " << endl;
        cout << "5 - Listar pessoas       " << endl;
        cout << "6 - Voltar               " << endl;
        cin >> op;

        switch (op)
        {
        case 1:
            {
                LDisciplinas.listeDisciplinas();
                fflush(stdin);
                getchar();
            } break;
        case 2:
            {
                LDepartamentos.listeDepartamentos();
                fflush(stdin);
                getchar();
            } break;
        case 3:
            {
                LUniversidades.listeUniversidades();
                fflush(stdin);
                getchar();
            } break;
        case 4:
            {
                LAlunos.listeAlunos();
                fflush(stdin);
                getchar();
            } break;
        case 5:
            {
                LPessoas.listePessoas();
                fflush(stdin);
                getchar();
            }
        case 6:
            {
            } break;
        default:
            {
                cout << "Opção inválida." << endl;
                getchar();
            } break;
        }
    }
}

void Principal::MenuGravar()
{
    int op = -1;

    while (op != 6)
    {
        system("cls");
        cout << " Informe sua opção:       " << endl;
        cout << "0 - Gravar tudo.          " << endl;
        cout << "1 - Gravar universidades. " << endl;
        cout << "2 - Gravar departamentos. " << endl;
        cout << "3 - Gravar disciplinas.   " << endl;
        cout << "4 - Gravar alunos.        " << endl;
        cout << "5 - Gravar professores.   " << endl;
        cout << "6 - Voltar.               " << endl;
        cin >> op;

        switch (op)
        {
            case 0: { GravarTudo(); }
                break;
            case 1: { GravarUniversidades(); }
                break;
            case 2: { GravarDepartamentos(); }
                break;
            case 3: { GravarDisciplinas(); }
                break;
            case 4: { GravarAlunos(); }
                break;
            case 5: { GravarProfessores(); }
                break;
            case 6: { cout << "FIM" << endl; }
                return;
            default: { cout << "Opção inválida." << endl;
                        system("Pause"); }
        }
    }
}

void Principal::MenuRecuperar()
{
    int op = -1;

    while (op != 6)
    {
        system("cls");
        cout << " Informe sua opção:       " << endl;
        cout << "0 - Recuperar tudo.          " << endl;
        cout << "1 - Recuperar universidades. " << endl;
        cout << "2 - Recuperar departamentos. " << endl;
        cout << "3 - Recuperar disciplinas.   " << endl;
        cout << "4 - Recuperar alunos.        " << endl;
        cout << "5 - Recuperar professores.   " << endl;
        cout << "6 - Voltar.                  " << endl;
        cin >> op;

        switch (op)
        {
            case 0: { RecuperarTudo(); }
                break;
            case 1: { RecuperarUniversidades(); }
                break;
            case 2: { RecuperarDepartamentos(); }
                break;
            case 3: { RecuperarDisciplinas(); }
                break;
            case 4: { RecuperarAlunos(); }
                break;
            case 5: { RecuperarProfessores(); }
                break;
            case 6: { cout << "FIM" << endl; }
                return;
            default: { cout << "Opção inválida." << endl;
                        system("Pause"); }
        }
    }
}

void Principal::CadUniversidade()
{
    char nomeUniversidade[150];
    Universidade* pUniv = NULL;

    cout << "Qual o nome da universidade? " << endl;
    cin >> nomeUniversidade;

    pUniv = new Universidade();
    pUniv->setNome(nomeUniversidade);
    LUniversidades.incluaUniversidade(pUniv);
}

void Principal::CadDepartamento()
{
    char nomeUniversidade[150];
    char nomeDepartamento[150];
    Universidade* pUniv;
    Departamento* pDepart;

    cout << "Qual o nome da universidade? " << endl;
    cin >> nomeUniversidade;
    pUniv = LUniversidades.localizar(nomeUniversidade);

    if (pUniv != NULL)
    {
        cout << "Qual o nome do departamento? " << endl;
        cin >> nomeDepartamento;
        pDepart = new Departamento();
        pDepart->setNome(nomeDepartamento);
        pDepart->setUniversidade(pUniv);
        LDepartamentos.incluaDepartamento(pDepart);
        pUniv->incluaDepartamento(pDepart);
    }
    else
    {
        cout << "Universidade inexistente. " << endl;
    }
}

void Principal::CadDisciplina()
{
    char nomeDisciplina[150];
    char nomeDepartamento[150];
    Disciplina* pDisc;
    Departamento* pDepart;

    cout << "Qual o nome do departamento? " << endl;
    cin >> nomeDepartamento;
    pDepart = LDepartamentos.localizar(nomeDepartamento);

    if (pDepart != NULL)
    {
        cout << "Qual o nome da disciplina?   " << endl;
        cin >> nomeDisciplina;
        pDisc = new Disciplina();
        pDisc->setNome(nomeDisciplina);
        pDisc->setDepartamento(pDepart);
        LDisciplinas.incluaDisciplina(pDisc);
        pDepart->incluaDisciplina(pDisc);
    }
    else
    {
        cout << "Departamento inexistente. " << endl;
    }
}

void Principal::CadAluno()
{
    char nomeAluno[150];
    int ra;
    Aluno* pAluno = NULL;

    cout << "Qual o nome do aluno? " << endl;
    cin >> nomeAluno;

    cout << "Qual o RA do aluno? " << endl;
    cin >> ra;

    pAluno = new Aluno(cont_idAluno++);
    pAluno->setNome(nomeAluno);
    pAluno->setRA(ra);
    LAlunos.incluaAluno(pAluno);
    LPessoas.incluaPessoa(static_cast<Pessoa*> (pAluno));
}

void Principal::RecuperarTudo()
{
    LUniversidades.recupereUniversidades();
    LDepartamentos.recupereDepartamentos();
    LDisciplinas.recupereDisciplinas();

    LAlunos.recupereAlunos();
}

void Principal::RecuperarUniversidades()
{
    LUniversidades.recupereUniversidades();
}

void Principal::RecuperarDepartamentos()
{
    LDepartamentos.recupereDepartamentos();
}

void Principal::RecuperarDisciplinas()
{
    LDisciplinas.recupereDisciplinas();
}

void Principal::RecuperarProfessores()
{

}

void Principal::RecuperarAlunos()
{
    LAlunos.recupereAlunos();
}

void Principal::GravarTudo()
{
    LUniversidades.graveUniversidades();
    LDepartamentos.graveDepartamentos();
    LDisciplinas.graveDisciplinas();

    LAlunos.graveAlunos();
}

void Principal::GravarUniversidades()
{
    LUniversidades.graveUniversidades();
}

void Principal::GravarDepartamentos()
{
    LDepartamentos.graveDepartamentos();
}

void Principal::GravarDisciplinas()
{
    LDisciplinas.graveDisciplinas();
}

void Principal::GravarProfessores()
{
    // TO DO
}

void Principal::GravarAlunos()
{
    LAlunos.graveAlunos();
}
