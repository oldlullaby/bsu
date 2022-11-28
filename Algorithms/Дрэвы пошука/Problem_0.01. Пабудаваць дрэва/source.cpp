#include <iostream>
#include <fstream>

struct Node
{
    int ind;
    Node *left, *right;

    Node() : Node(0, nullptr, nullptr) {}
    Node(int ind, Node *left, Node *right) : ind(ind), left(left), right(right) {}
};

class bst
{
    Node *root;

    void add_node(int ind, Node *k)
    {
        if (k->ind != ind) {
            
            if (k->ind < ind) {
                
                if (k->right == nullptr)
                    k->right = new Node(ind, nullptr, nullptr);
                else
                    add_node(ind, k->right);
            }
            else {
                
                if (k->left == nullptr)
                    k->left = new Node(ind, nullptr, nullptr);

                else
                    add_node(ind, k->left);
            }
        }
    }

    void left(Node *k, std::ofstream &out) {

        out << k->ind << std::endl;

        if (k->left != nullptr)
            left(k->left, out);

        if (k->right != nullptr)
            left(k->right, out);
            
    }

    void delback(Node *k) {
        
        if (k->left != nullptr) delback(k->left);
        if (k->right != nullptr) delback(k->right);

        delete k;
    }

public:
    bst() : root(new Node()) {}
    bst(const bst &tree) = default;
    ~bst() { delback(root); }

    friend std::ifstream & operator>>(std::ifstream &in, bst &tree) {

        int ind;
        if (in >> ind) {
            delete tree.root;
            tree.root = new Node(ind, nullptr, nullptr);
        }

        while (in >> ind)
            tree.add_node(ind, tree.root);
        
        return in;
    }

    friend std::ofstream & operator<<(std::ofstream &out, bst &tree) {

        tree.left(tree.root, out);
        return out;
    }
};

int main() {
    
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    bst tree;

    in >> tree; out << tree;
    
    return 0;
}
