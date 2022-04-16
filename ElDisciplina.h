/* C�DIGO LEGADO
*
* Esta classe foi usada como gerenciador de objetos da classe Disciplina
* durante o processo de aprendizado sobre orienta��o a objetos e n�o
* faz parte da vers�o atual do Sistema Acad�mico, visto que foi subs
* titu�do pela classe Elemento parametrizado com a classe Disciplina.
*
*/

#pragma once

#include "Disciplina.h"

class ElDisciplina
{
    private:
        Disciplina* pDisc;
        ElDisciplina* pProx;
        ElDisciplina* pAnter;
    public:
        ElDisciplina();
        ~ElDisciplina();

        void setDisciplina(Disciplina* d);
        Disciplina* getDisciplina();

        ElDisciplina* getProxDisciplina();
        void setProxDisciplina(ElDisciplina* d);
        ElDisciplina* getDisciplinaAnterior();
        void setDisciplinaAnterior(ElDisciplina* d);

        const char* getNome();
        void setNome(const char* nm);
};
