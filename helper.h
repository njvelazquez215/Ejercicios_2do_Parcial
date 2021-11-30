//
// Created by nicov on 29/11/2021.
//

#ifndef EJERCICIOS_2DO_PARCIAL_HELPER_H
#define EJERCICIOS_2DO_PARCIAL_HELPER_H

typedef struct persona {
    char nombre[50];
    char apellido[50];
    int edad;
} Persona;

//Ejercicio 1
Persona * queryPersonas(char * nombre, char * apellido, int edad);

//Ejercicio 3
//Estructura de registro con los campos del enunciado
typedef struct registro {
    char DNI [8];
    char nombre[50];
    char apellido[50];
} Registro;

//La funcion canonica genera y devuelve una llave a partir de un registro
char * funcionCanonica(Registro *);

//Devuelve el registro correspondiente a una cierta llave
Registro * queryRegistro(char * archivo, char * llave);


#endif //EJERCICIOS_2DO_PARCIAL_HELPER_H
