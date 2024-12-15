#ifndef DLL_PARENT_H_INCLUDED
#define DLL_PARENT_H_INCLUDED

#include <string>

#define First(L) ((L).first)
#define Last(L) ((L).last)
#define Info(P) ((P)->info)
#define Next(P) ((P)->next)
#define Prev(P) ((P)->prev)

using namespace std;

struct flight {
    string flightID;
    string flightRoute;
    string flightTime;
    int availableSeats;
};

typedef flight infotypeParent;
typedef struct elmListParent *addressParent;

struct elmListParent {
    infotypeParent info;
    addressParent next;
    addressParent prev;
};

struct ListParent {
    addressParent first;
    addressParent last;
};

void createListParent(ListParent &L);
addressParent createElementParent(infotypeParent dataBaru);
void insertFirstParent(ListParent &L, addressParent P);
void insertLastParent(ListParent &L, addressParent P);
void insertAfterParent(ListParent &L, addressParent Prec, addressParent P);
void deleteFirstParent(ListParent &L, addressParent &P);
void deleteLastParent(ListParent &L, addressParent &P);
void deleteAfterParent(ListParent &L, addressParent Prec, addressParent &P);
void showAllParents(ListParent L);
addressParent findParent(ListParent L, string flightID);
int countParents(ListParent L);

#endif // DLL_PARENT_H_INCLUDED
