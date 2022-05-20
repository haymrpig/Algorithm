class Solution {
public:
    struct Trie{
        int word_index;
        vector<Trie*> children;
        Trie(): word_index(-1), children(26, nullptr){}
    };
    
    void insert(Trie* root, string& word, int word_index){
        for(int i=0;i<word.size();i++){
            if(root->children[word[i]-'a'] == nullptr){
                root->children[word[i]-'a'] = new Trie();
            }
            root = root->children[word[i]-'a'];
        }
        root->word_index = word_index;
    }
    
    bool isPelindrome(string& word){
        for(int i=0;i<int(word.size()/2);i++){
            if(word[i] != word[word.size()-1-i]) return false;
        }
        return true;
    }
    
    void DFS(Trie* root, string word_temp, int word_index, vector<vector<int>>& answer){
        if(root==nullptr) return;
        if(word_temp != "" && root->word_index != -1){
            if(isPelindrome(word_temp)){
                answer.push_back({word_index, root->word_index});
            }
        }
        for(int i=0;i<26;i++){
            if(root->children[i] !=nullptr){
                DFS(root->children[i], word_temp+char(i+'a'), word_index, answer);
            }
        }
    }
    
    void findPelindrome(Trie* root, string& word, int word_index, vector<vector<int>>& answer){
        int index = 0;
        while(index < word.size() && root != nullptr){
            root = root->children[word[index++]-'a'];
            if(root!=nullptr && root->word_index != -1){
                string word_temp = word.substr(index);
                if(root->word_index != word_index && isPelindrome(word_temp)){
                    answer.push_back({word_index, root->word_index});
                }
            }
        }
        
        if(index == word.size()){
            DFS(root, "", word_index, answer);
        }
        
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        vector<vector<int>> answer;
        
        Trie* root = new Trie();
        
        // struct trie node
        for(int i=0;i<words.size();i++){
            string reversed_word = words[i];
            reverse(reversed_word.begin(), reversed_word.end());
            insert(root, reversed_word, i);
        }
        
        for(int i=0;i<words.size();i++){
            // if there is blank word in words and words[i] is pelidrum
            if(root->word_index != -1 && root->word_index != i && isPelindrome(words[i])){
                answer.push_back({i, root->word_index});
            }
            
            findPelindrome(root, words[i], i, answer);
        }
        return answer;
    }
};