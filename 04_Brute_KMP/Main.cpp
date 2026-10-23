#include <iostream>
#include <windows.h>


int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    std::string main_str,sub_str;
    sub_str = "ABABC";
    int next[5] = {-1,0,0,1,2};
    std::getline(std::cin,main_str);
    
    // ==================== 1. KMP 算法 ====================
    int counter = 0;
    int i=0,j=0;
    while(j <= 4)
    {
        if(i > (int)main_str.length()-1)
        {
            std::cout << "匹配失败！" << std::endl;
            return 0;
        }

        counter += 1;

        if(j >= 5) break;

        if(main_str[i] != sub_str[j])
        {
            j = next[j];
            if(j == -1)
            {
                j += 1;
                i += 1;
            }
            continue;
        }
        i += 1;
        j += 1;
    }

    std::cout << "匹配成功！\nKMP算法一共比对字符" << counter << "次" << std::endl;

     // ==================== 2. Brute 算法 ====================
    counter = 0;
    for(i=0,j=0;j<=4;++j)
    {
        if(i+j > (int)main_str.length()-1)
        {
            std::cout << "匹配失败！" << std::endl;
            return 0;
        }

        counter += 1;

        if(main_str[i+j] != sub_str[j])
        {
            j = -1;
            i += 1;
        }
    }
    
    std::cout << "Brute算法一共比对字符" << counter << "次" << std::endl;
}