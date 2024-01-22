#include<iostream>

using namespace std;
#include <vector>
#include <string>
#include <sstream>



//// find
//int main()
//{
//	string a = "한글자";
//
//
//	// 한글은 3바이트
//	cout << a.find("한") << endl;
//	cout << a.find("글") << endl;
//	cout << a.find("자") << endl;
//
//	cout << sizeof("한") << endl; //4바이트가 나오는것은 /0 종료문자가 포함되어 있기에
//	cout << sizeof("한글") << endl; //7바이트
//
//	// 영어는 1바이트
//	string b = "abc";
//	cout << b.find("a") << endl;
//	cout << b.find("b") << endl;
//	cout << b.find("c") << endl;
//
//}


//// split
//std::vector<std::string> split(const std::string & str, char delimiter) {
//    std::vector<std::string> tokens;
//    std::istringstream ss(str);
//    std::string token;
//
//    while (std::getline(ss, token, delimiter)) {
//        tokens.push_back(token);
//    }
//
//    return tokens;
//}
//
//int main() {
//    std::string input = "Hello,World,This,is,C++,split,example";
//    char delimiter = ',';
//    std::vector<std::string> result = split(input, delimiter);
//
//    for (const std::string& token : result) {
//        std::cout << token << std::endl;
//    }
//
//    return 0;
//}

// split2,substr,erase
vector<string> split(string input, string delimiter) {
	vector<string> ret;
	long long pos = 0;
	string token = "";
	while ((pos = input.find(delimiter)) != string::npos) { // 찾는 문자열의 첫번째 위치
		token = input.substr(0, pos); // 길이만큼 짜른 문자열을 반환
		ret.push_back(token);
		input.erase(0, pos + delimiter.length()); // 길이만큼 삭제
	}
	ret.push_back(input);
	return ret;
}

int main() {
	string s = "아무리 먹어도 살이 안찌면 얼마나 좋을까", d = " ";
	vector<string> a = split(s, d);
	for (string b : a) cout << b << "\n";
}



//// getline_1

//int main() {
// 
//    // getline(istream& is, string& str, char delim); delim deafult = enter;
//    std::string input;
//
//    std::cout << "문자열을 입력하세요: ";
//    std::getline(std::cin, input);
//
//    std::cout << "입력한 문자열: " << input << std::endl;
//
//    return 0;
//}

////  getline_2
//int main() {
//    std::string input = "Hello, World! \nThis \nis a custom input stream.";
//
//    // 문자열을 스트림으로 변환
//    std::istringstream customStream(input);
//
//    std::string line;
//    while (std::getline(customStream, line)) {
//        std::cout << "읽은 문자열: " << line << std::endl;
//    }
//
//    return 0;
//}