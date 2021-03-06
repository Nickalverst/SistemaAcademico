#pragma once
#include "Pessoa.h"

class Aluno : public Pessoa
{
private:
	int RA;
	Disciplina* pDiscAssociada;
public:
	Aluno(int i);
	Aluno();
	virtual ~Aluno();
	void setRA(int ra);
	int getRA();
	void setDisciplina(Disciplina* pd);
	Disciplina* getDisciplina();
	int getId();
};
