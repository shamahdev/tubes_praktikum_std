#ifndef SLL_CHILD_H_INCLUDED
#define SLL_CHILD_H_INCLUDED

#include <string>

#define First(L) ((L).first)
#define Next(P) ((P)->Next)
#define Info(P) ((P)->info)

using namespace std;

struct aircraft {
    string aircraftID;
    string aircraftModel;
    int totalSeats;
    float maxWeight;
};

typedef aircraft infotypeChild;
typedef struct elmListChild *addressChild;

struct elmListChild {
    infotypeChild info;
    addressChild Next;
};

struct ListChild {
    addressChild first;
};

void createListChild(ListChild &L);
addressChild createElementChild(infotypeChild dataBaru);
void insertFirstChild(ListChild &L, addressChild P);
void insertLastChild(ListChild &L, addressChild P);
void insertAfterChild(ListChild &L, addressChild Prec, addressChild P);
void deleteFirstChild(ListChild &L, addressChild &P);
void deleteLastChild(ListChild &L, addressChild &P);
void deleteAfterChild(ListChild &L, addressChild Prec, addressChild &P);
void showAllChildren(ListChild L);
addressChild findChild(ListChild L, string flightID);
int countChildren(ListChild L);
void deleteElementChild(ListChild &LC, string aircraftID);
#endif // SLL_CHILD_H_INCLUDED
