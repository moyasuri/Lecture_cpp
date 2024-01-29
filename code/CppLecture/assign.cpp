#include <iostream>
#include <string>


int main()
{
    std::string str1;
    std::string str2;
    std::string str3;


    again:
    std::cout << "\n2개의 정수 입력\n";
    std::cin >> str1 >> str2;


    while (1)
    {
        std::cin >> str1 >> str2;;
        for (int i = 0; i < str1.size(); i++) {
            if (isdigit(str1[i]) != 0) {
                break;
            }
        }

        for (int i = 0; i < str2.size(); i++) {
            if (isdigit(str2[i]) != 0) {
                break;
            }
        }
    }


    str3 = str1;

    std::cout << "\n" << str3.append(str2) << "\n";
    std::cout << "\n" << (stoi(str1) + stoi(str2)) << "\n";


}




