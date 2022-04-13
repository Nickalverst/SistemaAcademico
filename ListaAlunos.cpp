#include "ListaAlunos.h"
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;

ListaAlunos::ListaAlunos()
{
}

ListaAlunos::~ListaAlunos()
{
}

void ListaAlunos::incluaAluno(Aluno* pa)
{
    if (NULL != pa)
    {
        LTAlunos.incluaInfo(pa);
    } else
    {
        cout << "Ponteiro nulo. \n" << endl;
    }
}

void ListaAlunos::listeAlunos()
{
    Elemento<Aluno>* pElAux = NULL;
    Aluno* pAlAux = NULL;
    pElAux = LTAlunos.getPrimeiro();

    for (pElAux = LTAlunos.getPrimeiro(); pElAux != NULL; pElAux = pElAux->getProximo())
    {
        pAlAux = pElAux->getInfo();
        cout << "Aluno " << pAlAux->getNome() << " matriculado na disciplina. " << endl;
    }
}

void ListaAlunos::listeAlunosInverso()
{
    Elemento<Aluno>* pElAux = NULL;
    Aluno* pAlAux = NULL;
    for (pElAux = LTAlunos.getAtual(); pElAux != NULL; pElAux = pElAux->getAnterior())
    {
        cout << "Aluno " << pAlAux->getNome() << " matriculado na disciplina. " << endl;
    }
}

void ListaAlunos::graveAlunos()
{
    ofstream GravadorAlunos("alunos.dat", ios::out);

    if (!GravadorAlunos)
    {
        cerr << "Arquivo não pode ser aberto. " << endl;
        fflush(stdin);
        getchar();
        return;
    }

    Elemento<Aluno>* pAuxElAluno = NULL;
    Aluno* pAuxAluno = NULL;

    for (pAuxElAluno = LTAlunos.getPrimeiro(); pAuxElAluno != NULL; pAuxElAluno = pAuxElAluno->getProximo())
    {
        pAuxAluno = pAuxElAluno->getInfo();

        GravadorAlunos << pAuxAluno->getId()   << ""
                       << pAuxAluno->getRA()   << ""
                       << pAuxAluno->getNome() << endl;
    }

    GravadorAlunos.close();
    cout << "Êxito na gravação dos alunos. " << endl;
    fflush(stdin);
    getchar();
}

void ListaAlunos::recupereAlunos()
{
    ifstream RecuperadorAlunos("alunos.dat", ios::in);

    if (!RecuperadorAlunos)
    {
        cerr << "Arquivo não pode ser aberto. " << endl;
        fflush(stdin);
        getchar();
        return;
    }
    limpaLista();

    while (!RecuperadorAlunos.eof())
    {
        Aluno* pAuxAluno = NULL;
        int id;
        int RA;
        char nome[150];

        RecuperadorAlunos >> id >> RA >> nome;
        if (0 != strcmp(nome, ""))
        {
            pAuxAluno = new Aluno(-1);
            pAuxAluno->setId(id);
            pAuxAluno->setRA(RA);
            pAuxAluno->setNome(nome);

            incluaAluno(pAuxAluno);
        }
    }

    RecuperadorAlunos.close();
    cout << "Êxito na recuperação dos alunos. " << endl;
    fflush(stdin);
    getchar();
}

void ListaAlunos::limpaLista()
{
    LTAlunos.limpar();

    /// ESTAVA LIMPANDO A LISTA DUAS VEZES, UMA AQUI
    /// E UMA NA DESTRUTORA DA CLASSE LISTA.
    /*Elemento<Aluno> *pAux1 = NULL, *pAux2 = NULL;

    for (pAux1 = LTAlunos.getPrimeiro(); pAux1 != NULL; pAux1 = pAux2)
    {
        pAux2 = pAux1->getProximo();
        delete (pAux1);
    }*/
}
