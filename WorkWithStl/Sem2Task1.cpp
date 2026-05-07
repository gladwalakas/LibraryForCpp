#include <iostream>
#include <set>
#include <map>
#include <string>
#include <cstdlib>

using namespace std;

set<int> getDigits(int n) 
{
    set<int> digits;
    n = abs(n);

    if (n == 0) 
        digits.insert(0);

    else while (n) 
        digits.insert(n % 10); 
    n /= 10; 

    return digits;
}

int main() 
{
    map<int, pair<bool, bool>> info;
    int num;
    while (cin >> num) 
    {
        int len = to_string(abs(num)).length();
        if (len == 2 || len == 3) 
        {
            set<int> digits = getDigits(num);
            for (int d : digits)
            {
                if (len == 2) 
                    info[d].first = true;

                else
                    info[d].second = true;
            }
        }
    }
    bool found = false;
    for (auto& p : info) 
    {
        if (p.second.first && !p.second.second) 
        {
            cout << p.first << " ";
            found = true;
        }
    }
    if (!found) 
        cout << "Таких цифр нет";

    cout << endl;
    return 0;
}