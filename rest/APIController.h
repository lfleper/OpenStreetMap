//
// Created by lfleper on 05.06.20.
//

#ifndef OPENSTREETMAP_APICONTROLLER_H
#define OPENSTREETMAP_APICONTROLLER_H

#include <iostream>
using namespace std;

const string OPEN_STREET_API_LINK = "https://api.openstreetmap.org/api/0.6/map?bbox=7.6817,51.3669,7.6910,51.3723";

class APIController {
public:
    string getResponse();
    string getResponse(string url);
};


#endif //OPENSTREETMAP_APICONTROLLER_H
