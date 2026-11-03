class TrieNode {
public:
    TrieNode* children[26];
    int count;
    
    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        count = 0;
    }
};

class Solution {
private:
    TrieNode* root;

    void insert(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
            curr->count++; // Increment count for this prefix
        }
    }

    int getScore(const string& word) {
        TrieNode* curr = root;
        int totalScore = 0;
        for (char c : word) {
            int idx = c - 'a';
            curr = curr->children[idx];
            totalScore += curr->count; // Add the score of the prefix
        }
        return totalScore;
    }

public:
    vector<int> sumPrefixScores(vector<string>& words) {
        root = new TrieNode();
        
        // Step 1: Build the Trie
        for (const string& word : words) {
            insert(word);
        }
        
        // Step 2: Compute prefix scores for each word
        vector<int> ans;
        ans.reserve(words.size());
        for (const string& word : words) {
            ans.push_back(getScore(word));
        }
        
        return ans;
    }
};