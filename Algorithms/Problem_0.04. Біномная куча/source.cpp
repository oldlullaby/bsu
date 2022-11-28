#include <fstream>
#include <iostream>
#include <vector>

std::vector <long long int> f(long long int n){
    std::vector<long long int> v;
    while(n) {
        v.emplace_back(n % 2);
        n /= 2;
    }
    std::vector<long long int> vz;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == 1){
            vz.emplace_back(i);
        }
    }
    std::vector<long long int> res (vz.size());
    for(int i = 0; i < res.size(); ++i){
        res[i] = vz[i];
    }

    return res;
}

int main() {
    std::ifstream in ("input.txt");
    std::ofstream out ("output.txt");
    long long int n; in >> n;

    std::cout << n;

    std::vector <long long int> trees = f(n);
    trees = f(n);

    for (long long tree : trees) {
        out << tree << std::endl;
    }
    in.close(); out.close();
    return 0;
}
