#include "Pessoa.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Universidade.h"
using std::cout;
using std::endl;

int Pessoa::cont = 0;

Pessoa::Pessoa(int i, int nDia, int nMes, int nAno, const string nNome)
{
    id = i;
    cont++;

    nome = nNome;

    if (nDia > 0 && nDia <= 31)
        diaNasc = nDia;
    if (nMes <= 12 && nMes > 0)
        mesNasc = nMes;

    anoNasc = nAno;

    idade = -1;

    calculaIdade(7, 3, 2022);
}

Pessoa::Pessoa() // O C++ sempre cria uma construtora sem parâmetros
{
    cont++;
    inicializa(0, 0, 0);
}

Pessoa::~Pessoa()
{
    cont--;
}

int Pessoa::getCont()
{
    return cont;
}

void Pessoa::inicializa(int nDia, int nMes, int nAno, const string nNome)
{
    id = -1;
    nome = nNome;

    if (nDia > 0 && nDia <= 31)
        diaNasc = nDia;
    if (nMes <= 12 && nMes > 0)
        mesNasc = nMes;

    anoNasc = nAno;

    idade = -1;

    calculaIdade(7, 3, 2022);
}

void Pessoa::calculaIdade(int diaAT, int mesAT, int anoAT)
{
    idade = anoAT - anoNasc;

	if (anoAT > anoNasc)
	{
		if (mesNasc > mesAT)
		{
			idade -= 1;
		} else {
			if (mesNasc == mesAT)
			{
				if (diaNasc > diaAT)
				{
					idade -= 1;
				}
			}
		}
	} else {
		cout << "Anos atual e de nascimento incompatíveis." << endl;
		return;
	}
}

void Pessoa::imprimeIdade()
{
    cout << nome << " tem " << idade << " anos de idade." << endl;
}

void Pessoa::calculaImprimeIdade(int diaAT, int mesAT, int anoAT)
{
    calculaIdade(diaAT, mesAT, anoAT);
    imprimeIdade();
}

int Pessoa::getIdade() const
{
    return idade;
}

string Pessoa::getNome()
{
    return nome;
}

void Pessoa::setNome(string nNome)
{
    nome = nNome;
}

void Pessoa::setDataDeNascimento(int nDia, int nMes, int nAno)
{
    if (nDia > 0 && nDia <= 31)
        diaNasc = nDia;
    if (nMes <= 12 && nMes > 0)
        mesNasc = nMes;

    anoNasc = nAno;
}

int Pessoa::getId() const
{
    return id;
}

void Pessoa::setId(int i)
{
    id = i;
}

void Pessoa::informaProventos()
{
    cout << "Nenhuma informação sobre proventos de " << nome << "." << endl;
}
