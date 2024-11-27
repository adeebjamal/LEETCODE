#include<bits/stdc++.h>
using namespace std;
class MagicDictionary {
    unordered_set<string> hash;
public:
    MagicDictionary() {
        return;
    }
    
    void buildDict(vector<string> dictionary) {
        for(string& str: dictionary) {
            this->hash.insert(str);
        }
    }
    
    bool search(string searchWord) {
        for(int i = 0; i < searchWord.length(); i++) {
            for(char letter = 'a'; letter <= 'z'; letter++) {
                if(searchWord[i] == letter) {
                    continue;
                }
                string copy = searchWord;
                copy[i] = letter;
                if(this->hash.find(copy) != this->hash.end()) {
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */