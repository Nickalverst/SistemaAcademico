#include "Departamento.h"
#include "Universidade.h"
#include "Disciplina.h"
#include "ListaDisciplinas.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

Departamento::Departamento(const char* n)
{
    strcpy(nome, n);
    pObjLDisciplinas = new ListaDisciplinas(-1, "");
}

Departamento::~Departamento()
{
    if (pObjLDisciplinas)
    {
        delete pObjLDisciplinas;
    }
}

void Departamento::setNome(const char* n)
{
    strcpy(nome, n);
    pObjLDisciplinas->setNome(n);
}

char* Departamento::getNome()
{
    return nome;
}

void Departamento::setUniversidade(Universidade* uni)
{
    uniFiliada = uni;
}

Universidade* Departamento::getUniversidade()
{
    return uniFiliada;
}

void Departamento::incluaDisciplina(Disciplina* pd)
{
    pObjLDisciplinas->incluaDisciplina(pd);
}

void Departamento::listeDisciplinas()
{
    pObjLDisciplinas->listeDisciplinas();
}

void Departamento::listeDisciplinasReverso()
{
    pObjLDisciplinas->listeDisciplinasReverso();
}
