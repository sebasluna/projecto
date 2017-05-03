#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> 

#define fil 3
#define col 3

void Llenar_Matriz(int matriz[fil][col]);
int LlenarAutomatica(int matriz[fil][col]);
int LlenarTeclado(int matriz[fil][col]);
void contenido_menu();
void menu();
void MostrarMatriz(int matriz[fil][col]);
int MatrizTranspuesta(int [fil][col]);
int DeterminanteMatriz(int [fil][col]);
int MultiplicacionPorEscalar(int [fil][col]);
int PotenciaMatriz(int [fil][col]);
int MatrizA_Mas_MatrizB(int matriz[fil][col], int matriz1[fil][col]);
int MatrizA_Menos_MatrizB(int matriz[fil][col], int matriz1[fil][col]);
int MatrizA_Por_MatrizB(int matriz[fil][col], int matriz1[fil][col]);
void salir();

int main() {
	
	int matriz[fil][col], matriz1[fil][col];
	Llenar_Matriz(matriz);
	menu();
	return 0;
}
void Llenar_Matriz(int matriz[fil][col]){
	
	int opcion;
	do{
		printf("\t\tBIENVENIDO");
	    printf("\n 1. Llenar Matriz Automaticamente");
	    printf("\n 2. Llenar Matriz Manualmente");
		printf("\n 3. Salir");  
		printf("\n Ingrese La Opcion Deseada: ");
		scanf("%d", &opcion);	  
	}while(opcion < 0 || opcion > 3);
	switch(opcion){
		case 1: LlenarAutomatica(matriz);
			break;
		case 2:  LlenarTeclado(matriz);	
			break;
		case 3: exit(0);
			break;
		default: Llenar_Matriz(matriz);
            break;		
	}
	system("pause");
}

int LlenarAutomatica(int matriz[fil][col]){
	
	 int f, c;
	 int i=0;
	 
       for (f = 0; f < fil; f++){
         for (c = 0; c < col; c++){
            matriz[f][c]=i;
            printf("\t%d",matriz[f][c]);
            i=i+1;
         }
       printf("\n");
    }
    return (matriz[f][c]);
}

int LlenarTeclado(int matriz[fil][col]){
	
	int f, c;
	
    for(f = 0; f < fil; f++){
        for(c = 0; c < col; c++){
        	
           printf("Ingrese un numero  en la posicion [%d][%d]: ", f,c);
           scanf("%d", &matriz[f][c]);
          
        }
        printf("\n");
    }
    return (matriz[f][c]);
}
void contenido_menu(int opcion){
    printf("  |---------------------CALCULADORA DE MATRICES--------------------|\n");
    printf("  |                                  |                             |\n");
    printf("  |   1. Mostrar Matriz.             |   6. Matriz A + Matriz B    |\n");
    printf("  |   2. Matriz Transpuesta.         |   7. Matriz A - Matriz B    |\n");
    printf("  |   3. Determinante de Matriz.     |   8. Matriz A * Matriz B    |\n");
    printf("  |   4. Multiplicacion Por Escalar. |   0. Salir.                 |\n");
    printf("  |   5. Potencia de Matriz.         |                             |\n");
    printf("  |----------------------------------------------------------------|\n");

}
void menu(){
	
    int opcion;
    char ese;
    int contador = 0;
    int matriz[fil][col];
    int matriz1[fil][col];
    
    do{
       system("cls");
       contenido_menu(opcion);
       if(contador > 0){
            printf("\n Opcion invalida, es un numero del 0 al 8");
       }
       printf("\nIngrese la opcion deseada: ");
       scanf("%d", &opcion);
       contador += 1;
    }while(opcion > 9 || opcion < 0);
    
    switch(opcion){
        case 1: MostrarMatriz(matriz);
            break;
        case 2: MatrizTranspuesta(matriz);
            break;
        case 3: DeterminanteMatriz(matriz);
            break;
        case 4: MultiplicacionPorEscalar(matriz);
            break;
        case 5: PotenciaMatriz(matriz);
            break;
        case 6: MatrizA_Mas_MatrizB(matriz, matriz1);
            break;
        case 7: MatrizA_Menos_MatrizB(matriz, matriz1);
            break;
        case 8: MatrizA_Por_MatrizB(matriz, matriz1);
            break;
        case 0: exit(0);
            break;
        default: menu();
            break;
    }
    printf("\nPresione una letra para continuar: ");
    scanf(" %c", &ese);
    menu();
}

void MostrarMatriz( int matriz[fil][col]){
	int f, c;
    for(f = 0; f < fil; f++){
        for(c = 0; c < col; c++){
            printf("%d ", matriz[f][c]);
        }
        printf("\n");
    }
}

