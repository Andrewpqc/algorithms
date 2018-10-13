#include <string>
#include <iostream>
#include <algorithm>

bool anagrams1(const std::string &s1, const std::string &s2) {
    if (s1.empty() && s2.empty()) return true;
    if (s1.empty() || s2.empty()) return false;

    if (s1.length() != s2.length()) return false;

    int map[256] = {0};
    for (auto i = 0; i < s1.length(); ++i) {
        ++map[s1[i]];
        --map[s2[i]];
    }

    for(auto i = 0; i < s1.length(); ++i) {
        if (map[s1[i]] != 0)
            return false;
    }

    return true;
}

bool anagrams2(const std::string s1, const std::string s2){
    if (s1.empty() && s2.empty()) return true;
    if (s1.empty() || s2.empty()) return false;

    if (s1.length() != s2.length()) return false;


    std::sort(s1.begin(),s1.end());
    std::sort(s2.begin(),s2.end());

    if(s1==s2) return true;
    else return false;
}

int main(){
    auto s1="sdfgcc";
    auto s2="dfgscf";
    std::cout<<anagrams1(s1,s2)<<std::endl;
    std::cout<<anagrams2(s1,s2)<<std::endl;
    return 0;
}