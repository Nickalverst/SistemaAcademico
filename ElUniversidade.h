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
