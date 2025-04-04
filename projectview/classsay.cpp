#include "class.h"
#include<iostream>
#include <unordered_map>
using namespace std;



// 定义一个结构体用于存储括号类型和索引
struct BracketInfo {
    char type; // 括号类型：'(', '{', '[', '<'
    int index; // 括号在表达式中的索引
};

// 修改括号匹配逻辑
void printMatchedPairs(string expr) {
    linkedStack<BracketInfo> s;
    int length = expr.size();

    unordered_map<char, char> matchingPairs = {
        {')', '('}, {'}', '{'}, {']', '['}, {'>', '<'}
    };

    cout << "Processing expression: " << expr << endl;

    for (int i = 0; i < length; i++) {
        char current = expr.at(i);

        if (current == '(' || current == '{' || current == '[' || current == '<') {
            s.push({ current, i });
            cout << "Pushed '" << current << "' at index " << i << endl;
        }
        else if (current == ')' || current == '}' || current == ']' || current == '>') {
            if (!s.empty()) {
                BracketInfo top = s.top();
                if (top.type == matchingPairs[current]) {
                    cout << "Matched '" << top.type << "' at index " << top.index << " with '" << current << "' at index " << i << endl;
                    s.pop();
                }
                else {
                    cout << "Mismatched '" << top.type << "' at index " << top.index << " and '" << current << "' at index " << i << endl;
                    s.pop();
                }
            }
            else {
                cout << "No matching left bracket for '" << current << "' at index " << i << endl;
            }
        }
    }

    while (!s.empty()) {
        BracketInfo unmatched = s.top();
        cout << "No matching right bracket for '" << unmatched.type << "' at index " << unmatched.index << endl;
        s.pop();
    }
}
