//
// Created by lufle002 on 25.05.20.
//

#include "graph.h"
#include "queue.h"
#include <iostream>
#include <string>
#include <ctime>

Graph::Graph() {
    knotenzahl = 0;
}

int LoadGraph(istream &is, Graph &G)
{
    int error =0;
    char c;
    int intvalue,vertex,edge;
    string tempstring;

    // Erste Zeile: G (Knotenzahl)
    c=is.get();
    if (c!='G') error=10;
    if (error==0){
        is>>intvalue;
        if (is.bad()) error=21;
        else if (intvalue<1) error=22;
        else if (intvalue>MAX_KNOTEN) error=23;
        else G.knotenzahl=intvalue;
    }
    while (error==0 && c!=EOF)
    {
        c=is.get();
        switch (c){
            case 'V':
                is>>intvalue;
                if (is.bad()) error=31;
                if (error==0)
                {
                    c=is.get();
                    getline(is,tempstring);
                    if (intvalue>0 && intvalue<=MAX_KNOTEN)
                    {
                        vertex=intvalue;
                        size_t firstQuote=tempstring.find_first_of("\"",0);
                        size_t lastQuote=tempstring.find_last_of("\"",tempstring.size());
                        if ((firstQuote!=string::npos) && (lastQuote!=string::npos))
                        {
                            tempstring=tempstring.substr(firstQuote+1,lastQuote-1);
                        }
                        G.V[vertex].name=tempstring;
                    }
                }
                break;
            case 'E':
                is>>intvalue;
                if (is.bad()) error=41;
                if (error==0){
                    vertex=intvalue;
                    is>>intvalue;
                    if (is.bad()) error=42;
                }
                if (error==0){
                    edge=intvalue;
                    is>>intvalue;
                    if (is.bad()) error=43;
                }
                if (error==0){
                    G.Adj[vertex][edge]=intvalue;
                }
                break;
            case ' ': break;
            case '\n': break;
            case '\r': break;
            case '\t': break;
        }
    }
    return error;
}

void SaveGraph(ostream &os, Graph &G) {
    int error = 0;
    int intValue, vertex, edge;
    string tmpString;
    bool stop = false;

    if (error==0){
        intValue = G.knotenzahl;
        if (intValue<1) error=22;
        else if (intValue>MAX_KNOTEN) error=23;
        else {
            G.knotenzahl=intValue;
            os << "G " + std::to_string(intValue) + "\n";
        }
    }
    int count = 1;
    while (error == 0 && !stop) {
        for (int l = 0; l < G.knotenzahl; l++) {
            os << "V " + std::to_string(count) + " \"" + G.V[l+1].name + "\"\n";

            for (int i = 1; i <= G.knotenzahl; i++) {
                if (G.Adj[count][i] >= 1) {
                    os << "E " + std::to_string(count) + " " + std::to_string(i) + " " + std::to_string(G.Adj[i][count]) + "\n";
                }
            }
            ++count;
        }
        stop = true;
    }
}

void PRINT_ADJ(Graph &G) {
    for (int i = 1; i <= G.knotenzahl; i++) {
        for (int j = 1; j <= G.knotenzahl; j++) {
            cout << G.Adj[i][j];
        }
        cout << endl;
    }
}

void BFS(Graph &G, int s) {
    for (int i = 0; i < G.knotenzahl; i++) {
        G.V[i].farbe = WEISS;
        G.V[i].d = UNENDLICH;
    }

    G.V[s].farbe = GRAU;
    G.V[s].d = 0;

    Queue q = Queue();
    ENQUEUE(q, s);

    while (Queue_NotEmpty(q)) {
        int knoten = DEQUEUE(q);

        for (int i = 1; i <= G.knotenzahl; i++) {
            if (G.Adj[knoten][i] == 1) {
                if (G.V[i].farbe == WEISS) {
                    G.V[i].farbe = GRAU;
                    G.V[i].d = G.V[knoten].d + 1;
                    ENQUEUE(q, i);
                }
            }
        }
        G.V[knoten].farbe = SCHWARZ;
    }

    for (int i = 1; i <= G.knotenzahl; i++) {
        cout << "Knoten " << i << " " << G.V[i].d << endl;
    }
}

void Insert_Edge(Graph &G, int u, int v) {
    G.Adj[u][v] = 1;
    G.Adj[v][u] = 1;
}

void Delete_Edge(Graph &G, int u, int v) {
    G.Adj[u][v] = 0;
    G.Adj[v][u] = 0;
}

void Flip_Edge(Graph &G, int u, int v) {
    G.Adj[u][v] = G.Adj[v][u] = (G.Adj[u][v] == 0) ? 1 : 0;
}

void Insert_Random_Edge(Graph &G) {
    srand(time(NULL));
    int u = (rand()%G.knotenzahl - 1) + 1;
    int v = (rand()%G.knotenzahl - 1) + 1;

    G.Adj[u][v] = 1;
    G.Adj[v][u] = 1;
}

void Insert_Random_Edges(Graph &G, int i) {
    for (int l = 0; l < i; l++) {
        Insert_Random_Edge(G);
    }
}

