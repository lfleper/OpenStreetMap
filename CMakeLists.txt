cmake_minimum_required(VERSION 3.15)
project(openstreetmap)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lcurl")

add_executable(openstreetmap main.cpp rest/APIController.cpp rest/APIController.h rest/CURLplusplus.h xml/XMLController.cpp
        xml/XMLController.h xml/Structs.h pugixml-1.10/src/pugiconfig.hpp pugixml-1.10/src/pugixml.cpp pugixml-1.10/src/pugixml.hpp
        xml/Node.cpp xml/Node.h xml/Way.cpp xml/Way.h xml/Osm.cpp xml/Osm.h xml/Relation.cpp xml/Relation.h
        graph/GraphService.cpp graph/GraphService.h graph/graph.cpp graph/graph.h graph/knoten.h graph/queue.cpp graph/queue.h)
target_link_libraries(openstreetmap curl)


