#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s)
{
    int hour = stoi(s.substr(0, 2));
    string period = s.substr(8, 2);

    if (period == "AM")
    {
        if (hour == 12)
            hour = 0;
    }
    else
    { // PM
        if (hour != 12)
            hour += 12;
    }

    stringstream ss;
    ss << setw(2) << setfill('0') << hour;

    return ss.str() + s.substr(2, 6);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
