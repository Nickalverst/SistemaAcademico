#pragma once

#include "Pessoa.h"
#include "Lista.h"

class ListaPessoas
{
    private:
        Lista<Pessoa> LTPessoas;

    public:
        ListaPessoas();
        ~ListaPessoas();

        void incluaPessoa(Pessoa* pa);
        void limpaLista();

        Pessoa* localizar (const char* n);

        void listePessoas();
        void listePessoasInverso();
};
