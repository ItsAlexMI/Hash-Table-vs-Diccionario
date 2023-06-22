#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Definición de la estructura del nodo de la lista enlazada
typedef struct Node {
    char key[50];
    int value;
    struct Node* next;
} Node;

// Definición de la estructura de la hash table
typedef struct {
    Node* table[TABLE_SIZE];
} HashTable;

// Función de hash simple que suma los valores ASCII de los caracteres de la clave
int hashFunction(const char* key) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i];
    }
    return sum % TABLE_SIZE;
}

// Función para insertar un elemento en la hash table
void insert(HashTable* hashtable, const char* key, int value) {
    int index = hashFunction(key);

    // Crear un nuevo nodo
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->value = value;
    newNode->next = NULL;

    // Verificar si la posición está vacía
    if (hashtable->table[index] == NULL) {
        hashtable->table[index] = newNode;
    } else {
        // Si hay colisión, agregar el nodo al inicio de la lista
        newNode->next = hashtable->table[index];
        hashtable->table[index] = newNode;
    }
}

// Función para buscar un elemento en la hash table
int search(HashTable* hashtable, const char* key) {
    int index = hashFunction(key);

    // Verificar si la posición está vacía
    if (hashtable->table[index] == NULL) {
        return -1;  // Elemento no encontrado
    }

    // Recorrer la lista enlazada en la posición y buscar el elemento
    Node* currentNode = hashtable->table[index];
    while (currentNode != NULL) {
        if (strcmp(currentNode->key, key) == 0) {
            return currentNode->value;  // Elemento encontrado
        }
        currentNode = currentNode->next;
    }

    return -1;  // Elemento no encontrado
}

// Función principal
int main() {
    HashTable hashtable;

    // Inicializar la tabla con valores nulos
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashtable.table[i] = NULL;
    }

    // Insertar elementos en la hash table
    insert(&hashtable, "clave1", 10);
    insert(&hashtable, "clave2", 20);
    insert(&hashtable, "clave3", 30);

    // Buscar elementos en la hash table
    printf("Valor de clave1: %d\n", search(&hashtable, "clave1"));
    printf("Valor de clave2: %d\n", search(&hashtable, "clave2"));
    printf("Valor de clave3: %d\n", search(&hashtable, "clave3"));

    return 0;
}
