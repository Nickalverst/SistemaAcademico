#include "ElUniversidade.h"
#include <stdio.h>

ElUniversidade::ElUniversidade()
{
    pProx = NULL;
    pAnter = NULL;
}

ElUniversidade::~ElUniversidade()
{
    pProx = NULL;
    pAnter = NULL;
}

char* ElUniversidade::getNome()
{
    return pUniv->getNome();
}

void ElUniversidade::setNome(const char* nm)
{
    pUniv->setNome(nm);
}

void ElUniversidade::setUniversidade(Universidade* d)
{
    pUniv = d;
}

Universidade* ElUniversidade::getUniversidade()
{
    return pUniv;
}

ElUniversidade* ElUniversidade::getUniversidadeAnterior()
{
    return pAnter;
}

void ElUniversidade::setUniversidadeAnterior(ElUniversidade* d)
{
    pAnter = d;
}

ElUniversidade* ElUniversidade::getProxUniversidade()
{
    return pProx;
}

void ElUniversidade::setProxUniversidade(ElUniversidade* d)
{
    pProx = d;
}
