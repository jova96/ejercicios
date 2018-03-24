#include <stdio.h>
#include <stdlib.h>

#define MSJ_ERROR_PREFIJO "ERROR"
#define MSJ_ERROR_INGRESO_INVALIDO "Debe ingresar un dia del año ( 1,2...366)"
#define MSJ_ERROR_CAMBIO_INESPERADO "Se produjo un error mientras se ejecutaba el programa"

enum { DOMINGO = 1 , LUNES = 2 , MARTES = 3, MIERCOLES = 4, JUEVES  = 5,
			VIERNES = 6 , SABADO = 7 } ;          /* se necesita un orden creciente de saltos de a 1 */
                                                                              /*que comiencen en DOMINGO*/
int main (void)
{

	short unsigned int primer_dia_anio;
    short int dia_ingresado;
     int var_aux;

	primer_dia_anio = DOMINGO;                /* todas las opciones son las de enum*/

	puts("ingresa un valor");
	if ( (scanf("%hi",&dia_ingresado) ) != 1 ) {          /* si scanf lee bien la entrada , debe devolver 1*/
		fprintf(stderr,"%s: %s\n",MSJ_ERROR_PREFIJO,MSJ_ERROR_INGRESO_INVALIDO);
		return EXIT_FAILURE;
	}
	while( ( var_aux = getchar() ) != '\n' && var_aux != EOF){
	}                                                                                     /*limpia el buffer*/

   if( !( dia_ingresado =(dia_ingresado % 7) ) ){         /* dia_ingresado pasa a ser la posicion del dia */
		dia_ingresado  += 7;                         					 /* tomando el orden definido en enum*/
	}                                                                                   /* suma 7 para considerar la posicion 0 como 7*/

	if( (dia_ingresado = (dia_ingresado + primer_dia_anio - 1 ) )  > 7 ){    /*para otro pri.._dia_año*/
		dia_ingresado -=7;                                                 /*dia_ingresado pasa a ser la cantidad de saltos */
	}                                                                                  /* que se hacen a partir del primer_dia_año*/
                                                                                        /* si supera 7 vuelve a comenzar desde el */
	switch(dia_ingresado)                                               /*primer dia de la semana considerado en enum*/
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

	    default :
			printf("%s: %s\n",MSJ_ERROR_PREFIJO,MSJ_ERROR_CAMBIO_INESPERADO);
	}

	return EXIT_SUCCESS;

}


