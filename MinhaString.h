#pragma once
#include <iostream>
using namespace std;

class MinhaString
{
private:
	int tamanho;
	char* pStr;

	void setString(const char* s);

public:
	MinhaString(const char* s = "");
	~MinhaString();

	const char* getString();

	void operator = (const char* s); // Sobrecarga do operador "recebe"
	void operator = (MinhaString& s);
	bool operator == (MinhaString& s);
};

ostream& operator << (ostream& saida, MinhaString& p);
