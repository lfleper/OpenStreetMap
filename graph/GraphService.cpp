//
// Created by lfleper on 17.06.20.
//

#include <map>
#include "GraphService.h"

GraphService::GraphService(Osm osm) {
    this->osm = osm;
}

Graph GraphService::getGraph() {
    Graph graph = Graph();
    graph.knotenzahl = osm.getNodes().size();

    // name
    int knoten = 0;
    for (Node n : osm.getNodes()) {
        graph.V[knoten].name = std::to_string(n.getId());
        ++knoten;
    }

    // create adj
    for (int i = 0; i < osm.getNodes().size(); i++) {
        for (Way w : osm.getWays()) {
            for (int j = 0; j < w.getNd().size(); j++) {
                if (osm.getNodes().at(i).getId() == w.getNd().at(j).ref) {
                    for (int u = 0; u < osm.getNodes().size(); u++) {
                        if (j != 0 && w.getNd().at(j-1).ref == osm.getNodes().at(u).getId()) {
                            Insert_Edge(graph, i, u);
                        }
                    }

                    for (int u = 0; u < osm.getNodes().size(); ++u) {
                        if (j != w.getNd().size() - 1 && w.getNd().at(j+1).ref == osm.getNodes().at(u).getId()) {
                            Insert_Edge(graph, i, u);
                        }
                    }
                }
           }
        }
    }

    return graph;
}


