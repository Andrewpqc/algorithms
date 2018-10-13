#include <iostream>
#include <string>
#include <tuple>

inline std::tuple<bool, int> check_is_match(const std::string &src,
                                            unsigned long index, const std::string &tgt) {
    int i;
    for (i = 1; i < tgt.length(); ++i) {
        if (src[index + i] != tgt[i])
            return std::make_tuple(false, index + i);
    }
    return std::make_tuple(true, index + i);
}

int strstr(const std::string &src, const std::string &tgt) {
    if (src.empty() && tgt.empty()) return 0;
    if (src.empty()) return -1;
    if (tgt.empty()) return 0;

    auto src_len = src.length();
    auto tgt_len = tgt.length();

    if (tgt_len > src_len) return -1;

    for (auto i = 0; i < src_len; i++) {
        if (src[i] == tgt[0]) {
            bool matched;
            int new_index;
            std::tie(matched, new_index) = check_is_match(src, i, tgt);
            if (matched) return i;
            else i = new_index;
        }
    }
    return -1;
}


int main() {
    std::string src = "abcdef";
    std::string tgt = "abcffd";
    auto result = strstr(src, tgt);
    std::cout << result << std::endl;
    return 0;
}