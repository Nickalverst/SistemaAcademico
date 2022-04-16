#include "ListaDisciplinas.h"

#include <fstream>
#include <iostream>
using namespace std;

ListaDisciplinas::ListaDisciplinas()
{
}

ListaDisciplinas::~ListaDisciplinas()
{
    limpaLista();
}

void ListaDisciplinas::incluaDisciplina(Disciplina* pd)
{
    if (pd != NULL)
    {
        LTDisciplinas.push_back(pd);
    }
    else
    {
        cout << "Ponteiro nulo. " << endl;
    }
}

void ListaDisciplinas::listeDisciplinas()
{
    for (int i = 0; i < (int)LTDisciplinas.size(); i++)
    {
        cout << LTDisciplinas[i]->getNome() << endl;
    }
}

void ListaDisciplinas::listeDisciplinasReverso()
{
    for (int i = (int)LTDisciplinas.size(); i > 0 ; i--)
    {
        cout << LTDisciplinas[i]->getNome() << endl;
    }
}


void ListaDisciplinas::graveDisciplinas()
{
    ofstream GravadorDisciplinas("disciplinas.dat", ios::out);

    if (!GravadorDisciplinas)
    {
        cerr << "Arquivo não pode ser aberto. " << endl;
        fflush(stdin);
        getchar();
        return;
    }

    for (int i = 0; i < (int)LTDisciplinas.size(); i++)
    {
        GravadorDisciplinas << LTDisciplinas[i]->getId()   << ""
                            << LTDisciplinas[i]->getNome() << endl;
    }

    GravadorDisciplinas.close();
    cout << "Êxito na gravação das disciplinas. " << endl;
    fflush(stdin);
    getchar();
}

void ListaDisciplinas::recupereDisciplinas()
{
    ifstream RecuperadorDisciplinas("disciplinas.dat", ios::in);

    if (!RecuperadorDisciplinas)
    {
        cerr << "Arquivo não pode ser aberto. " << endl;
        fflush(stdin);
        getchar();
        return;
    }
    limpaLista();

    while (!RecuperadorDisciplinas.eof())
    {
        Disciplina* pAuxDisciplina = NULL;
        int id;
        string nome;

        RecuperadorDisciplinas >> id >> nome;
        if (nome != "")
        {
            pAuxDisciplina = new Disciplina(-1);
            pAuxDisciplina->setId(id);
            pAuxDisciplina->setNome(nome);

            incluaDisciplina(pAuxDisciplina);
        }
    }

    RecuperadorDisciplinas.close();
    cout << "Êxito na recuperação das disciplinas. " << endl;
    fflush(stdin);
    getchar();
}

void ListaDisciplinas::limpaLista()
{
    for (int i = 0; i < (int)LTDisciplinas.size(); i++)
    {
        delete LTDisciplinas[i];
    }
    LTDisciplinas.clear();
}
