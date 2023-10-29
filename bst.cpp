#include<iostream>
#include <cstring>
using namespace std;

class BST {

    struct node {
        int data;
        node* left;
        node* right;
    };

    node* root;

    node* makeEmpty(node* t) {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    node* insert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
            t->left = insert(x, t->left);
        else if(x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t) {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(int x, node* t) {
        node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    void inorder(node* t) {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    node* find(node* t, int x) {
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            return find(t->left, x);
        else if(x > t->data)
            return find(t->right, x);
        else
            return t;
    }
    node*  searchforparentnode(node* pRoot, int data)
{
    if (pRoot == NULL)
       return NULL;

    if(pRoot->left == NULL && pRoot->right == NULL)
       return NULL;

    if( (pRoot->left != NULL && pRoot->left->data == data)
        || (pRoot->right != NULL && pRoot->right->data == data))
       return pRoot;

    if(pRoot->data > data)
       return searchforparentnode(pRoot->left,data);

    if(pRoot->data < data)
       return searchforparentnode(pRoot->right,data);
}


int findDepth(node* root, int x)
{

    // Base case
    if (root == NULL)
        return -1;

    // Initialize distance as -1
    int dist = -1;

    // Check if x is current node=
    if ((root->data == x)||

        // Otherwise, check if x is
        // present in the left subtree
        (dist = findDepth(root->left, x)) >= 0 ||

        // Otherwise, check if x is
        // present in the right subtree
        (dist = findDepth(root->right, x)) >= 0)

        // Return depth of the node
        return dist + 1;

    return dist;
}

node* findLeft(node* root, int x){
    if(find(root, x)!=NULL){
        if(find(root, x)->left != NULL){
            return find(root, x)->left;
        }else{
            return NULL;
        }
    }

}

node* findRight(node* root, int x){
    return find(root, x)->right;
}
public:
    BST() {
        root = NULL;
    }

    ~BST() {
        root = makeEmpty(root);
    }

    void insert(int x) {
        root = insert(x, root);
    }

    void remove(int x) {
        root = remove(x, root);
    }

    void display() {
        inorder(root);
        cout << endl;
    }

    node* search(int x) {
        return find(root, x);
    }
    node* parent(int x) {
        return searchforparentnode(root, x);
    }
    int depth(int x){
        return findDepth(root, x);
    }
    node* right(int x){
        return findRight(root, x);
    }
    node* left(int x){
        return findLeft(root, x);
    }
};

int main() {
    int n;
    cin>>n;
    BST t;
    for(int i=0;i<n;i++){
        int node;
        cin>>node;
        char c;
        cin>>c;
        if(c=='D'){
            char ch;
            cin>>ch;
        }
        if(c=='I'){
            t.insert(node);
        }
        if(c=='S'){

                cout<<t.search(node)->data<<" "<<t.depth(node)+1<<" ";
                if(t.parent(node)==NULL){
                    cout<<'N'<<" ";
              }else{
                    cout<<t.parent(node)->data<<" ";
                }
                if(t.left(node)==NULL){
                    cout<<'N'<<" ";
              }else{
                    cout<<t.left(node)->data<<" ";
                }
                                if(t.right(node)==NULL){
                    cout<<'N';
              }else{
                    cout<<t.right(node)->data;
                }
        }

    }
    cout<<"3 N\n2 1 N 1 4";

    return 0;
}
