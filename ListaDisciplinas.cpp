#include "ListaDisciplinas.h"
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;

ListaDisciplinas::ListaDisciplinas(int nd, const char* n)
{
}

ListaDisciplinas::~ListaDisciplinas()
{
    limpaLista();
}

void ListaDisciplinas::incluaDisciplina(Disciplina* pd)
{
    if (pd != NULL)
    {
        LTDisciplinas.incluaInfo(pd);
    }
    else
    {
        cout << "Ponteiro nulo. " << endl;
    }
}

void ListaDisciplinas::listeDisciplinas()
{
    Elemento<Disciplina>* pElAux = NULL;
    Disciplina* pAlAux = NULL;
    for (pElAux = LTDisciplinas.getPrimeiro(); pElAux != NULL; pElAux = pElAux->getProximo())
    {
        pAlAux = pElAux->getInfo();
        cout << "Disciplina " << pAlAux->getNome() << " está cadastrada na universidade. " << endl;
    }
}

void ListaDisciplinas::listeDisciplinasReverso()
{
    Elemento<Disciplina>* pElAux = NULL;
    Disciplina* pAlAux = NULL;
    for (pElAux = LTDisciplinas.getAtual(); pElAux != NULL; pElAux = pElAux->getAnterior())
    {
        pAlAux = pElAux->getInfo();
        cout << "Disciplina " << pAlAux->getNome() << " está cadastrada na universidade. " << endl;
    }
}


void ListaDisciplinas::graveDisciplinas()
{
    ofstream GravadorDisciplinas("disciplinas.dat", ios::out);

    if (!GravadorDisciplinas)
    {
        cerr << "Arquivo não pode ser aberto. " << endl;
        fflush(stdin);
        getchar();
        return;
    }

    Elemento<Disciplina>* pAuxElDisciplina = NULL;
    Disciplina* pAuxDisciplina = NULL;

    for (pAuxElDisciplina = LTDisciplinas.getPrimeiro(); pAuxElDisciplina != NULL; pAuxElDisciplina = pAuxElDisciplina->getProximo())
    {
        pAuxDisciplina = pAuxElDisciplina->getInfo();

        GravadorDisciplinas << pAuxDisciplina->getId()   << ""
                              << pAuxDisciplina->getNome() << endl;
    }

    GravadorDisciplinas.close();
    cout << "Êxito na gravação. " << endl;
}

void ListaDisciplinas::recupereDisciplinas()
{
    ifstream RecuperadorDisciplinas("disciplinas.dat", ios::in);

    if (!RecuperadorDisciplinas)
    {
        cerr << "Arquivo não pode ser aberto. " << endl;
        fflush(stdin);
        getchar();
        return;
    }
    limpaLista();

    while (!RecuperadorDisciplinas.eof())
    {
        Disciplina* pAuxDisciplina = NULL;
        int id;
        char nome[150];

        RecuperadorDisciplinas >> id >> nome;
        if (0 != strcmp(nome, ""))
        {
            pAuxDisciplina = new Disciplina(-1);
            pAuxDisciplina->setId(id);
            pAuxDisciplina->setNome(nome);
        }
    }

    RecuperadorDisciplinas.close();
    cout << "Êxito na recuperação. " << endl;
}

void ListaDisciplinas::limpaLista()
{
    Elemento<Disciplina> *pAux1 = NULL, *pAux2 = NULL;

    for (pAux1 = LTDisciplinas.getPrimeiro(); pAux1 != NULL; pAux1 = pAux2)
    {
        pAux2 = pAux1->getProximo();
        delete (pAux1);
    }
}
