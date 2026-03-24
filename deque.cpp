#include <bits/stdc++.h>
using namespace std;

deque<int> q;
void print() {
    for (auto i : q) {
        cout << i << " ";
    }
    cout << "\n";
}
void addElement(int new_element) {
    // per il massimo basta invertire il minore con il maggiore nella guardia
    // del while
    while (!q.empty() && q.back() > new_element) {
        q.pop_back();
    }
    q.push_back(new_element);
}

int getMin() { return q.front(); }

void rmElement(int remove_element) {
    if (!q.empty() && q.front() == remove_element) {
        q.pop_front();
    }
}

int main() {
    vector<int> v = {3, 1, 4, 2, 5};
    int M = 2;
    int N = v.size();
    vector<int> res;

    for (int i = 0; i <= N - M; i++) {
        for (int j = 0; j < M; j++) {
            addElement(v.at(i + j));
            // cout << "i: " << i << "\nj: " << j << "\ni+j: " << i + j << "\n";
        }
        res.push_back(getMin());

        rmElement(getMin());
    }
    cout << "Risultato: ";
    for (auto i : res) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
