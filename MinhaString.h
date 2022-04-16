/* C�DIGO LEGADO
*
* Esta classe foi desenvolvida objetivando o aprendizado de sobrecar-
* ga de m�todos e operadores e da palavra-chave const e n�o faz parte
* da vers�o atual do Sistema Acad�mico, visto que a classe String, da
* Standard Template Library (STL) agora desempenha seu papel.
*
*/

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
