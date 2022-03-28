#include "ListaAlunos.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

ListaAlunos::ListaAlunos(int na, const char* n)
{
    numero_alunos = na;
    cont_alunos = 0;

    pElAlunoAtual = NULL;
    pElAlunoPrim = NULL;

    strcpy(nome, n);
}

ListaAlunos::~ListaAlunos()
{
    ElAluno *pAux1, *pAux2;

    pAux2 = NULL;

    for (pAux1 = pElAlunoPrim; pAux1 != NULL; pAux1 = pAux2)
    {
        pAux2 = pAux1->getProxAluno();
        delete(pAux1);
    }

    pElAlunoPrim = NULL;
    pElAlunoAtual = NULL;

    /* Versão do professor:

    ElAluno *pAux1, *pAux2;

    pAux1 = pElAlunoPrim;
    pAux2 = pAux1;

    while (pAux1 != NULL)
    {
        pAux2 = pAux1->pProx;
        delete(pAux1);
        pAux1 = pAux2;
    }

    pElAlunoPrim = NULL;
    pElAlunoAtual = NULL;

    */
}

void ListaAlunos::setNumeroAlunos(int na)
{
    numero_alunos = 1;
    numero_alunos = na;
}

int ListaAlunos::getNumeroAlunos()
{
    return numero_alunos;
}

void ListaAlunos::setNome(char* n)
{
    strcpy(nome, n);
}

char* ListaAlunos::getNome()
{
    return nome;
}

void ListaAlunos::incluaAluno(Aluno* pa)
{
    ElAluno* pAux;

    pAux = new ElAluno();
    pAux->setAluno(pa);

    if((cont_alunos < numero_alunos) && (pa != NULL))
    {
        if (pElAlunoPrim == NULL)
        {
            pElAlunoPrim = pAux;
            pElAlunoAtual = pAux;
        } else
        {
            pElAlunoAtual->setProxAluno(pAux);
            pAux->setAlunoAnterior(pAux);
            pElAlunoAtual = pAux;
        }
        cont_alunos++;
    } else
    {
        if (pa != NULL)
        {
            cout << "Aluno não incluído. Turma já lotada em " << numero_alunos << " alunos. \n" << endl;
        } else
        {
            cout << "Ponteiro nulo. \n" << endl;
        }
    }
}

void ListaAlunos::listeAlunos()
{
    ElAluno* pAux = NULL;
    for (pAux = pElAlunoPrim; pAux != NULL; pAux = pAux->getProxAluno())
    {
        cout << "Aluno " << pAux->getNome() << " matriculado na disciplina " << nome << "." << endl;
    }
}

void ListaAlunos::listeAlunosInverso()
{
    ElAluno* pAux = NULL;
    for (pAux = pElAlunoAtual; pAux != NULL; pAux = pAux->getAlunoAnterior())
    {
        cout << "Aluno " << pAux->getNome() << " matriculado na disciplina " << nome << "." << endl;
    }
}
