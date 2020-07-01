#include <iostream>
#include <vector>

using namespace std;

int main() {

    int a;
    cin >> a;
    vector<int> s(a);

    for(int i = 0;i < s.size(); i ++) {
        cin >> s[i];
    }

    for(int i = 0; i <s.size(); i ++) {
        if(s[i] + s[i+1] == 20) {
            cout << "We made it 20!" << endl;
            break;
        }
        else {
            cout << "No success" << endl;
        }
    }
    return 0;
}
