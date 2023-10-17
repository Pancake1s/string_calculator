#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() {
    string str, str1, str2, score;
    auto t = 0, t1 = 0;
    cout << "Enter a expression" << endl;
    cin >> str;
    str = ' ' + str + ' ';
    for (size_t i = 0; i < str.length(); i++) {
        t = i;
        t1 = i;
        if (str[i] == '^') {
            while (str[t - 1] != '-' && str[t - 1] != '+' && str[t - 1] != '/' && str[t - 1] != '^' && str[t - 1] != '*' && str[t - 1] != ' ') {
                str1 += str[t - 1];
                t--;
            }
            std::reverse(str1.begin(), str1.end());
            while (str[t1 + 1] != '-' && str[t1 + 1] != '+' && str[t1 + 1] != '/' &&
                str[t1 + 1] != '^' && str[t1 + 1] != '*' && str[t1 + 1] != ' ') {
                str2 += str[t1 + 1];
                t1++;
            }
            double num1 = stod(str1);
            double num2 = stod(str2);
            num1 = pow(num1, num2);
            score = std::to_string(num1);
            str = ' ' + str.substr(0, t) + score + str.substr(t1 + 1, str.length()) + ' ';
            cout << str << endl;
            str1.clear();
            str2.clear();
            i = 0;
        }
    }
    for (int i = 0; i < str.length(); i++) {
        t = i;
        t1 = i;
        if (str[i] == '*' || str[i] == '/') {
            while (str[t - 1] != '-' && str[t - 1] != '+' && str[t - 1] != '/' && str[t1] != '^' && str[t - 1] != '*' && str[t - 1] != ' ') {
                str1 += str[t - 1];
                t--;
            }
            std::reverse(str1.begin(), str1.end());
            while (str[t1 + 1] != '-' && str[t1 + 1] != '+' && str[t1 + 1] != '/' &&
                str[t1 + 1] != '^' && str[t1 + 1] != '*' && str[t1 + 1] != ' ') {
                str2 += str[t1 + 1];
                t1++;
            }
            double num1 = stod(str1);
            double num2 = stod(str2);
            if (str[i] == '*')
                num1 = num1 * num2;
            if (str[i] == '/')
                num1 = num1 / num2;
            score = std::to_string(num1);
            str = ' ' + str.substr(0, t) + score + str.substr(t1 + 1, str.length()) + ' ';
            cout << str << endl;
            str1.clear();
            str2.clear();
            i = 0;
        }
    }
    for (int i = 0; i < str.length(); i++) {
        t = i;
        t1 = i;
        if (str[i] == '+' || str[i] == '-') {
            while (str[t - 1] != '-' && str[t - 1] != '+' && str[t - 1] != '/' && str[t1] != '^' && str[t - 1] != '*' && str[t - 1] != ' ') {
                str1 += str[t - 1];
                t--;
            }
            std::reverse(str1.begin(), str1.end());
            while (str[t1 + 1] != '-' && str[t1 + 1] != '+' && str[t1 + 1] != '/' && str[t1 + 1] != '^' && str[t1 + 1] != '*' && str[t1 + 1] != ' ') {
                str2 += str[t1 + 1];
                t1++;
            }
            double num1 = stod(str1);
            double num2 = stod(str2);
            if (str[i] == '+')
                num1 += num2;
            if (str[i] == '-')
                num1 -= num2;
            score = std::to_string(num1);
            str = ' ' + str.substr(0, t) + score + str.substr(t1 + 1, str.length()) + ' ';
            cout << str << endl;
            str1.clear();
            str2.clear();
            i = 0;
        }
    }
    return 0;
}