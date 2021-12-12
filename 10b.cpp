#include <iostream>
#include <stack>
#include <map>
#include <vector>

using namespace std;

map<char,int> table = {
  { '(', 1 },
  { '[', 2 },
  { '{', 3 },
  { '<', 4 }
};

long long calc(stack<char>& st) {
  long long tmp = 0;
  while (st.size()) {
    char c = st.top(); st.pop();
    tmp = (tmp * 5) + table[c];
  }
  return tmp;
}

int main() {
  string s;
  vector<long long> v;
  while (cin >> s) {
    stack<char> st;
    bool valid = 1;
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
      valid = 0;
      break;
    }
    if (valid) {
      v.push_back(calc(st));
    }
  }
  sort(v.begin(), v.end());
  cout << v[v.size() / 2] << "\n";
}

