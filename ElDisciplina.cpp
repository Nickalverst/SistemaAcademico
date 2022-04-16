/* CÓDIGO LEGADO
*
* Esta classe foi usada como gerenciador de objetos da classe Disciplina
* durante o processo de aprendizado sobre orientação a objetos e não
* faz parte da versão atual do Sistema Acadêmico, visto que foi subs
* tituído pela classe Elemento parametrizado com a classe Disciplina.
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
