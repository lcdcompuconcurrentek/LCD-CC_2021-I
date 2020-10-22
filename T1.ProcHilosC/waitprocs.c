//Yañez Espindola Jose Marcos
//José David Vázquez Rojas
//Hugo Carlos Moran Peraza
//Luis Fernando Flores Tiburcio

#include <stdio.h> //Es el archivo de cabecera que contiene las definiciones de las macros, las constantes, las declaraciones de funciones de la biblioteca estándar
#include <stdlib.h> //Contiene los prototipos de funciones de C para gestión de memoria dinámica, control de procesos y otras.
#include <sys/wait.h> // Usaremos esta libreria para la función wait () bloquea el proceso de llamada hasta que uno de sus procesos secundarios sale o se recibe una señal. Después de que termina el proceso hijo, el padre continúa su ejecución después de esperar la instrucción de llamada al sistema.
#include <unistd.h> // Archivo de encabezado que proporciona acceso a la API del sistema operativo POSIX

# define NUM_PROCESOS 5 //Se define la constante NUM_PROCESOS
int I = 0; //Se declara i como variable global, la cual sera incrementada en el ciclo for
void codigo_del_proceso (int id)  // Recibe el id del proceso hijo
{
   int i; //Se declara i como variable local, la cual sera incrementada en el ciclo for

   for (i = 0; i < 50; i++) // Se inicia un ciclo for para el proceso hijo del 0 al 50
        printf("Proceso %d: i = %d, I = %d\n", id, i, I++ ); // se crea el ciclo con el contador mostrando las variables del ciclo y de la global, viendo que no se afecta la variable I 
   exit (id);

}

int main(void)
{
    int p; //Se declara p que sera utilizada en el for
    int id[NUM_PROCESOS] = {1, 2, 3, 4, 5}; //Creamos un arreglo con los id que le asignaremos a cada proceso hijo
    int pid; //Variable utilizada para el id dado por el SO para los procesos
    int salida; //Variable que recibe el id del proceso que finaliza su ejecucion

    for (p = 0; p < NUM_PROCESOS; p++) {
      pid = fork(); //Se crea un proceso hijo
      if  (pid == -1){ //En caso de que la creacion fracase, se manda el mensaje de error
          perror("Error al crear un proceso: ");
          exit(-1);
      }
      else if (pid == 0) //En caso de que se haya creado el proceso hijo con exito se llama a la funcion codigo_del proceso pasando como proceso 
          codigo_del_proceso (id[p]);
    }

    // codigo proceso padre
    for (p = 0; p < NUM_PROCESOS; p++) { //Para cada uno de los procesos hijos creados por el padre
        pid = wait(&salida); //Se esperara hasta que cada uno de estos termine su ejecucion
        printf("Proceso %d con id = %x terminado\n", pid, salida >> 8); //Cuando cada uno de ellos acaba, nos mostrara el id del proceso padre, y el id del hijo que nos devuelve la funcion wait
    }

    return(0);
}

