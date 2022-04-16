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
        LTAlunos.push_back(pa);
    } else
    {
        cout << "Ponteiro nulo. \n" << endl;
    }
}

void ListaAlunos::listeAlunos()
{
    for (int i = 0; i < (int)LTAlunos.size(); i++)
    {
        cout << LTAlunos[i]->getNome() << endl;
    }
}

void ListaAlunos::listeAlunosInverso()
{
    for (int i = LTAlunos.size(); i > 0; i--)
    {
        cout << LTAlunos[i]->getNome() << endl;
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

    for (int i = 0; i < (int)LTAlunos.size(); i++)
    {
        GravadorAlunos << LTAlunos[i]->getId()   << ""
                       << LTAlunos[i]->getRA()   << ""
                       << LTAlunos[i]->getNome() << endl;
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
        string nome;

        RecuperadorAlunos >> id >> RA >> nome;
        if (nome != "")
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
    for (int i = 0; i < (int)LTAlunos.size(); i++)
    {
        delete LTAlunos[i];
    }
    LTAlunos.clear();

    /// ESTAVA LIMPANDO A LISTA DUAS VEZES, UMA AQUI
    /// E UMA NA DESTRUTORA DA CLASSE LISTA.
    /*Elemento<Aluno> *pAux1 = NULL, *pAux2 = NULL;

    for (pAux1 = LTAlunos.getPrimeiro(); pAux1 != NULL; pAux1 = pAux2)
    {
        pAux2 = pAux1->getProximo();
        delete (pAux1);
    }*/
}
