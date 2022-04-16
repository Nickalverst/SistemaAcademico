/* CÓDIGO LEGADO
*
* Esta classe foi desenvolvida objetivando o aprendizado de sobrecar-
* ga de métodos e operadores e da palavra-chave const e não faz parte
* da versão atual do Sistema Acadêmico, visto que a classe String, da
* Standard Template Library (STL) agora desempenha seu papel.
*
*/

#include "MinhaString.h"

MinhaString::MinhaString(const char* s)
{
    pStr = NULL;
    setString(s);
}

MinhaString::~MinhaString()
{
	delete []pStr;
	pStr = NULL;
}

const char* MinhaString::getString()
{
	return getString();
}

void MinhaString::setString(const char* s)
{
    if (pStr != NULL)
    {
        delete []pStr;
    }

    tamanho = strlen(s);
	pStr = new char[tamanho + 1];
	strcpy_s(pStr, tamanho + 1, s);
}

void MinhaString::operator = (const char* s)
{
	setString(s);
}

void MinhaString::operator = (MinhaString& s)
{
	operator = (s.getString());
}

bool MinhaString::operator == (MinhaString& s)
{
	if (0 == strcmp(pStr, s.getString()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

ostream &operator<<(ostream& saida, MinhaString& s)
{
	saida << s.getString();
	return saida;
}
