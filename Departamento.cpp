#include "Departamento.h"
#include "Universidade.h"
#include "Disciplina.h"
#include "ListaDisciplinas.h"

#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

Departamento::Departamento(int i, const char* n)
{
    id = i;
    strcpy(nome, n);
    //ObjLDisciplinas();
}

Departamento::~Departamento()
{
    /*if (ObjLDisciplinas != NULL)
    {
        delete ObjLDisciplinas;
    }*/
}

void Departamento::setNumeroDisciplinas(int i)
{
    numero_disc = i;
}

int Departamento::getNumeroDisciplinas()
{
    return numero_disc;
}

void Departamento::setNome(const char* n)
{
    strcpy(nome, n);
}

char* Departamento::getNome()
{
    return nome;
}

void Departamento::setId(int i)
{
    id = i;
}

int Departamento::getId()
{
    return id;
}

void Departamento::setUniversidade(Universidade* uni)
{
    uniFiliada = uni;
}

Universidade* Departamento::getUniversidade()
{
    return uniFiliada;
}

void Departamento::incluaDisciplina(Disciplina* pd)
{
    /*if (NULL != pd)
    {
        ObjLDisciplinas.incluaDisciplina(pd);
        cont_disc++;
    }
    else
    {
        cout << "Erro! Disciplina não incluída. Ponteiro inválido. " << endl;
    }*/

}

void Departamento::listeDisciplinas()
{
    /*cout << "\nDisciplinas cadastradas no departamento " << nome << ":" << endl;
    ObjLDisciplinas.listeInfos();*/
}

void Departamento::listeDisciplinasReverso()
{
    /*cout << "\nDisciplinas cadastradas no departamento " << nome << ":" << endl;
    ObjLDisciplinas.listeDisciplinasReverso();*/
}
