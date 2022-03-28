#include "Caixa.h"
#include <stdio.h>

Caixa::Caixa(float nAltura, float nLargura, float nProfundidade)
{
    if (nAltura > 0 && nLargura > 0 && nProfundidade > 0)
    {
        altura = nAltura;
        largura = nLargura;
        profundidade = nProfundidade;
    } else {
        printf("N�meros inv�lidos.");
        altura = 0;
        largura = 0;
        profundidade = 0;
    }
}

void Caixa::setAltura (float nAltura)
{
    if (nAltura > 0)
        altura = nAltura;
    else
        printf("Altura inv�lida (<=0).");
}

void Caixa::setLargura(float nLargura)
{
    if (nLargura > 0)
        largura = nLargura;
    else
        printf("Largura inv�lida (<=0).");
}

void Caixa::setProfundidade(float nProfundidade)
{
    if (nProfundidade > 0)
        profundidade = nProfundidade;
    else
        printf("Profundidade inv�lida (<=0).");
}

float Caixa::calcularAreaExt()
{
    float area = 2 * (largura * altura + largura * profundidade + altura * profundidade);
    return area;
}

float Caixa::calcularVolume()
{
    float volume = largura * altura * profundidade;
    return volume;
}
