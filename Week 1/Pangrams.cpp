#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    // Create a set to track all unique letters in the string
    unordered_set<char> unique_letters;

    // Iterate over each character in the string
    for (char c : s) {
        // Convert the character to lowercase
        char lower_c = tolower(c);

        // If it is a letter, add it to the set
        if (lower_c >= 'a' && lower_c <= 'z') {
            unique_letters.insert(lower_c);
        }
    }

    // Check if the set contains all 26 letters of the alphabet
    if (unique_letters.size() == 26) {
        return "pangram";
    } else {
        return "not pangram";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
