#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        string s = "";
        int index = 0;
        bool insert = true;
        bool copystatus = false;
        int copyindex1 = 0;
        int copyindex2 = 0;
        string copy = "";
        string op;
        cin >> op;
        int len = op.length();
        for (int i = 0; i < len; i++) {
            // System.out.println(op[i]);
            if (op[i] >= 'a' && op[i] <= 'z') {
                copystatus = false;
                if (insert) {
                    if (s.length() + 1 > n) {
                        continue;
                    }

                    if (index < s.length() && index > 0) {
                        string tmp1 = s.substr(0, index);
                        string tmp2 = s.substr(index, s.length());
                        s = tmp1 + op[i] + tmp2;
                        index++;
                    } else if (index == 0) {
                        s = op[i] + s;
                        index++;
                    } else {
                        s = s + op[i];
                        index++;
                    }
                } else {
                    if (index < s.length()) {
                        string tmp1 = s.substr(0, index);
                        string tmp2 = s.substr(index + 1, s.length());
                        s = tmp1 + op[i] + tmp2;
                    }
                    index++;
                }
            }
            if (op[i] == 'L') {
                if (index != 0)
                    index--;
                if (copystatus) {
                    copyindex2 = index;
                }
            }
            if (op[i] == 'R') {
                if (index != s.length())
                    index++;
                if (copystatus) {
                    copyindex2 = index;
                }
            }
            if (op[i] == 'S') {
                insert = !insert;
                copystatus = false;
            }
            if (op[i] == 'B') {
                copystatus = false;
                if (index > 0) {
                    string tmp1 = s.substr(0, index - 1);
                    string tmp2 = s.substr(index, s.length());
                    s = tmp1 + tmp2;
                    index--;
                }
            }
            if (op[i] == 'C') {
                if (!copystatus) {
                    copyindex1 = index;
                } else {
                    copyindex2 = index;
                    copy = s.substr(min(copyindex1, copyindex2),
                                    max(copyindex1, copyindex2));
                    copyindex1 = 0;
                    copyindex2 = 0;
                }
                copystatus = !copystatus;
            }
            if (op[i] == 'D') {
                if (copystatus) {
                    string tmp1 = s.substr(0, min(copyindex1, copyindex2));
                    string tmp2 =
                        s.substr(max(copyindex1, copyindex2), s.length());
                    s = tmp1 + tmp2;
                    copystatus = !copystatus;
                } else {
                    if (index != s.length()) {
                        string tmp1 = s.substr(0, index);
                        string tmp2 = s.substr(index + 1, s.length());
                        s = tmp1 + tmp2;
                    }
                }
            }
            if (op[i] == 'V') {
                copystatus = false;
                if (insert) {
                    if (s.length() + copy.length() > n)
                        continue;
                    string tmp1 = s.substr(0, index);
                    string tmp2 = s.substr(index, s.length());
                    s = tmp1 + copy + tmp2;
                    index = index + copy.length();
                } else {
                    if (index + copy.length() > n) {
                        continue;
                    }
                    if (index + copy.length() >= s.length()) {
                        string tmp1 = s.substr(0, index);
                        s = tmp1 + copy;
                        index = index + copy.length();
                    } else {
                        string tmp1 = s.substr(0, index);
                        string tmp2 =
                            s.substr(index + copy.length(), s.length());
                        s = tmp1 + copy + tmp2;
                        index = index + copy.length();
                    }
                }
            }
            // System.out.println("S: " + s + " index:" + index + " insert:"
            // + insert + " copystatus:" + copystatus + " copy:"
            // + copy + " cp1:" + copyindex1 + " cp2:" + copyindex2);
        }
        if (s.length() == 0) {
            puts("NOTHING");
        } else
            cout << s << endl;
    }
}
