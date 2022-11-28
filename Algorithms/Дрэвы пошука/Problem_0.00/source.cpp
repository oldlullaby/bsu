#include <iostream>
#include <fstream>

struct Node
{
    long long ind;
    Node *left, *right;

    Node() : Node(0, nullptr, nullptr) {}
    Node(long long ind, Node *left, Node *right) : ind(ind), left(left), right(right) {}
};

class bst
{
    Node *root;

    void add_node(long long ind, Node *k)
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

    void sum(Node *k, std::ofstream &out, long long &s) {

        s += k->ind;

        if (k->left != nullptr) {
            sum(k->left, out, s);
        }


        if (k->right != nullptr) {
            sum(k->right, out, s);
        }

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

        long long ind;
        if (in >> ind) {
            delete tree.root;
            tree.root = new Node(ind, nullptr, nullptr);
        }

        while (in >> ind)
            tree.add_node(ind, tree.root);

        return in;
    }

    friend std::ofstream & operator<<(std::ofstream &out, bst &tree) {

        long long sum = 0;
        tree.sum(tree.root, out, sum);
        out << sum << std::endl;
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
