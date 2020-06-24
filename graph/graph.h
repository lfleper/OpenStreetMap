#ifndef GRAPH_H
#define GRAPH_H

/*
Struktur eines Graphen, so wie er bei der Breitensuche im Buch
Algorithmen – Eine Einführung; Cormen, Leiserson, Rivest, Stein
benutzt wird
 */

#include "knoten.h"
#include <ostream>
using namespace std;

const int MAX_KNOTEN=5646 + 1;

/**
 * @brief Graph
 */
class Graph
{
public:
    Knoten V[MAX_KNOTEN];               // Feld aller Knoten
    int knotenzahl;                     // Anzahl, der im Graph definierten Knoten
    int** Adj = new int*[MAX_KNOTEN];    // Adjazentmatrix
    Graph();                // knotenzahl auf 0 setzen, Adjazentmatrix löschen
    ~Graph();
};

/**
 * @brief BFS - Breitensuche auf einem Graphen G gemäß Pseudocode
 * Kapitel 22.2 Breitensuche auf Seite 605
 * @param G Graph
 * @param s Index des Startknotens
 */
void BFS(Graph &G, int s);

/**
 * @brief PRINT_PATH gibt die Knoten entlang eines kürzesten Pfades von s nach v aus,
 * wobei sie voraussetzt, dass BFS bereits einen Breitensuchbaum berechnet hat
 * Pseudocode Kapitel 22.2 Seite 611
 * @param G Graph
 * @param s Index des Startknotens
 * @param v Index des Endknotens
 */
void PRINT_PATH(Graph &G, int s, int v);

void PRINT_ADJ(Graph &G);

/**
 * @brief SaveGraph Schreibt die Graphdaten in den geöffneten ostream
 * (oder abgeleitet: iostream, ofstream, ostringstream)
 * @param os geöffneter output stream
 * @param G Graph, der gespeichert wird
  */
void SaveGraph(ostream &os, Graph &G);

/**
 * @brief LoadGraph
 * @param is geöffneter input stream
 * @param G Graph, in den eingelesen wird
 * @return Error Number
 */
int LoadGraph(istream &is, Graph &G);

/**
 * @brief Insert_Edge Fügt eine ungerichtete Kante von Knoten u nach Knoten v ein
 * @param G Graph, in dem die Kante hinzugefügt wird
 * @param u Startknoten der ungerichteten Kante
 * @param v Endknoten der ungerichteten Kante
 */
void Insert_Edge(Graph &G, int u, int v);

/**
 * @brief Delete_Edge Löscht eine ungerichtete Kante von Knoten u nach Knoten v
 * @param G Graph, in dem die Kante gelöscht wird
 * @param u Startknoten der zu löschenden ungerichteten Kante
 * @param v Endknoten der zu löschenden ungerichteten Kante
 */
void Delete_Edge(Graph &G, int u, int v);

/**
 * @brief Flip_Edge Ändert die Adjazenz zwischen Knoten u und Knoten v
 * @param G Graph, in dem die Kante geändert (hinzugefügt / gelöscht) wird
 * @param u Startknoten
 * @param v Endknoten
 */
void Flip_Edge(Graph &G, int u, int v);

/**
 * @brief Graph_Debug
 * @param G Auszugebender Graph
 */
void Graph_Debug(Graph &G);

/**
 * @brief Insert_Random_Edge
 * @param G
 */
void Insert_Random_Edge(Graph &G);

/**
 * @brief Insert_Random_Edges
 * @param G
 * @param i
 */
void Insert_Random_Edges(Graph &G, int i);

#endif // GRAPH_H