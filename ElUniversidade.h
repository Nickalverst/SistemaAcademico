/* C�DIGO LEGADO
*
* Esta classe foi usada como gerenciador de objetos da classe Universidade
* durante o processo de aprendizado sobre orienta��o a objetos e n�o
* faz parte da vers�o atual do Sistema Acad�mico, visto que foi subs
* titu�do pela classe Elemento parametrizado com a classe Universidade.
*
*/

#pragma once

#include "Universidade.h"

class ElUniversidade
{
    private:
        Universidade* pUniv;
        ElUniversidade* pProx;
        ElUniversidade* pAnter;
    public:
        ElUniversidade();
        ~ElUniversidade();

        void setUniversidade(Universidade* d);
        Universidade* getUniversidade();

        ElUniversidade* getProxUniversidade();
        void setProxUniversidade(ElUniversidade* d);
        ElUniversidade* getUniversidadeAnterior();
        void setUniversidadeAnterior(ElUniversidade* d);

        char* getNome();
        void setNome(const char* nm);
};
