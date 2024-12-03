### 1. 控制 cout 打印颜色
```
#include <iostream>

// 定义颜色常量
const std::string RESET   = "\033[0m";
const std::string RED     = "\033[31m";      // 红色
const std::string GREEN   = "\033[32m";      // 绿色
const std::string YELLOW  = "\033[33m";      // 黄色
const std::string BLUE    = "\033[34m";      // 蓝色
const std::string MAGENTA = "\033[35m";      // 品红色
const std::string CYAN    = "\033[36m";      // 青色
const std::string WHITE   = "\033[37m";      // 白色

int main() {
    std::cout << RED << "这是红色文本" << RESET << std::endl;
    std::cout << GREEN << "这是绿色文本" << RESET << std::endl;
    std::cout << YELLOW << "这是黄色文本" << RESET << std::endl;
    std::cout << BLUE << "这是蓝色文本" << RESET << std::endl;
    std::cout << MAGENTA << "这是品红色文本" << RESET << std::endl;
    std::cout << CYAN << "这是青色文本" << RESET << std::endl;
    std::cout << WHITE << "这是白色文本" << RESET << std::endl;
    return 0;
}
```
