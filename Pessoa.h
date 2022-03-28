#pragma once
#include "Universidade.h"
#include "Departamento.h"
class Pessoa
{
protected:
    int idade;
    int diaNasc;
    int mesNasc;
    int anoNasc;
    char nome[30];

public:
    Pessoa(int nDia, int nMes, int nAno, const char* nome = "");
    Pessoa();
    void inicializa (int nDia, int nMes, int nAno, const char* nome = "");

    void calculaIdade(int diaAt, int mesAt, int anoAt);
    void imprimeIdade();
    void calculaImprimeIdade(int diaAT, int mesAT, int anoAT);

    int getIdade();
    char* getNome();

    void setNome(char nNome[30]);
    void setDataDeNascimento(int nDia, int nMes, int nAno);
};
