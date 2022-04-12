#include "Departamento.h"
#include "Disciplina.h"

Disciplina::Disciplina(int i, const char* n, const char* ac, int na):
ObjLAlunos()
{
    id = i;
    pDepAssociado = NULL;

    numero_alunos = na;
    strcpy(nome, n);
    strcpy(area_conhecimento, ac);
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

int Disciplina::getNumeroAlunos()
{
    return numero_alunos;
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
    if (NULL != al)
    {
        if ((cont_alunos < numero_alunos) || (-1 == numero_alunos))
        {
            ObjLAlunos.incluaAluno(al);
            cont_alunos++;
        }
        else
        {
            cout << "Aluno não incluído. Turma lotada em " << numero_alunos << "alunos. " << endl;
        }
    }
    else
    {
        cout << "Erro! Aluno não incluído. Ponteiro inválido. " << endl;
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
