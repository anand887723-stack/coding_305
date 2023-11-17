#include <iostream>
using namespace std;

int main()
{
    // Initialize total to 0
    int total = 0;

    // Read a positive integer greater than 5
    int n;
    cout << "Enter a positive number greater than 5: ";
    cin >> n;

    // Validate the input
    while (n <= 5)
    {
        cout << "Your number must be greater than 5." << endl;
        cout << "Enter a positive number greater than 5: ";
        cin >> n;
    }

    // Calculate the sum using a while loop
    int i = 1;
    while (i <= n)
    {
        total += i;
        i++;
    }

    // Display the result
    cout << "1+";
    for (int j = 2; j < n; j++)
    {
        cout << j << "+";
    }
    cout << n << " = " << total << endl;

    return 0;
}
