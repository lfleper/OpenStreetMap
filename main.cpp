#include <iostream>
#include "rest/APIController.h"
#include "xml/XMLController.h"
#include "graph/GraphService.h"
#include "xml/Osm.h"
#include <fstream>
#include "graph/graph.h"

using namespace std;

void menu();
int printMenu();
void example();
void url();

/**
 * starten des menus.
 *
 * @return -
 */
int main() {
    menu();

    return 0;
}

/**
 * auswahl des menu punkts.
 */
void menu() {
    int in = 0;

    while (in != 9) {
        in = printMenu();
        switch (in) {
            case 1:
                example();
                break;
            case 2:
                url();
                break;
        }
    }
    cout << endl << "Beendet .." << endl;
}

/**
 * laden der beispiel osm datei (ALEXANDERHOEHE).
 */
void example() {
    APIController controller = APIController();

    XMLController xmlController = XMLController(controller.getResponse());
    Osm osm = xmlController.parse();

    GraphService graphService = GraphService(osm);
    Graph g = graphService.getGraph();

    filebuf fb;
    string filename;
    cout << "Geben Sie einen Dateinamen ein (*.gdi): " << endl;
    cin >> filename;
    if (fb.open(filename, ios::out)) {
        ostream os(&fb);
        SaveGraph(os, g);
        fb.close();

        cout << "Knotenzahl: " << g.knotenzahl << endl;
    } else {
        cout << "Datei konnte nicht geöffnet werden" << endl;
    }
}

/**
 * laden einer osm datei mittels api link.
 */
void url() {
    APIController controller = APIController();

    string url;
    cout << "Geben Sie eine OpenStreetMap URL ein: " << endl;
    cout << "Achtung! Zu grosse Bereiche werden von OpenStreetMap nicht als *.osm Datei ausgegeben." << endl;
    cout << "Beispiel: [https://api.openstreetmap.org/api/0.6/map?bbox=7.6817,51.3669,7.6910,51.3723]" << endl;
    cin >> url;

    XMLController xmlController = XMLController(controller.getResponse(url));
    Osm osm = xmlController.parse();

    GraphService graphService = GraphService(osm);
    Graph g = graphService.getGraph();

    filebuf fb;
    string filename;
    cout << "Geben Sie einen Dateinamen ein (*.gdi);" << endl;
    cin >> filename;
    if (fb.open(filename, ios::out)) {
        ostream os(&fb);
        SaveGraph(os, g);
        fb.close();

        cout << "Knotenzahl: " << g.knotenzahl << endl;
    } else {
        cout << "Datei konnte nicht geöffnet werden" << endl;
    }
}

/**
 * ausgeben des menus.
 *
 * @return Menu Nummer.
 */
int printMenu() {
    int in = 0;
    cout << "[1] Iserlohn Alexanderhöhe (Beispiel)" << endl;
    cout << "[2] OpenStreetMap URL (API)" << endl;
    cout << "[9] Beenden" << endl;
    cin >> in;
    return in;
}