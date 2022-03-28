#include <stdio.h>
#include <iostream>
using namespace std;
#include "Horario.h"
#include "Caixa.h"
#include "Pessoa.h"
#include "Principal.h"

int main()
{
    Principal objetoPrincipal;

    return 0;
}


/// EXERC�CIOS QUE N�O SEI DE ONDE S�O

/*   EXERC�CIOS 1 E 2   */
/*
    int entradaH = 0,
        saidaH = 0,
        entradaM = 0,
        saidaM = 0,
        intervalo = 0;

    float custo = 0;

    printf("Coloque a hora do hor�rio de entrada: ");
    scanf("%d", &entradaH);

    printf("\nColoque o minuto do hor�rio de entrada: ");
    scanf("%d", &entradaM);

    printf("\nColoque a hora do hor�rio de sa�da: ");
    scanf("%d", &saidaH);

    printf("\nColoque o minuto do hor�rio de sa�da: ");
    scanf("%d", &saidaM);

    Horario Entrada(entradaH, entradaM);
    Horario Saida(saidaH, saidaM);


    intervalo = Entrada.calcularIntervalo(Saida);

    if (intervalo < 3 * 60)
        custo = 4.5;
    else if (intervalo < 12 * 60)
        custo = 4.5 + ((intervalo - 3 * 60) / 15) * 0.75;
    else
        custo = 33;

    printf("\nIntervalo: %d minutos.\nCusto: %.2f.", intervalo, custo);
*/
/*   EXERC�CIO 3   */
/*
    float c1a,
        c1l,
        c1p,
        c2a,
        c2l,
        c2p;


    printf("Coloque a altura da caixa 1: ");
    scanf("%f", &c1a);

    printf("\nColoque a largura da caixa 1: ");
    scanf("%f", &c1l);

    printf("\nColoque a profundidade da caixa 1: ");
    scanf("%f", &c1p);

    printf("\nColoque a altura da caixa 2: ");
    scanf("%f", &c2a);

    printf("\nColoque a largura da caixa 2: ");
    scanf("%f", &c2l);

    printf("\nColoque a profundidade da caixa 2: ");
    scanf("%f", &c2p);

    Caixa C1(c1a, c1l, c1p);
    Caixa C2(c2a, c2l, c2p);

    printf ("�rea da caixa 1: %.2f.\nVolume da caixa 1: %.2f.\n �rea da caixa 2: %.2f.\nVolume da caixa 2: %.2f. ",
            C1.calcularAreaExt(), C1.calcularVolume(), C2.calcularAreaExt(), C2.calcularVolume());

*/

/*   EXERCÍCIOS 4 E 5   */
