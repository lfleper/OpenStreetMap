//
// Created by lfleper on 05.06.20.
//

#ifndef OPENSTREETMAP_XMLCONTROLLER_H
#define OPENSTREETMAP_XMLCONTROLLER_H

#include <string>
#include <iostream>
#include "Osm.h"
#include "../pugixml-1.10/src/pugixml.hpp"
using namespace std;

class XMLController {
private:
    string file;
    pugi::xml_document doc;
    pugi::xml_parse_result result;
public:
    XMLController(const string &file);
    Osm parse();
};


#endif //OPENSTREETMAP_XMLCONTROLLER_H
