//
// Created by lfleper on 17.06.20.
//

#ifndef OPENSTREETMAP_GRAPHSERVICE_H
#define OPENSTREETMAP_GRAPHSERVICE_H


#include <vector>
#include "../xml/Way.h"
#include "../xml/Structs.h"
#include "../xml/Osm.h"
#include "graph.h"

class GraphService {
private:
    Osm osm;
public:
    GraphService(Osm osm);
    Graph getGraph();
};


#endif //OPENSTREETMAP_GRAPHSERVICE_H
