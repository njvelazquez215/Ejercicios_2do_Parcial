#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

int main() {

    //Ejercicio 1
    Persona * personas;
    personas = queryPersonas("Nicolas", NULL, -1);

    //Ejercicio 3
    Registro * reg =queryRegistro("../personas.db", "12345678Nicolas Velazquez");

    return 0;
}
