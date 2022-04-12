#pragma once
#include "Universidade.h"
#include "Departamento.h"
class Pessoa
{
protected:
    int id;
    int idade;
    int diaNasc;
    int mesNasc;
    int anoNasc;
    char nome[30];

public:
    Pessoa(int i, int nDia = 0, int nMes = 0, int nAno = 0, const char* nNome = "");
    Pessoa();
    void inicializa (int nDia, int nMes, int nAno, const char* nome = "");

    void calculaIdade(int diaAt, int mesAt, int anoAt);
    void imprimeIdade();
    void calculaImprimeIdade(int diaAT, int mesAT, int anoAT);

    int getIdade();
    char* getNome();

    void setId(int id);
    int getId();

    void setNome(char nNome[30]);
    void setDataDeNascimento(int nDia, int nMes, int nAno);
};
