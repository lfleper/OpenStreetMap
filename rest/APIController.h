//
// Created by lfleper on 05.06.20.
//

#ifndef OPENSTREETMAP_APICONTROLLER_H
#define OPENSTREETMAP_APICONTROLLER_H

#include <iostream>
using namespace std;

//const string OPEN_STREET_API_LINK = "https://api.openstreetmap.org/api/0.6/map?bbox=7.6817,51.3669,7.6910,51.3723";
const string OPEN_STREET_API_LINK = "https://www.openstreetmap.org/api/0.6/map?bbox=7.68286%2C51.36787%2C7.68707%2C51.36935";

class APIController {
public:
    string getResponse();
};


#endif //OPENSTREETMAP_APICONTROLLER_H
