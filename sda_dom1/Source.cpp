#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

bool isSmallLetter(char ch)
{
    return ch >= 'a' && ch <= 'z';
}
bool isNum(char ch)
{
    return ch >= '0' && ch <= '9';
}
bool isCapitalLetter(char ch)
{
    return ch >= 'A' && ch <= 'Z';
}

int main() {
    int n;
    cin >> n;
    string arr;
    cin >> arr;
    int temp[62]{ 0 };

    for (int i = 0; i < n; i++)
    {
        if (isNum(arr[i]))
        {
            temp[arr[i] - '0']++;
        }
        else if (isSmallLetter(arr[i]))
        {
            int j = arr[i];
            temp[j - 87]++;
        }
        else if (isCapitalLetter(arr[i]))
        {
            int j = arr[i];
            temp[j - 29]++;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < temp[i]; j++)
        {
            cout << i;
        }
    }

    for (int i = 10; i < 36; i++)
    {
        
        for (int j = 0; j < temp[i]; j++)
        {char asciiChar = static_cast<char>(i + 86+1);
            cout << asciiChar;
        }
    }

    for (int i = 36; i < 62; i++)
    {
        
        for (int j = 0; j < temp[i]; j++)
        {
            char asciiChar = static_cast<char>(i + 28+1);
            cout << asciiChar;
        }
    }

}