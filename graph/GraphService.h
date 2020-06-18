//
// Created by lfleper on 17.06.20.
//

#ifndef OPENSTREETMAP_GRAPHSERVICE_H
#define OPENSTREETMAP_GRAPHSERVICE_H


#include <vector>
#include "../xml/Way.h"
#include "../xml/Structs.h"

class GraphService {
private:

public:
    GraphService();
    void printConnectedWays(std::vector<Way> ways);
};


#endif //OPENSTREETMAP_GRAPHSERVICE_H
