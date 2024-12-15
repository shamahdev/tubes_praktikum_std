#include "parent.h"
#include <iostream>

void createListParent(ListParent &L) {
    First(L) = NULL;
    Last(L) = NULL;
}

addressParent createElementParent(infotypeParent dataBaru) {
    addressParent P = new elmListParent;
    Info(P) = dataBaru;
    Next(P) = NULL;
    Prev(P) = NULL;
    return P;
}

void insertFirstParent(ListParent &L, addressParent P) {
    if (First(L) == NULL) {
        First(L) = P;
        Last(L) = P;
    } else {
        Next(P) = First(L);
        Prev(First(L)) = P;
        First(L) = P;
    }
}

void insertLastParent(ListParent &L, addressParent P) {
    if (First(L) == NULL) {
        First(L) = P;
        Last(L) = P;
    } else {
        Prev(P) = Last(L);
        Next(Last(L)) = P;
        Last(L) = P;
    }
}

void deleteFirstParent(ListParent &L, addressParent &P) {
    if (First(L) != NULL) {
        P = First(L);
        if (First(L) == Last(L)) {
            First(L) = NULL;
            Last(L) = NULL;
        } else {
            First(L) = Next(P);
            Prev(First(L)) = NULL;
            Next(P) = NULL;
        }
    }
}

void deleteLastParent(ListParent &L, addressParent &P) {
    if (First(L) != NULL) {
        P = Last(L);
        if (First(L) == Last(L)) {
            First(L) = NULL;
            Last(L) = NULL;
        } else {
            Last(L) = Prev(P);
            Next(Last(L)) = NULL;
            Prev(P) = NULL;
        }
    }
}

void showAllParents(ListParent L) {
    addressParent P = First(L);
    while (P != NULL) {
        cout << "Flight ID: " << Info(P).flightID << endl;
        cout << "Route: " << Info(P).flightRoute << endl;
        cout << "Time: " << Info(P).flightTime << endl;
        cout << "Available Seats: " << Info(P).availableSeats << endl;
        cout << "------------------------" << endl;
        P = Next(P);
    }
}

addressParent findParent(ListParent L, string flightID) {
    addressParent P = First(L);
    while (P != NULL) {
        if (Info(P).flightID == flightID) {
            return P;
        }
        P = Next(P);
    }
    return NULL;
}
