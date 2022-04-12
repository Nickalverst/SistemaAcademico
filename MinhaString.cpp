#include "MinhaString.h"
#include <string.h>
#include <stdlib.h>

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
	strcpy(pStr, s);
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
