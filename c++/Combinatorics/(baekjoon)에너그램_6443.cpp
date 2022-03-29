#include <iostream>
#include<string>
using namespace std;
 
int N, len, alphabet[26];
string str;
string output;
 
void DFS(int depth) {
    if (depth == len) {
        cout << output << '\n';
        return;
    }
 
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] > 0) {
            alphabet[i]--;
            output += ('a' + i);
            DFS(depth + 1);
            output.erase(output.end() - 1);
            alphabet[i]++;
        }
    }
}
 
int main() {
    cin >> N;
    while(N--){
        output = "";
        for (int i = 0; i < 26; i++)
            alphabet[i] = 0;
        
        cin >> str;
        len = str.length();
        for (int i = 0; i < len; i++) {
            alphabet[str[i] - 'a']++;
        }
 
        DFS(0);
    }
}