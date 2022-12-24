#include <fstream>
#include <vector>
#include <stack>

int main() {

    std::ifstream in ("labyrinth.in"); std::ofstream out("labyrinth.out");


    int num_successful_people = 0; std::stack <std::pair <int, int> > dmdx, not_good_way;
    int lyudzi, ro_wz, co_lz; in >> ro_wz >> co_lz >> lyudzi;


    std::vector <bool> is_vyhad(co_lz); std::vector <std::pair <int, int> > kaardynaty(8);
    std::vector <int> uvahody(lyudzi), vyhady(lyudzi);


    std::vector < std::vector<int> > total_matrix(ro_wz, std::vector<int>(co_lz)),
                                    matrix_of_labyrinth(ro_wz + 2, std::vector<int>(co_lz + 2, 1));


    kaardynaty[0] = std::make_pair(-1, -1); kaardynaty[1] = std::make_pair(0, -1);
    kaardynaty[2] =  std::make_pair(1, -1); kaardynaty[3] = std::make_pair(1, 0);
    kaardynaty[4] =   std::make_pair(1, 1); kaardynaty[5] = std::make_pair(0, 1);
    kaardynaty[6] =  std::make_pair(-1, 1); kaardynaty[7] = std::make_pair(-1, 0);

    for (int i = 0; i < lyudzi; ++i) in >> uvahody[i];
    for (int i = 0; i < lyudzi; ++i) {

        in >> vyhady[i];
        is_vyhad[vyhady[i] - 1] = true;

    } for (int i = 0; i < ro_wz; ++i) {

        for (int j = 0; j < co_lz; ++j) {

            in >> total_matrix[i][j];
            matrix_of_labyrinth[i + 1][j + 1] = total_matrix[i][j];

        }
    }

    for (int d = 0; d < lyudzi; ++d) {

        bool mesca_navedanaye = false; int padlik = 0, naadvar = 0;

        int jj = uvahody[d], ii = 1;  std::pair <int, int> pac_pos = std::make_pair(ii, jj);
        dmdx.push(std::make_pair(ii, jj)); matrix_of_labyrinth[ii][jj] = 2 + d;

        while (jj < co_lz + 1 and ii < ro_wz + 1) {

            bool ajx = true;
            for (int k = 0; k < 8; ++k) {

                if (!matrix_of_labyrinth[ii + kaardynaty[(padlik + k) % 8].first][jj + kaardynaty[(padlik + k) % 8].second] or
                            ii + kaardynaty[(padlik + k) % 8].first == ro_wz and is_vyhad[jj + kaardynaty[(padlik + k) % 8].second - 1] and
                                    jj + kaardynaty[(padlik + k) % 8].second) {

                    jj = jj + kaardynaty[(padlik + k) % 8].second; ii = ii + kaardynaty[(padlik + k) % 8].first;
                    padlik = (padlik + k + 5) % 8; matrix_of_labyrinth[ii][jj] = d + 2;
                    dmdx.push(std::make_pair(ii, jj)); ajx = false; naadvar = 0; break;

                } else if (is_vyhad[jj - 1] and ii == ro_wz) {

                    jj = jj + kaardynaty[(padlik + k) % 8].second; ii = ii + kaardynaty[(padlik + k) % 8].first;
                    ajx = false; dmdx.push(std::make_pair(ii, jj)); break;

                }

            }
            if (is_vyhad[jj - 1]  and  ii == ro_wz) {
                mesca_navedanaye = true; break;
            }

            if (!dmdx.empty() and ajx) {

                not_good_way.push(std::make_pair(ii, jj));
                matrix_of_labyrinth[ii][jj] = -1; dmdx.pop();

                if (!dmdx.empty()) {
                    jj = dmdx.top().second; ii = dmdx.top().first;
                }

                if (!naadvar) padlik = (padlik + 5) % 8; naadvar = naadvar + 1;

            }

            else if (jj == pac_pos.second and ii == pac_pos.first) {

                while (!dmdx.empty()) {

                    matrix_of_labyrinth [dmdx.top().first] [dmdx.top().second] = 0;
                    dmdx.pop();

                } break;

            }
        }

        if (mesca_navedanaye) {

            num_successful_people = num_successful_people + 1;
            while (!dmdx.empty()) {
                total_matrix [dmdx.top().first - 1] [dmdx.top().second - 1] = d + 2; dmdx.pop();
            }

        }
    }


    out << num_successful_people << std::endl;
    for (int i = 0; i < ro_wz; ++i) {
        for (int j = 0; j < co_lz; ++j) {
            out << total_matrix[i][j] << " ";
        }
        out << std::endl;
    }


    in.close(); out.close(); return 0;

}
