#include <iostream>
#include <iomanip>

using namespace std;

// Global variables to track available seats
int firstClassSeats = 15;
int businessClassSeats = 25;
int economyClassSeats = 50;

// Constants for ticket prices and tax rate
const double FIRST_CLASS_PRICE = 750.0;
const double BUSINESS_CLASS_PRICE = 225.0;
const double ECONOMY_CLASS_PRICE = 150.0;
const double TAX_RATE = 0.085;

// Function to take user input for ticket type
void takeTypeInput(char &ticketType)
{
    // Step 2: Prompt the user for a ticket type.
    cout << "Enter the ticket type ('F' for First Class, 'B' for Business Class, 'E' for Economy Class): ";
    cin >> ticketType;

    // Convert the ticketType to uppercase (case insensitive).
    ticketType = toupper(ticketType);

    // Step 3: Check if the input is valid and if there are available tickets of that type left.
    while (ticketType != 'F' && ticketType != 'B' && ticketType != 'E')
    {
        cout << "Invalid ticket type. Please enter a valid ticket type: ";
        cin >> ticketType;
        ticketType = toupper(ticketType);
    }
}

// Function to check if tickets of the selected type are available
void checkTypeAvailable(char &ticketType)
{
    // Check if there are available tickets of the selected type.
    while ((ticketType == 'F' && firstClassSeats == 0) ||
           (ticketType == 'B' && businessClassSeats == 0) ||
           (ticketType == 'E' && economyClassSeats == 0))
    {
        cout << "Sorry, there are no available tickets of that type." << endl;
        takeTypeInput(ticketType);
    }
}

// Function to take user input for the number of tickets
void takeAmountInput(int &ticketAmount, char &ticketType)
{
    // Display the available number of tickets for the selected class
    if (ticketType == 'B')
        cout << "Available number of tickets for Business Class: " << businessClassSeats << endl;
    else if (ticketType == 'F')
        cout << "Available number of tickets for First Class: " << firstClassSeats << endl;
    else
        cout << "Available number of tickets for Economy Class: " << economyClassSeats << endl;

    cout << "-----------------------------------------------------------------" << endl;

    // Step 4: Prompt the user for a ticket amount.
    cout << "Enter the number of tickets you want to purchase: ";
    cin >> ticketAmount;

    // Step 5: Validate the ticket amount.
    while (ticketAmount < 0 || (ticketType == 'F' && ticketAmount > firstClassSeats) ||
           (ticketType == 'B' && ticketAmount > businessClassSeats) ||
           (ticketType == 'E' && ticketAmount > economyClassSeats))
    {
        cout << "Invalid ticket amount. Please enter a valid number of tickets: ";
        cin >> ticketAmount;
    }
}

// Function to calculate and display the total cost of the transaction
void calculateAmount(double &totalCost, int &ticketAmount, char &ticketType)
{
    if (ticketType == 'F')
    {
        totalCost = ticketAmount * FIRST_CLASS_PRICE * (1 + TAX_RATE);
        firstClassSeats -= ticketAmount;
    }
    else if (ticketType == 'B')
    {
        totalCost = ticketAmount * BUSINESS_CLASS_PRICE * (1 + TAX_RATE);
        businessClassSeats -= ticketAmount;
    }
    else if (ticketType == 'E')
    {
        totalCost = ticketAmount * ECONOMY_CLASS_PRICE * (1 + TAX_RATE);
        economyClassSeats -= ticketAmount;
    }

    cout << "Total cost of the transaction (including 8.5% tax): $" << fixed << setprecision(2) << totalCost << endl;
}

// Main booking process helper function
void bookingProcess()
{
    char ticketType;
    int ticketAmount;

    takeTypeInput(ticketType);

    checkTypeAvailable(ticketType);

    takeAmountInput(ticketAmount, ticketType);

    // Step 6: Calculate the cost of the transaction and display it.
    double totalCost = 0.0;
    calculateAmount(totalCost, ticketAmount, ticketType);

    char shutdown;
    cout << "Shut down? (Y/N): ";
    cin >> shutdown;

    // Convert the shutdown input to uppercase (case insensitive).
    shutdown = toupper(shutdown);

    // Step 8: Check if the input for shutdown is valid.
    while (shutdown != 'Y' && shutdown != 'N')
    {
        cout << "Invalid input. Please enter 'Y' or 'N': ";
        cin >> shutdown;
        shutdown = toupper(shutdown);
    }

    if (shutdown == 'N')
        bookingProcess();
    else
        return;
}

int main()
{
    // Step 1: Declare variables to hold the amount of available seats.

    // Start the booking process
    bookingProcess();

    return 0;
}
