#include "Disciplina.h"
#include "Departamento.h"

#include <stdio.h>
#include <string.h>

Disciplina::Disciplina(const char* n, const char* ac, int na)
{
    pDepAssociado = NULL;

    ObjAlunos = new ListaAlunos(na, n);

    strcpy(area_conhecimento, ac);
    strcpy(nome, n);
}

Disciplina::~Disciplina()
{
    pDepAssociado = NULL;
}

void Disciplina::setId(int n)
{
    id = n;
}

int Disciplina::getId()
{
    return id;
}

void Disciplina::setNome(const char* n)
{
    strcpy(nome, n);
}

char* Disciplina::getNome()
{
    return nome;
}

void Disciplina::setDepartamento(Departamento* pdpto)
{
    pDepAssociado = pdpto;


    pdpto->incluaDisciplina(this);
}

Departamento* Disciplina::getDepartamento()
{
    return pDepAssociado;
}

void Disciplina::incluirAluno(Aluno* al)
{
    ObjAlunos->incluaAluno(al);
}

void Disciplina::listaAlunos()
{
    ObjAlunos->listeAlunos();
}

void Disciplina::listaAlunosReverso()
{
    ObjAlunos->listeAlunosInverso();
}
