/*
    Autora: Laura Rocha
*/
#include <stdio.h>

int main(){
    int total10, total20, total50, total100, saque, proto10, proto20, proto50, proto100, resto, auxiliar;

    printf("Informe a quantidade de cedulas de 10: ");
    scanf("%d", &total10);
    printf("Informe a quantidade de cedulas de 20: ");
    scanf("%d", &total20);
    printf("Informe a quantidade de cedulas de 50: ");
    scanf("%d", &total50);
    printf("Informe a quantidade de cedulas de 100: ");
    scanf("%d", &total100);

    while (saque != 0){
        printf("=====================================================================\n");
        printf("Total de notas de 10 disponiveis: %d\n", total10);
        printf("Total de notas de 20 disponiveis: %d\n", total20);
        printf("Total de notas de 50 disponiveis: %d\n", total50);
        printf("Total de notas de 100 disponiveis: %d\n", total100);
        printf("Saldo total do caixa: %d\n", total100 * 100 + total50 * 50 + total20 * 20 + total10 * 10);
        printf("Informe o valor do saque (0 para finalizar): ");
        scanf("%d", &saque);
        printf("Saque: %d\n", saque);
        proto100 = 0;
        proto50 = 0;
        proto20 = 0;
        proto10 = 0;

        /*Condicao de parada*/
        if (saque == 0)
            break;

        /*Caso: dinheiro total do caixa nao eh suficiente para realizar o saque*/
        if (((total100 * 100 + total50 * 50 + total20 * 20 + total10 * 10) < saque)){
            printf("Nao ha saldo suficiente neste caixa para realizar o saque!\n");
            continue;}
        else{
            resto = saque;
            auxiliar = 2; /*A variavel auxiliar possui 3 possiveis valores: 0 (nao ha cedulas), 2 = o laco ainda deve continuar e 1 (foi possivel realizar o saque)*/

            //laco para compor as notas necessarias para realizar o saque
            while (auxiliar == 2){
                // Condicao de parada do laco (quando foi possivel fazer a combinacao das notas)
                if (resto == 0){
                    auxiliar = 1;
                    break;}
                if ((total100 > 0) && (resto >= 100)){
                    resto -= 100;
                    proto100++;
                    total100--;
                    continue;}
                else{
                    if ((total50 > 0) && (resto >= 50)){
                        resto -= 50;
                        proto50++;
                        total50--;
                        continue;}
                    else{
                        if ((total20 > 0) && (resto >= 20)){
                            resto -= 20;
                            proto20++;
                            total20--;
                            continue;}
                        else{
                            if ((total10 > 0) && (resto >= 10)){
                                resto -= 10;
                                proto10++;
                                total10--;
                                continue;}
                            else{
                                auxiliar = 0;
                                /*Resetando a quantidade de notas que foram alteradas,
                                ja que nessa condicao, nao sera possivel realizar o saque*/
                                total100 += proto100;
                                total50 += proto50;
                                total20 += proto20;
                                total10 += proto10;
                                break;}     }       }       }
            }
            if (auxiliar == 1){
                printf("Quantidade de cedulas de 10: %d\n", proto10);
                printf("Quantidade de cedulas de 20: %d\n", proto20);
                printf("Quantidade de cedulas de 50: %d\n", proto50);
                printf("Quantidade de cedulas de 100: %d\n", proto100);
            }
            if (auxiliar == 0)
                printf("Nao ha cedulas para realizar este valor de saque!\n");
        }
    }
    printf("Fim do programa. Volte sempre!\n");
    return 0;
}
