#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Trie {
    struct TrieNode {
        vector<TrieNode*> children;
        bool isWord;
        int cnt;
        TrieNode() : isWord(false), children(26, nullptr) {}
    };
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        delete root;
    }
    void insert(string word) {
        TrieNode* node = root;
        for(char c : word) {
            if(node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->isWord = true;
    }
    bool search(string word) {
        TrieNode* node = root;
        for(char c : word) {
            if(node->children[c - 'a'] == nullptr) {
                return false;
            }
            node = node->children[c - 'a'];
        }
        return node->isWord;
    }
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char c : prefix) {
            if(node->children[c - 'a'] == nullptr) {
                return false;
            }
            node = node->children[c - 'a'];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl; // 1
    cout << trie.search("app") << endl; // 0
    trie.insert("app");
    cout << trie.search("app") << endl; // 1
    cout << trie.startsWith("app") << endl; // 1
    return 0;
}