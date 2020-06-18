#ifndef KNOTEN_H
#define KNOTEN_H
#include <climits>
#include <string>

using namespace std;

enum KnotenFarbe {WEISS,GRAU,SCHWARZ};
#define NIL -1
#define UNENDLICH INT_MAX

/**
 * @brief Klasse Knoten
 */
class Knoten
{
public:
    KnotenFarbe farbe;  // Farbmarkierung für Breitensuche
    int d;              // Distanz zum Startknoten bei der Breitensuche
    int vorgaenger;     // Pi
    string name;        // Name des Knotens (Erweiterung OD)
    Knoten(){d=UNENDLICH; vorgaenger=NIL; farbe=WEISS; name=""; }
};

#endif // KNOTEN_H