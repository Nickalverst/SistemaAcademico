#include "ListaDepartamentos.h"
#include <string.h>
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
        cout << "Departamento n�o inclu�do, limite de " << numero_dep << "excedido. \n" << endl;
    }
}

void ListaDepartamentos::listeDepartamentos()
{
    for (ElDepartamento* pAux = pElDepartamentoPrim; pAux != NULL; pAux = pAux->getProxDepartamento())
    {
        printf("O departamento %s pertence � universidade %s. \n", pAux->getNome(), nome); // pAux->getDepartamento()->getUniversidade()->getNome());
    }
}

void ListaDepartamentos::listeDepartamentosReverso()
{
    for (ElDepartamento* pAux = pElDepartamentoAtual; pAux != NULL; pAux = pAux->getDepartamentoAnterior())
    {
        printf("O departamento %s pertence � universidade %s. \n", pAux->getNome(), nome); // pAux->getDepartamento()->getUniversidade()->getNome());
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
