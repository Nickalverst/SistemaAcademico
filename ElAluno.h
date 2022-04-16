/* C�DIGO LEGADO
*
* Esta classe foi usada como gerenciador de objetos da classe Aluno
* durante o processo de aprendizado sobre orienta��o a objetos e n�o
* faz parte da vers�o atual do Sistema Acad�mico, visto que foi subs
* titu�do pela classe Elemento parametrizado com a classe Aluno.
*
*/

#pragma once

#include "Aluno.h"

class ElAluno
{
    private:
        Aluno* pAl;
        ElAluno* pProx;
        ElAluno* pAnter;
    public:
        ElAluno();
        ~ElAluno();

        void setAluno(Aluno* pa);
        Aluno* getAluno();

        ElAluno* getProxAluno();
        void setProxAluno(ElAluno* al);
        ElAluno* getAlunoAnterior();
        void setAlunoAnterior(ElAluno* al);

        char* getNome();
        void setNome(const char* nm);
};
