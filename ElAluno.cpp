/* C�DIGO LEGADO 
* 
* Esta classe foi usada como gerenciador de objetos da classe Aluno
* durante o processo de aprendizado sobre orienta��o a objetos e n�o
* faz parte da vers�o atual do Sistema Acad�mico, visto que foi subs
* titu�do pela classe Elemento parametrizado com a classe Aluno.
* 
*/

#include "ElAluno.h"

ElAluno::ElAluno()
{
    pProx = NULL;
    pAnter = NULL;
}

ElAluno::~ElAluno()
{
    pProx = NULL;
    pAnter = NULL;
}

char* ElAluno::getNome()
{
    return pAl->getNome();
}

void ElAluno::setNome(const char* nm)
{
    pAl->setNome(nm);
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
