#include "ElAluno.h"
#include <stdio.h>

ElAluno::ElAluno()
{

}

ElAluno::~ElAluno()
{
}

char* ElAluno::getNome()
{
    return pAl->getNome();
}

void ElAluno::setNome(const char* nm)
{
    //pAl->setNome(nm);
}

void ElAluno::setAluno(Aluno* pa)
{
    pAl = pa;
}

Aluno* ElAluno::getAluno()
{
    return pAl;
}

ElAluno* ElAluno::getAlunoAnterior()
{
    return pProx;
}

void ElAluno::setAlunoAnterior(ElAluno* al)
{
    pAnter = al;
}

ElAluno* ElAluno::getProxAluno()
{
    return pAnter;
}

void ElAluno::setProxAluno(ElAluno* al)
{
    pProx = al;
}
