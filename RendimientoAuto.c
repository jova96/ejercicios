#include <stdio.h>
#include <stdlib.h>

#define SALIR -1

#define MSJ_INGRESO_KM_RECORRIDOS "Ingrese los kilometros recorridos "
#define MSJ_OPCION_TERMINAR " -1 para terminar"
#define MSJ_INGRESO_PRECIO_COMBUSTIBLE_POR_L "Ingrese el precio del cobustible por litro "
#define MSJ_INGRESO_MONTO_TOTAL_POR_COMPRA "Ingrese el monto total utilizado en esta compra"
#define MSJ_RENDIMIENTO_PARCIAL "Rendimiento (1/100km) de este tanke"
#define MSJ_RENDIMIENTO_PROMEDIO "Rendimiento promedio (1/100km)"
#define MSJ_MEJOR_RENDIMIENTO "Mejor rendimiento (1/100km)"
#define MSJ_PEOR_RENDIMIENTO "Peor rendimiento (1/100km)"
#define MSJ_KM_TOTAL_RECORRIDO "Distancia total recorrida (km)"
#define MSJ_COMBUSTIBLE_TOTAL "Combustible total consumido (l)"
#define MSJ_COSTO_TOTAL_VEHICULO "Costo total de su vehiculo ($)"

#define MSJ_ERROR_PREFIJO "ERROR"
#define MSJ_ERROR_INGRESO "Se espera un valor numerico"
#define MSJ_ERROR_INGRESO_SALIR "Ingreso la opcion salir antes de ingresar algun valor"

int main(void)
{

	float km_recorridos_parcial = 0;
	float km_recorridos_total = 0;
	float precio_combustible_por_L = 0;
	float monto_combustible_parcial = 0;
	float monto_combustible_total = 0;
	float combustible_total_consumido = 0;
	float rendimiento_parcial = 0;
	float rendimiento_promedio = 0;
	float mejor_rendimiento = 0;
	float peor_rendimiento = 0;
	int estado = 0;
	int var_conteo = 0;

	printf("%s ( %s)\n",MSJ_INGRESO_KM_RECORRIDOS,MSJ_OPCION_TERMINAR);
	if( ( scanf("%f",&km_recorridos_parcial) ) != 1){
		fprintf(stderr,"%s: %s\n",MSJ_ERROR_PREFIJO,MSJ_ERROR_INGRESO);
		return EXIT_FAILURE;
	}

	if( km_recorridos_parcial == SALIR ){
		fprintf(stderr,"%s: %s\n",MSJ_ERROR_PREFIJO,MSJ_ERROR_INGRESO_SALIR);
		return EXIT_FAILURE;
	}

	while( estado != SALIR ){

		var_conteo +=1;
		km_recorridos_total += km_recorridos_parcial;

		puts(MSJ_INGRESO_PRECIO_COMBUSTIBLE_POR_L);
		if( ( scanf("%f",&precio_combustible_por_L) ) != 1){
			fprintf(stderr,"%s: %s\n",MSJ_ERROR_PREFIJO,MSJ_ERROR_INGRESO);
			return EXIT_FAILURE;
		}

        puts(MSJ_INGRESO_MONTO_TOTAL_POR_COMPRA);
		if( ( scanf("%f",&monto_combustible_parcial) ) != 1){
			fprintf(stderr,"%s: %s\n",MSJ_ERROR_PREFIJO,MSJ_ERROR_INGRESO);
			return EXIT_FAILURE;
		}

		monto_combustible_total += monto_combustible_parcial;
		combustible_parcial_consumido = monto_combustible_parcial / precio_combustible_por_L;
		combustible_total_consumido += combustible_parcial_consumido;
		rendimiento_parcial = ((combustible_parcial_consumido)* 100 ) / km_recorridos_parcial;
		rendimiento_promedio += rendimiento_parcial;


		printf("%s : %f\n\n",MSJ_RENDIMIENTO_PARCIAL, rendimiento_parcial);

		if(rendimiento_parcial >= mejor_rendimiento ){
			mejor_rendimiento = rendimiento_parcial;
		}
		if(peor_rendimiento == 0){
			peor_rendimiento = rendimiento_parcial;
		}
		else if(peor_rendimiento > rendimiento_parcial){
			peor_rendimiento = rendimiento_parcial;
		}

		printf("%s ( %s)\n",MSJ_INGRESO_KM_RECORRIDOS,MSJ_OPCION_TERMINAR);
		if( ( scanf("%f",&km_recorridos_parcial) ) != 1){
			fprintf(stderr,"%s: %s\n",MSJ_ERROR_PREFIJO,MSJ_ERROR_INGRESO);
			return EXIT_FAILURE;
		}

		if( km_recorridos_parcial == SALIR ){
			estado = SALIR;
		}

	}

	printf("%s >> %f\n",MSJ_RENDIMIENTO_PROMEDIO,rendimiento_promedio / conteo);
	printf("%s >> %f\n",MSJ_MEJOR_RENDIMIENTO,mejor_rendimiento);
	printf("%s >> %f\n",MSJ_PEOR_RENDIMIENTO,peor_rendimiento);
	printf("%s >> %f\n",MSJ_KM_TOTAL_RECORRIDO,km_recorridos_total);
	printf("%s >> %f\n",MSJ_COMBUSTIBLE_TOTAL,combustible_total_consumido);
	printf("%s >> %f\n",MSJ_COSTO_TOTAL_VEHICULO,monto_combustible_total);

}
