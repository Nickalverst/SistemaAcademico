#pragma once

#include "Elemento.h"

#include <iostream>
using namespace std;

template<class TIPO>
class Lista
{
private:
    Elemento<TIPO>* pPrimeiro;
    Elemento<TIPO>* pAtual;

public:
    Lista();
    ~Lista();

    void inicializa();
    void limpar();

    bool incluaElemento(Elemento<TIPO>* pElemento);
    bool incluaInfo(TIPO* pInfo);

    Elemento<TIPO>* getPrimeiro();
    Elemento<TIPO>* getAtual();
};

template<class TIPO>
Lista<TIPO>::Lista()
{
    inicializa();
}

template<class TIPO>
Lista<TIPO>::~Lista()
{
    limpar();
}

template<class TIPO>
void Lista<TIPO>::inicializa()
{
    pPrimeiro = NULL;
    pAtual = NULL;
}

template<class TIPO>
void Lista<TIPO>::limpar()
{
    Elemento<TIPO>* pAux1 = pPrimeiro;
    Elemento<TIPO>* pAux2 = NULL;

    while (pAux1 != NULL)
    {
        pAux2 = pAux1->getProximo();
        if (pAux1 != NULL)
        {
            if (pAux1->getInfo() != NULL)
            {
                delete(pAux1->getInfo());
                pAux1->setInfo(NULL);
            }
            delete(pAux1);
            pAux1 = NULL;
        }
        pAux1 = pAux2;
    }

    pPrimeiro = NULL;
    pAtual = NULL;
}

template<class TIPO>
bool Lista<TIPO>::incluaElemento(Elemento<TIPO>* pElemento)
{
    if (NULL != pElemento)
    {
        if (NULL == pPrimeiro)
        {
            pPrimeiro = pElemento;
            pAtual = pElemento;
        }
        else
        {
            pElemento->setAnterior(pAtual);
            pAtual->setProximo(pElemento);
            pAtual = pElemento;
        }

        return true;
    }
    else
    {
        cout << "Erro, elemento nulo na lista. " << endl;
        return false;
    }
}

template<class TIPO>
bool Lista<TIPO>::incluaInfo(TIPO* pInfo)
{
    if (NULL != pInfo)
    {
        Elemento<TIPO>* pElemento = NULL;
        pElemento = new Elemento<TIPO>();
        pElemento->setInfo(pInfo);
        incluaElemento(pElemento);
        return true;
    }
    else
    {
        cout << "Erro, elemento nulo na lista. " << endl;
        return false;
    }
}

template<class TIPO>
Elemento<TIPO>* Lista<TIPO>::getPrimeiro()
{
    return pPrimeiro;
}

template<class TIPO>
Elemento<TIPO>* Lista<TIPO>::getAtual()
{
    return pAtual;
}
