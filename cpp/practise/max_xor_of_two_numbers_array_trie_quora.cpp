const static int SIZE = 2;
const static int MSB = 30;
class trie {
private:
    struct trieNode {
        trieNode* children[SIZE];
        trieNode() {
            for(int i = 0; i < SIZE; ++i) {
                children[i] = nullptr;
            }
        }
        ~trieNode() {
            for(int i = 0; i < SIZE; ++i) {
                delete children[i];
                children[i] = nullptr;
            }
        }
    };
    trieNode* root;
public:
    trie(): root(new trieNode()) {
    }
    ~trie() {
        delete root;
        root = nullptr;
    }

    void insert(int key) {
        trieNode* pCrawl = root;
        for(int i = MSB; i >= 0; --i) {
            bool bit = (bool)(key & (1 << i));
            if(!pCrawl->children[bit]) {
                pCrawl->children[bit] = new trieNode();
            }
            pCrawl = pCrawl->children[bit];
        }
    }

    int query(int key) {
        int Xor = 0;
        trieNode *pCrawl = root;
        for(int i = MSB; i >= 0; --i) {
            bool bit = (bool)(key & (1 << i));
            if(pCrawl->children[!bit]) {
                pCrawl = pCrawl->children[!bit];
                Xor |= (1 << i);
            } else {
                pCrawl = pCrawl->children[bit];
            }
        }
        return Xor;
    }
};

int findMaximumXOR(vector<int>& arr) {
    int n = arr.size();
    int result = 0;
    if(n < 2) return result;
    trie* Trie = new trie();
    Trie->insert(0);
    for(int i = 0; i < n; i++) {
        result = max(result, Trie->query(arr[i]));
        Trie->insert(arr[i]);
    }
    delete Trie;
    return result;
}
