#include <bits/stdc++.h> // Includes all standard libraries
using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    // Extract the hour, minutes, and seconds parts from the input string
    string hour = s.substr(0, 2);        // First 2 characters -> hours
    string minutes = s.substr(3, 2);    // Characters 3 and 4 -> minutes
    string seconds = s.substr(6, 2);    // Characters 6 and 7 -> seconds
    string period = s.substr(8, 2);     // Characters 8 and 9 -> AM or PM

    int hourInt = stoi(hour);           // Convert string hour to integer for calculations

    // Convert 12-hour format to 24-hour format
    if (period == "AM") {
        if (hourInt == 12) {            // 12:00 AM -> 00:00
            hour = "00";                // Replace hour with 00
        }
    } else {                            // PM case
        if (hourInt != 12) {            // Any PM hour except 12 -> add 12
            hourInt += 12;              // Example: 01:00 PM -> 13:00
            hour = to_string(hourInt);  // Convert back to string
        }
    }

    // Return the formatted 24-hour time
    return hour + ":" + minutes + ":" + seconds;
}

int main()
{
    // Take input and output the result
    ofstream fout(getenv("OUTPUT_PATH")); // Used to write the output to a file

    string s;
    getline(cin, s);                      // Read input time string

    string result = timeConversion(s);    // Call the function

    fout << result << "\n";               // Write output to file

    fout.close();                         // Close file
    return 0;
}
