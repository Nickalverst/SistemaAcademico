#include "ElDepartamento.h"
#include <stdio.h>

ElDepartamento::ElDepartamento()
{
    pProx = NULL;
    pAnter = NULL;
}

ElDepartamento::~ElDepartamento()
{
    pProx = NULL;
    pAnter = NULL;
}

char* ElDepartamento::getNome()
{
    return pDep->getNome();
}

void ElDepartamento::setNome(const char* nm)
{
    pDep->setNome(nm);
}

void ElDepartamento::setDepartamento(Departamento* dep)
{
    pDep = dep;
}

Departamento* ElDepartamento::getDepartamento()
{
    return pDep;
}

ElDepartamento* ElDepartamento::getDepartamentoAnterior()
{
    return pAnter;
}

void ElDepartamento::setDepartamentoAnterior(ElDepartamento* d)
{
    pAnter = d;
}

ElDepartamento* ElDepartamento::getProxDepartamento()
{
    return pProx;
}

void ElDepartamento::setProxDepartamento(ElDepartamento* d)
{
    pProx = d;
}
