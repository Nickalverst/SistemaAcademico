/* C�DIGO LEGADO
*
* Esta classe foi usada como gerenciador de objetos da classe Disciplina
* durante o processo de aprendizado sobre orienta��o a objetos e n�o
* faz parte da vers�o atual do Sistema Acad�mico, visto que foi subs
* titu�do pela classe Elemento parametrizado com a classe Disciplina.
*
*/

#include "ElDisciplina.h"

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

const char* ElDisciplina::getNome()
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
