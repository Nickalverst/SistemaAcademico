#pragma once

#include "Universidade.h"
#include "Lista.h"

class ListaUniversidades
{
    private:
        Lista<Universidade> LTUniversidades;
    public:
        ListaUniversidades();
        ~ListaUniversidades();

        void incluaUniversidade(Universidade *pu);
        void limpaLista();

        void listeUniversidades();
        void listeUniversidadesInverso();

        Universidade* localizar (const char* n);

        void graveUniversidades();
        void recupereUniversidades();

};
