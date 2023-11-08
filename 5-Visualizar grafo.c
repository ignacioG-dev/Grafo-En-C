#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 10

typedef int tVertice;

typedef struct{
	tVertice origen;
	tVertice destino;
}tArco;

typedef bool conjuntoVertices[N];
typedef bool conjuntoArcos[N][N];

typedef struct {
	conjuntoVertices vertices;
	conjuntoArcos arcos;
}tGrafo;

tArco arco;
tGrafo grafo;

void inicializar(tGrafo*);
void agregarVertice(tGrafo*,tVertice);
void agregarArco(tGrafo*,tArco);

int maximoVertice(tGrafo);
void visualizar(tGrafo);
bool existeVertice(tGrafo,tVertice);

int main(){
	inicializar(&grafo);
	
	agregarVertice(&grafo,1);
	agregarVertice(&grafo,2);
	agregarVertice(&grafo,3);	

	arco.origen=1;
	arco.destino=2;
	agregarArco(&grafo,arco);
	
	visualizar(grafo);		
	
	return 0;
}

void inicializar(tGrafo* pGrafo){
	int x,y;
	
	for(x=0;x<=N;x++){
		pGrafo->vertices[x]=0;
		
		for(y=0;y<=N;y++){
			pGrafo->arcos[x][y]=0;
		}
	}
}

void agregarVertice(tGrafo* pGrafo,tVertice pVertice){
	pGrafo->vertices[pVertice]=1;
	printf("\nSe agrego el vertice");
}

void agregarArco(tGrafo* pGrafo,tArco pArco){
	if(pGrafo->vertices[pArco.origen]==1&&
		pGrafo->vertices[pArco.destino]==1){ 
			pGrafo->arcos[pArco.origen][pArco.destino]=1;
			printf("\nSe agrego el arco [%d, %d]",pArco.origen,pArco.destino);
		} else{
			printf("\nNo se puede agregar el arco - Alguno de los vertices no esta activo");
		}
}

int maximoVertice(tGrafo pGrafo){
	int x,max;
	
	for(x=0;x<=N;x++){
		if(pGrafo.vertices[x]==1){
			max=x;
		}
	}
	
	return max;
}

void visualizar(tGrafo pGrafo){
	int x,y,maxVer;
	bool existeArista=false;
	
	maxVer=maximoVertice(pGrafo);
	
	printf("\nMATRIZ DE ADYACENCIA\n");
	for(x=1;x<=maxVer;x++){
		for(y=1;y<=maxVer;y++){
			existeArista=(pGrafo.arcos[x][y]==true)&&existeVertice(pGrafo,x)&&existeVertice(pGrafo,y);
			
			if(existeArista){
				printf(" 1 ");
			} else{
				printf(" 0 ");
			}
		}
		printf("\n");
	}
	
}

bool existeVertice(tGrafo pGrafo,tVertice pVertice){
	return pGrafo.vertices[pVertice]==1;
}


