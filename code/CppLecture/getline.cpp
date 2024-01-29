#include <iostream>
#include <string>

int main()
{
	std::string str;
	std::cin >> str; // 공백 이전까지 문자열 입력
	std::cout << "str1 : " << str << std::endl;


	std::getline(std::cin, str); // enter 처리
	std::getline(std::cin, str); // \n까지 문자열 입력

	std::cout << "str2 : " << str << std::endl;



	return 0;
}

