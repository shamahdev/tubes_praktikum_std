#include "relation.h"
#include <iostream>

void createListRelation(ListRelation &L) {
    First(L) = NULL;
}

addressRelation createElementRelation(infotypeRelation dataBaru) {
    addressRelation P = new elmListRelation;
    Info(P) = dataBaru;
    Next(P) = NULL;
    return P;
}

addressRelation firstRelation(ListRelation L) {
    return L.first;
}

void insertRelation(ListRelation &L, addressRelation P) {
    if (First(L) == NULL) {
        First(L) = P;
    } else {
        Next(P) = First(L);
        First(L) = P;
    }
}
void deleteFirstRelation(ListRelation &L, addressRelation &P) {
    if (First(L) != NULL) {
        P = First(L);
        if (Next(P) == NULL) {
            First(L) = NULL;
        } else {
            First(L) = Next(P);
            Next(P) = NULL;
        }
    }
}
void deleteLastRelation(ListRelation &L, addressRelation &P) {
    if (First(L) != NULL) {
        if (Next(First(L)) == NULL) {
            P = First(L);
            First(L) = NULL;
        } else {
            addressRelation Q = First(L);
            while (Next(Next(Q)) != NULL) {
                Q = Next(Q);
            }
            P = Next(Q);
            Next(Q) = NULL;
        }
    }
}

void deleteRelation(ListRelation &L, addressRelation &P) {
    if (First(L) != NULL) {
        if (P == First(L)) {
            First(L) = Next(P);
        } else {
            addressRelation Q = First(L);
            while (Next(Q) != P) {
                Q = Next(Q);
            }
            Next(Q) = Next(P);
        }
        Next(P) = NULL;
    }
}
void deleteAfterRelation(ListRelation &L, addressRelation Prec, addressRelation &P) {
    if (Prec != NULL && Next(Prec) != NULL) {
        P = Next(Prec);
        Next(Prec) = Next(P);
        Next(P) = NULL;
    }
}

addressRelation findRelation(ListRelation L, string flightID, string aircraftID) {
    addressRelation P = First(L);
    while (P != NULL) {
        if (Info(P).flightID == flightID && Info(P).aircraftID == aircraftID) {
            return P;
        }
        P = Next(P);
    }
    return NULL;
}

bool hasRelation(ListRelation L, string flightID, string aircraftID) {
    return findRelation(L, flightID, aircraftID) != NULL;
}

void showAllRelations(ListRelation L) {
    addressRelation P = First(L);
    while (P != NULL) {
        cout << "Flight ID: " << Info(P).flightID << endl;
        cout << "Aircraft ID: " << Info(P).aircraftID << endl;
        cout << "Status: " << Info(P).flightStatus << endl;
        cout << "------------------------" << endl;
        P = Next(P);
    }
}

void showChildrenOfParent(ListRelation L, ListChild LC, string flightID) {
    addressRelation P = First(L);
    while (P != NULL) {
        if (Info(P).flightID == flightID) {
            addressChild C = findChild(LC, Info(P).aircraftID);
            if (C != NULL) {
                cout << "Aircraft ID: " << Info(C).aircraftID << endl;
                cout << "Model: " << Info(C).aircraftModel << endl;
                cout << "Status: " << Info(P).flightStatus << endl;
                cout << "------------------------" << endl;
            }
        }
        P = Next(P);
    }
}

int countChildrenOfParent(ListRelation L, string flightID) {
    int count = 0;
    addressRelation P = First(L);
    while (P != NULL) {
        if (Info(P).flightID == flightID) {
            count++;
        }
        P = Next(P);
    }
    return count;
}

void editRelation(ListRelation &L, string oldFlightID, string oldAircraftID,
                  string newFlightID, string newAircraftID) {
    addressRelation P = findRelation(L, oldFlightID, oldAircraftID);
    if (P != NULL) {
        Info(P).flightID = newFlightID;
        Info(P).aircraftID = newAircraftID;
    }
}

void showParentsOfChild(ListRelation L, ListParent LP, string aircraftID) {
    addressRelation P = First(L);
    while (P != NULL) {
        if (Info(P).aircraftID == aircraftID) {
            addressParent parent = findParent(LP, Info(P).flightID);
            if (parent != NULL) {
                cout << "Flight ID: " << Info(parent).flightID << endl;
                cout << "Route: " << Info(parent).flightRoute << endl;
                cout << "Status: " << Info(P).flightStatus << endl;
                cout << "------------------------" << endl;
            }
        }
        P = Next(P);
    }
}

void showAllParentsWithChildren(ListRelation L, ListParent LP, ListChild LC) {
    addressParent P = First(LP);
    while (P != NULL) {
        cout << "Flight ID: " << Info(P).flightID << endl;
        cout << "Route: " << Info(P).flightRoute << endl;
        cout << "Time: " << Info(P).flightTime << endl;
        cout << "Related Aircraft:" << endl;
        showChildrenOfParent(L, LC, Info(P).flightID);
        cout << "========================" << endl;
        P = Next(P);
    }
}

void showAllChildrenWithParents(ListRelation L, ListParent LP, ListChild LC) {
    addressChild C = First(LC);
    while (C != NULL) {
        cout << "Aircraft ID: " << Info(C).aircraftID << endl;
        cout << "Model: " << Info(C).aircraftModel << endl;
        cout << "Related Flights:" << endl;
        showParentsOfChild(L, LP, Info(C).aircraftID);
        cout << "========================" << endl;
        C = Next(C);
    }
}

int countParentsOfChild(ListRelation L, string aircraftID) {
    int count = 0;
    addressRelation P = First(L);
    while (P != NULL) {
        if (Info(P).aircraftID == aircraftID) {
            count++;
        }
        P = Next(P);
    }
    return count;
}

int countChildrenWihoutParent(ListRelation L, ListChild LC) {
    int count = 0;
    addressChild C = First(LC);
    while (C != NULL) {
        if (countParentsOfChild(L, Info(C).aircraftID) == 0) {
            count++;
        }
        C = Next(C);
    }
    return count;
}

int countParentsWithoutChild(ListRelation L, ListParent LP) {
    int count = 0;
    addressParent P = First(LP);
    while (P != NULL) {
        if (countChildrenOfParent(L, Info(P).flightID) == 0) {
            count++;
        }
        P = Next(P);
    }
    return count;
}

void deleteElementRelation(ListRelation &LR, string flightID, string aircraftID) {
    addressRelation R = First(LR), prev = nullptr;

    while (R != nullptr) {
        if (Info(R).flightID == flightID && Info(R).aircraftID == aircraftID) {
            if (R == First(LR)) {
                deleteFirstRelation(LR, R);
            } else if (Next(R) == nullptr) {
                deleteLastRelation(LR, R);
            } else {
                deleteAfterRelation(LR, prev, R);
            }
            cout << "Relation deleted!" << endl;
            return;
        }
        prev = R;
        R = Next(R);
    }
    cout << "Relation not found!" << endl;
}