int MatrizTranspuesta(int matriz[fil][col]){
	int f, c;
	printf("matriz transpuesta \n");
    for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
            printf ("%d",matriz[c][f]);
        }
        printf("\n");
    }
}

int DeterminanteMatriz(int matriz[fil][col]){
	
	int resultado1,resultado2,deter;
	
	resultado1= matriz[0][0]*matriz[1][1]*matriz[2][2]+matriz[0][1]*matriz[1][2]*matriz[2][0]+matriz[0][2]*matriz[1][0]+matriz[2][1];
	resultado2= matriz[0][2]*matriz[1][1]*matriz[2][0]+matriz[0][0]*matriz[1][2]*matriz[2][1]+matriz[0][1]*matriz[1][0]+matriz[2][2];
	deter = resultado1-resultado2;
	return deter;
}


int MultiplicacionPorEscalar(int [fil][col]){
	int f, c, numero;
	int escalar[f][c], matriz[f][c];
	
	printf("\n ingrese el numero para multiplicar la matriz: ");
	scanf("%d", &numero);
	printf("\n la multiplicacion de la matriz por el numero es:");
   for(f = 0; f < fil; f++){
		for(c = 0; c < col; c++){
			escalar[f][c] = matriz[f][c] * numero;
			printf("%d",escalar[f][c]);
       } 
	  printf("\n");        
   }
}

int PotenciaMatriz(int matriz[fil][col]){
	int f, c, potencia;
	
	void MostrarMatriz(int matriz[fil][col]);
	printf("\n ingrese la potencia a elevar la matriz: ");
	scanf("%d", &potencia);
	for (int f = 0; f < 3; f++){ 
		for (int c = 0; c < 3; c++){
			matriz [f][c] = pow (matriz [f][c], potencia); 
			printf("%d",matriz[f][c]);
		}
		printf("\n");
	}
}

int MatrizA_Mas_MatrizB(int matriz[fil][col], int matriz1[fil][col]){
	int f, c;
	int suma_matriz[f][c];

	printf("      PRIMERA MATRIZ \n");
	void MostrarMatriz(int matriz[fil][col]);
	printf("      SEGUNDA MATRIZ \n");
    for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
            printf ("ingrese el valor en la posicion [%d][%d] ",f,c);
            scanf ("%d", & matriz1[f][c]);
        }
    }
      for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
             printf ("%d",matriz1[f][c]);
        }
        printf("\n");
    }
     printf("\n ESTA ES LA SUMA DE LAS 2 MATRICES \n");
    for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
            suma_matriz[f][c] = matriz[f][c] + matriz1[f][c];
            printf("%d",suma_matriz[f][c]);
        }
        printf("\n");
    }
}

int MatrizA_Menos_MatrizB(int matriz[fil][col], int matriz1[fil][col]){
	int f, c;  
	int resta_matriz[f][c];
	
	printf("      PRIMERA MATRIZ \n");
	void MostrarMatriz(int matriz[fil][col]);
	printf("      SEGUNDA MATRIZ \n");
    for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
            printf ("ingrese el valor en la posicion [%d][%d] ",f,c);
            scanf ("%d", & matriz1[f][c]);
        }
    }
      for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
             printf ("%d",matriz1[f][c]);
        }
        printf("\n");
    }
     printf("\n ESTA ES LA RESTA DE LAS 2 MATRICES \n");
    for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
            resta_matriz[f][c] = matriz[f][c] - matriz1[f][c];
            printf("%d",resta_matriz[f][c]);
        }
        printf("\n");
    }
}

int MatrizA_Por_MatrizB(int matriz[fil][col], int matriz1[fil][col]){
	int f, c; 
	int producto_matriz[f][c];
	
	printf("      PRIMERA MATRIZ \n");
	void MostrarMatriz(int matriz[fil][col]);
	printf("      SEGUNDA MATRIZ \n");
    for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
            printf ("ingrese el valor en la posicion [%d][%d] ",f,c);
            scanf ("%d", & matriz1[f][c]);
        }
    }
      for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
             printf ("%d",matriz1[f][c]);
        }
        printf("\n");
    }
     printf("\n ESTE ES EL PRODUCTO DE LAS 2 MATRICES \n");
    for(f = 0; f < fil; f++) {
        for(c = 0; c < col; c++) {
            producto_matriz[f][c] = matriz[f][c] * matriz1[f][c];
            printf("%d",producto_matriz[f][c]);
        }
        printf("\n");
    }
}


