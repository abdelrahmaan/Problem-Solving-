			//	Trie with unordered_map
class TrieNode {
public:
    unordered_map<char, TrieNode*> mp;
    bool isEnd;
    TrieNode *root;
    TrieNode(){
        this->isEnd = false;
    }
};

class Trie{
  private:
    TrieNode* root;
  
  public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode *cur = root;
        for(char c : word){
            if(cur->mp.find(c) == cur->mp.end())     cur->mp[c] = new TrieNode();
            cur = cur->mp[c];
        }
        cur->isEnd = true;
    }
    
    bool search(string word){
        TrieNode* cur = root;
        for(char c : word){
            if(cur->mp.find(c) == cur->mp.end())  return false;
            cur = cur->mp[c];
        }
        return cur->isEnd == true;
    }
    
    bool startsWith(string prefix){
        TrieNode* cur = root;
        for(char c : prefix){
            if(cur->mp.find(c) == cur->mp.end())  return false;
            cur = cur->mp[c];
        }
        return true;
    }
              
};