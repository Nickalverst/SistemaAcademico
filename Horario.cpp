#include "Horario.h"
#include <math.h>

Horario::Horario(int nHora, int nMin)
{
    if (nHora < 24 && nHora >= 0)
        hora = nHora;
    if (nMin >= 0 && nMin < 60)
        min = nMin;
}

int Horario::getHora()
{
    return hora;
}

int Horario::getMin()
{
    return min;
}

void Horario::setHora(int novaHora)
{
    if (novaHora < 24)
        hora = novaHora;
}

void Horario::setMin(int novoMin)
{
    if (novoMin < 60)
        hora = novoMin;
}

int Horario::calcularIntervalo(Horario b)
{
    int diferenca = 0;
    int minA = hora * 60 + min,
        minB = b.hora * 60 + b.min;

    diferenca = abs(minA - minB);
    return diferenca;
}
