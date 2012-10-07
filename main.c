#include <stdio.h>
#include <stdlib.h>

#include "hamiltonPath.h"

main(){
	Graph *g = GRAPHinit( 6 );              // Cria um grafo com 4 vértices {0, 1, 2, 3}
    GRAPHinsertE( g, EDGE( 4, 1) );         // Adiciona uma aresta
    GRAPHinsertE( g, EDGE( 1, 2) );         // Adiciona uma aresta
    GRAPHinsertE( g, EDGE( 1, 3) );         // Adiciona uma aresta
    GRAPHinsertE( g, EDGE( 1, 0) );         // Adiciona uma aresta
    GRAPHinsertE( g, EDGE( 0, 2) );         // Adiciona uma aresta
    GRAPHinsertE( g, EDGE( 0, 3) );         // Adiciona uma aresta
    GRAPHinsertE( g, EDGE( 2, 3) );         // Adiciona uma aresta
    GRAPHinsertE( g, EDGE( 5, 1) );         // Adiciona uma aresta
    GRAPHinsertE( g, EDGE( 3, 5) );         // Adiciona uma aresta

//    GRAPHinsertE( g, EDGE( 0, 3) );         // Adiciona uma aresta
	GRAPHshow( g );


	Edge *a = malloc( sizeof( Edge ) );
	int b, c;
	b = GRAPHedges( a, g );

	for( c = 0; c < b; c++ )
        printf("%d - %d\n", a[c].v, a[c].w );

    printf("Exite caminho de 2 à 1: %d\n", GRAPHpathH( g, 4, 5 ) );


}
