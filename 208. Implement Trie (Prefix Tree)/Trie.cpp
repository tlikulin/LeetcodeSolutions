class Trie {
private:
    struct TrieNode {
        array<TrieNode*, 26> next{};
        bool endOfWord = false;
    };

    TrieNode* root = new TrieNode();
public:
    Trie() = default;

    void insert(string word) {
        TrieNode* ptr = root;

        for (char c : word) {
            if (!ptr->next[c - 'a']) {
                ptr->next[c - 'a'] = new TrieNode();
            }

            ptr = ptr->next[c - 'a'];
        }

        ptr->endOfWord = true;
    }

    bool search(string word) {
        TrieNode* ptr = root;

        for (char c : word) {
            if (!ptr->next[c - 'a']) return false;
            ptr = ptr->next[c - 'a'];
        }

        return ptr->endOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* ptr = root;

        for (char c : prefix) {
            if (!ptr->next[c - 'a']) return false;
            ptr = ptr->next[c - 'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */