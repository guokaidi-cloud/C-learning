#include <iostream>
#include<queue>
#include<memory>
#include<ctime>
using namespace std;

class Object {
public:
    Object() = delete;
    Object(int x, int y) :x_(x), y_(y) {}

public:
    int x_;
    int y_;
};

using SpObj = shared_ptr<Object>;

int main()
{ 
    auto cmd = [](SpObj sp1, SpObj sp2) {
        return (sp1->x_ * sp1->x_ + sp1->y_ * sp1->y_) < (sp2->x_ * sp2->x_ + sp2->y_ * sp2->y_);
    };
    priority_queue<SpObj, vector<SpObj >, decltype(cmd)> que(cmd);
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        int m = rand() % 100;
        int n = rand() % 100;
        cout << "m : " << m ;
        cout << " n : " << n <<endl;
        SpObj sp_i(new Object(m, n));
        que.push(sp_i);
    }
    while (!que.empty()) {
        cout << " top of queue : " <<
            (que.top()->x_* que.top()->x_)+(que.top()->y_*que.top()->y_) << endl;
        que.pop();
    }
    return 0;

}