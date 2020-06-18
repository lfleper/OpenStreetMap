#include <iostream>
#include "rest/APIController.h"
#include "xml/XMLController.h"
#include "xml/Osm.h"
#include <fstream>
#include "graph/graph.h"

using namespace std;

const char* filename = "star12-9.gdi";

int main() {
    Graph g;
    filebuf ifb;
    if (ifb.open(filename, ios::in)) {
        istream is (&ifb);
        g = Graph();
        int valid = LoadGraph(is, g);
        ifb.close();
    }

    filebuf fb;
    if (fb.open("osm_iserlohn.gdi", ios::out)) {
        ostream os(&fb);

        SaveGraph(os, g);

        fb.close();
    } else {
        cout << "datei konnte nicht geöffnet werden" << endl;
    }

    /*APIController controller = APIController();

    XMLController xmlController = XMLController(controller.getResponse());
    Osm osm = xmlController.parse();*/


    return 0;
}
