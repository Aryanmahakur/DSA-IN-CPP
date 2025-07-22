#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    bool isEnd;
    unordered_map<char, TrieNode*> children;

    TrieNode() {
        isEnd = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert word into trie
    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    // Search full word
    bool search(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch))
                return false;
            node = node->children[ch];
        }
        return node->isEnd;
    }

    // Search prefix
    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (!node->children.count(ch))
                return false;
            node = node->children[ch];
        }
        return true;
    }
};

int main() {
    Trie trie;

    trie.insert("cat");
    trie.insert("cap");
    trie.insert("dog");

    cout << trie.search("cat") << endl;        // true
    cout << trie.search("can") << endl;        // false
    cout << trie.startsWith("ca") << endl;     // true
    cout << trie.startsWith("do") << endl;     // true
    cout << trie.startsWith("bat") << endl;    // false

    return 0;
}
