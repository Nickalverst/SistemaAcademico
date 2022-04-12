#pragma once

#include "ElUniversidade.h"
#include "Universidade.h"
#include "MinhaString.h"

class ListaUniversidades
{
private:
    int cont_univ;
    int numero_univ;
    MinhaString nome;
    ElUniversidade* pElUniversidadePrim;
    ElUniversidade* pElUniversidadeAtual;
public:
    ListaUniversidades(int nu = 1000, const char* n = "");
    ~ListaUniversidades();

    void setNome(const char* n);
    char* getNome();

    void incluaUniversidade(Universidade *pu);
    void listeUniversidades();
    void listeUniversidadesInverso();
    Universidade* localizar (const char* n);

    void graveUniversidades();
    void recupereUniversidades();
    void limpaLista();
};
