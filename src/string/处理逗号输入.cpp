#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include<vector>

using namespace std;

// 字符串处理逗号输入的一个例子

void Myprint(vector<vector<int>>& vec) {
    int m = vec.size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < vec.at(i).size(); j++) {
            cout << vec.at(i).at(j)<<" ";
        }
        cout << endl;
    }
}

using namespace std;
int main() {
    int num;
    cin >> num;
    string str;
    str = "\n";
    getline(cin, str);
    vector<vector<int>> vec;
    for (int i = 0; i < num; i++) {
        string str;
        getline(cin, str);
        stringstream ss(str);

        vector<int> nums;
        string tmp;
        while (getline(ss, tmp, ',')) {
            nums.push_back(stoi(tmp));
        }
        vec.emplace_back(move(nums));
    }
    Myprint(vec);
    return 0;
}
