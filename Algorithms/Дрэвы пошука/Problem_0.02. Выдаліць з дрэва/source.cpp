#include <iostream>
#include <fstream>

struct Node
{
    long long ind;
    Node *left, *right, *father;

    Node() : Node(0, nullptr, nullptr, nullptr) {}
    Node(long long key, Node *father, Node *left, Node *right)
            : ind(key), father(father), left(left), right(right) {}
};

class bst
{
    Node *root;

    static void del_right(Node *del) {

        Node *smin = find_min(del->right);
        del->ind = smin->ind;

        if (smin->father == del) smin->father->right = smin->right;
        else {
            if (smin->right != nullptr) smin->right->father = smin->father;
            smin->father->left = smin->right;
        }
        delete smin;

    }

    void delete_root(Node *del) {

        if (del->right != nullptr) root = del->right;
        else if (del->left != nullptr) root = del->left;
        delete del;

    }

    static void delair(Node *k) {

        if (k->ind > k->father->ind) {
            if (k->right != nullptr) k->father->right = k->right;
            else k->father->right = k->left;
        } else {
            if (k->right != nullptr) k->father->left = k->right;
            else k->father->left = k->left;
        }
        delete k;

    }

    static Node *find_min(Node *current) {

        Node *smin = current;
        while (smin->left != nullptr) smin = smin->left;
        return smin;

    }

    Node * find_node(Node *n, long long ind) {
        Node *result = nullptr;

        if (ind > n->ind) {

            if (n->right != nullptr) result = find_node(n->right, ind);
            else return nullptr;

        } else if (ind < n->ind) {

            if (n->left != nullptr) result = find_node(n->left, ind);
            else return nullptr;

        } else if (ind == n->ind) result = n;

        return result;
    }

    void node_adding(long long ind, Node *ths) {

        if (ind != ths->ind) {

            if (ind > ths->ind) {
                if (ths->right == nullptr)
                    ths->right = new Node(ind, ths, nullptr, nullptr);
                else
                    node_adding(ind, ths->right);

            } else {

                if (ths->left == nullptr)
                    ths->left = new Node(ind, ths, nullptr, nullptr);
                else
                    node_adding(ind, ths->left);

            }
        }
    }

    void SLT(Node *k, std::ofstream &out) {

        out << k->ind << '\n';
        if (k->left != nullptr) SLT(k->left, out);
        if (k->right != nullptr) SLT(k->right, out);

    }

    void tree_removing(Node *n) {

        if (n->left != nullptr) tree_removing(n->left);
        if (n->right != nullptr) tree_removing(n->right);
        delete n;

    }

public:

    bst() : root(new Node()) {}
    bst(const bst &tree) = default;
    ~bst() { tree_removing(root); }

    friend std::ifstream & operator>>(std::ifstream &in, bst &tree) {
        long long ind = 0;

        in >> ind;

        delete tree.root;
        tree.root = new Node(ind, nullptr, nullptr, nullptr);


        while (in >> ind)
            tree.node_adding(ind, tree.root);
        return in;
    }

    friend std::ofstream & operator<<(std::ofstream &out, bst &tree) {
        tree.SLT(tree.root, out);
        return out;
    }

    void delright(long long ind) {

        Node *found = find_node(root, ind);
        if (found != nullptr) {

            if (found->right != nullptr && found->left != nullptr) del_right(found);
            else if (found == root) delete_root(found);
            else delair(found);

        }
    }
};

int main() {

    std::ifstream in("input.txt"); std::ofstream out("output.txt");

    long long index_del = 0;

    bst *tree = new bst();
    in >> index_del; in >> *tree; tree->delright(index_del);
    out << *tree;

    in.close(); out.close();

    return 0;
}
