#include <stdio.h>
#include <stdlib.h>
#define DIM 100

void  LeggereArray(int v[], int dim);
int CalcolarePositivi(int v[], int dim);
int CalcolareNegativi(int v[], int dim);

int main(void) {
	int n;   //descrizione e vincoli
	int Valori[DIM];
	int Positivi;
	int Negativi;
	int Nulli;
	int Pari;
	int Dispari;
	int Crescente;
	int Decrescente;
	int NessunaTendenza;


	int i;

	//Leggere n
	do{
			printf("Inserire valore intero > di 0 e <= di 100: ");
			scanf("%d", &n);
		}while(n<=0 || n>100);

	LeggereArray(Valori, n);
	Positivi=CalcolarePositivi(Valori, n);
	Negativi=CalcolareNegativi(Valori, n);

	// Calcolare Nulli
		Nulli=0;
		i=0;
			while(i<n){
				if(Valori[i]==0){
					Nulli++;
				}
				i++;
			}

	// Calcolare pari
		Pari=0;
		i=0;
			while(i<n){
				if(Valori[i]%2==0){
					Pari++;
				}
				i++;
			}

	// Calcolare dispari
		Dispari=0;
		i=0;
			while(i<n){
				if(Valori[i]%2!=0){
					Dispari++;
				}
				i++;
			}

	//Verificare crescenza
		Crescente=1;
		i=0;
			while(i<n-1 && Crescente==1){
				if(Valori[i]>Valori[i+1]){
					Crescente=0;
				}
				i++;
			}

	//Verificare decrescenza
		Decrescente=1;
		i=0;
			while(i<n-1 && Decrescente==1){
				if(Valori[i]<Valori[i+1]){
					Decrescente=0;
				}
				i++;
			}

	// verificare nessuna tendenza
	if(Crescente==0 && Decrescente==0){
		NessunaTendenza=1;
	}

	// Stampare risultati
		printf("Numero di elementi positivi=%d\n", Positivi);
		printf("Numero di elementi negativi=%d\n", Negativi);
		printf("Numero di elementi nulli=%d\n", Nulli);
		printf("Numero di elementi pari=%d\n", Pari);
		printf("Numero di elementi dispari=%d\n", Dispari);
		if(Crescente==1){
			printf("I numeri del vettore sono crescenti\n");
		}else{
			if(Decrescente==1){
				printf("I numeri del vettore sono decrescenti\n");
			}else{
				printf("I numeri del vettore non sono crescenti o decrescenti\n");
			}
		}

	system("PAUSE");
	return 0;
}



int CalcolarePositivi(int v[], int dim)
{
	int p;
	int i;
	p=0;
	i=0;
	while(i<dim){
		if(v[i]>0) p=p+1;
		i=i+1;
	}
	return p;
}

/*
 * Calcola il numero di valori negativi presenti in Valori
 *
 *
 */
int CalcolareNegativi(int v[], int dim)
{
	int n;  //numero di valori negativi, >=0
	int i;  //
	n=0;
	i=0;
	while(i<dim){
		if(v[i]<0) n=n+1;
		i=i+1;
	}
	return n;
}

/*
 * Legge n valori da tastiera e li inserisce in Valori
 *
 *
 */
void LeggereArray(int v[], int dim)
{int i;  //
i=0;
while (i<dim){
	printf("Inserire %d-esimo valore: ", i+1);
	scanf("%d",&v[i]);
	i=i+1;
	}
return;
}

