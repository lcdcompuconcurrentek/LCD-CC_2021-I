//Yañez Espindola Jose Marcos
//José David Vázquez Rojas
//Hugo Carlos Moran Peraza
//Luis Fernando Flores Tiburcio

#include <stdio.h>//Es el archivo de cabecera que contiene las definiciones de las macros, las constantes, las declaraciones de funciones de la biblioteca estándar
#include <stdlib.h>//Contiene los prototipos de funciones de C para gestión de memoria dinámica, control de procesos y otras.
#include <unistd.h>// Archivo de encabezado que proporciona acceso a la API del sistema operativo POSIX.
#include <string.h> //Libreria para el manejo de cadenas.
#include <sys/types.h>//Contiene tipos de datos de próposito general.

int main(void){
	
	int 	fd[2], nbytes; //Arreglo para la tuberia de conexion entre los procesos
	pid_t	childpid; // Variable para el proceso
	char	cadena[] = "Hola, mundo!!\n"; // variable para enviar el mensaje 
	char	lectura[80]; 

	pipe(fd); // se establece la variable fd como la tuberia de conexion

	if ((childpid = fork()) == -1){ //Si hay un error en la creacion del proceso
		perror("fork");//Se muestra el error fork
		exit(1);//Regresa un 1 para indicar que el proceso finalizo

	}

	if (childpid == 0){

		/* Proceso hijo cierra el pipe en el canal de entrada */
		close(fd[0]);

		/* Envía "cadena" por medio del canal de salida del pipe */
		write(fd[1], cadena, strlen(cadena));
		exit(0);//Regresa un 0 para indicar que el proceso finalizo
	}
	else{
		
		/* Proceso padre cierra el canal de salida del pipe */
		close(fd[1]);
		/* Lee "cadenacar" del pipe */
		nbytes = read(fd[0], lectura, sizeof(lectura));
		printf("Cadena recibida: %s", lectura);
	}

	return(0);


}