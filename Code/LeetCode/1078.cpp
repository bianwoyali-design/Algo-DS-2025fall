#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    string text = "alice is a good girl she is a good student", first = "a", second = "good";

    vector<string> words;
    int it1 = 0, it2 = 0;
    while (true)
    {
        while (it1 < text.length() && text[it1] == ' ')
            it1++;
        if (it1 >= text.length())
            break;
        it2 = it1 + 1;
        while (it2 < text.length() && text[it2] != ' ')
            it2++;
        words.push_back(text.substr(it1, it2 - it1));
        it1 = it2 + 1;
    }
    vector<string> ans;
    for (int i = 2; i < words.size(); i++)
        if (words[i - 2] == first && words[i - 1] == second)
            ans.push_back(words[i]);
    for (auto i : ans)
        cout << i << ' ';
    return 0;
}