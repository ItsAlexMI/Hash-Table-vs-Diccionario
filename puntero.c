#include <stdio.h>

int main() {
    int number = 42;
    int* ptr;

    ptr = &number;  // Asigna la dirección de memoria de 'number' al puntero 'ptr'

    printf("Valor de number: %d\n", number);
    printf("Dirección de memoria de number: %p\n", &number);
    printf("Valor de ptr: %p\n", ptr);
    printf("Valor apuntado por ptr: %d\n", *ptr);

    *ptr = 99;  // Modifica el valor apuntado por 'ptr'

    printf("Nuevo valor de number: %d\n", number);

    return 0;
}
