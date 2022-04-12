#include "ListaDepartamentos.h"
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;

ListaDepartamentos::ListaDepartamentos(int nd, const char* n)
{
    numero_dep = nd;
    cont_dep = 0;

    pElDepartamentoAtual = NULL;
    pElDepartamentoPrim = NULL;

    strcpy(nome, n);
}

ListaDepartamentos::~ListaDepartamentos()
{
    ElDepartamento *pAux1, *pAux2;

    pAux1 = pElDepartamentoPrim;
    pAux2 = pAux1;

    while (pAux1 != NULL)
    {
        pAux2 = pAux1->getProxDepartamento();
        delete(pAux1);
        pAux1 = pAux2;
    }

    pElDepartamentoAtual = NULL;
    pElDepartamentoPrim = NULL;
}

void ListaDepartamentos::setNome(const char* n)
{
    strcpy(nome, n);
}

void ListaDepartamentos::incluaDepartamento(Departamento* pd)
{
    if ((cont_dep < numero_dep && pd != NULL) || (numero_dep == -1 && pd != NULL))
    {
        ElDepartamento* pAux = new ElDepartamento;

        pAux->setDepartamento(pd);

        if (pElDepartamentoPrim == NULL)
        {
            pElDepartamentoPrim = pAux;
            pElDepartamentoAtual = pAux;
        } else
        {
            pElDepartamentoAtual->setProxDepartamento(pAux);
            pAux->setDepartamentoAnterior(pElDepartamentoAtual);
            pElDepartamentoAtual = pAux;
        }
        cont_dep++;
    }
    else
    {
        cout << "Departamento não incluído, limite de " << numero_dep << "excedido. \n" << endl;
    }
}

void ListaDepartamentos::listeDepartamentos()
{
    for (ElDepartamento* pAux = pElDepartamentoPrim; pAux != NULL; pAux = pAux->getProxDepartamento())
    {
        printf("O departamento %s pertence à universidade %s. \n", pAux->getNome(), nome); // pAux->getDepartamento()->getUniversidade()->getNome());
    }
}

void ListaDepartamentos::listeDepartamentosReverso()
{
    for (ElDepartamento* pAux = pElDepartamentoAtual; pAux != NULL; pAux = pAux->getDepartamentoAnterior())
    {
        printf("O departamento %s pertence à universidade %s. \n", pAux->getNome(), nome); // pAux->getDepartamento()->getUniversidade()->getNome());
    }
}

Departamento* ListaDepartamentos::localizar(char* n)
{
    ElDepartamento *pAux = NULL;

    for (pAux = pElDepartamentoPrim; pAux != NULL; pAux = pAux->getProxDepartamento())
    {
        if (0 == strcmp(n, pAux->getNome()))
        {
            return pAux->getDepartamento();
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

    ElDepartamento* pAuxElDepartamento = NULL;
    Departamento* pAuxDepartamento = NULL;

    for (pAuxElDepartamento = pElDepartamentoPrim; pAuxElDepartamento != NULL; pAuxElDepartamento = pAuxElDepartamento->getProxDepartamento())
    {
        pAuxDepartamento = pAuxElDepartamento->getDepartamento();

        GravadorDepartamentos << pAuxDepartamento->getId()   << ""
                              << pAuxDepartamento->getNome() << endl;
    }

    GravadorDepartamentos.close();
    cout << "Êxito na gravação. " << endl;
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
        }
    }

    RecuperadorDepartamentos.close();
    cout << "Êxito na recuperação. " << endl;
}

void ListaDepartamentos::limpaLista()
{
    ElDepartamento *pAux1 = NULL, *pAux2 = NULL;

    for (pAux1 = pElDepartamentoPrim; pAux1 != NULL; pAux1 = pAux2)
    {
        pAux2 = pAux1->getProxDepartamento();
        delete (pAux1);
    }

    pElDepartamentoAtual = NULL;
    pElDepartamentoPrim = NULL;
}
