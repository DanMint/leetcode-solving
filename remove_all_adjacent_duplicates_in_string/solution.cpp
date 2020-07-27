class Solution {
public:
    string removeDuplicates(const string& S) {
        stack<char> main;
        stack<char> reprintOne;

        for (const char &el : S) {
            if (main.empty()) {
                main.push(el);
            }
            else if (main.top() == el) {
                main.pop();
            }
            else {
                main.push(el);
            }
        }

        string s;

        while (!main.empty()) {
            reprintOne.push(main.top());
            main.pop();
        }

        while (!reprintOne.empty()) {
            s.append(1,reprintOne.top());
            reprintOne.pop();
        }

        return s;
     }
};

