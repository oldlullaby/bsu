#include <algorithm>
#include <fstream>
#include <string>

struct Node {

    Node *left, *right;
    long long int data;

    explicit Node(long long int data = 0) : data(data), right(nullptr), left(nullptr){}
    [[nodiscard]] bool is_2sons() const { return left && right; }

};

class bst {
public:

    bst() : root(nullptr) {};

    void add(const long long int &data);
    void remove_node(const long long int &data);

    Node* get_root(){return root;}

    void print_r(std::ostream& out, Node* root_r, bool &a);

private:
    static void remove_s1(Node* p, Node** p_r);
    Node* root;
};

void bst::add(const long long int &data) {

    Node* p = root;
    Node** p_r = &root;
    while (p) {

        if (data == p->data) return;
        else if (data > p->data) {

            p_r = &p->right;
            p = p->right;

        } else {

            p_r = &p->left;
            p = p->left;

        }
    }
    *p_r = new Node(data);

}

void bst::remove_node(const long long int &data) {

    Node* kmp = root;
    Node** kmp_r = &root;

    while (kmp != nullptr && data != kmp->data) {

        if (data < kmp->data) {
            kmp_r = &kmp->left; kmp = kmp->left;

        } else if (data > kmp->data) {
            kmp_r = &kmp->right; kmp = kmp->right;
        }
    }

    if (kmp == nullptr) return;
    if (kmp->is_2sons()) {

        kmp_r = &kmp->right; Node* p = kmp->right;

        while (p->left != nullptr) { kmp_r = &p->left; p = p->left; }
        kmp->data = p->data;
        remove_s1(p, kmp_r);

    } else remove_s1(kmp, kmp_r);
}

void bst::remove_s1(Node* p, Node** p_r) {

    if (p->left != nullptr) *p_r = p->left;
    else *p_r = p->right;

    delete p;

}

void bst::print_r(std::ostream& out, Node* root_r, bool &a) {

    if (!root_r) { return; }
    
    if (!a) { out << root_r->data; a = 1;}
    else out << " " << root_r->data;
    
    print_r(out, root_r->left, a);
    print_r(out, root_r->right, a);

}

bool is_mirror(Node* a, Node* b) {

    bool result = false;
    if (a == nullptr && b == nullptr) result = true;
    else if (a != nullptr && b != nullptr){

        result = ( (a->left == nullptr && b->right == nullptr) || (a->left != nullptr && b->right != nullptr) )
                && ( (a->right == nullptr && b->left == nullptr) || (a->right != nullptr && b->left != nullptr) )
                && (is_mirror(a->left, b->right) && is_mirror(a->right, b->left) );
        
    }

    return result;

}

int main() {

    std::ifstream in("tst.in");
    std::ofstream out("tst.out");

    bst tree_1;
    std::string value_1, root_1;
    long long int value_2, root_2; bst tree_2;

    std::getline(in, root_1); tree_1.add(std::stoi(root_1));

    while (in.peek() != '*' && std::getline(in, value_1, '\n')) tree_1.add(std::stoi(value_1));

    std::string line;
    std::getline(in, line);
    in >> root_2; tree_2.add(root_2);

    while (in >> value_2) { tree_2.add(value_2); }

    tree_1.remove_node(std::stoi(root_1));
    tree_2.remove_node(root_2);

    bool axaxaxa = 0;

    if (!is_mirror(tree_1.get_root(), tree_2.get_root()))
        out << "NO" << std::endl;
    else {
        out << "YES" << std::endl;
        tree_1.print_r(out, tree_1.get_root(), axaxaxa);
        out << std::endl;
        axaxaxa = 0;
        tree_2.print_r(out, tree_2.get_root(), axaxaxa);
    }


    in.close(); out.close();
    return 0;
}

