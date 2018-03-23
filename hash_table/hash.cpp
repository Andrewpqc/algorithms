// #include <iostream>
// #include <functional>
// #include <string>
// using namespace std;

// int main (void){
//     hash<string> string_hash;
//     string s="hello";
//     cout<<string_hash(s)<<endl;
//     return 0;
// }

//除法散列
//乘法散列
//全域散列
#include <iostream>
#include <functional>
#include <string>
 
int main()
{
    std::string str = "Meet the new boss...";
    std::hash<std::string> hash_fn;
    size_t str_hash = hash_fn(str);
 
    std::cout << str_hash << '\n';
}

