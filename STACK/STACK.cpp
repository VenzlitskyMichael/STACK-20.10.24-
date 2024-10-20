#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

string chBrack(const string& str) {
    stack<char> brack;
    unordered_map<char, char> mBrack = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };
    for (size_t i = 0; i < str.length(); ++i) {
        char curr = str[i];
        if (curr == ';') break;
        if (curr == '(' || curr == '{' || curr == '[') {
            brack.push(curr);
        }
        else if (curr == ')' || curr == '}' || curr == ']') {
            if (!brack.empty() && brack.top() == mBrack[curr]) {
                brack.pop();  
            }
            else {
                return "Eror pos " + to_string(i) + ": " + str.substr(0, i + 1);
            }
        }
    }
    if (!brack.empty()) {
        return "EROR DONT CLOSE ) '" + string(1, brack.top()) + "'";
    }
    return "NICEEEE";
}

int main() {
    string str1 = "({x-y-z} * [x + 2y] - (z + 4x));";
    string str2 = "([x-y-z} * [x + 2y) - {z + 4x)];";
    cout << chBrack(str1) << endl; 
    cout << chBrack(str2) << endl; 

    return 0;
}
