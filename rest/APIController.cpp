//
// Created by lfleper on 05.06.20.
//

#include "APIController.h"
#include <iostream>
#include "CURLplusplus.h"

using namespace std;

string APIController::getResponse() {
    CURLplusplus client;
    string text = client.Get(OPEN_STREET_API_LINK);

    return text;
}
