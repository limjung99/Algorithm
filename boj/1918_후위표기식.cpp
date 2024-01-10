#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <memory.h>
using namespace std;

string Convert2postfix(string prefix) {
    string ans;
    vector<char> op;

    for(int i=0;i<prefix.size();i++) {
        char now = prefix[i];

        if(now=='+' || now=='-') {
            while (!op.empty() && op.back()!='(') {
                ans.push_back(op.back());
                op.pop_back();
            }
            op.push_back(now);
        }
        else if(now=='/' || now=='*') {
            while(!op.empty() && (op.back()=='/' || op.back()=='*')){
                ans.push_back(op.back());
                op.pop_back();
            }
            op.push_back(now);
        }
        else if(now=='(') {
            op.push_back(now);
        }
        else if(now==')') {
            while (!op.empty() && op.back()!='('){
                ans.push_back(op.back());
                op.pop_back();
            }
            op.pop_back();
        }
        else {
            ans.push_back(now);
        }
    }

    while(!op.empty()){
        ans.push_back(op.back());
        op.pop_back();
    }

    return ans;
}


int main(int argc, char **argv) {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin>>s;

    string ans = Convert2postfix(s);
    cout<<ans;
}