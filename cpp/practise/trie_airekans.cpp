sturct TrieNode
{
    TrieNode()
    {
        memset(next, 0, 26 * sizeof(TrieNode*));
        count = 0;
    }

    TrieNode* next[26]; // We assume that only alphabetical char will be present.
    int count;
};

void insert(TrieNode* root, char* s)
{
    if (*s == '\0')
    {
        return;
    }

    TrieNode* cur = root;
    char* ptr = s;
    char c;
    while ((c = *ptr) != '\0')
    {
        c = c - 'a';
        if (cur->next[c] == NULL)
        {
            cur->next[c] = new TrieNode;
        }

        cur = cur->next[c]
        ++ptr;
    }

    cur->count++;
}

int search(TrieNode* root, char* s)
{
    TrieNode* cur = root;
    char* ptr = s;
    char c;
    while ((c = *ptr) != '\0')
    {
        c = c - 'a';
        if (cur->next[c] == NULL)
        {
            return 0;
        }

        cur = cur->next[c]
        ++ptr;
    }
    return cur->count;
}

void dump(TrieNode* root)
{
    std::string& s;
    dump_impl(root, s);
}

void dump_impl(TrieNode* node, const std::string& s)
{
    if (node->count > 0)
    {
        cout << "string: " << s << " count: " << node->count << endl;
    }
    for (int i = 0; i < 26; ++i)
    {
        if (node->next[i] != NULL)
        {
            dump_impl(node->next[i], s + ('a' + i));
        }
    }
}

void delete(TrieNode* node)
{
    if (node == NULL)
    {
        return;
    }

    for (int i = 0; i < 26; ++i)
    {
        if (node->next[i] != NULL)
        {
            delete(node->next[i]);
            node->next[i] = NULL;
        }
    }
    delete node
}
