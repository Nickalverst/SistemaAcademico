#include "ListaUniversidades.h"

#include <fstream>
#include <iostream>
using namespace std;

ListaUniversidades::ListaUniversidades()
{
}

ListaUniversidades::~ListaUniversidades()
{
    limpaLista();
}

void ListaUniversidades::incluaUniversidade(Universidade* pd)
{
    if (NULL != pd)
    {
        LTUniversidades.push_back(pd);
    } else
    {
        cout << "Ponteiro nulo. \n" << endl;
    }
}

void ListaUniversidades::listeUniversidades()
{
    for (int i = 0; i < (int)LTUniversidades.size(); i++)
    {
        cout << LTUniversidades[i]->getNome() << endl;
    }
}

void ListaUniversidades::listeUniversidadesInverso()
{
    for (int i = (int)LTUniversidades.size(); i > 0; i--)
    {
        cout << LTUniversidades[i]->getNome() << endl;
    }
}

Universidade* ListaUniversidades::localizar(const string n)
{
    for (int i = 0; i < (int)LTUniversidades.size(); i++)
    {
        if (n == LTUniversidades[i]->getNome())
        {
            return LTUniversidades[i];
        }
    }

    return NULL;
}


void ListaUniversidades::graveUniversidades()
{
    ofstream GravadorUniversidades("disciplinas.dat", ios::out);

    if (!GravadorUniversidades)
    {
        cerr << "Arquivo não pode ser aberto. " << endl;
        fflush(stdin);
        getchar();
        return;
    }

    for (int i = 0; i < (int)LTUniversidades.size(); i++)
    {
        GravadorUniversidades << LTUniversidades[i]->getId()   << ""
                              << LTUniversidades[i]->getNome() << endl;
    }

    GravadorUniversidades.close();
    cout << "Êxito na gravação das universidades. " << endl;
    fflush(stdin);
    getchar();
}

void ListaUniversidades::recupereUniversidades()
{
    ifstream RecuperadorUniversidades("universidade.dat", ios::in);

    if (!RecuperadorUniversidades)
    {
        cerr << "Arquivo não pode ser aberto. " << endl;
        fflush(stdin);
        getchar();
        return;
    }
    limpaLista();

    while (!RecuperadorUniversidades.eof())
    {
        Universidade* pAuxUniversidade = NULL;
        int id;
        string nome;

        RecuperadorUniversidades >> id >> nome;
        if (nome != "")
        {
            pAuxUniversidade = new Universidade(-1);
            pAuxUniversidade->setId(id);
            pAuxUniversidade->setNome(nome);

            incluaUniversidade(pAuxUniversidade);
        }
    }

    RecuperadorUniversidades.close();
    cout << "Êxito na recuperação das universidades. " << endl;
    fflush(stdin);
    getchar();
}

void ListaUniversidades::limpaLista()
{
    for (int i = 0; i < (int)LTUniversidades.size(); i++)
    {
        delete LTUniversidades[i];
    }
    LTUniversidades.clear();
}
