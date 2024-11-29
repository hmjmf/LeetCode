
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> split(const std::string &s, char delimiter) {
    std::vector<std::string> result;
    auto begin = s.begin();
    while (begin < s.end()) {
        auto iter = std::find(begin, s.end(), delimiter);
        if (iter != s.end()) {
            result.push_back(std::string(begin, iter));
        } else {
            result.push_back(std::string(begin, s.end()));

        }
        begin = iter + 1;
    }
    return result;
}

std::string replace(const std::string &subject, const std::string &search, const std::string &replace) {
    std::string s = subject;
    size_t pos = 0;
    while((pos = s.find(search, pos)) != std::string::npos) {
        s.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return s;
}

template<typename T>
void print_vector(const std::vector<T> &v) {
    for(const auto &i:v){
        std::cout << i << std::endl;
    }
}