#include "ListaUniversidades.h"
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;

ListaUniversidades::ListaUniversidades(int nd, const char* n)
{
    numero_univ = nd;
    cont_univ = 0;

    pElUniversidadeAtual = NULL;
    pElUniversidadePrim = NULL;

    nome = n;
}

ListaUniversidades::~ListaUniversidades()
{
    ElUniversidade *pAux1, *pAux2;

    pAux1 = pElUniversidadePrim;
    pAux2 = pAux1;

    while (pAux1 != NULL)
    {
        pAux2 = pAux1->getProxUniversidade();
        delete(pAux1);
        pAux1 = pAux2;
    }

    pElUniversidadeAtual = NULL;
    pElUniversidadePrim = NULL;
}

void ListaUniversidades::setNome(const char* n)
{
    nome = n;
}

void ListaUniversidades::incluaUniversidade(Universidade* pd)
{
    if ((cont_univ < numero_univ && pd != NULL) || (numero_univ == -1 && pd != NULL))
    {
        ElUniversidade* pAux = new ElUniversidade;

        pAux->setUniversidade(pd);

        if (pElUniversidadePrim == NULL)
        {
            pElUniversidadePrim = pAux;
            pElUniversidadeAtual = pAux;
        } else
        {
            pElUniversidadeAtual->setProxUniversidade(pAux);
            pAux->setUniversidadeAnterior(pElUniversidadeAtual);
            pElUniversidadeAtual = pAux;
        }
        cont_univ++;
    }
    else
    {
        cout << "Universidade não incluída, limite de " << numero_univ << "excedido. \n" << endl;
    }
}

void ListaUniversidades::listeUniversidades()
{
    for (ElUniversidade* pAux = pElUniversidadePrim; pAux != NULL; pAux = pAux->getProxUniversidade())
    {
        printf("%s. \n", pAux->getNome());
    }
}

void ListaUniversidades::listeUniversidadesInverso()
{
    for (ElUniversidade* pAux = pElUniversidadeAtual; pAux != NULL; pAux = pAux->getUniversidadeAnterior())
    {
        printf("%s. \n", pAux->getNome());
    }
}

Universidade* ListaUniversidades::localizar(const char* n)
{
    ElUniversidade *pAux = NULL;

    for (pAux = pElUniversidadePrim; pAux != NULL; pAux = pAux->getProxUniversidade())
    {
        if (0 == strcmp(n, pAux->getNome()))
        {
            return pAux->getUniversidade();
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

    ElUniversidade* pAuxElUniversidade = NULL;
    Universidade* pAuxUniversidade = NULL;

    for (pAuxElUniversidade = pElUniversidadePrim; pAuxElUniversidade != NULL; pAuxElUniversidade = pAuxElUniversidade->getProxUniversidade())
    {
        pAuxUniversidade = pAuxElUniversidade->getUniversidade();

        GravadorUniversidades << pAuxUniversidade->getId()   << ""
                              << pAuxUniversidade->getNome() << endl;
    }

    GravadorUniversidades.close();
    cout << "Êxito na gravação. " << endl;
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
        }
    }

    RecuperadorUniversidades.close();
    cout << "Êxito na recuperação. " << endl;
}

void ListaUniversidades::limpaLista()
{
    ElUniversidade *pAux1 = NULL, *pAux2 = NULL;

    for (pAux1 = pElUniversidadePrim; pAux1 != NULL; pAux1 = pAux2)
    {
        pAux2 = pAux1->getProxUniversidade();
        delete (pAux1);
    }

    pElUniversidadeAtual = NULL;
    pElUniversidadePrim = NULL;
}
