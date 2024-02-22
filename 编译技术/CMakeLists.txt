# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(CCDProject)

# 指定 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加 Flex 和 Bison 的查找模块
find_package(BISON)
find_package(FLEX)

# 生成词法分析器
FLEX_TARGET(MyScanner lex.l ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c)
# 生成语法分析器
BISON_TARGET(MyParser parser.ypp ${CMAKE_CURRENT_BINARY_DIR}/parser.tab.cpp)
# 添加 Flex/Bison 输出的依赖关系
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

# 包含生成的文件
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# 指定源文件
set(SOURCE_FILES
        ast.cpp
        semantics.cpp
        GenIR.cpp
        GenObject.cpp
        ${BISON_MyParser_OUTPUTS}
        ${FLEX_MyScanner_OUTPUTS}
)

# 添加可执行文件
add_executable(parser ${SOURCE_FILES})

# 如果有其他库依赖，可以在这里链接
# target_link_libraries(parser your_libraries)
