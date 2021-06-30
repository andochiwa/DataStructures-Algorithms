#include<bits/stdc++.h>
using namespace std;

static constexpr int MAX_LEVEL = 16; // 设置最大层
class SkipNode {
public:
    int val;
    vector<SkipNode*> next; // 下一层
    SkipNode(int val = -1, int level = MAX_LEVEL): val(val), next(level, nullptr) {}
};

class SkipList {
private:
    static constexpr int P = RAND_MAX / 2; // 设置概率层P
    SkipNode* head; // 头结点
    int level = 0; // 当前层数
    // 获得插入概率的函数，用投硬币的方式
    int randomLevel() {
        int level = 1; // 第一层必须插入
        while (rand() % RAND_MAX < P && level < MAX_LEVEL) { // 投硬币
            level++;
        }
        return level;
    }
public:
    SkipList() {
        head = new SkipNode();
        srand(time(nullptr)); // 设置随机数种子
    }

    void add(int num) {
        auto node = head;
        int newLevel = randomLevel();
        level = max(level, newLevel);
        auto newNode = new SkipNode(num, newLevel);
        for (int i = level - 1; i >= 0; i--) {
            while (node->next[i] && node->next[i]->val < num) {
                node = node->next[i];
            }
            if (i <= newLevel) {
                auto next = node->next[i];
                node->next[i] = newNode;
                newNode->next[i] = next;
            }
        }
    }

    bool search(int num) {
        auto node = head;
        for (int i = level - 1; i >= 0; i--) {
            while (node->next[i] && node->next[i]->val < num) {
                node = node->next[i];
            }
            if (node->next[i] && node->next[i]->val == num) {
                return true;
            }
        }
        return false;
    }



    bool remove(int num) {
        auto node = head;
        for (int i = level - 1; i >= 0; i--) {
            while (node->next[i] && node->next[i]->val < num) {
                node = node->next[i];
            }
            if (node->next[i] && node->next[i]->val == num) {
                auto del = node->next[i];
                // 删除每层的结点
                for (; i >= 0; i--) {
                    // 找出要删除的结点
                    while (node->next[i] != del) {
                        node = node->next[i];
                    }
                    // 删除
                    node->next[i] = node->next[i]->next[i];
                    // 修正层数
                    if (!head->next[i]) {
                        level = i;
                    }
                }
                delete del;
                return true;
            }
        }
        return false;
    }

    void traverse(int num) {
        auto node = head;
        if (num == -1) {
            while (node->next[0]) {
                cout << node->next[0]->val << " ";
                node = node->next[0];
            }
        } else {
            for (int i = level - 1; i >= 0; i--) {
                while (node->next[i] && node->next[i]->val < num) {
                    node = node->next[i];
                }
            }
            while (node->next[0]) {
                cout << node->next[0]->val << " ";
                node = node->next[0];
            }
        }
        cout << "\n";
    }
};

int main(void) {

    auto list = new SkipList();
    for (int i = 0; i < 1000; i++) {
        list->add(rand());
    }
    list->add(0);
    // list->add(0);
    // list->add(4);
    // list->add(3);
    // list->add(6);
    // list->add(8);
    // list->add(2);
    // list->remove(6);
    // list->traverse(-1);
    // list->traverse(1);
    return 0;
}