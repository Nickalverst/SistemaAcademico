#include "ListaPessoas.h"
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;

ListaPessoas::ListaPessoas()
{
}

ListaPessoas::~ListaPessoas()
{
}

void ListaPessoas::incluaPessoa(Pessoa* pe)
{
    if (NULL != pe)
    {
        LTPessoas.incluaInfo(pe);
    }
    else
    {
        cout << "Ponteiro nulo. \n" << endl;
    }
}

void ListaPessoas::listePessoas()
{
    Elemento<Pessoa>* pElAux = NULL;
    Pessoa* pPeAux = NULL;

    for (pElAux = LTPessoas.getPrimeiro(); pElAux != NULL; pElAux = pElAux->getProximo())
    {
        pPeAux = pElAux->getInfo();
        printf("%s. \n", pPeAux->getNome());
    }
}

void ListaPessoas::listePessoasInverso()
{
    Elemento<Pessoa>* pElAux = NULL;
    Pessoa* pPeAux = NULL;

    for (pElAux = LTPessoas.getAtual(); pElAux != NULL; pElAux = pElAux->getAnterior())
    {
        pPeAux = pElAux->getInfo();
        printf("%s. \n", pPeAux->getNome());
    }
}

Pessoa* ListaPessoas::localizar(const char* n)
{
    Elemento<Pessoa>* pElAux = NULL;
    Pessoa* pDeAux = NULL;

    for (pElAux = LTPessoas.getPrimeiro(); pElAux != NULL; pElAux = pElAux->getProximo())
    {
        pDeAux = pElAux->getInfo();
        if (0 == strcmp(n, pDeAux->getNome()))
        {
            return pDeAux;
        }
    }

    return NULL;
}

void ListaPessoas::limpaLista()
{
    LTPessoas.limpar();
}
