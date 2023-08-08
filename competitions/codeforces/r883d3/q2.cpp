#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char getGameResult(const vector<string> &field)
{
    for (int i = 0; i < 3; i++)
    {
        if (field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] != '.')
            return field[i][0];
    }

    for (int i = 0; i < 3; i++)
    {
        if (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] != '.')
            return field[0][i];
    }

    if (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] != '.')
        return field[0][0];

    if (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] != '.')
        return field[0][2];

    return 'D';
}

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        vector<string> field(3);
        for (int i = 0; i < 3; i++)
        {
            cin >> field[i];
        }
        char result = getGameResult(field);
        string resultString = "";
        if (result == 'D')
            resultString = "DRAW";
        else
            resultString += result;
        cout << resultString << endl;
    }
}