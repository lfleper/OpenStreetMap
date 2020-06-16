//
// Created by lfleper on 16.06.20.
//

#ifndef OPENSTREETMAP_OSM_H
#define OPENSTREETMAP_OSM_H

#include <iostream>
#include "Structs.h"
#include "Way.h"
#include "Node.h"
#include "Relation.h"

class Osm {
private:
    bounds_t bounds;
    vector<Node> nodes;
    vector<Way> ways;
    vector<Relation> relations;
public:
    const vector<Relation> &getRelations() const;

    void setRelations(const vector<Relation> &relations);

    const bounds_t &getBounds() const;

    void setBounds(const bounds_t &bounds);

    const vector<Node> &getNodes() const;

    void setNodes(const vector<Node> &nodes);

    const vector<Way> &getWays() const;

    void setWays(const vector<Way> &ways);
};


#endif //OPENSTREETMAP_OSM_H
