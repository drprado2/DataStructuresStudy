#include <stdio.h>
#include <malloc.h>

typedef struct {
    int idade;
    int peso;
} Pessoa;

int main(){    
    // Aqui declaramos uma variável, ela é uma referencia de memória, já com valor alocado
    int x = 25;
    // Aqui declaramos um ponteiro, que irá apontar para uma memória que irá guardar um inteiro
    // O * define ponteiros
    int* y;
    // Aqui com o uso do & nós pegamos a referência de memória de x
  //  y = &x;
    // Aqui nós falamos para ir na memória a qual a referencia aponta e setar o valor de 30
    // o * faz isso
    *y = 30;
    printf("Veja o valor de x %i e de y:", x, *y);

    //A função malloc aloca X bytes de memória ram, e retorna o endereço da memória como ponteiro pra int
    // a função sizeof fala a quantidade de memória necessária para armazenar um determinado tipo
    // A função malloc retorna um ponteiro pra VOID, então podemos fazer um cast
    int* abc = (int*)malloc(sizeof(int));
    *abc = 30;

    // Com structs nós também podemos fazer a alocação de memória
    Pessoa* ponteiroStruct = (Pessoa*) malloc(sizeof(Pessoa));
    // Para acessar os valores da struct referenciados pelo ponteiro usamos ->
    ponteiroStruct->idade = 25;
    ponteiroStruct->peso = 88;

    printf("Pessoa de exemplo tem %i anos e %i kilos de peso \n", ponteiroStruct->idade, ponteiroStruct->peso);
    getchar();
}