//
// Created by lfleper on 05.06.20.
//

#ifndef OPENSTREETMAP_STRUCTS_H
#define OPENSTREETMAP_STRUCTS_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct {
    double minlat;
    double minlon;
    double maxlat;
    double maxlon;
} bounds_t;

typedef struct {
    string k;
    string v;
} tag_t;

typedef struct {
    long ref;
} nd_t;

typedef struct {
    string type;
    long ref;
    string role;
} member_t;

#endif //OPENSTREETMAP_STRUCTS_H
