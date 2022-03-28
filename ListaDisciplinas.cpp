#include "ListaDisciplinas.h"
#include <string.h>
#include <iostream>
using namespace std;

ListaDisciplinas::ListaDisciplinas(int nd, const char* n)
{
    numero_disc = nd;
    cont_disc = 0;

    pElDisciplinaAtual = NULL;
    pElDisciplinaPrim = NULL;

    strcpy(nome, n);
}

ListaDisciplinas::~ListaDisciplinas()
{
    ElDisciplina *pAux1, *pAux2;

    pAux1 = pElDisciplinaPrim;
    pAux2 = pAux1;

    while (pAux1 != NULL)
    {
        pAux2 = pAux1->getProxDisciplina();
        delete(pAux1);
        pAux1 = pAux2;
    }

    pElDisciplinaAtual = NULL;
    pElDisciplinaPrim = NULL;
}

void ListaDisciplinas::setNome(const char* n)
{
    strcpy(nome, n);
}

void ListaDisciplinas::incluaDisciplina(Disciplina* pd)
{
    if ((cont_disc < numero_disc && pd != NULL) || (numero_disc == -1 && pd != NULL))
    {
        ElDisciplina* pAux = new ElDisciplina;

        pAux->setDisciplina(pd);

        if (pElDisciplinaPrim == NULL)
        {
            pElDisciplinaPrim = pAux;
            pElDisciplinaAtual = pAux;
        } else
        {
            pElDisciplinaAtual->setProxDisciplina(pAux);
            pAux->setDisciplinaAnterior(pElDisciplinaAtual);
            pElDisciplinaAtual = pAux;
        }
        cont_disc++;
    }
    else
    {
        cout << "Disciplina não incluída, limite de " << numero_disc << "excedido. \n" << endl;
    }
}

void ListaDisciplinas::listeDisciplinas()
{
    for (ElDisciplina* pAux = pElDisciplinaPrim; pAux != NULL; pAux = pAux->getProxDisciplina())
    {
        printf("A disciplina %s pertence ao departamento %s. \n", pAux->getNome(), pAux->getDisciplina()->getDepartamento()->getNome());
    }
}

void ListaDisciplinas::listeDisciplinasReverso()
{
    for (ElDisciplina* pAux = pElDisciplinaAtual; pAux != NULL; pAux = pAux->getDisciplinaAnterior())
    {
        printf("A disciplina %s pertence ao departamento %s. \n", pAux->getNome(), pAux->getDisciplina()->getDepartamento()->getNome());
    }
}
