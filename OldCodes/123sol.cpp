#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <list>
#include <map>
#include <set>

using namespace std;

int main() {
    map<string, list<pair<string, int>>> index_map;
    set<string> ignore_words;
    string input;
    string word;
    while (getline(cin, input) && input != "::") {
        word = "";
        for (int i = 0; i < input.size(); i++)
            word += toupper(input.at(i));
        ignore_words.insert(word);
    }

    string lower_title;
    while (getline(cin, input)) {
        word = "";
        lower_title = "";
        for (char c : input)
            lower_title += tolower(c);
        for (int i = 0; i < lower_title.size(); i++) {
            char c = lower_title.at(i);
            if (c == ' ') {
                if (ignore_words.count(word) == 0)
                    index_map[word].push_back(make_pair(lower_title, i-word.size()));
                word = "";
            } else {
                word += toupper(c);
            }
        }
        if (ignore_words.count(word) == 0)
            index_map[word].push_back(
                    make_pair(lower_title, lower_title.size() - word.size())
            );
    }
    string title, key;
    int index;
    for (map<string, list<pair<string, int>>>::iterator i = index_map.begin(); i != index_map.end(); i++) {
        for (list<pair<string, int>>::iterator j = i->second.begin(); j != i->second.end(); j++) {
            //cout << "====================================================" << endl;
            key = i->first;
            title = (*j).first;
            title.replace((*j).second, key.size(), key);
            cout << title << endl;
        }
    }

    return 0;
}
