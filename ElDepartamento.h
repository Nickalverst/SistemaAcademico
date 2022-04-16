/* CÓDIGO LEGADO
*
* Esta classe foi usada como gerenciador de objetos da classe Departamento
* durante o processo de aprendizado sobre orientação a objetos e não
* faz parte da versão atual do Sistema Acadêmico, visto que foi subs
* tituído pela classe Elemento parametrizado com a classe Departamento.
*
*/

#pragma once

#include "Departamento.h"

class ElDepartamento
{
    private:
        Departamento* pDep;
        ElDepartamento* pProx;
        ElDepartamento* pAnter;
    public:
        ElDepartamento();
        ~ElDepartamento();

        void setDepartamento(Departamento* dep);
        Departamento* getDepartamento();

        ElDepartamento* getProxDepartamento();
        void setProxDepartamento(ElDepartamento* dep);
        ElDepartamento* getDepartamentoAnterior();
        void setDepartamentoAnterior(ElDepartamento* dep);

        char* getNome();
        void setNome(const char* nm);
};
