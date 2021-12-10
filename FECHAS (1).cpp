/*******************************************************************************
 				FECHAS

  Este programa constituye una prueba de algunas rutinas de temporizacion con 
  las que cuenta el sistema operativo UNIX. Estas rutinas son llamadas de
  sistema accesibles desde el lenguaje C y que pueden utilizarse para desarro-
  llar sistemas de reloj o temporizadores.

  Las subrutinas de biblioteca que se prueban en este programa son:

  char *asctime(), *ctime();
  struct tm *gmtime(), *localtime();

  La estructura tm tiene el siguiente formato:

	struct tm {
		int	tm_sec;        segundos 
		int	tm_min;        minutos 
		int	tm_hour;       horas  
		int	tm_mday;       dia   
		int	tm_mon;        mes  
		int	tm_year;       a~o 
		int	tm_wday;       dia de la semana
		int	tm_yday;       dia del a~o 
		int	tm_isdst;
	};

   A ctime se le pasa el tiempo transcurrido desde la fecha y hora base, en se-
   gundos, a traves del entero largo tiempo. Y devuelve una cadena de caracte-
   res, con la fecha y hora correspondiente. Se tiene una fecha y hora base en 
   la PC, a partir de ella cuenta el tiempo transcurrido.

   A asctime se le da la estructura que tiene almacenados todos los datos
   relativos a la fecha, y la rutina entrega una cadena de caracteres con
   la hora y fecha.

   A localtime se le da el tiempo transcurrido en segundos, y deposita todos
   los datos relativos a la fecha, en la estructura tm apuntada por reloj.

   gmtime es identica a localtime, excepto porque los datos que deja en
   reloj son los correspondientes a la hora de Greenwich.

   time obtiene el tiempo transcurrido total medido por el sistema, dado en
   segundos.

*/

/********************************* MACROS **********************************/
//se define una nueva libreria para limpiar el bufer
#define Lespera       printf("Para continuar oprime <cr>");\
		      while (getchar()!= '\n')
#define Lsaltos(b)    {int a;for (a=0;a<b;a++) printf("\n");}//se define una nueva libreria para saltos de linea 

#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

time_t tiempo,tiempo1;
struct tm *reloj;
char *fechayhora;
main()
{
 Lsaltos(5);//salto de lineas
 printf("*****************************************************************\n");
 printf("*                                                               *\n");
 printf("*                                                               *\n");
 printf("*                                                               *\n");
 printf("*                                                               *\n");
 printf("*                 PRUEBA DE LAS RUTINAS DE                      *\n");
 printf("*                          FECHAS                               *\n");
 printf("*                                                               *\n");
 printf("*                                                               *\n");
 printf("*                                                               *\n");
 printf("*****************************************************************\n");
 Lsaltos(5);//salto de lineas
 Lespera;//se llama a la funcion para lespera para limpiar el bufer
 INICIO://etiqueta para el salto de rutina
   tiempo = time(0);//tiempo actual
   fechayhora = ctime(&tiempo);//fecha y hora
   printf("fecha y hora:\t%s\n\n",fechayhora);//se imprime la fecha y hora actual
   Lespera;
   reloj = localtime(&tiempo);
   printf("A~O:%d\n",(*reloj).tm_year);//se imprime el a~o actual
   printf("MES:%d\n",(*reloj).tm_mon);//se imprime el mes actual
   printf("DIA:%d\n",(*reloj).tm_mday);//se imprime el dia actual
   printf("HORAS:%d\n",(*reloj).tm_hour);//se imprime la hora actual
   printf("MINUTOS:%d\n",(*reloj).tm_min);// se imprime los minutos actuales
   printf("SEGUNDOS:%d\n",(*reloj).tm_sec);// se imprime los segundos actuales
   printf("DIA DE LA SEMANA:%d\n",(*reloj).tm_wday);//se imprime el dia de la semana actual
   printf("DIA DEL A~O:%d\n",(*reloj).tm_yday);//se imprime el dia del a~o actual
   printf("tm_isdst:%d\n",(*reloj).tm_isdst);//se imprime el tiempo de verano actual
   Lespera;
   printf("%s\n",asctime(reloj));//se imprime la fecha y hora actual
   Lespera;//se llama a la funcion para lespera para limpiar el bufer
   reloj = gmtime(&tiempo);//se obtiene la fecha y hora actual en formato UTC
   printf("A~O:%d\n",(*reloj).tm_year);//se imprime el a~o actual
   printf("MES:%d\n",(*reloj).tm_mon);//se imprime el mes actual
   printf("DIA:%d\n",(*reloj).tm_mday);//se imprime el dia actual
   printf("HORAS:%d\n",(*reloj).tm_hour);//se imprime la hora actual
   printf("MINUTOS:%d\n",(*reloj).tm_min);// se imprime los minutos actuales
   printf("SEGUNDOS:%d\n",(*reloj).tm_sec);// se imprime los segundos actuales
   printf("DIA DE LA SEMANA:%d\n",(*reloj).tm_wday);//se imprime el dia de la semana actual
   printf("DIA DEL A~O:%d\n",(*reloj).tm_yday);//se imprime el dia del a~o actual
   printf("tm_isdst:%d\n",(*reloj).tm_isdst);//se imprime el tiempo de verano actual
   getchar();
   printf("Para salir oprime s");
   if (getchar() == 's') exit(0);
   Lespera;
  goto INICIO;
}

