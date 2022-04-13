#pragma once

#include "Aluno.h"

class Estagiario : public Aluno
{
protected:
    float bolsaEstudo;

public:
    Estagiario(int diaNa, int mesNa, int anoNa, const char* n = "");
    Estagiario();
    ~Estagiario();

    void inicializa();
    void setBolsaEstudo(float b);
    float getBolsaEstudo();

    void informaProventos();
};
