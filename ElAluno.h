/* CÓDIGO LEGADO
*
* Esta classe foi usada como gerenciador de objetos da classe Aluno
* durante o processo de aprendizado sobre orientação a objetos e não
* faz parte da versão atual do Sistema Acadêmico, visto que foi subs
* tituído pela classe Elemento parametrizado com a classe Aluno.
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
