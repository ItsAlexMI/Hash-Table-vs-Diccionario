#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Node {
    char key[50];
    char value[50];
    struct Node* next;
} Node;

typedef struct {
    Node* table[TABLE_SIZE];
} HashTable;

int hashFunction(const char* key) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i];
    }
    return sum % TABLE_SIZE;
}

void insert(HashTable* hashtable, const char* key, const char* value) {
    int index = hashFunction(key);

    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    newNode->next = NULL;

    if (hashtable->table[index] == NULL) {
        hashtable->table[index] = newNode;
    } else {
        newNode->next = hashtable->table[index];
        hashtable->table[index] = newNode;
    }
}

const char* search(HashTable* hashtable, const char* key) {
    int index = hashFunction(key);

    if (hashtable->table[index] == NULL) {
        return NULL;
    }

    Node* currentNode = hashtable->table[index];
    while (currentNode != NULL) {
        if (strcmp(currentNode->key, key) == 0) {
            return currentNode->value;
        }
        currentNode = currentNode->next;
    }

    return NULL;
}

void update(HashTable* hashtable, const char* key, const char* newValue) {
    int index = hashFunction(key);

    if (hashtable->table[index] == NULL) {
        printf("Elemento no encontrado\n");
        return;
    }

    Node* currentNode = hashtable->table[index];
    while (currentNode != NULL) {
        if (strcmp(currentNode->key, key) == 0) {
            strcpy(currentNode->value, newValue);
            printf("Elemento actualizado\n");
            return;
        }
        currentNode = currentNode->next;
    }

    printf("Elemento no encontrado\n");
}

void removeElement(HashTable* hashtable, const char* key) {
    int index = hashFunction(key);

    if (hashtable->table[index] == NULL) {
        printf("Elemento no encontrado\n");
        return;
    }

    if (strcmp(hashtable->table[index]->key, key) == 0) {
        Node* temp = hashtable->table[index];
        hashtable->table[index] = temp->next;
        free(temp);
        printf("Elemento eliminado\n");
        return;
    }

    Node* currentNode = hashtable->table[index];
    while (currentNode->next != NULL) {
        if (strcmp(currentNode->next->key, key) == 0) {
            Node* temp = currentNode->next;
            currentNode->next = temp->next;
            free(temp);
            printf("Elemento eliminado\n");
            return;
        }
        currentNode = currentNode->next;
    }

    printf("Elemento no encontrado\n");
}

void printElements(HashTable* hashtable) {
    printf("Elementos en la Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashtable->table[i] != NULL) {
            Node* currentNode = hashtable->table[i];
            while (currentNode != NULL) {
                printf("Clave: %s, Valor: %s\n", currentNode->key, currentNode->value);
                currentNode = currentNode->next;
            }
        }
    }
}

int main() {
    HashTable hashtable;
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashtable.table[i] = NULL;
    }

    int opcion;
    char key[50];
    char value[50], newValue[50];

while (1) {
    printf("\n---- Hash Table ----\n");
    printf("1. Insertar elemento\n");
    printf("2. Buscar elemento\n");
    printf("3. Actualizar elemento\n");
    printf("4. Eliminar elemento\n");
    printf("5. Ver todos los elementos\n");
    printf("6. Salir\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);
    getchar(); // Limpiar el búfer de entrada

    switch (opcion) {
        case 1:
        
            printf("Ingrese la clave: ");
            fgets(key, sizeof(key), stdin);
            key[strcspn(key, "\n")] = '\0'; // Eliminar el carácter de nueva línea
            printf("Ingrese el valor: ");
            fgets(value, sizeof(value), stdin);
            value[strcspn(value, "\n")] = '\0'; // Eliminar el carácter de nueva línea
            insert(&hashtable, key, value);
            break;

            case 2:
                printf("Ingrese la clave: ");
                fgets(key, sizeof(key), stdin);
                key[strlen(key) - 1] = '\0'; // Eliminar el carácter de nueva línea
                const char* result = search(&hashtable, key);
                if (result != NULL) {
                    printf("Valor encontrado: %s\n", result);
                } else {
                    printf("Elemento no encontrado\n");
                }
                break;
            case 3:
                printf("Ingrese la clave: ");
                fgets(key, sizeof(key), stdin);
                key[strlen(key) - 1] = '\0'; // Eliminar el carácter de nueva línea
                printf("Ingrese el nuevo valor: ");
                fgets(newValue, sizeof(newValue), stdin);
                newValue[strlen(newValue) - 1] = '\0'; // Eliminar el carácter de nueva línea
                update(&hashtable, key, newValue);
                break;
            case 4:
                printf("Ingrese la clave: ");
                fgets(key, sizeof(key), stdin);
                key[strlen(key) - 1] = '\0'; // Eliminar el carácter de nueva línea
                removeElement(&hashtable, key);
                break;
            case 5:
                printElements(&hashtable);
                break;
            case 6:
                printf("Saliendo...\n");
                exit(0);
            default:
                printf("Opción inválida\n");
                break;
        }
    }

    return 0;
}
