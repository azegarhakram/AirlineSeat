/*

This program will simulate seat reservation.
--------------------------------------------

For that the proram will :

1. Print a diagram of the seat
2. Determine the number of availeble seats
3. Allow the user to pick a seat then mark it a s sold
4. Mark the seat as available if the ticket is returned

*/


#include <iostream>
#include <iomanip>
#include <string>


// We have one plane for this program and the number of ROXS ans SEATS are
// CONST so we will fixe them before the compilation of the code

#define ROWS  25
#define SEATS  6

void InitialiseSeats(char array[][SEATS],int elements);
void ShowSeatMap(char seats[ROWS][SEATS]);

int main()
{
    
    // Initalisation of seats in a plane
    char PlaneSeats[ROWS][SEATS] = {0};

    std::string answer;

    // Initialisation of the seats
    InitialiseSeats(PlaneSeats, ROWS);



    std::cout << "\n__________________________________________________________________"<< std::endl;

    std::cout << "------ START OF THE RESERVATION! WELCOME :)"<< std::endl;
    //std::cin.get();

    ShowSeatMap(PlaneSeats);

    std::cout << "\n__________________________________________________________________"<< std::endl;

    std::cout << "------ END OF THE RESERVATION! HAVE A NICE DAY :)"<< std::endl;
    //std::cin.get();
    return 0;
}

/*
************************************************************************
*   Function initialize array
*   
*   This function initialize an char array with rundomly disributed X and O  
* 
*   Input:
*       1. array[] - Type char - Represent seating chart for aircraft
*                    X means seat not availble, O means seat vacant
*       2. elemnts - Number of rows on the aircraft 
*
*   Required global value: SEATS
*
*************************************************************************
*/

void InitialiseSeats(char array[][SEATS],int elements)
{
    for (int i = 0; i < elements; ++i)
    {
        for (int j = 0; j < SEATS; ++j)
        {
            if (rand() % 2 == 0)
                array[i][j] = 'O'; // Vacant seat
            else
                array[i][j] = 'X'; // Seat is not availeable

        }
    }

    return;
}

/*
************************************************************************
*   Function seat map
*   
*   Input:
*       1. array[] - Type char - Represent seating chart for aircraft
*                    X means seat not availble, O means seat vacant
*
*   Required global value: ROWS and SEATS
*
*************************************************************************
*/


void ShowSeatMap(char seats[ROWS][SEATS])
{
    std::cout << "\n\n--------" << std::endl;
    std::cout << "SEAT MAP|" << std::endl;
    std::cout << "--------\n\n" << std::endl;

    std::cout << "Seat ";
    std::cout << std::setw(2)<< " " << " |";

    for (int j = 0; j < SEATS; ++j)
    {
        if (j == SEATS/2)
            std::cout << " ";
        std::cout << std::setw(2) << j+1 ;
    }

    std::cout << std::endl << std::endl;
    for (int i = 0; i < ROWS; ++i)
    {
        std::cout << "Row  ";
        std::cout << std::setw(2) << i+1 << " | ";

        for (int j = 0; j < SEATS; ++j)
        {
            if (j == SEATS/2)
                std::cout << " ";
            std::cout << std::setw(2) << ((seats[i][j]=='X')?"\033[1;31mX\033[0m ":"\033[1;32mO\033[0m ");
        }

        std::cout << std::endl;
    }
}