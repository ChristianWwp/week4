// w4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <set>
#include <map>
#include <string>

int main() {
	std::set<int> numbers;

	// Prompt user to enter set of numbers
	int num;
	std::cout << "Enter a set of numbers (enter -1 to end):\n";
	do {
		std::cin >> num;
		if (num != -1) {
			numbers.insert(num);
		}
	} while (num != -1);

	// Prompt user to search for a number in the set
	std::cout << "Enter a number to search for in the set: ";
	std::cin >> num;
	if (numbers.count(num) > 0) {
		std::cout << "The number " << num << " is in the set.\n";
	}
	else {
		std::cout << "The number " << num << " is not in the set.\n";
	}

	// Prompt user to erase a number from the set
	std::cout << "Enter a number to erase from the set: ";
	std::cin >> num;
	if (numbers.erase(num) > 0) {
		std::cout << "The number " << num << " was erased from the set.\n";
	}
	else {
		std::cout << "The number " << num << " is not in the set and cannot be erased.\n";
	}

	// Prompt user to associate strings with the remaining numbers in the set
	std::map<int, std::string> num_strings;
	for (int n : numbers) {
		std::string str;
		std::cout << "Enter a string to associate with the number " << n << ": ";
		std::cin >> str;
		num_strings[n] = str;
	}

	// Display the contents of the map
	std::cout << "Number\tString\n";
	for (const auto& pair : num_strings) {
		std::cout << pair.first << "\t" << pair.second << "\n";
	}

	// Prompt user to search for a string associated with a number in the map
	do {
		std::cout << "Enter a number to retrieve the associated string (enter -1 to quit): ";
		std::cin >> num;
		if (num == -1) {
			break;
		}
		auto iter = num_strings.find(num);
		if (iter != num_strings.end()) {
			std::cout << "The string associated with " << num << " is " << iter->second << "\n";
		}
		else {
			std::cout << "No string is associated with " << num << ".\n";
		}
	} while (true);

	// Prompt user to change the string associated with a number in the map
	do {
		std::cout << "Enter a number to change the associated string (enter -1 to quit): ";
		std::cin >> num;
		if (num == -1) {
			break;
		}
		auto iter = num_strings.find(num);
		if (iter != num_strings.end()) {
			std::string new_str;
			std::cout << "Enter a new string to associate with " << num << ": ";
			std::cin >> new_str;
			iter->second = new_str;
			std::cout << "The new string associated with " << num << " is " << iter->second << "\n";
		}
		else {
			std::cout << "No string is associated with " << num << ".\n";
		}
	} while (true);

	return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
