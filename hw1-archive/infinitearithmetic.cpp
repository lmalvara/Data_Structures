// main.cpp
#include "ArgumentManager.h"
#include"DoubleLinkedList.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cerr << "Usage: infinitearithmetic \"input=<filename>;digitsPerNode=<number>\"\n";
	}
	ArgumentManager am(argc, argv);
	std::string filename = am.get("input");
	int digitsPerNode = atoi(am.get("digitsPerNode").c_str());
	std::ifstream ifs(filename.c_str());
	std::string line;
	while (getline(ifs, line)) {
		std::string num1;
		std::string num2;
		std::string op;

		for (int i = 0; i < line.size(); i++) {			//replace symbols with space
			if (!isalnum(line[i])) {
				op.push_back(line[i]);
				op = line[i];
				line[i] = ' ';
			}
		}
		stringstream ss(line.c_str());			// get num1 num2 and operator in line
		ss >> num1 >> num2;


		// get num1 num2 and operator in line
		// ...
		DoubleLinkedList l1(num1, digitsPerNode);  // DoubleLinkedList(const std::string& num, int digitsPerNode)
		DoubleLinkedList l2(num2, digitsPerNode);
		
		if (op == "+") {
			if (num1.length() >= num2.length())
			{
				cout << num1 << op << num2 << "=";
				add(l1, l2);
			}
			else
			{
				cout << num1 << op << num2 << "=";
				add(l2, l1);
			}
		
		}
		//DoubleLinkedList l;  // DoubleLinkedList();
		//if (/* plus */)
		//{
		//	l = l1 + l2;
		//}         // DoubleLinkedList operator + (const DoubleLinkedList& list) const;  DoubleLinkedList& operator = (const DoubleLinkedList& list); 
		//else if (/* mult */)     // DoubleLinkedList operator * (const DoubleLinkedList& list) const;
		//{
		//	l = l1 * l2;
		//}
		//else if (/* div */)
		//{
		//	l = l1 / l2;
		//}         // DoubleLinkedList operator / (const DoubleLinkedList& list) const;
		//else if (...)
		//{//...}
		//else {
		//	 ...
		//}

		// output result
		//}

		return 0;
	}
}