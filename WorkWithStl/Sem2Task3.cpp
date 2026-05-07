#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    string line;
    getline(cin, line);  // читаем всю строку

    map<string, int> wordTypes;
    string currentWord;
    set<string> sentenceWords;

    for (char ch : line)  // перебираем символы строки
    {
        if (isalpha(ch))
            currentWord += tolower(ch);
        else
        {
            if (!currentWord.empty())
            {
                sentenceWords.insert(currentWord);
                currentWord.clear();
            }

            if (ch == '.' || ch == '?' || ch == '!')
            {
                int mask = 0;
                if (ch == '.') mask = 1;
                else if (ch == '!') mask = 2;
                else if (ch == '?') mask = 4;

                for (const string& word : sentenceWords)
                    wordTypes[word] |= mask;

                sentenceWords.clear();
            }
        }
    }

    // Если после цикла осталось слово или предложение
    if (!currentWord.empty())
        sentenceWords.insert(currentWord);

    if (!sentenceWords.empty())
        for (const string& word : sentenceWords)
            wordTypes[word] |= 1;

    // Вывод результата
    bool first = true;
    for (const auto& p : wordTypes)
    {
        int mask = p.second;
        if ((mask & (1 | 2)) && !(mask & 4))
        {
            if (!first) cout << " ";
            cout << p.first;
            first = false;
        }
    }
    cout << endl;

    return 0;
}