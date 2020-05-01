#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Constantes
#define MAXIMO 10

//Variables Globales
int n=0, i;

int menu(){
	int opcion;
	printf("------------------------\n");
	printf("Menu de Funciones\n");
	printf("------------------------\n");
	printf("0. Salir\n");
	printf("1. Imprimir Calificaciones\n");
	printf("2. Agregar una Calificacion\n");
	printf("3. Eliminar una Calificacion\n");
	printf("4. Buscar una Calificacion\n");
	printf("5. Buscar Promedio\n");
	printf("6. Calcular calificacion mayor\n");
	printf("7. Calcular calificacion menor\n");
	printf("8. Calcular cuantos aprobados\n");
	printf("9. Calcular desviacion estandar\n");
	printf("------------------------\n");
	printf("Introduce la opcion deseada: ");
	scanf("%d", &opcion);
	return opcion;
}

int agregar(float x[], float dato){
	int band = 0;
	if (n<MAXIMO){
		x[n]=dato;
		n++;
		band=1;
	}
	return band;
}

void imprimir(float x[]){
	printf("No. \t Cal \n");
	printf("--------------------\n");
	for (i = 0; i<n; i++){
		printf("%3d \t %3.1f \n", i+1, x[i]);
	}
	printf("--------------------\n");
}

int eliminar(float x[], int pos){
	int band = 0;
	if (pos>0 && pos<n){
		for (i=pos; i<n-1; i++){
			x[i] =  x[i+1];
		}
		n--;
		band = 1;
	}
	return band;
}

int buscar(float x[], float dato){
	int pos = -1;
	for (i = 0; i<n; i++){
		if (x[i] == dato){
			pos = i+1;
			break;
		}
	}
	return pos;
}

float promedio(float x[]){
	float suma = 0;
	for (i = 0; i<n; i++){
		suma += x[i];
	}
	return (suma/n);
}

float mayor(float x[]){
	int mayor = 0;
	for(i = 0; i<n; i++){
		if(x[i]>mayor){
			mayor = x[i];
		}
	}
	return mayor;
}

float menor(float x[]){
	int menor = 100000;
	for(i = 0; i<n; i++){
		if(x[i]<menor){
			menor = x[i];
		}
	}
	return menor;
}

int aprobados(float x[]){
	int a = 0;
	for(i = 0; i<n; i++){
		if(x[i]>=7){
			a++;
		}
	}
	return a;
}

float desviacion(float x[]){
	float calificaciones[MAXIMO];
	float prom = promedio(calificaciones), desc, sum = 0;
	for (i = 0; i<n; i++){
		desc = pow((x[i]-prom), 2);
		sum += desc;
	}
	return sqrt(sum/n);
}

int main(){
	int opcion, p;
	float dato;
	float calificaciones[MAXIMO];
	do {\
		system("cls");
		opcion = menu();
		switch(opcion){
			case 0:
				printf("Adios...");
			break;
			
			case 1:
				imprimir(calificaciones);
			break;
			
			case 2:
				printf("Introduce la calificacion: ");
				scanf("%f", &dato);
				if(agregar(calificaciones, dato)){
					printf("Calificacion agregada!\n");
				}
				else{
					printf("No es posible agregar el dato\nArreglo lleno\n");
				}
			break;
			
			case 3:
				printf("Introduce la posicion a eliminar: ");
				scanf("%d", &p);
				int f = p-1;
				if (eliminar(calificaciones, f)){
					printf("Posicion eliminada!\n");
				}
				else{
					printf("Posicion invalida!\n");
				}
			break;
			
			case 4:
				printf("Introduce la calificacion a buscar: ");
				scanf("%f", &dato);
				p = buscar(calificaciones, dato);
				if(p>0){
					printf("Calificacion encontrada en la posicion %d\n", p);
				}
				else{
					printf("Calificacion no encontrada\n");
				}
			break;
			
			case 5:
				printf("El promedio es %.2f \n", promedio(calificaciones));
			break;
			
			case 6:
				printf("La calificacion mayor: %.2f \n", mayor(calificaciones));
			break;
			
			case 7:
				printf("La calificacion menor: %.2f \n", menor(calificaciones));
			break;
			
			case 8:
				printf("Numero de aprobados: %d \n", aprobados(calificaciones));
			break;	
			
			case 9:
				printf("La desviacion estandar: %.2f \n", desviacion(calificaciones));
			
			default:
				printf("Opcion no valida!\n");
			break;
		}
		system("pause");
	}while(opcion!=0);	
	return 0;
}
