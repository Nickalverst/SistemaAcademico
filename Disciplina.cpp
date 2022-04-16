#include "Departamento.h"
#include "Disciplina.h"

Disciplina::Disciplina(int i, string n, string ac, int na):
ObjLAlunos()
{
    id = i;
    pDepAssociado = NULL;

    numero_alunos = na;
    nome = n;
    area_conhecimento = ac;
}

Disciplina::~Disciplina()
{
    pDepAssociado = NULL;
}

void Disciplina::setNumeroAlunos(int na)
{
    numero_alunos = 1;
    numero_alunos = na;
}

int Disciplina::getNumeroAlunos() const
{
    return numero_alunos;
}

void Disciplina::setId(int n)
{
    id = n;
}

int Disciplina::getId() const
{
    return id;
}

void Disciplina::setNome(string n)
{
    nome = n;
}

string Disciplina::getNome() const
{
    return nome;
}

void Disciplina::setDepartamento(Departamento* pdpto)
{
    pDepAssociado = pdpto;


    pdpto->incluaDisciplina(this);
}

Departamento* Disciplina::getDepartamento() const
{
    return pDepAssociado;
}

void Disciplina::incluirAluno(Aluno* al)
{
    if (NULL != al)
    {
        if ((cont_alunos < numero_alunos) || (-1 == numero_alunos))
        {
            ObjLAlunos.incluaAluno(al);
            cont_alunos++;
        }
        else
        {
            cout << "Aluno n�o inclu�do. Turma lotada em " << numero_alunos << "alunos. " << endl;
        }
    }
    else
    {
        cout << "Erro! Aluno n�o inclu�do. Ponteiro inv�lido. " << endl;
    }
}

void Disciplina::listaAlunos()
{
    cout << "\nAlunos matriculados na disciplina " << area_conhecimento << ":" << endl;
    ObjLAlunos.listeAlunos();
}

void Disciplina::listaAlunosReverso()
{
    cout << "\nAlunos matriculados na disciplina " << area_conhecimento << ":" << endl;
    ObjLAlunos.listeAlunosInverso();
}
