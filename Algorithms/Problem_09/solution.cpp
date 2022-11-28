#include <algorithm>
#include <fstream>
#include <set>

struct Node {

    Node *left, *right;
    long long int data, h, dist_max, lenmax, m_1, m_2;

    explicit Node(long long int data = 0) : data(data), right(nullptr), left(nullptr), h(0),
                                            dist_max(0), lenmax(0), m_1(0), m_2(0) {};


    [[nodiscard]] bool is_2sons() const { return left && right; }
    [[nodiscard]] bool is_leaf() const { return (left == nullptr) && (right == nullptr); }

    [[nodiscard]] bool is_left_s() const { return left != nullptr; }
    [[nodiscard]] bool is_right_s() const { return right != nullptr; }

};

class bst {
public:

    bst() : root(nullptr), lenmax(0) {};

    void add(const long long int &data);
    void remove_node(const long long int &data);

    void print(std::ostream& out) { print_r(out, root); }
    void levels() { levels(root); }
    void part_1() { part_1(root); }
    void part_2(std::set <long long int> &pm) { part_2(root, nullptr, pm); }

private:

    void part_1(Node* root_r);
    void part_2(Node* root_r, Node* p, std::set <long long int> &pm);

    void levels(Node* root_r);
    void print_r(std::ostream& out, Node* root_r);
    static void remove_s1(Node* p, Node** p_r);

    long long int lenmax;
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

void bst::levels(Node* root_r) {

    if (!root_r) return;

    levels(root_r->left);
    levels(root_r->right);

    if (root_r->is_leaf()) {

        root_r->h = 0; root_r->lenmax = 0; root_r->dist_max = 1;

    } else if (root_r->is_2sons()) {

        root_r->h = 1 + std::max(root_r->left->h, root_r->right->h);
        root_r->lenmax = 2 + root_r->left->h + root_r->right->h;

        if (root_r->lenmax > this->lenmax) this->lenmax = root_r->lenmax;
        if (root_r->right->h == root_r->left->h) root_r->dist_max = root_r->left->dist_max + root_r->right->dist_max;

        else if (root_r->right->h > root_r->left->h) root_r->dist_max = root_r->right->dist_max;
        else root_r->dist_max = root_r->left->dist_max;

    } else if (root_r->is_left_s()) {

        root_r->h = 1 + root_r->left->h;
        root_r->dist_max = root_r->left->dist_max;
        root_r->lenmax = 1 + root_r->left->h;

        if (root_r->lenmax > this->lenmax) this->lenmax = root_r->lenmax;
    }
    else {

        root_r->h = 1 + root_r->right->h;
        root_r->dist_max = root_r->right->dist_max;
        root_r->lenmax = 1 + root_r->right->h;

        if (root_r->lenmax > this->lenmax) this->lenmax = root_r->lenmax;

    }

}

void bst::part_1(Node* root_r) {

    if (!root_r) return;

    if (root_r->lenmax == this->lenmax) {

        if (root_r->is_2sons()) { root_r->m_2 = root_r->left->dist_max * root_r->right->dist_max; }
        else if (root_r->is_left_s()) { root_r->m_2 = root_r->left->dist_max; }
        else if (root_r->is_right_s()) { root_r->m_2 = root_r->right->dist_max; }
        else if (root_r->is_leaf()) { root_r->m_2 = 1; }

    }
    part_1(root_r->left);
    part_1(root_r->right);

}

void bst::part_2(Node* root_r, Node* p, std::set<long long int> &pm) {

    if (!root_r) return;
    if (root_r == this->root) root_r->m_1 = 0;

    else if (p!= nullptr && p->is_2sons()) {

        if (p->right->h == p->left->h) root_r->m_1 = p->m_2 + root_r->dist_max * p->m_1 / p->dist_max;
        else if (p->right->h > p->left->h) {

            if (root_r == p->right) root_r->m_1 = p->m_1 + p->m_2;
            else if (root_r == p->left) root_r->m_1 = p->m_2;

        } else if (p->right->h < p->left->h) {

            if (root_r == p->left) root_r->m_1 = p->m_1 + p->m_2;
            else if (root_r == p->right) root_r->m_1 = p->m_2;

        }
    }
    else if (p != nullptr && !p->is_leaf()) root_r->m_1 = p->m_1 + p->m_2;

    if (root_r->m_1 + root_r->m_2)
        pm.insert(root_r->data);

    part_2(root_r->left, root_r, pm);
    part_2(root_r->right, root_r, pm);

}

void bst::print_r(std::ostream& out, Node* root_r) {

    if (!root_r) { return; }
    out << root_r->data << std::endl;
    print_r(out, root_r->left);
    print_r(out, root_r->right);

}

void problem_9(std::ifstream& in, std::ofstream& out) {

    long long int value; bst tree;
    while (in >> value) { tree.add(value); }

    tree.levels(); tree.part_1();

    std::set <long long int> pm;
    tree.part_2(pm);

    auto it = pm.begin(); it++;

    tree.remove_node(*it);
    tree.print(out);

    in.close(); out.close();

}

int main() {

    std::ifstream in("in.txt");
    std::ofstream out("out.txt");
    problem_9(in, out);
    return 0;

}
