#include <iostream>
#include "relation.h"

using namespace std;

void menu() {
    cout << "========== Flight Management System ==========" << endl;
    cout << "1.  Add Flight" << endl;
    cout << "2.  Add Aircraft" << endl;
    cout << "3.  Create Flight-Aircraft Relation" << endl;
    cout << "4.  Show All Flights" << endl;
    cout << "5.  Show All Aircraft" << endl;
    cout << "6.  Show All Relations" << endl;
    cout << "7.  Show Aircraft of a Flight" << endl;
    cout << "8.  Show Flights of an Aircraft" << endl;
    cout << "9.  Show All Flights with Their Aircraft" << endl;
    cout << "10. Show All Aircraft with Their Flights" << endl;
    cout << "11. Count Aircraft of a Flight" << endl;
    cout << "12. Count Flights of an Aircraft" << endl;
    cout << "13. Count Aircraft without Flights" << endl;
    cout << "14. Count Flights without Aircraft" << endl;
    cout << "15. Edit Flight-Aircraft Relation" << endl;
    cout << "0.  Exit" << endl;
    cout << "Choice: ";
}

int main() {
    ListParent LP;
    ListChild LC;
    ListRelation LR;
    
    createListParent(LP);
    createListChild(LC);
    createListRelation(LR);
    
    int choice = -1;
    while (choice != 0) {
        menu();
        cin >> choice;
        cout << endl;
        
        switch(choice) {
            case 1: {
                infotypeParent flight;
                cout << "Enter Flight ID: ";
                cin >> flight.flightID;
                cout << "Enter Flight Route: ";
                cin.ignore();
                getline(cin, flight.flightRoute);
                cout << "Enter Flight Time: ";
                getline(cin, flight.flightTime);
                cout << "Enter Available Seats: ";
                cin >> flight.availableSeats;
                
                addressParent P = createElementParent(flight);
                insertFirstParent(LP, P);
                cout << "Flight added successfully!" << endl;
                break;
            }
            case 2: {
                infotypeChild aircraft;
                cout << "Enter Aircraft ID: ";
                cin >> aircraft.aircraftID;
                cout << "Enter Aircraft Model: ";
                cin.ignore();
                getline(cin, aircraft.aircraftModel);
                cout << "Enter Total Seats: ";
                cin >> aircraft.totalSeats;
                cout << "Enter Max Weight: ";
                cin >> aircraft.maxWeight;
                
                addressChild C = createElementChild(aircraft);
                insertFirstChild(LC, C);
                cout << "Aircraft added successfully!" << endl;
                break;
            }
            case 3: {
                infotypeRelation rel;
                cout << "Enter Flight ID: ";
                cin >> rel.flightID;
                cout << "Enter Aircraft ID: ";
                cin >> rel.aircraftID;
                cout << "Enter Flight Status: ";
                cin.ignore();
                getline(cin, rel.flightStatus);
                
                addressRelation R = createElementRelation(rel);
                insertRelation(LR, R);
                cout << "Relation created successfully!" << endl;
                break;
            }
            case 4:
                showAllParents(LP);
                break;
            case 5:
                showAllChildren(LC);
                break;
            case 6:
                showAllRelations(LR);
                break;
            case 7: {
                string flightID;
                cout << "Enter Flight ID: ";
                cin >> flightID;
                showChildrenOfParent(LR, LC, flightID);
                break;
            }
            case 8: {
                string aircraftID;
                cout << "Enter Aircraft ID: ";
                cin >> aircraftID;
                showParentsOfChild(LR, LP, aircraftID);
                break;
            }
            case 9:
                showAllParentsWithChildren(LR, LP, LC);
                break;
            case 10:
                showAllChildrenWithParents(LR, LP, LC);
                break;
            case 11: {
                string flightID;
                cout << "Enter Flight ID: ";
                cin >> flightID;
                cout << "Number of Aircraft: " << countChildrenOfParent(LR, flightID) << endl;
                break;
            }
            case 12: {
                string aircraftID;
                cout << "Enter Aircraft ID: ";
                cin >> aircraftID;
                cout << "Number of Flights: " << countParentsOfChild(LR, aircraftID) << endl;
                break;
            }
            case 13:
                cout << "Aircraft without Flights: " << countChildrenWihoutParent(LR, LC) << endl;
                break;
            case 14:
                cout << "Flights without Aircraft: " << countParentsWithoutChild(LR, LP) << endl;
                break;
            case 15: {
                string oldFlightID, oldAircraftID, newFlightID, newAircraftID;
                cout << "Enter Current Flight ID: ";
                cin >> oldFlightID;
                cout << "Enter Current Aircraft ID: ";
                cin >> oldAircraftID;
                cout << "Enter New Flight ID: ";
                cin >> newFlightID;
                cout << "Enter New Aircraft ID: ";
                cin >> newAircraftID;
                
                editRelation(LR, oldFlightID, oldAircraftID, newFlightID, newAircraftID);
                cout << "Relation updated successfully!" << endl;
                break;
            }
            case 0:
                cout << "Thank you for using Telkom Air Flight Management System!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
        cout << endl;
    }
    
    return 0;
}
