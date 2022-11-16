#include <bits/stdc++.h>
using namespace std;

// // void build(const S& sentence_list, M& root) {
// //     for (const auto& sentence : sentence_list) {
// //         string word;
// //         stringstream ss(sentence);
// //         M* base = &root;

// //         while (ss >> word) {
// //             auto found = base->find(word);
// //             if (base->find(word) == base->end()) {
// //                 base->insert({word})
// //             }
// //         }
// //     }
// // }

// int main() {
//     string words[] = {"Hello", "World"};

//     for (auto &word : words) {
//         reverse(word.begin(), word.end());
//         for (auto &c : word) {
//             tolower(c);
//         }
//     }

//     for (auto el : words) cout << el << " ";
// }

int main() {
    const char *filepath = "";

    const int BUF_SIZE = 1024;
    char *buffer[1024] = {0};
    FILE *file;

    if (file = fopen(filepath, "r")) {
        fgets((char *)buffer, BUF_SIZE, file);
    }

    fclose(file);
}
