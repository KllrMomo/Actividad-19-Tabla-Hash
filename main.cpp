#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxElement 25

typedef struct Nodo {
    char *nombre;
    struct Nodo *siguiente;
} Nodo;

int claveHash(char *apellido) {
    size_t suma = 1;
    for (int i = 0; i < strlen(apellido); i++) {
        suma = suma * apellido[i];
    }
    return suma % maxElement;
}

void inicializarTabla(Nodo* tabla[]) {
    for (int i = 0; i < maxElement; i++) {
        tabla[i] = NULL;
    }
}


void insertarEnTabla(Nodo* tabla[], char* nombre) {
    int indice = claveHash(nombre);


    Nodo *nuevoNodo = (Nodo *) malloc(sizeof(Nodo));
    nuevoNodo->nombre = strdup(nombre);
    nuevoNodo->siguiente = NULL;


    if (tabla[indice] == NULL) {
        tabla[indice] = nuevoNodo;
    } else {

        nuevoNodo->siguiente = tabla[indice];
        tabla[indice] = nuevoNodo;
    }
}

void imprimirTablaHash(Nodo* tabla[]) {
    for (int i = 0; i < maxElement; i++) {
        printf("Indice[%d]: ", i);
        Nodo* actual = tabla[i];
        while (actual != NULL) {
            printf("%s -> ", actual->nombre);
            actual = actual->siguiente;
        }
        printf("NULL\n");
    }
}

int buscarNombre(Nodo* tabla[], char* nombre) {
    int indice = claveHash(nombre);
    Nodo* actual = tabla[indice];
    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
            return 1;
        }
        actual = actual->siguiente;
    }
    return 0;
}

int main() {

    Nodo* tabla[maxElement];
    inicializarTabla(tabla);


    insertarEnTabla(tabla, "ACOSTA MENDOZA");
    insertarEnTabla(tabla, "AGUILAR RIVAS");
    insertarEnTabla(tabla, "CAMACHO ROMERO");
    insertarEnTabla(tabla, "CORONADO ROMO");
    insertarEnTabla(tabla, "CRUZ LABRADA");
    insertarEnTabla(tabla, "ESTEBAN SALINAS");
    insertarEnTabla(tabla, "GONZALEZ PEREZ");
    insertarEnTabla(tabla, "IBARRA MORA");
    insertarEnTabla(tabla, "LOPEZ MAGDALENO");
    insertarEnTabla(tabla, "LOPEZ RODRIGUEZ");
    insertarEnTabla(tabla, "MORAN AMAO");
    insertarEnTabla(tabla, "OROZCO TALAMANTES");
    insertarEnTabla(tabla, "PEREDIA PARRA");
    insertarEnTabla(tabla, "Rendón Gonzalez");
    insertarEnTabla(tabla, "RODRÍGUEZ ESTRADA");
    insertarEnTabla(tabla, "SANDEZ CURRO");
    insertarEnTabla(tabla, "SANDOVAL RAMIREZ");
    insertarEnTabla(tabla, "SANTOS MACIEL");
    insertarEnTabla(tabla, "SIERRA URIAS");
    insertarEnTabla(tabla, "Silva López");
    insertarEnTabla(tabla, "Torres Durante");
    insertarEnTabla(tabla, "VALDES CORONA");
    insertarEnTabla(tabla, "VALDEZ FLORES");
    insertarEnTabla(tabla, "VARGAS GAMEZ");

    imprimirTablaHash(tabla);

    if (buscarNombre(tabla, "LOPEZ RODRIGUEZ")) {
        printf("Si se localizo el nombre\n");
    } else {
        printf("No se localizo el nombre\n");
    }

    return 0;
}