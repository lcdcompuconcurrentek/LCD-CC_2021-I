//Yañez Espindola Jose Marcos
//José David Vázquez Rojas
//Hugo Carlos Moran Peraza
//Luis Fernando Flores Tiburcio

#include <stdio.h> //Es el archivo de cabecera que contiene las definiciones de las macros, las constantes, las declaraciones de funciones de la biblioteca estándar
#include <stdlib.h> //Contiene los prototipos de funciones de C para gestión de memoria dinámica, control de procesos y otras.
#include <sys/types.h> //Contiene tipos de datos de próposito general.
#include <sys/wait.h> // Usaremos esta libreria para la función wait () bloquea el proceso de llamada hasta que uno de sus procesos secundarios sale o se recibe una señal. Después de que termina el proceso hijo, el padre continúa su ejecución después de esperar la instrucción de llamada al sistema.
#include <unistd.h> // Archivo de encabezado que proporciona acceso a la API del sistema operativo POSIX

int main(void)
{
   int i; // variable entera i
   int a,b; // variable entera a,b que servira para leer las entradas
   pid_t pidh1,pidh2,pidx; //Declaramos las varibles de tipo pid_t que es un tipo de dato especial par identificar procesos, aunque se puede usar perfectamente el tipo de dato int
   int prod,mayor;// variables enteras para asignar el producto y numero mayor de las entradas
   int res; // 

   printf("\nDame dos enteros: \n"); // Se muestra en pantalla la instrucción para leer las entradas
   scanf("%d%d", &a, &b);// Guaradamos las entradas en las variables a y b
   pidh1 = fork(); //Creamos el proceso hijo

// código del padre
   if(pidh1) //Si se ejecuta el codigo del padre, ya que pidh1=0
   {
      printf("%d",pidh1);
      pidh2 = fork(); //Se crea otro proceso hijo
      if(pidh2)//Si se ejecuta el codigo del padre, ya que pidh2=0
      {
         //printf("%d",pidh2);
        for(i = 0; i < 2; i++)//Para cada uno de los procesos hijos creados
        {
           pidx = wait(&res); // Se espera a que se termine de ejecutar cada proceso
 	         if (pidx == pidh1) //Si termina primero el proceso hijo1
               prod = res; // Se le asigna a prod el resultado del hijo 1
            else // de lo contrario
               mayor = res; // Se le asigna a mayor el resultado del hijo 2
        }
        printf("\n El producto de %d y %d es %d", a,b,prod>>8);//Se muestra el resultado del producto 
        printf("\n El mayor de %d y %d es %d \n", a,b,mayor>>8);//Se muestra el mayor (se agrego >>8 ya que aparentemente lo que nos regresa exit hay que hacerle un recorrido de 8 bits para observar el resultado esperado) 
      }
      else//Si se esta ejecutando el hijo 2
      {
         //printf("%d",pidh2);
         if(a > b)//Nos regresa al finalizar el proceso el valor mayor
           exit(a);//Cuando el proceso hijo2 finaliza, Retorna el valor de a
         else
           exit(b);//Cuando el proceso hijo2 finaliza, Retorna el valor de b
      }
   }
//Si se esta ejecutando el hijo 1
   else
      {
         //printf("%d",pidh1);
	      prod = a * b;//Nos calcula el producto
	      exit(prod); //Cuando el proceso hijo1 finaliza, Retorna el valor de prod
      }

  return(0);

 }
