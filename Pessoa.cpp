#include "Pessoa.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Universidade.h"
using std::cout;
using std::endl;

Pessoa::Pessoa(int i, int nDia, int nMes, int nAno, const char* nNome)
{
    id = i;

    strcpy(nome, nNome);

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
    inicializa(0, 0, 0);
}

void Pessoa::inicializa(int nDia, int nMes, int nAno, const char* nNome)
{
    id = -1;
    strcpy(nome, nNome);

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

int Pessoa::getIdade()
{
    return idade;
}

char* Pessoa::getNome()
{
    return nome;
}

void Pessoa::setNome(char nNome[])
{
    strcpy(nome, nNome);
}

void Pessoa::setDataDeNascimento(int nDia, int nMes, int nAno)
{
    if (nDia > 0 && nDia <= 31)
        diaNasc = nDia;
    if (nMes <= 12 && nMes > 0)
        mesNasc = nMes;

    anoNasc = nAno;
}

int Pessoa::getId()
{
    return id;
}

void Pessoa::setId(int i)
{
    id = i;
}
