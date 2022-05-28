#include <math.h>
typedef struct DataDiode
{
    float n;
    float Vgap
} DataDiode;

DataDiode getDataDiode()
{
    int tipo;
    DataDiode data;
    printf("Informe o tipo do diodo:\n1 - Silicio\n2 - Germanio\n3 - Arsenieto de gálio\n");
    scanf("%d", &tipo);
    switch (tipo)
    {
    // n=2 para cilicio e 1 para germanio
    case 1:
        data.n = 1;
        data.Vgap = 0.785;
        break;
    case 2:
        data.n = 2;
        data.Vgap = 1.21;
        break;
    case 3:
        printf("Não foi encontrado o valor de N para este caso. Por este motivo não é possivel realizar com este elemento.\n\n\n");
        data.Vgap = 1.424;
        exit(0);
        break;
    default:
        printf("Opção invalida. Finalizando programa.\n\n\n");
        exit(0);
        break;
    }
    return data;
}
/**
 * @brief converter temperatura de celcios para farenheit
 *
 * @param Tdc temperatura em celcios
 * @return float
 */
float convertTempCelsiusToKelvin(float Tdc)
{
    float Tdk = Tdc + 273.15;
    return Tdk;
}
void printAllArgument(int argc, char *argv[])
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
}
void calcularResistor();

void calcularLed()
{
    float n;
    float Vgap;
    int tipo = 0;
    /**
     * @brief Id é a corrente no diodo
     * @brief Vgap é a tensão de gap que é a tensão minima para o diodo transmitir corrente.
     */
    float Tdc = 1, Id = -1;
    printf("Informe a temperatura do ambiente onde o diodo está em celcius.\n");
    scanf("%f", &Tdc);
    float Tdk = convertTempCelsiusToKelvin(Tdc);

    float Vd = 1;
    printf("Informe a Tensão sobre o diodo.\n");
    scanf("%f", &Vd);
    /**
     * @brief Is é a corrente que o diodo apresenta quando lhe é imposto uma tensão negativa.
     */
    float Is = 1;
    printf("Informe a corrente inversa do diodo\n");
    scanf("%f", &Is);

    DataDiode data = getDataDiode();
    n = data.n;
    Vgap = data.Vgap;
    float k = 11600 / n;
    printf("Valor de Vd:%.2f\tValor de Vgap:%.2f\tValor de n:%.2f\tValor de k:%.2f\n", Vd, Vgap, n, k);
    if (Vd < Vgap)
    {
        printf("Tensão menor que a tensão de gap\n\n\n");
        exit(0);
    }
    float aux = k * Vd / Tdk;
    printf("Valor de aux: %.2f\n", aux);
    Id = Is * ((exp(aux)) - 1);
    printf("Corrente no diodo: %.2f\n", Id);
    float Rd = Vd / Id;
    printf("Resistencia do diodo: %.2f ohn.\n", Rd);
    printf("\n\n");
}
void calcularLedSimplificado()
{
    float Vs, Ve, I;
    printf("Informe a tensão da fonte.\n");
    scanf("%f", &Vs);
    printf("Informe a tensão do diodo.\n");
    scanf("%f", &Ve);
    printf("Informe a corrente no diodo.\n");
    scanf("%f", &I);
    printf("A resistencia necessaria é de no minimo: %f", (Vs - Ve) / I);
}
int main(int argc, char *argv[])
{
    int modo = 0;
    printf("Escolha o modo de operação:\n1 - Calcular Resistor\n2 - Calcular Led\n");
    scanf("%d", modo);
    switch (modo)
    {
    case 1:
        calcularResistor();
        break;
    case 2:
        calcularLedSimplificado();
        break;
    }
    return 0;
}

int getCorAndPrint()
{
    int cor;
    printf("0 - preto\n");
    printf("1 - Marron\n");
    printf("2 - Vermelho\n");
    printf("3 - Laranja\n");
    printf("4 - Amarelo\n");
    printf("5 - Verde\n");
    printf("6 - Azul\n");
    printf("7 - Violeta\n");
    printf("8 - Cinza\n");
    printf("9 - Branco\n");
    scanf("%d", &cor);
    return cor;
}
float getConfiancaAndPrint()
{
    int cor;
    printf("1 - Marron\n");
    printf("2 - Vermelho\n");
    printf("3 - Dourado\n");
    printf("4 - Prata\n");
    scanf("%d", &cor);
    printf("%d", cor);
    switch (cor)
    {
    case 1:
        return 0.01;
    case 2:
        return 0.02;
    case 3:
        return 0.05;
    case 4:
        return 0.1;
    }
}
void calcularResistor()
{
    int numeroCores;
    int cor, aux = 0, expoent;
    float confianca;
    printf("Qual o numero de cores do resistor?\n3\n4\n");
    scanf("%d", &numeroCores);
    if (numeroCores < 3 || numeroCores > 5)
    {
        printf("Numero de cores invalido.\n\n\n");
        exit(0);
    }
    for (int i = 3; i <= numeroCores; i++)
    {
        aux *= 10;
        printf("Qual a cor %d?\n", i - 3);
        cor = getCorAndPrint();
        printf("cor: %d\n", cor);
        aux = aux + cor;
        printf("aux: %d\n", aux);
    }
    printf("Qual a cor %d?\n", numeroCores - 1);
    expoent = getCorAndPrint();
    printf("expoente: %d\n", cor);
    printf("Qual a cor %d?\n", numeroCores);
    confianca = getConfiancaAndPrint();
    printf("Confiança: %d\n", cor);
    printf("A resistencia do resistor é: %d*10^(%d) +||- %.2f\n", aux, expoent, confianca * 100);
}