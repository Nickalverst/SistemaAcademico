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
        LTDepartamentos.incluaInfo(pd);
    }
    else
    {
        cout << "Ponteiro nulo. \n" << endl;
    }
}

void ListaDepartamentos::listeDepartamentos()
{
    Elemento<Departamento>* pElAux = NULL;
    Departamento* pDeAux = NULL;

    for (pElAux = LTDepartamentos.getPrimeiro(); pElAux != NULL; pElAux = pElAux->getProximo())
    {
        pDeAux = pElAux->getInfo();
        printf("%s. \n", pDeAux->getNome());
    }
}

void ListaDepartamentos::listeDepartamentosReverso()
{
    Elemento<Departamento>* pElAux = NULL;
    Departamento* pDeAux = NULL;

    for (pElAux = LTDepartamentos.getAtual(); pElAux != NULL; pElAux = pElAux->getAnterior())
    {
        pDeAux = pElAux->getInfo();
        printf("%s. \n", pDeAux->getNome());
    }
}

Departamento* ListaDepartamentos::localizar(const char* n)
{
    Elemento<Departamento>* pElAux = NULL;
    Departamento* pDeAux = NULL;

    for (pElAux = LTDepartamentos.getPrimeiro(); pElAux != NULL; pElAux = pElAux->getProximo())
    {
        pDeAux = pElAux->getInfo();
        if (0 == strcmp(n, pDeAux->getNome()))
        {
            return pDeAux;
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

    Elemento<Departamento>* pAuxElDepartamento = NULL;
    Departamento* pAuxDepartamento = NULL;

    for (pAuxElDepartamento = LTDepartamentos.getPrimeiro(); pAuxElDepartamento != NULL; pAuxElDepartamento = pAuxElDepartamento->getProximo())
    {
        pAuxDepartamento = pAuxElDepartamento->getInfo();

        GravadorDepartamentos << pAuxDepartamento->getId()   << ""
                              << pAuxDepartamento->getNome() << endl;
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
        char nome[150];

        RecuperadorDepartamentos >> id >> nome;
        if (0 != strcmp(nome, ""))
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
    LTDepartamentos.limpar();
}
