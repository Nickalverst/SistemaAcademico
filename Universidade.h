#pragma once
#include "Departamento.h"
#include "ListaDepartamentos.h"
#include <vector>
using namespace std;

class Universidade
{
    private:
        int id;
        string nome;
        ListaDepartamentos ObjLDepartamentos;

    public:
        Universidade(int i = -1, const string n = "");
        ~Universidade();

        void setNome(const string n);
        string getNome();

        int getId();
        void setId(int i);

        void incluaDepartamento(Departamento* pdep);
        void listeDepartamentos();
        void listeDepartamentosReverso();
};
