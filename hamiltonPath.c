#include <stdio.h>
#include <stdlib.h>

#include "hamiltonPath.h"

// Há algum problema com os ponteiros.

#define maxV 10

int visited[maxV];


/// Forma simplificada de representação da estrutura Edge.
/// @a: início (ou fim) de uma aresta.
/// @b: início (ou fim) de uma aresta.
/// @return: a própria aresta.
Edge EDGE( int a, int b)
{
    Edge e;
    e.v = a;
    e.w = b;
    return e;
}


/// Inicia um grafo com @V vértices. Retorna um ponteiro para o grafo.
/// @V: número de vértices do grafo.
/// @return: ponteiro para o grafo criado.
Graph* GRAPHinit( int V )
{
    Graph *G = malloc(sizeof( G ) );
    G->V = V;
    G->E = 0;
    G->adj = MATRIXinit( V, V, 0 );
    return G;
}


/// Insere uma aresta @e ao grafo @G. Incrementa o contador de arestas do gravo.
/// @G: grafo a ser inserida a aresta.
/// @e: aresta a ser inserida ao grafo.
void GRAPHinsertE( Graph *G, Edge e )
{

    if( (e.v > G->V - 1 ) || ( e.w > G->V -1 ) ){
        printf("ERRO: valor do vértice adicionado não existe!\n");
        return;
    }
    int v = e.v, w = e.w;
    if( G->adj[v][w] == 0 )
        G->E++;
    G->adj[v][w] = 1;
    G->adj[w][v] = 1;
}


/// Remove uma aresta @e do grafo @G. Descrementa o contador de arestas do grafo.
/// @G: grafo que contém a aresta a ser removida.
/// @e: aresta com os valores a serem removidos.
void GRAPHremoveE( Graph *G, Edge e )
{
    int v = e.v, w = e.w;
    if( G->adj[v][w] == 1 )
        G->E--;
    G->adj[v][w] = 0;
    G->adj[w][v] = 0;
}


/// Preenche o vetor de Edges @a com todas as arestas existentes no grafo.
/// @a: vetor de arestas.
/// @G: grafo de busca.
/// @return: número de arestas existentes.
int GRAPHedges( Edge a[], Graph *G )
{
    int v, w, E = 0;
    for( v = 0; v < G->V; v++)
        for( w = v+1; w < G->V; w++)
            if( G->adj[v][w] == 1 )
                a[E++] = EDGE( v, w );
    return E;
}


/// Inicia uma matrix, alocando com tamanho dependente dos parâmetros.
/// @r: número de colunas.
/// @v: número de linhas.
/// @val: valor para cada posição da matriz.
/// @return: retorna um ponteiro para a matriz.
int **MATRIXinit( int r, int v, int val )
{
    int i, j;
    int **t = malloc( r *sizeof( int* ) );
    for( i = 0; i < r; i++ )
        t[i] = malloc( v * sizeof( int ) );
    for( i = 0; i < r; i++ )
        for( j = 0; j < v; j++ )
            t[i][j] = val;
    return t;
}


/// Imprime todas as arestas existentes no grafo.
/// @G: ponteiro para o grafo a ser varrido.
void GRAPHshow( Graph *G )
{
    int i, j;
    printf("%d vertices, %d edges\n", G->V, G->E );
    for( i = 0; i < G->V; i++ )
    {
        printf("%2d:", i);
        for( j = 0; j < G->V; j++)
            if( G->adj[i][j] == 1 )
                printf("  %2d", j );
        printf("\n");
    }
}

//int randV( Graph G )
//{
//    return G->V * ( rand() /( RAND_MAX + 1.0 ) );
//}
//
//Graph GRAPHrand( int V, int E )
//{
//    Graph G = GRAPHinit( V );
//    while( G->E < E )
//        GRAPHinsertE( G, EDGE(randV(G), randV(G) ) );
//    return G;
//}



int pathR( Graph *G, int v, int w, int d )
{
    int t;
    printf("O que já foi visitado?\n");
    for( t = 0; t < G->V; t++ )
        printf("%d=%d, ", t, visited[t]);
    printf("\n");
    if( v == w )
    {
        if( d == 0 )
            return 1;
        else
            return 0;
    }
    visited[v] = 1;         /// Erro aqui. Rever o livro.
    for( t = 0; t < G->V; t++ )
        if( G->adj[v][t] == 1 )
            if( visited[t] == 0 )
                if( pathR( G, t, w, d-1 ) ){
                    printf("%d-> ", t );
                    return 1;
                }
    visited[v] = 0;
    return 0;
}

int GRAPHpathH( Graph *G, int v, int w )
{
    int t;
    for( t = 0; t < G->V; t++ )
        visited[t] = 0;
    return pathR( G, v, w, G->V-1 );
}


//main(){
//    static int visited[maxV];
//
//}
