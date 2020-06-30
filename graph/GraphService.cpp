//
// Created by lfleper on 17.06.20.
//

#include <map>
#include "GraphService.h"
#include <math.h>

GraphService::GraphService(Osm osm) {
    this->osm = osm;
}
double GraphService::getDistance(Node a, Node b){
    //lat -> phi -> breitengrad
    //long -> alpha -> längengrad
    double first = sin(toRadians(a.getLat())) * sin(toRadians(b.getLat())) + cos(toRadians(a.getLat())) * cos(toRadians(b.getLat())) * cos(toRadians(a.getLon() - b.getLon()));
    return 6366000.00 * acos(first);
}
double GraphService::toRadians(double a){
    return (M_PI / 180.00) * a;
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
                            double distance = getDistance(osm.getNodes().at(i), osm.getNodes().at(u));
                            Insert_Edge(graph, i, u, distance);
                        }
                    }

                    for (int u = 0; u < osm.getNodes().size(); ++u) {
                        if (j != w.getNd().size() - 1 && w.getNd().at(j+1).ref == osm.getNodes().at(u).getId()) {
                            double distance = getDistance(osm.getNodes().at(i), osm.getNodes().at(u));
                            Insert_Edge(graph, i, u, distance);
                        }
                    }
                }
           }
        }
    }

    return graph;
}



