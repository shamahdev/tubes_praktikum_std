#include "child.h"
#include <iostream>

void createListChild(ListChild &L) {
    First(L) = NULL;
}

addressChild createElementChild(infotypeChild dataBaru) {
    addressChild P = new elmListChild;
    Info(P) = dataBaru;
    Next(P) = NULL;
    return P;
}

void insertFirstChild(ListChild &L, addressChild P) {
    if (First(L) == NULL) {
        First(L) = P;
    } else {
        Next(P) = First(L);
        First(L) = P;
    }
}

void insertLastChild(ListChild &L, addressChild P) {
    if (First(L) == NULL) {
        First(L) = P;
    } else {
        addressChild Q = First(L);
        while (Next(Q) != NULL) {
            Q = Next(Q);
        }
        Next(Q) = P;
    }
}

void deleteFirstChild(ListChild &L, addressChild &P) {
    if (First(L) != NULL) {
        P = First(L);
        if (Next(First(L)) == NULL) {
            First(L) = NULL;
        } else {
            First(L) = Next(P);
            Next(P) = NULL;
        }
    }
}

void deleteLastChild(ListChild &L, addressChild &P) {
    if (First(L) != NULL) {
        if (Next(First(L)) == NULL) {
            P = First(L);
            First(L) = NULL;
        } else {
            addressChild Q = First(L);
            while (Next(Next(Q)) != NULL) {
                Q = Next(Q);
            }
            P = Next(Q);
            Next(Q) = NULL;
        }
    }
}

void showAllChildren(ListChild L) {
    addressChild P = First(L);
    while (P != NULL) {
        cout << "Aircraft ID: " << Info(P).aircraftID << endl;
        cout << "Model: " << Info(P).aircraftModel << endl;
        cout << "Total Seats: " << Info(P).totalSeats << endl;
        cout << "Max Weight: " << Info(P).maxWeight << endl;
        cout << "------------------------" << endl;
        P = Next(P);
    }
}

addressChild findChild(ListChild L, string aircraftID) {
    addressChild P = First(L);
    while (P != NULL) {
        if (Info(P).aircraftID == aircraftID) {
            return P;
        }
        P = Next(P);
    }
    return NULL;
}
