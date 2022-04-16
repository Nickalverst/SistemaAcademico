/* CÓDIGO LEGADO 
* 
* Esta classe foi usada como gerenciador de objetos da classe Aluno
* durante o processo de aprendizado sobre orientação a objetos e não
* faz parte da versão atual do Sistema Acadêmico, visto que foi subs
* tituído pela classe Elemento parametrizado com a classe Aluno.
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
