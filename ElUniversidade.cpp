/* CÓDIGO LEGADO
*
* Esta classe foi usada como gerenciador de objetos da classe Universidade
* durante o processo de aprendizado sobre orientação a objetos e não
* faz parte da versão atual do Sistema Acadêmico, visto que foi subs
* tituído pela classe Elemento parametrizado com a classe Universidade.
*
*/

#include "ElUniversidade.h"

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
