#ifndef QUEUE_H
#define QUEUE_H

/*
Definition einer Klasse Queue und deren Hilfsfunktionen.
Algorithmen – Eine Einführung; Cormen, Leiserson, Rivest, Stein

10.1 Stapel und Warteschlangen
Seite 236

Zitat aus dem Vorwort:
Zudem benutzen wir Punktnotation für die Angabe von Objektattributen.
Unser Pseudocode bleibt prozedural. Anders formuliert, anstatt Methoden auf
Objekten laufen zu lassen, rufen wir einfach Prozeduren auf, denen wir Objekte
als Parameter mitgeben.
  */

const int MAX_QUEUE=1000;

/**
 * @brief The Queue class
 */
class Queue
{
public:
    int Q[MAX_QUEUE+1]; // Genutzt werden die Elemente 1 .. MAX_QUEUE
    int laenge;         // maximale Anzahl der Elemente
    int ende;
    int kopf;
    int anzahl;         // aktuelle Anzahl der Elemente in der Warteschlange (optionale Erweiterung)
    Queue() { laenge=MAX_QUEUE; kopf=0; ende=0; anzahl=0; }
};

/**
 * @brief ENQUEUE - INSERT Operation einer Warteschlange
 * @param Q  Warteschlange
 * @param x  Wert, der in die Warteschlange eingefügt werden soll
 */
void ENQUEUE(Queue &Q, int x);

/**
 * @brief DEQEUE - DELETE Operation einer Warteschlange
 * @param Q
 * @return Wert, der aus der Warteschlange herausgenommen wurde
 */
int DEQUEUE(Queue &Q);

/**
 * @brief Queue_Empty Gibt zurück, ob die Queue leer ist
 * @param Q
 * @return TRUE / FALSE
 */
bool Queue_Empty(Queue &Q);

/**
 * @brief Queue_NotEmpty Gibt zurück, ob die Queue nicht leer ist
 * @param Q
 * @return TRUE / FALSE
 */
bool Queue_NotEmpty(Queue &Q);

/**
 * @brief Queue_Debug Debug Ausgabe der Queue
 * @param Q
 */
void Queue_Debug(Queue &Q);


#endif // QUEUE_H