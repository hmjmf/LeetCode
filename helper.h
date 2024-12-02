
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

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
    std::cout << "vector: ";
    for (const auto &i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void print_2dvector(const std::vector<std::vector<T>> &v) {
    std::cout << "vector: " << std::endl;
    for (const auto &i : v) {
        for (const auto &j : i) {
            std::cout << j << " ";
    }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    static ListNode * make_list(const std::vector<int> &v) {
        if(v.size()) {
            ListNode *h = new ListNode(v[0]);
            auto l = h;
            for (int i = 1; i < v.size(); i++) {
                l->next = new ListNode(v[i]);
                l = l->next;
            }
            return h;
        } else {
            return nullptr;
        }
    }
    static void print_list(ListNode *l) {
        std::cout << "List: ";
        while(l) {
            std::cout << l->val << " ";
            l = l->next;
        }
        std::cout << std::endl;
    }
};