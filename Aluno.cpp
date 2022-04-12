#include "Aluno.h"

Aluno::Aluno(int i) : Pessoa(id)
{
    id = -1;
	RA = 0;
}

Aluno::~Aluno()
{
}

void Aluno::setRA(int ra)
{
	RA = ra;
}
int Aluno::getRA()
{
	return RA;
}

int Aluno::getId()
{
	return id;
}
