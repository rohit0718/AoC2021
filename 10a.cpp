#include <iostream>
#include <stack>
#include <map>

using namespace std;

map<char,int> table = {
  { ')', 3 },
  { ']', 57 },
  { '}', 1197 },
  { '>', 25137 }
};

int main() {
  string s;
  long long res = 0;
  while (cin >> s) {
    stack<char> st;
    for (char& c : s) {
      if (c == '(' || c == '{' || c == '[' || c == '<') {
        st.push(c);
        continue;
      }
      if (st.size() && ((c == ')' && st.top() == '(') || (c == ']' && st.top() == '[')
            || (c == '>' && st.top() == '<') || (c == '}' && st.top() == '{'))) {
        st.pop();
        continue;
      }
      res += table[c];
      break;
    }
  }
  cout << res << "\n";
}

