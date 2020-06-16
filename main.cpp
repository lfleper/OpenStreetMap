#include <iostream>
#include "rest/APIController.h"
#include "xml/XMLController.h"
#include "xml/Osm.h"

int main() {
    APIController controller = APIController();

    XMLController xmlController = XMLController(controller.getResponse());
    Osm osm = xmlController.parse();

    for (Way w : osm.getWays()) {
        cout << w.getId() << endl;
    }

    return 0;
}
