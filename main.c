#include <stdio.h>
#include <stdlib.h>

#include "hamiltonPath.h"

main(){
	Graph *g = GRAPHinit( 4 );              // Cria um grafo com 4 vértices {0, 1, 2, 3}

    GRAPHinsertE( g, EDGE( 1, 2) );         // Adiciona uma aresta válida.
    GRAPHinsertE( g, EDGE( 3, 0) );         // Adiciona uma aresta a um vértice inválido. ( > 3 )
	GRAPHshow( g );


	Edge *a = malloc( sizeof( Edge ) );
	int b, c;
	b = GRAPHedges( a, g );

	for( c = 0; c < b; c++ )
        printf("%d - %d\n", a[c].v, a[c].w );



}
