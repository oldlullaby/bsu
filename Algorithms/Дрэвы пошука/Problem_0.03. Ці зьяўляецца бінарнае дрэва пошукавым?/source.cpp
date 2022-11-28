#include <iostream>
#include <limits>

struct Node
{
    long long int data, father, left, right;
    char dir;

    Node() : dir('N'), data(0), father(0), left(std::numeric_limits<long long int>::min()),
             right(std::numeric_limits<long long int>::max()){}


    bool is_add_t(const Node& fth) {

        long long fda = fth.data;

        if (dir == 'L') {

            long long fleft = fth.left;

            if (data < fda) right = fda;
            else return false;

            if (data >= fleft) left = fleft;
            else return false;

        } else {

            long long fright = fth.right;

            if (data >= fda) left = fda;
            else return false;

            if (data < fright) right = fright;
            else return false;

        }
        return true;
    }
};

int main() {

FILE *input = nullptr, *output = nullptr;
    long long int N;

    fopen_s(&input, "bst.in", "r");
    fopen_s(&output, "bst.out", "w");

    fscanf(input, "%lld", &N);

    if (N) {
    long long int data;
    fscanf(input, "%lld", &data);

    Node p; p.data = data;
    Node* t = new Node[N]; t[0] = p;

    for (size_t i = 1; i < N; i++) {

        Node& c = t[i];

        fscanf(input, "%lld", &c.data);
        fscanf(input, "%lld", &c.father);
        fscanf(input, "%*c%c", &c.dir, 1);


        if (!c.is_add_t(t[c.father - 1])) {
            fprintf_s(output, "NO");
            return 0;
        }
    }

    fprintf_s(output, "YES");
    }
    else fprintf_s(output, "NO");

    return 0;
}
