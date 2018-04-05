#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CANTIDAD_COEF 3 /* (cant.._coef - 1) sera el grado del polinomio*/
#define MSJ_PRESNTACION_PROGRAMA "Evaluar x0 en el polinomio   a2 * X^2 + a1 *X^1 + a0"
#define MSJ_INGRESO_COEF "Ingrese el valor de el coeficiente"
#define MSJ_INGRESO_EVALUAR_POLINOMIO "Ingrese el valor donde evaluara el polinomio"
#define MSJ_RESULTADO_POL_EVALUADO "El valor del polinomio es"

#define MSJ_ERROR_PREFIJO "ERROR"
#define MSJ_ERROR_INGRESO "Ingreso invalido"

typedef enum{ ST_OK,ST_ERROR_INGRESO,ST_EXP_NEGATIVO } status_t;

status_t limpiar_buffer(void);
status_t potencia_positiva(double,int,double []);

int main(void)
{
    int var_conteo;
    double valor_polinomio , pol_evaluado;
    double potencia[1];
    double coef[CANTIDAD_COEF];

	puts(MSJ_PRESNTACION_PROGRAMA);
	for(var_conteo = 0 ; var_conteo < CANTIDAD_COEF ; var_conteo++){
		printf("%s a%i:",MSJ_INGRESO_COEF,var_conteo);
		if( scanf("%lf",&coef[var_conteo] ) != 1){
			fprintf(stderr,"%s: %s\n",MSJ_ERROR_PREFIJO,MSJ_ERROR_INGRESO);
			return EXIT_FAILURE;
		}
		if(limpiar_buffer() == ST_ERROR_INGRESO){
			fprintf(stderr,"%s: %s\n",MSJ_ERROR_PREFIJO,MSJ_ERROR_INGRESO);
			return EXIT_FAILURE;
		}
	}

	printf("%s:",MSJ_INGRESO_EVALUAR_POLINOMIO);
	if( scanf("%lf",&valor_polinomio) != 1){
		fprintf(stderr,"%s: %s\n",MSJ_ERROR_PREFIJO,MSJ_ERROR_INGRESO);
		return EXIT_FAILURE;
	}
	if(limpiar_buffer() == ST_ERROR_INGRESO){
		fprintf(stderr,"%s: %s\n",MSJ_ERROR_PREFIJO,MSJ_ERROR_INGRESO);
		return EXIT_FAILURE;
	}

	for(var_conteo = 0 , pol_evaluado = 0; var_conteo < CANTIDAD_COEF ; var_conteo++){
		if(potencia_positiva(valor_polinomio,var_conteo,potencia) == ST_OK){
			pol_evaluado += ( coef[var_conteo] * potencia[0] );
		}
		else{
			fprintf(stderr,"%s:%s\n",MSJ_ERROR_PREFIJO,MSJ_ERROR_INGRESO);
			return EXIT_FAILURE;
		}
	}

	printf("%s :%.4f\n",MSJ_RESULTADO_POL_EVALUADO,pol_evaluado);
	return EXIT_SUCCESS;
}



status_t limpiar_buffer(void)
{

	int var_aux;

	if( ( var_aux = getchar() ) == '\n' || var_aux == EOF ){
		return ST_OK;
	}
	else{
		return ST_ERROR_INGRESO;
	}
}



status_t potencia_positiva(double base , int exponente , double potencia[])
{
	size_t var_conteo;

	if( exponente < 0){
		return ST_EXP_NEGATIVO;
	}

	for(var_conteo = 0 , potencia[0] = 1 ; var_conteo < exponente ; var_conteo++){
		potencia[0] *= base;
	}

	return ST_OK;
}
