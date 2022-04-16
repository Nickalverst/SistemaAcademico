#include "ListaPessoas.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;

ListaPessoas::ListaPessoas()
{
}

ListaPessoas::~ListaPessoas()
{
    limpaLista();
}

void ListaPessoas::incluaPessoa(Pessoa* pe)
{
    if (NULL != pe)
    {
        LTPessoas.push_back(pe);
    }
    else
    {
        cout << "Ponteiro nulo. \n" << endl;
    }
}

void ListaPessoas::listePessoas()
{
    for (int i = 0; i < (int)LTPessoas.size(); i++)
    {
        cout << LTPessoas[i]->getNome() << endl;
    }
}

void ListaPessoas::listePessoasInverso()
{
    for (int i = (int)LTPessoas.size(); i > 0; i--)
    {
        cout << LTPessoas[i]->getNome() << endl;
    }
}

Pessoa* ListaPessoas::localizar(const string n)
{
    for (int i = 0; i < (int)LTPessoas.size(); i++)
    {
        if (n == LTPessoas[i]->getNome())
        {
            return LTPessoas[i];
        }
    }

    return NULL;
}

void ListaPessoas::limpaLista()
{
    for (int i = 0; i < (int)LTPessoas.size(); i++)
    {
        delete LTPessoas[i];
    }
    LTPessoas.clear();
}
