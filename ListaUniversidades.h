#pragma once

#include "Universidade.h"
#include <string>
#include <vector>
using namespace std;

class ListaUniversidades
{
    private:
        vector<Universidade*> LTUniversidades;
    public:
        ListaUniversidades();
        ~ListaUniversidades();

        void incluaUniversidade(Universidade *pu);
        void limpaLista();

        void listeUniversidades();
        void listeUniversidadesInverso();

        Universidade* localizar (const string n);

        void graveUniversidades();
        void recupereUniversidades();
};
