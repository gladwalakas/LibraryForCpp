#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RUS");

    string line;
    getline(cin, line);  // Читаем всю строку
    istringstream iss(line);

    int k;
    iss >> k;  // Первое число — k

    map<long long, int> freq;
    string token;

    while (iss >> token) 
    {  // Читаем остальные токены из строки
        try 
        {
            size_t pos;
            long long num = stoll(token, &pos);
            if (pos == token.length()) 
                freq[num]++;
            
        }
        catch (...) 
        {
        }
    }

    set<pair<int, long long>> sorted;
    for (const auto& p : freq) 
        sorted.insert({ p.second, p.first });
    

    int printed = 0;
    for (const auto& p : sorted) 
    {
        if (printed >= k) 
            break;

        cout << p.second << " ";
        printed++;
    }
    cout << endl;   

    return 0;
}