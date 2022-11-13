/*Programa de control de guardado de la informacion de estudiantes:
a. Nombre
b. Edad
c. Promedio de notas que tengan
d. Fecha de nacimiento
e. Direction donde vive

 El menu es:
 1. Capturar Valores
 2. Mostrar valores
 3. Buscar por edad
 4. Buscar por nombre
 5. Salir
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Creando estructura de estudiantes
struct nacimiento{
    int dia, mes, año;
};

struct direccion{
    char direccion[40];
    char ciudad[30];
    char paiz[30];
};

struct datos{
    char Name[30];
    struct nacimiento fecha;
    struct direccion d_students;
    int Edad;
    float Promedio;
}alumnos[2];

//Prototipos de funciones que hacen cosas específicas
void Tomadatos();
void Mostrartodos();
void BuscarEdad();
void BuscarNombre();
void salir();
void Menu();

int main() {
    Menu();
    system("PAUSE");
    return 0;
}

//Definicion de las funciones-prototipos
void Tomadatos(){
    for(int i = 0; i < 2; i++){
        fflush(stdin);
        printf("\nIngrese nombre de estudiante # %d: ", i+1);
        gets(alumnos[i].Name);
        fflush(stdin);
        printf("Ingrese la edad del alumno # %d: ", i+1);
        scanf("%d", &alumnos[i].Edad);
        printf("Ingrese Fecha de nacimiento del alumno # %d: \n", i+1);
        printf("Dia: ");
        scanf("%d", &alumnos[i].fecha.dia);
        printf("Mes: ");
        scanf("%d", &alumnos[i].fecha.mes);
        printf("Ano: ");
        scanf("%d", &alumnos[i].fecha.año);
        printf("Ingrese la direccion del alumno: ");
        gets(alumnos[i].d_students.direccion);
        fflush(stdin);
        printf("Ingrese la cuidad: ");
        gets(alumnos[i].d_students.ciudad);
        fflush(stdin);
        printf("Ingrese el paiz: ");
        gets(alumnos[i].d_students.paiz);
        fflush(stdin);
        printf("Ingrese el promedio del alumno # %d: ", i+1);
        scanf("%f", &alumnos[i].Promedio);
        fflush(stdin);
    }
}

void Mostrartodos(){
    printf("Mostrando los datos de los alumnos \n");
    for(int i = 0; i < 2; i++){
        printf("_________________________________\n");
        printf("Alumno # %d\n ", i+1);
        printf("Nombre: %s\n", alumnos[i].Name);
        printf("Edad: %d\n", alumnos[i].Edad);
        printf("Fecha de nacimiento: %d / %d / %d \n", alumnos[i].fecha.dia, alumnos[i].fecha.mes, alumnos[i].fecha.año);
        printf("Direccion: %s , %s , %s \n" , alumnos[i].d_students.direccion, alumnos[i].d_students.ciudad, alumnos[i].d_students.paiz);
        printf("Promedio: %f\n", alumnos[i].Promedio);
    }
}
void BuscarEdad(){
    int edad, find = 0;
    printf("__________________________________\n");
    printf("Ingrese la edad a buscar:  ");
    scanf("%d", &edad);
    printf("__________________________________\n");
    for(int i = 0; i < 2; i++){
        if(alumnos[i].Edad == edad){
            find = 1;
            printf("_________________________________\n");
            printf("Alumno # %d\n ", i+1);
            printf("Nombre: %s\n", alumnos[i].Name);
            printf("Edad: %d\n", alumnos[i].Edad);
            printf("Fecha de nacimiento: %d / %d / %d \n", alumnos[i].fecha.dia, alumnos[i].fecha.mes, alumnos[i].fecha.año);
            printf("Direccion: %s , %s , %s \n" , alumnos[i].d_students.direccion, alumnos[i].d_students.ciudad, alumnos[i].d_students.paiz);
            printf("Promedio: %f\n", alumnos[i].Promedio);
        }
    }
    if(find == 0){
        printf("_________________________________________\n");
        printf("No se encontro alumnos con la edad %d\n", edad);
        printf("_________________________________________\n");
    }
}

void BuscarNombre(){
    int find = 0, comparador;
    char nombre[30];
    printf("_________________________________________\n");
    printf("Ingrese el nombre a buscar:  ");
    gets(nombre);
    fflush(stdin);
    printf("__________________________________\n");
    for(int i = 0; i < 2; i++){
        comparador = strcmp(&alumnos[i].Name, &nombre);
        if(comparador == 0){
            find = 1;
            printf("_________________________________\n");
            printf("Alumno # %d\n ", i+1);
            printf("Nombre: %s\n", alumnos[i].Name);
            printf("Edad: %d\n", alumnos[i].Edad);
            printf("Fecha de nacimiento: %d / %d / %d \n", alumnos[i].fecha.dia, alumnos[i].fecha.mes, alumnos[i].fecha.año);
            printf("Direccion: %s , %s , %s \n" , alumnos[i].d_students.direccion, alumnos[i].d_students.ciudad, alumnos[i].d_students.paiz);
            printf("Promedio: %f\n", alumnos[i].Promedio);
        }
    }
    if(find == 0){
        printf("_________________________________________\n");
        printf("No se encontro alumnos con %c como nombre\n", nombre);
        printf("_________________________________________\n");
    }
}

void salir(){
    printf("*(*)Programa finalizado(*)*\n");
}

void Menu() {

    int opcion;
    do {
        printf("_________________________________________\n");
        printf("MENU DE OPCIONES\n");
        printf("1. Ingreso de alumnos\n");
        printf("2. Mostrar todos los alumnos\n");
        printf("3. Buscar alumno(s) por edad\n");
        printf("4. Buscar alumno(s) por nombre\n");
        printf("5. Salir del Sistema\n");
        printf("Seleccione una opcion:\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                Tomadatos();
                break;
            case 2:
                if (alumnos[1].Edad != 0){
                Mostrartodos();}
                else printf("\nNo ha ingresado datos \nIngrese datos primero\n");
                break;
            case 3:
                if(alumnos[1].Edad != 0){
                    BuscarEdad();
                }
                else printf("\nNo ha ingresado datos \nIngrese datos primero\n");
                break;
            case 4:
                if (alumnos[1].Edad != 0) {
                    BuscarNombre();
                }
                else printf("\nNo ha ingresado datos \nIngrese datos primero\n");
                break;
            case 5:
                salir();
                break;
            default:
                printf("Opcion Incorrecta -- Selecione otra opcion");
        }
    } while (opcion != 5);
}
