#include "child.h"
#include <iostream>

void createListChild(ListChild &L) {
    First(L) = NULL;
}
void deleteAfterChild(ListChild &L, addressChild Prec, addressChild &P) {
    if (Prec != NULL && Next(Prec) != NULL) {
        P = Next(Prec);
        Next(Prec) = Next(P);
        Next(P) = NULL;
    }
}

addressChild createElementChild(infotypeChild dataBaru) {
    addressChild P = new elmListChild;
    Info(P) = dataBaru;
    Next(P) = NULL;
    return P;
}
addressChild findChild(ListChild L, string aircraftID) {
    addressChild C = First(L);
    while (C != NULL) {
        if (Info(C).aircraftID == aircraftID) {
            return C;
        }
        C = Next(C);
    }
    return NULL;
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
        cout << "Max Weight (kg): " << Info(P).maxWeight << endl;
        cout << "------------------------" << endl;
        P = Next(P);
    }
}


void deleteElementChild(ListChild &LC, string aircraftID) {
    addressChild C = First(LC), prev = nullptr;

    while (C != nullptr) {
        if (Info(C).aircraftID == aircraftID) {
            if (C == First(LC)) {
                deleteFirstChild(LC, C);
            } else if (Next(C) == nullptr) {
                deleteLastChild(LC, C);
            } else {
                deleteAfterChild(LC, prev, C);
            }
            cout << "Aircraft deleted!" << endl;
            return;
        }
        prev = C;
        C = Next(C);
    }
    cout << "Aircraft not found!" << endl;
}

