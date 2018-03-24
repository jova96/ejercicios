#include <stdio.h>

enum { DOMINGO = 1 , LUNES = 2 , MARTES = 3, MIERCOLES = 4, JUEVES  = 5,
			VIERNES = 6 , SABADO = 7 } ;          /* se necesita un orden creciente de saltos de a 1 */
                                                                              /*que comiencen en DOMINGO*/
int main (void)
{

	short unsigned int primer_dia_año;
    short int dia_ingresado;

	primer_dia_año = DOMINGO;

	puts("ingresa un valor");
	scanf("%i",&dia_ingresado);

   if( !( dia_ingresado =(dia_ingresado % 7) ) ){         /* dia_ingresado pasa a ser la posicion del dia */
		dia_ingresado  += 7                         						 /* tomando el orden definido en enum*/
	}                                                                                   /* suma 7 para considerar la posicion 0 como 7*/

	if( (dia_ingresado = (dia_ingresado + primer_dia_año - 1 ) )  >= 7 ){    /*para otro pri.._dia_año*/
		dia_ingresado -=7                                                 /*dia_ingresado pasa a ser la cantidad de saltos */
	}                                                                                  /* que se hacen a partir del primer_dia_año*/
                                                                                        /* si supera 7 vuelve a comenzar desde el */
                                                                                        /*primer dia de la semana considerado en enum*/

	switch(dia_ingresado)
	{

		case DOMINGO :
			puts("es domingo") ;
			break;

		case LUNES :
			 puts("es lunes")  ;
			break;

		case MARTES :
			puts("es martes") ;
			break;

		case MIERCOLES :
			puts("es miercoles") ;
			break;

		case JUEVES :
			puts("es jueves") ;
			break;

		case VIERNES :
			puts("es viernes") ;
			break;

		case SABADO :
			puts("es sabado") ;
			break;
		case default :
			puts("algo")
	}

	return 0;

}
