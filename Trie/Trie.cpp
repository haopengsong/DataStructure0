class TrieNode {
public:
    TrieNode* next[26];
    bool isEnd;
    TrieNode() {
        memset(next, 0, sizeof(next));
        isEnd = false;
    }
};
class Trie {
private:
    TrieNode* root;
    TrieNode* find(string word) {
        TrieNode* p = root;
        for (int i = 0; i < word.size() && p != nullptr; i++) {
            p = p -> next[word[i] - 'a'];
        }
        return p;
    }
    void clear(TrieNode* root) {
        for (int i = 0; i < 26; i++) {
            if (root -> next[i] != nullptr) {
                clear(root -> next[i]);
            }
        }
        delete root;
    }
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        clear(root);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for (int i = 0; i < word.size(); i++) {
            if (p -> next[word[i] - 'a'] == nullptr) {
                p -> next[word[i] - 'a'] = new TrieNode(); 
            }
            p = p -> next[word[i] - 'a'];
        }
        p -> isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = find(word);
        return p != nullptr && p -> isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }
};

/**
 * Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
