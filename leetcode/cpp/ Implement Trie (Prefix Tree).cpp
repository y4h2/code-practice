//60ms
// Initialize your data structure here.
struct TrieNode{
  char content;
  bool flag = false;
  TrieNode* child[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) 
    {
        TrieNode* index = root;
        TrieNode* temp;
        
        for (int i = 0; i < word.length(); ++i)
        {
            temp = index->child[word[i] - 'a'];
            if (temp == NULL)
            {
                index->child[word[i] - 'a'] = new TrieNode();
                //使用temp = createNode(word[i])会导致runtime error
            }
            index = index->child[word[i] - 'a'];
        }
        index->flag = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) 
    {
        TrieNode* index = root;
        TrieNode* temp;
        int i;
        for (i = 0; i < word.length(); ++i)
        {
            temp = index->child[word[i] - 'a'];
            if (temp == NULL) 
                break;
            index = index->child[word[i] - 'a'];
        }
        
        //匹配失败两种情况，没有走完就break了，走完了自然退出但是字符串没有匹配完
        if(i == word.length() && index->flag)
            return true;
        else
            return false;
    }
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) 
    {
        TrieNode* index = root;
        TrieNode* temp;
        
        for (int i = 0; i < prefix.length(); ++i)
        {
            temp = index->child[prefix[i] - 'a'];
            if (temp == NULL)
            {
                return false;
            }
            index = index->child[prefix[i] - 'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");



//另一种createNode方式
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode()
    {
        for (int i = 0; i < 26; ++i)
        {
            child[i] = NULL;
        }
    }
    ~TrieNode(){}
   
public:
    char content = NULL;
    bool flag = false;
    TrieNode* child[26];
};

TrieNode* createNode(char ch)
{
    TrieNode* node = new TrieNode();
    node->content = ch;
    node->flag = false;
    for (int i = 0; i < 26; ++i)
    {
        node->child[i] = NULL;
    }
    return node;
}

class Trie {
public:
    Trie() {
        root = createNode(' ');
    }

    // Inserts a word into the trie.
    void insert(string word) 
    {
        TrieNode* index = root;
        TrieNode* temp;
        
        for (int i = 0; i < word.length(); ++i)
        {
            temp = index->child[word[i] - 'a'];
            if (temp == NULL)
            {
                index->child[word[i] - 'a'] = createNode(word[i]);
                //使用temp = createNode(word[i])会导致runtime error
            }
            index = index->child[word[i] - 'a'];
        }
        index->flag = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) 
    {
        TrieNode* index = root;
        TrieNode* temp;
        int i;
        for (i = 0; i < word.length(); ++i)
        {
            temp = index->child[word[i] - 'a'];
            if (temp == NULL)
                break;
            index = index->child[word[i] - 'a'];
        }
        
        if(i == word.length() && index->flag)
            return true;
        else
            return false;
    }
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) 
    {
        TrieNode* index = root;
        TrieNode* temp;
        
        for (int i = 0; i < prefix.length(); ++i)
        {
            temp = index->child[prefix[i] - 'a'];
            if (temp == NULL)
            {
                return false;
            }
            index = index->child[prefix[i] - 'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
