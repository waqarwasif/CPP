#include <iostream>
#include <string>
using namespace std;

int main()
{
    try
    {
        // OUTER TRY (The Big Boss)
        cout << "Outer try starts" << endl;

        try
        {
            // INNER TRY (The Worker)
            cout << "Inner try starts" << endl;

            throw 100; // Disaster! We throw an INT
        }
        catch (const string &e)
        {
            // INNER CATCH: The supervisor only knows how to handle STRINGS.
            // Because 100 is not a string, this block is SKIPPED.
            cout << "Inner catch grabbed a string." << endl;
        }

        cout << "After inner try (Skipped)" << endl;
    }
    catch (int e)
    {
        // OUTER CATCH: catches the INT
        cout << "Outer catch grabbed the error: " << e << endl;
    }

    cout << "Program ends normally." << endl;
    return 0;
}