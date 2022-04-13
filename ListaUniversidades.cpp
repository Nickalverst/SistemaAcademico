#include "ListaUniversidades.h"
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;

ListaUniversidades::ListaUniversidades()
{
}

ListaUniversidades::~ListaUniversidades()
{
}

void ListaUniversidades::incluaUniversidade(Universidade* pd)
{
    if (NULL != pd)
    {
        LTUniversidades.incluaInfo(pd);
    } else
    {
        cout << "Ponteiro nulo. \n" << endl;
    }
}

void ListaUniversidades::listeUniversidades()
{
    Elemento<Universidade>* pElAux = NULL;
    Universidade* pUnAux = NULL;

    for (pElAux = LTUniversidades.getPrimeiro(); pElAux != NULL; pElAux = pElAux->getProximo())
    {
        pUnAux = pElAux->getInfo();
        printf("%s. \n", pUnAux->getNome());
    }
}

void ListaUniversidades::listeUniversidadesInverso()
{
    Elemento<Universidade>* pElAux = NULL;
    Universidade* pUnAux = NULL;

    for (pElAux = LTUniversidades.getAtual(); pElAux != NULL; pElAux = pElAux->getAnterior())
    {
        pUnAux = pElAux->getInfo();
        printf("%s. \n", pUnAux->getNome());
    }
}

Universidade* ListaUniversidades::localizar(const char* n)
{
    Elemento<Universidade> *pElAux = NULL;
    Universidade* pUnAux = NULL;

    for (pElAux = LTUniversidades.getPrimeiro(); pElAux != NULL; pElAux = pElAux->getProximo())
    {
        pUnAux = pElAux->getInfo();
        if (0 == strcmp(n, pUnAux->getNome()))
        {
            return pUnAux;
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

    Elemento<Universidade>* pAuxElUniversidade = NULL;
    Universidade* pAuxUniversidade = NULL;

    for (pAuxElUniversidade = LTUniversidades.getPrimeiro(); pAuxElUniversidade != NULL; pAuxElUniversidade = pAuxElUniversidade->getProximo())
    {
        pAuxUniversidade = pAuxElUniversidade->getInfo();

        GravadorUniversidades << pAuxUniversidade->getId()   << ""
                              << pAuxUniversidade->getNome() << endl;
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
        char nome[150];

        RecuperadorUniversidades >> id >> nome;
        if (0 != strcmp(nome, ""))
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
    LTUniversidades.limpar();
}
