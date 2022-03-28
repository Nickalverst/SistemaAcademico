#include "Principal.h"
#include "Universidade.h"
#include "ListaAlunos.h"
#include "ListaDepartamentos.h"
#include "ListaDisciplinas.h"
#include <iostream>
using namespace std;
#include <time.h>

Principal::Principal():
Simao(3, 10, 1976, "Jean Simão"), // Sempre chamar as contrutoras (o C++ sempre chama)
Einstein(14, 3, 1879, "Albert Einstein"),
Newton(4, 1, 1643, "Isaac Newton"),
UTFPR("Universidade Tecnológica Federal do Paraná"),
Princeton("Princeton University"),
Cambridge("Cambridge University"),
Matematica("Matemática"),
Informatica("Informática"),
Fisica("Física"),
TecProg("Técnicas de Programação", "Computação", 52),
FundProg("Fundamentos de Programação", "Computação", 40),
Calculo("Cálculo Diferencial e Integral", "Matemática", 60),
Nicolas(25, 07, 2001, "Nicolas Barbieri Sousa")
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
    // Agregação dos departamentos às universidades
    UTFPR.incluaDepartamento(&Informatica);
    Princeton.incluaDepartamento(&Fisica);
    Cambridge.incluaDepartamento(&Matematica);
}

void Principal::InicializaDepartamentos()
{
    // Associação das universidades aos departamentos
    Informatica.setUniversidade(&UTFPR);
    Fisica.setUniversidade(&Princeton);
    Matematica.setUniversidade(&Cambridge);
}

void Principal::InicializaProfessores()
{
    // Associação dos professores às universidades
    Simao.setUniversidade(&UTFPR);
    Einstein.setUniversidade(&Princeton);
    Newton.setUniversidade(&Cambridge);

    // Associação dos professores aos departamentos
    Simao.setDepartamento(&Informatica);
    Einstein.setDepartamento(&Fisica);
    Newton.setDepartamento(&Matematica);
}

void Principal::InicializaDisciplinas()
{
    Calculo.setDepartamento(&Matematica);
    TecProg.setDepartamento(&Informatica);
    FundProg.setDepartamento(&Informatica);

    Calculo.incluirAluno(&Nicolas);
    TecProg.incluirAluno(&Nicolas);
}

void Principal::InicializaAlunos()
{
    Nicolas.setRA(2306387);
}

void Principal::Executar()
{
    Menu();
    /*
    Simao.calculaImprimeIdade(diaAtual, mesAtual, anoAtual);
    Einstein.calculaImprimeIdade(diaAtual, mesAtual, anoAtual);
    Newton.calculaImprimeIdade(diaAtual, mesAtual, anoAtual);

    Simao.OndeTrabalho();
    Einstein.OndeTrabalho();
    Newton.OndeTrabalho();

    UTFPR.listeDepartamentos();
    Informatica.listeDisciplinas();*/
}

void Principal::Menu()
{
    int op = -1;

    while (op != 3)
    {
        system("cls");
        cout << " Informe sua opção:   " << endl;
        cout << "1 - Cadastrar.        " << endl;
        cout << "2 - Executar.         " << endl;
        cout << "3 - Sair.             " << endl;
        cin >> op;

        switch (op)
        {
            case 1: { MenuCad(); }
                break;
            case 2: { MenuExe(); }
                break;
            case 3: { cout << "FIM" << endl; }
                break;
            default: { cout << "Opção inválida." << endl;
                        system("Pause"); }

        }
    }
}

void Principal::MenuCad()
{
    int op = -1;

    while (op!= 4)
    {
        system("cls");
        cout << "Informe sua opção:           " << endl;
        cout << "1 - Cadastrar disciplinas.   " << endl;
        cout << "2 - Cadastrar departamentos. " << endl;
        cout << "3 - Cadastrar universidades. " << endl;
        cout << "4 - Sair.                    " << endl;
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
                    cout << "FIM" << endl;
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

    while (op != 4)
    {
        system("cls");
        cout << "Informe sua opção:       " << endl;
        cout << "1 - Listar disciplinas   " << endl;
        cout << "2 - Listar departamentos " << endl;
        cout << "3 - Listar universidades " << endl;
        cout << "4 - Sair                 " << endl;
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
                cout << "FIM" << endl;
            } break;
        default:
            {
                cout << "Opção inválida." << endl;
                getchar();
            } break;
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
    char nomeUniversidade[150];
    char nomeDepartamento[150];
    Disciplina* pDisc;
    Universidade* pUniv;
    Departamento* pDepart;

    cout << "Qual o nome da universidade? " << endl;
    cin >> nomeUniversidade;
    pUniv = LUniversidades.localizar(nomeUniversidade);

    if (pUniv != NULL)
    {
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
    else
    {
        cout << "Universidade inexistente. " << endl;
    }
}
