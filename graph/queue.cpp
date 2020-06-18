//
// Created by lufle002 on 25.05.20.
//

#include "queue.h"
#include <iostream>

using namespace std;

void ENQUEUE(Queue &Q, int x) {
    Q.Q[Q.ende] = x;
    if (Q.ende == Q.laenge) {
        Q.ende = 1;
    }  else {
        Q.ende = Q.ende + 1;
    }
}

int DEQUEUE(Queue &Q) {
    int x = Q.Q[Q.kopf];
    if (Q.kopf == Q.laenge) {
        Q.kopf = 1;
    } else {
        Q.kopf = Q.kopf + 1;
    }

    return x;
}

bool Queue_Empty(Queue &Q) {
    return Q.ende == Q.kopf;
}

bool Queue_NotEmpty(Queue &Q) {
    return !Queue_Empty(Q);
}

void Queue_Debug(Queue &Q) {
    int length = 6;
    for (int i = 1; i <= length-1; i++) {
        ENQUEUE(Q, i);
    }

    for (int i = 1; i <= length / 2; i++) {
        if (Queue_NotEmpty(Q)) {
            cout << "Q is not empty" << endl;
        } else {
            cout << "err: Q is empty" << endl;
        }

        if (Queue_Empty(Q)) {
            cout << "err: Q is empty" << endl;
        } else {
            cout << "Q is not empty" << endl;
        }

        int element = DEQUEUE(Q);
        if (element == i) {
            cout << "dequeue is i" << endl;
        } else {
            cout << "err: dequeue is not i" << endl;
        }

        cout << endl;
    }

    for (int i = length; i <= length+2; i++) {
        ENQUEUE(Q, i);
    }

    for (int i = (length/2)+1; i <= length+2; i++) {
        if (Queue_NotEmpty(Q)) {
            cout << "Q not empty" << endl;
        } else {
            cout << "err: Q is empty" << endl;
        }

        if (Queue_Empty(Q)) {
            cout << "err: Q is empty" << endl;
        } else {
            cout << "Q is not empty" << endl;
        }

        int element = DEQUEUE(Q);
        cout << "el: " << element << endl;
        if (element == i) {
            cout << "element is i" << endl;
        } else {
            cout << "err: element is not i" << endl;
        }

        cout << endl;
    }

    cout << endl;

    if (Queue_NotEmpty(Q)) {
        cout << "err: Q is not empty" << endl;
    } else {
        cout << "Q is empty" << endl;
    }

    if (Queue_Empty(Q)) {
        cout << "Q is empty" << endl;
    } else {
        cout << "err: Q is not empty"  << endl;
    }
}
