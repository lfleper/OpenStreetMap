//
// Created by lfleper on 16.06.20.
//

#include "Osm.h"

const bounds_t &Osm::getBounds() const {
    return bounds;
}

void Osm::setBounds(const bounds_t &bounds) {
    Osm::bounds = bounds;
}

const vector<Node> &Osm::getNodes() const {
    return nodes;
}

void Osm::setNodes(const vector<Node> &nodes) {
    Osm::nodes = nodes;
}

const vector<Way> &Osm::getWays() const {
    return ways;
}

void Osm::setWays(const vector<Way> &ways) {
    Osm::ways = ways;
}

const vector<Relation> &Osm::getRelations() const {
    return relations;
}

void Osm::setRelations(const vector<Relation> &relations) {
    Osm::relations = relations;
}
