#pragma once
#include "Universidade.h"
#include "Departamento.h"
#include <string>
using namespace std;

class Pessoa
{
protected:
    int id;
    int idade;
    int diaNasc;
    int mesNasc;
    int anoNasc;
    string nome;
    static int cont;

public:
    Pessoa(int i, int nDia = 0, int nMes = 0, int nAno = 0, const string nNome = "");
    Pessoa();
    virtual ~Pessoa();
    void inicializa (int nDia, int nMes, int nAno, const string nome = "");

    void calculaIdade(int diaAt, int mesAt, int anoAt);
    void imprimeIdade();

    void calculaImprimeIdade(int diaAT, int mesAT, int anoAT);
    int getIdade() const;

    void setNome(string nNome);
    string getNome();

    void setId(int id);
    int getId() const;

    static int getCont();

    void setDataDeNascimento(int nDia, int nMes, int nAno);

    virtual void informaProventos();
};
