#include "ListaUniversidades.h"
#include <string.h>
#include <iostream>
using namespace std;

ListaUniversidades::ListaUniversidades(int nd, const char* n)
{
    numero_univ = nd;
    cont_univ = 0;

    pElUniversidadeAtual = NULL;
    pElUniversidadePrim = NULL;

    strcpy(nome, n);
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
    strcpy(nome, n);
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
        printf("%s. \n", pAux->getNome(), nome);
    }
}

void ListaUniversidades::listeUniversidadesInverso()
{
    for (ElUniversidade* pAux = pElUniversidadeAtual; pAux != NULL; pAux = pAux->getUniversidadeAnterior())
    {
        printf("%s. \n", pAux->getNome(), nome);
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
