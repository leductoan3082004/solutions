#include <bits/stdc++.h>
using namespace std;
stack<int> stk;
struct Node {
    int data;
    Node *next;
};
Node *ptr;
Node *head1 = NULL;
Node *head2 = NULL;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        Node *tmp = new Node;
        tmp->data = x;
        tmp->next = NULL;
        if(head1 == NULL) {
            head1 = tmp;
            ptr = tmp;
        } else {
            ptr->next = tmp;
            ptr = ptr->next;
        }
    }
    while(head1 != NULL) {
        if(head1->data % 2 == 0) {
            stk.push(head1->data);
        } else {
            bool flag = 1;
            while(!stk.empty() || flag) {
                if(stk.empty())
                    flag = 0;
                Node *tmp = new Node;
                tmp->data = flag ? stk.top() : head1->data;
                tmp->next = NULL;
                if(head2 == NULL) {
                    head2 = tmp;
                    ptr = tmp;
                } else {
                    ptr->next = tmp;
                    ptr = ptr->next;
                }
                if(!stk.empty())
                    stk.pop();
            }
        }
        head1 = head1->next;
    }
    while(!stk.empty()) {
        Node *tmp = new Node;
        tmp->data = stk.top();
        tmp->next = NULL;
        if(head2 == NULL) {
            head2 = tmp;
            ptr = tmp;
        } else {
            ptr->next = tmp;
            ptr = ptr->next;
        }
        stk.pop();
    }
    while(head2 != NULL) {
        cout << head2->data << ' ';
        head2 = head2->next;
    }
    cout << '\n';
    return 0;
}
