#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* newNode(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* insertBst(Node *root, int val) {

     if(root==NULL) {
        return newNode(val);
     }

     if(root->data>val) {
         root->left =  insertBst(root->left, val);
     } else if(root->data<val) {
         root->right = insertBst(root->right, val);
     }

     return root;
}

bool isPairPresent(Node *root, int sum) {
    stack<Node*> s1;
    stack<Node*> s2;
    bool done1 = false;
    bool done2 = false;
    Node* curr1 = root;
    Node* curr2 = root;
    int val1 = 0;
    int val2 = 0;

    while(1) {
        while(!done1) {
            if(curr1) {
                s1.push(curr1);
                curr1 = curr1->left;
            } else {
                if(s1.empty()) {
                    done1 = true;
                }
                val1 = s1.top()->data;
                s1.pop();
                done1 = true;
            }
        }

        while(!done2) {
            if(curr2) {
                s2.push(curr2);
                curr2 = curr2->right;
            } else {
                if(s1.empty()) {
                    done2 = true;
                }
                val2 = s2.top()->data;
                s2.pop();
                done2 = true;
            }
        }

        if(val1 + val2 == sum) {
            cout<<"Pair found: "<<val1<<"+"<<val2<<endl;
            return true;
        } else if(val1 + val2 <sum) {
            done1 = false;
        } else if(val1 + val2 > sum) {
            done2 = false;
        }

        if(val1 > val2) {
            return false;
        }
    }
}

int main()
{
    /* 
                15 
                / \ 
            10 20 
            / \ / \ 
            8 12 16 25 */
    Node* root = newNode(15);
    root->left = newNode(10);
    root->right = newNode(20);
    root->left->left = newNode(8);
    root->left->right = newNode(12);
    root->right->left = newNode(16);
    root->right->right = newNode(25);

    int target = 33;
    if (isPairPresent(root, target) == false)
        cout << "\nNo such values are found\n";
    return 0;
}

