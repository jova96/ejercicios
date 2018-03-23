#include <stdio.h>

typedef enum { DOMINGO = 0 , LUNES , MARTES , MIERCOLES , JUEVES , VIERNES , SABADO = 6 } dia_t;

int main (void)
{

	dia_t primer_dia;
	dia_t segundo_dia;
	dia_t tercer_dia;
	dia_t cuarto_dia;
	dia_t quinto_dia;
	dia_t sexto_dia;
	dia_t septimo_dia;
	dia_t  dia_actual;
    int dia_ingresado;

	primer_dia = DOMINGO;

	puts("ingresa un valor");
	scanf("%i",&dia_ingresado);

	switch(primer_dia)
	{

		case DOMINGO :
										primer_dia = DOMINGO ; segundo_dia = LUNES ;
										tercer_dia = MARTES ; cuarto_dia = MIERCOLES ;
										quinto_dia = JUEVES ; sexto_dia = VIERNES ;
										septimo_dia = SABADO ;  break;

		case LUNES :
										primer_dia = LUNES ; segundo_dia = MARTES ;
										tercer_dia = MIERCOLES ; cuarto_dia = JUEVES ;
										quinto_dia = VIERNES ; sexto_dia = SABADO ;
										septimo_dia = DOMINGO ;  break;

		case MARTES :
										primer_dia = MARTES ; segundo_dia = MIERCOLES ;
										tercer_dia = JUEVES ; cuarto_dia = VIERNES ;
										quinto_dia = SABADO ; sexto_dia = DOMINGO ;
										septimo_dia = LUNES ;  break;

		case MIERCOLES :
										primer_dia = MIERCOLES ; segundo_dia = JUEVES ;
										tercer_dia = VIERNES ; cuarto_dia = SABADO ;
										quinto_dia = DOMINGO ; sexto_dia = LUNES ;
										septimo_dia = MARTES ;  break;

		case JUEVES :
										primer_dia = JUEVES ; segundo_dia = VIERNES ;
										tercer_dia = SABADO ; cuarto_dia = DOMINGO ;
										quinto_dia = LUNES ; sexto_dia = MARTES ;
										septimo_dia = MIERCOLES ;  break;

		case VIERNES :
										primer_dia = VIERNES ; segundo_dia = SABADO ;
										tercer_dia = DOMINGO ; cuarto_dia = LUNES ;
										quinto_dia = MARTES ; sexto_dia = MIERCOLES ;
										septimo_dia = JUEVES ;  break;

		case SABADO :
										primer_dia = SABADO ; segundo_dia = DOMINGO ;
										tercer_dia = LUNES ; cuarto_dia = MARTES ;
										quinto_dia = MIERCOLES ; sexto_dia = JUEVES ;
										septimo_dia = VIERNES ;  break;
	}

	switch(dia_ingresado % 7)
	{

		case primer_dia :
			dia_actual = DOMINGO ; break;

		case segundo_dia :
			dia_actual = LUNES ;   break;

		case tercer_dia :
			dia_actual = MARTES ; break;

		case cuarto_dia :
			dia_actual = MIERCOLES ; break;

		case quinto_dia :
			dia_actual = JUEVES ;    break;

		case sexto_dia :
			dia_actual = VIERNES ;  break;

		case septimo_dia :
			dia_actual = SABADO ;    break;
	}

	switch(dia_actual)
	{

		case DOMINGO :
			puts("es domingo") ; break;

		case LUNES :
			 puts("es lunes")  ;   break;

		case MARTES :
			puts("es martes") ; break;

		case MIERCOLES :
			puts("es miercoles") ; break;

		case JUEVES :
			puts("es jueves") ;    break;

		case VIERNES :
			puts("es viernes") ;  break;

		case SABADO :
			puts("es sabado") ;    break;
	}

	return 0;

}
