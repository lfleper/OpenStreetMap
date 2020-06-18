#include <iostream>
#include "rest/APIController.h"
#include "xml/XMLController.h"
#include "xml/Osm.h"
#include <fstream>

using namespace std;

int main() {
    APIController controller = APIController();

    XMLController xmlController = XMLController(controller.getResponse());
    Osm osm = xmlController.parse();



    return 0;
}
