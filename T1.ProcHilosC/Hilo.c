//Yañez Espindola Jose Marcos
//José David Vázquez Rojas
//Hugo Carlos Morán Peraza
//Luis Fernando Flores Tiburcio

#include <pthread.h> //Biblioteca con instrucciones para trabajar con hilos en c
#include <stdio.h>  //Es el archivo de cabecera que contiene las definiciones de las macros, las constantes, las declaraciones de funciones de la biblioteca estándar
void *codigo_del_hilo(void *id) //Apuntador la funcion codigo_del_hilo, la cual recibe un apunador de tipo vacio(que no se conoce el tipo de este apntador)
{
 int i;// variable entera para el ciclo
 for(i = 0; i < 50; i++)// ciclo con la 50 iteraciones 
  printf("\n Soy el hilo: %d, iter = %d", *(int*)id, i);//Se imprime el id del hilo, y la variable i la cual aumenta en cada iteracion del for
 pthread_exit(id);// termina el hilo y regresa el id
}
int main(void)// Se declara la función principal (regresa un entero por default y no recibe nada)
{
  pthread_t hilo; //Se declara un tipo de variable thread llamada hilo  
  int id = 245; //Identificador que le asignamos a nuestro hilo
  int *salida;  //Apuntador a una variable de tipo entero
  pthread_create(&hilo, NULL, codigo_del_hilo, &id);  //Crea el hilo, pasando la direccion de "hilo", el apuntador a la funcion que va a realizar el hilo, y la direccion del id que creamos para el hilo
  pthread_join(hilo, (void **)&salida); //Funcion que espera a que el hilo que se pasa como parametro termine su ejecucion, tambien recibe un apuntador "salida" con conversion explicita a doble apuntador void
  //el cual, cuando el hilo 1 finaliza, apuntara a la localidad de memoria de id
  printf("\n Hilo %d terminado \n", *(int*)salida); //Se imprime un mensaje de que el hilo con identificador igual a "salida" ha terminado
  return(0); //regresa un 0 para indicar al sistema que se ejecuto correctamente
}