#pragma once

#include "Pessoa.h"
#include <vector>
#include <string>
using namespace std;

class ListaPessoas
{
    private:
        vector<Pessoa*> LTPessoas;

    public:
        ListaPessoas();
        ~ListaPessoas();

        void incluaPessoa(Pessoa* pa);
        void limpaLista();

        Pessoa* localizar (const string n);

        void listePessoas();
        void listePessoasInverso();
};
