//Yañez Espindola Jose Marcos
//José David Vázquez Rojas
//Hugo Carlos Morán Peraza
//Luis Fernando Flores Tiburcio

#include <pthread.h>//Biblioteca con instrucciones para trabajar con hilos en c
#include <stdio.h>//Es el archivo de cabecera que contiene las definiciones de las macros, las constantes, las declaraciones de funciones de la biblioteca estándar
void *codigo_del_hilo(void *id)// Se declara la función principal (regresa un entero por default y no recibe nada)
{
 int i; //Variable auxiliar para contador del bucle
 for(i = 0; i < 50; i++)  // Se crea un bucle de 0 a 50 iteraciones
  printf("\n Soy el hilo: %d, iter = %d", *(int*)id, i);  //Se imprime el id del hilo, y la variable i la cual aumenta en cada iteracion del for
 pthread_exit(id);  // termina el hilo y regresa el id
}
int main(void)  // Se declara la función principal (regresa un entero por default y no recibe nada)
{
  pthread_t hilo1, hilo2; //Se crean 2 hilos hilo1 e hilo2
  int id1 = 11; //Identificador que le asignamos al hilo1
  int id2 = 55; //Identificador que le asignamos la hilo2
  int *salida1; //Apuntador a una variable de tipo entero para la salida 1
  int *salida2; //Apuntador a una variable de tipo entero para la salida 2
  pthread_create(&hilo1, NULL, codigo_del_hilo, &id1); //Crea el hilo1, pasando la direccion del hilo1, el apuntador a la funcion que va a realizar el hilo1, y la direccion del id que creamos para el hilo1
  pthread_create(&hilo2, NULL, codigo_del_hilo, &id2); //Crea el hilo2, pasando la direccion del hilo2, el apuntador a la funcion que va a realizar el hilo2, y la direccion del id que creamos para el hilo2
  pthread_join(hilo1, (void **)&salida1); //Funcion que espera a que el hilo que se pasa como parametro termine su ejecucion, tambien recibe un apuntador "salida1" con conversion explicita a doble apuntador void
  //el cual, cuando el hilo 1 finaliza, apuntara a la localidad de memoria de id1
  pthread_join(hilo2, (void **)&salida2); //Funcion que espera a que el hilo que se pasa como parametro termine su ejecucion, tambien recibe un apuntador "salida2" con conversion explicita a doble apuntador void
  //el cual, cuando el hilo 2 finaliza, apuntara a la localidad de memoria de id2
  printf("\n Hilos %d y %d terminados \n",*(int*)salida1,*(int*)salida2);//Se imprime un mensaje de que los hilos con identificador igual a "salida1" y "salida2" han terminado
  printf("%p \n",salida1); //Comprobacion de que la direccion a la que apunta salida1 es igual a la direccion de id1
  printf("%p \n",&id1);
  printf("%p \n",salida2); //Comprobacion de que la direccion a la que apunta salida2 es igual a la direccion de id2
  printf("%p \n",&id2);
  return(0);
}