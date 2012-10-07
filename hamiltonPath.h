#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int V, E;
    int **adj;
} Graph;

typedef struct {
    int v, w;
} Edge;

Edge EDGE( int, int );

//typedef struct graph *Graph;

Graph* GRAPHinit( int );

void GRAPHinsertE( Graph*, Edge );

void GRAPHremoveE( Graph*, Edge );

int GRAPHedges( Edge[], Graph *G );

Graph GRAPHcopy( Graph* );

void GRAPHdestrpy( Graph* );

int **MATRIXinit( int r, int v, int val );

int pathR( Graph *G, int v, int w, int d );

int GRAPHpathH( Graph *G, int v, int w );
