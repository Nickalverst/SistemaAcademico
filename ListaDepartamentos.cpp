#include "ListaDepartamentos.h"
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;

ListaDepartamentos::ListaDepartamentos()
{
}

ListaDepartamentos::~ListaDepartamentos()
{
}

void ListaDepartamentos::incluaDepartamento(Departamento* pd)
{
    if (NULL != pd)
    {
        LTDepartamentos.push_back(pd);
    }
    else
    {
        cout << "Ponteiro nulo. \n" << endl;
    }
}

void ListaDepartamentos::listeDepartamentos()
{
    for (int i = 0; i < (int)LTDepartamentos.size(); i++)
    {
        cout << LTDepartamentos[i]->getNome() << endl;
    }
}

void ListaDepartamentos::listeDepartamentosReverso()
{
    for (int i = LTDepartamentos.size(); i > 0; i--)
    {
        cout << LTDepartamentos[i]->getNome() << endl;
    }
}

Departamento* ListaDepartamentos::localizar(string n)
{
    for (int i = 0; i < (int)LTDepartamentos.size(); i++)
    {
        if (LTDepartamentos[i]->getNome() == n)
        {
            return LTDepartamentos[i];
        }
    }

    return NULL;
}

void ListaDepartamentos::graveDepartamentos()
{
    ofstream GravadorDepartamentos("departamentos.dat", ios::out);

    if (!GravadorDepartamentos)
    {
        cerr << "Arquivo não pode ser aberto. " << endl;
        fflush(stdin);
        getchar();
        return;
    }

    for (int i = 0; i < (int)LTDepartamentos.size(); i++)
    {
        GravadorDepartamentos << LTDepartamentos[i]->getId()   << ""
                              << LTDepartamentos[i]->getNome() << endl;
    }

    GravadorDepartamentos.close();
    cout << "Êxito na gravação dos departamentos. " << endl;
    fflush(stdin);
    getchar();
}

void ListaDepartamentos::recupereDepartamentos()
{
    ifstream RecuperadorDepartamentos("alunos.dat", ios::in);

    if (!RecuperadorDepartamentos)
    {
        cerr << "Arquivo não pode ser aberto. " << endl;
        fflush(stdin);
        getchar();
        return;
    }
    limpaLista();

    while (!RecuperadorDepartamentos.eof())
    {
        Departamento* pAuxDepartamento = NULL;
        int id;
        string nome;

        RecuperadorDepartamentos >> id >> nome;
        if (nome != "")
        {
            pAuxDepartamento = new Departamento(-1);
            pAuxDepartamento->setId(id);
            pAuxDepartamento->setNome(nome);

            incluaDepartamento(pAuxDepartamento);
        }
    }

    RecuperadorDepartamentos.close();
    cout << "Êxito na recuperação dos departamentos. " << endl;
    fflush(stdin);
    getchar();
}

void ListaDepartamentos::limpaLista()
{
    for (int i = 0; i < (int)LTDepartamentos.size(); i++)
    {
        delete LTDepartamentos[i];
    }
    LTDepartamentos.clear();
}
