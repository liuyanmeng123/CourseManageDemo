//
// Created by 86189 on 2021/8/22.
//
#include <iostream>
#include <limits>

using namespace std;

void showInfo(const string& info) {
    cout << info << endl;
}

int getIntInput() {
        int in;
        while (true)
        {
            cin >> in;
            if (!cin)
            {
                cerr << "错误的类型，请重新输入" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            else break;
        }
        return in;
}