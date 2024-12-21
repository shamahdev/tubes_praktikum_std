#ifndef SLL_RELATION_H_INCLUDED
#define SLL_RELATION_H_INCLUDED

#include <string>
#include "parent.h"
#include "child.h"

#define First(L) ((L).first)
#define Next(P) ((P)->Next)
#define Info(P) ((P)->info)

using namespace std;

struct relation {
    string flightID;
    string aircraftID;
    string flightStatus;
};

typedef relation infotypeRelation;
typedef struct elmListRelation *addressRelation;

struct elmListRelation {
    infotypeRelation info;
    addressRelation Next;
};

struct ListRelation {
    addressRelation first;
};

void createListRelation(ListRelation &L);
addressRelation firstRelation(ListRelation L);
addressRelation createElementRelation(infotypeRelation dataBaru);
void insertRelation(ListRelation &L, addressRelation P);
void deleteRelation(ListRelation &L, addressRelation &P);
addressRelation findRelation(ListRelation L, string flightID, string aircraftID);
void showAllRelations(ListRelation L);
void showChildrenOfParent(ListRelation L, ListChild LC, string flightID);
void showParentsOfChild(ListRelation L, ListParent LP, string aircraftID);
void showAllParentsWithChildren(ListRelation L, ListParent LP, ListChild LC);
void showAllChildrenWithParents(ListRelation L, ListParent LP, ListChild LC);
int countChildrenOfParent(ListRelation L, string flightID);
int countParentsOfChild(ListRelation L, string aircraftID);
int countChildrenWihoutParent(ListRelation L, ListChild LC);
int countParentsWithoutChild(ListRelation L, ListParent LP);
bool hasRelation(ListRelation L, string flightID, string aircraftID);
void editRelation(ListRelation &L, string oldFlightID, string oldAircraftID,
                  string newFlightID, string newAircraftID);
void deleteElementRelation(ListRelation &LR, string flightID, string aircraftID);
#endif // SLL_RELATION_H_INCLUDED
