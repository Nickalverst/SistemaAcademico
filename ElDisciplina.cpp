#include "ElDisciplina.h"
#include <stdio.h>

ElDisciplina::ElDisciplina()
{
    pProx = NULL;
    pAnter = NULL;
}

ElDisciplina::~ElDisciplina()
{
    pProx = NULL;
    pAnter = NULL;
}

char* ElDisciplina::getNome()
{
    return pDisc->getNome();
}

void ElDisciplina::setNome(const char* nm)
{
    pDisc->setNome(nm);
}

void ElDisciplina::setDisciplina(Disciplina* d)
{
    pDisc = d;
}

Disciplina* ElDisciplina::getDisciplina()
{
    return pDisc;
}

ElDisciplina* ElDisciplina::getDisciplinaAnterior()
{
    return pAnter;
}

void ElDisciplina::setDisciplinaAnterior(ElDisciplina* d)
{
    pAnter = d;
}

ElDisciplina* ElDisciplina::getProxDisciplina()
{
    return pProx;
}

void ElDisciplina::setProxDisciplina(ElDisciplina* d)
{
    pProx = d;
}
