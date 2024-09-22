#include <iostream>
#include "aeroflot.h"

using namespace std;

void inputFlights(AEROFLOT flights[], int);
void sortFlightsByNumber(AEROFLOT flights[], int);
void swap(AEROFLOT &first, AEROFLOT &second);
void printFlightsToDestination(AEROFLOT flights[], int, char*);

int main()
{
    setlocale(LC_ALL, "ru");

	const int SIZE = 7;
	AEROFLOT flights[SIZE];

    inputFlights(flights, SIZE);

    sortFlightsByNumber(flights, SIZE);

    char destination[100];
    cout << "Enter your search destination:";
    cin.getline(destination, 100);

    printFlightsToDestination(flights, SIZE, destination);
}

void inputFlights(AEROFLOT flights[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << "Enter flight details" << i + 1 << ":\n";
        cout << "Destination: ";
        cin >> flights[i].destination;
        cout << "Flight number:";
        cin >> flights[i].flightNumber;
        cout << "Aircraft type:";
        cin >> flights[i].planeType;
        cout << endl;
    }
}

void sortFlightsByNumber(AEROFLOT flights[], int size)
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size - i; j++) 
        {
            if (flights[j].flightNumber > flights[j + 1].flightNumber) swap(flights[j], flights[j + 1]);
        }
    }
}

void swap(AEROFLOT& first, AEROFLOT& second) 
{
    AEROFLOT temp = first;
    first = second;
    second = temp;
}

void printFlightsToDestination(AEROFLOT flights[], int size, char* destination)
{
    bool is_destination = false;

    for (int i = 0; i < size; i++)
    {
        if (flights[i].destination == destination)
        {
            cout << "Destination: ";
            cout << flights[i].destination;
            cout << "Flight number: ";
            cout << flights[i].flightNumber;
            cout << "Aircraft type: ";
            cout <<flights[i].planeType;
            cout << endl;
            
            is_destination = true;
        }
    }
    if (!is_destination) cout << "There is no flight to this destination.";
    
}