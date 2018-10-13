#设置项目名称
PROJECT(algo)

#要求CMake的最低版本为2.8
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_COMPILE_OPTIONS(-std=c++11)


#添加库文件搜索路径
LINK_DIRECTORIES(/usr/local/lib /usr/lib)

ADD_EXECUTABLE(strstr str/strstr/strstr.cpp)
ADD_EXECUTABLE(anagrams str/anagrams/anagrams.cpp)

