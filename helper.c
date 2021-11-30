//
// Created by nicov on 29/11/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helper.h"

//Ejercicio 1
//Realice el programa que busque secuencialmente dentro de archivo de personas, los registros correspondientes a una
//llave secundaria dada.

Persona * queryPersonas(char * nombre, char * apellido, int edad){
    FILE * fPersonas = fopen("../personas.db","rb");

    fseek(fPersonas, 0, SEEK_END);
    long longitudRegistro = sizeof(Persona);
    long cantidadDePersonas = ftell(fPersonas) / longitudRegistro
    Persona * bufferDePersonas = (Persona *) malloc(sizeof(Persona));
    Persona * query = (Persona *) malloc(cantidadDePersonas * sizeof(Persona)); //Genero el arreglo con el query
    int cantidadQuery = 0;

    for (int i = 0; i < cantidadDePersonas; ++i) {
        fseek(fPersonas, longitudRegistro * i, SEEK_SET); //Busco cada registro
        fread(bufferDePersonas, sizeof(Persona), 1, fPersonas);
        if ((strcmp(nombre, bufferDePersonas->nombre) == 0 || nombre == NULL) &&
            (strcmp(nombre, bufferDePersonas->apellido) == 0 || apellido == NULL) &&
            (bufferDePersonas->edad == edad || edad < 0)) {
            query[cantidadQuery] = *bufferDePersonas;
            cantidadQuery++;
        }
    }

    fclose(fPersonas);
    return query;
}

//Ejercicio 3
//Defina una funcion que realice una busqueda secuencial en todos los registros de un archivo, hasta encontrar un registro con una llave dada.
//Para eso necesitara de una funcion canonica de la forma char * funcionCanonica(Registro *). Suponga que el archivo contiene informacion
//asociada a clientes de una empresa (DNI,nombre, apelido, etc).

char * funcionCanonica(Registro * reg) {
    //Asumiendo que esta funcion genera una llave primaria con la info del registro.
    int length = strlen(reg->DNI) + strlen(reg->nombre);
    char * llave = (char *) malloc(length + 1);
    strcpy(llave, reg->DNI);
    strcat(llave, reg->apellido);
    strcat(llave, reg->nombre);
    llave[length] = '\0';

    return llave;
}

Registro * queryRegistro(char * archivo, char * llave) {
    FILE * fPersonas = fopen(archivo, "rb");

    fseek(fPersonas, 0, SEEK_END);
    long longitudRegistro = sizeof(Registro);
    long cantidadDePersonas = ftell(fPersonas) / longitudRegistro;
    Registro * bufferDePersonas = (Registro *) malloc(sizeof(Registro));
    Registro * query = malloc(sizeof(Registro)); //genero el arreglo con el query

    for (int i = 0; i < cantidadDePersonas; ++i) {
        fseek(fPersonas, longitudRegistro * i, SEEK_SET); //Busco cada registro
        fread(bufferDePersonas, sizeof(Persona), 1, fPersonas);
        if (strcmp(llave, funcionCanonica(bufferDePersonas)) == 0){
            *query = *bufferDePersonas;
            break;
        }
    }

    fclose(fPersonas);
    return query;
}