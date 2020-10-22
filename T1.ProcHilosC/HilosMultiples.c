#include <pthread.h>  //Biblioteca con instrucciones para trabajar con hilos en c
#include <stdio.h>    //Es el archivo de cabecera que contiene las definiciones de las macros, las constantes, las declaraciones de funciones de la biblioteca estándar
#include <stdlib.h>   //Contiene los prototipos de funciones de C para gestión de memoria dinámica, control de procesos y otras.
#include <string.h>   //Libreria para el manejo de cadenas.
#define NUM_HILOS 5   //Se define la constante NUM_HILOS como entero 5
int I = 0;            //Se define la variable compartida entre hilos "I" inizializada en 0
void *codigo_del_hilo(void *id)// Se declara la función principal (regresa un entero por default y no recibe nada)
{
    int i;  //Variable auxiliar para contador del bucle
    for(i = 0; i < 50; i++) // Se crea un bucle de 0 a 50 iteraciones
      printf("Hilo %d; i = %d, I = %d\n", *(int*)id, i, I++); //Se imprime el id del hilo, la variable i local para cada hilo, la cual aumenta en cada iteracion del for, y la variable global I
      //que es compartida entre todos los hilos
 pthread_exit(id);// termina el hilo y regresa el id
}
int main(void) // Se declara la función principal (regresa un entero por default y no recibe nada)
{
    int h;//variable auxiliar para el bucle 
    pthread_t hilos[NUM_HILOS]; //Se crean un arreglo con 5 hilos
    int id[NUM_HILOS] = {1, 2, 3, 4, 5};//Se le asignan los id's de los hilos del 1 al 5 respectivamente
    int error;//Variable para imprimir el error y mostrar en pantalla si es el caso.
    int *salida;//Apuntador a una variable de tipo entero
    for (h = 0; h < NUM_HILOS; h++){//Se crean cada uno de los hilos, con un for
        error = pthread_create(&hilos[h], NULL, codigo_del_hilo, &id[h]);//Crea el hilo1, pasando la direccion del hilo i-esimo, el apuntador a la funcion que va a realizar el hilo, y la direccion del id que creamos para el hilo i-esimo
        if (error){//Si existe un error en la creacion del hilo
          fprintf(stderr, "Error %d %s\n", error, strerror (error));//Imprime un mensaje de error
          exit(-1);
        }
    }
    for (h = 0; h < NUM_HILOS; h++){//Se crea un bucle de 0 a 5 para cada tarea de los hilos
        error = pthread_join(hilos[h], (void **)&salida);//Funcion que espera a que el hilo que se pasa como parametro termine su ejecucion, tambien recibe un apuntador "salida" con conversion explicita a doble apuntador void
  //el cual, cuando el hilo finaliza, apuntara a la localidad de memoria de id de ese hilo
        if (error)//Si existe un error en la ejecucion del hilo
          fprintf(stderr, "Error %d %s\n", error, strerror (error));//Imprime un mensaje de error si es el caso
        else// si no existe ningun error
          printf("hilo %d terminado\n", *salida);//Imprime el identificador del hilo que acaba de terminar su ejecucion
    }
}