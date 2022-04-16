/* C�DIGO LEGADO
*
* Esta classe foi usada como gerenciador de objetos da classe Departamento
* durante o processo de aprendizado sobre orienta��o a objetos e n�o
* faz parte da vers�o atual do Sistema Acad�mico, visto que foi subs
* titu�do pela classe Elemento parametrizado com a classe Departamento.
*
*/

#include "ElDepartamento.h"

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
