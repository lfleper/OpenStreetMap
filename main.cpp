#include <iostream>
#include "rest/APIController.h"
#include "xml/XMLController.h"
#include "graph/GraphService.h"
#include "xml/Osm.h"
#include <fstream>
#include "graph/graph.h"

using namespace std;

const char* filename = "star12-9.gdi";

int main() {
    APIController controller = APIController();

    XMLController xmlController = XMLController(controller.getResponse());
    Osm osm = xmlController.parse();

    GraphService graphService = GraphService(osm);
    Graph g = graphService.getGraph();

    filebuf fb;
    if (fb.open("osm_iserlohn.gdi", ios::out)) {
        ostream os(&fb);

        SaveGraph(os, g);

        fb.close();
    } else {
        cout << "datei konnte nicht geöffnet werden" << endl;
    }

    cout << "Anzahl Knoten: " << osm.getNodes().size() << endl;
    cout << "Anzahl Wege: " << osm.getWays().size() << endl;


    return 0;
}
