#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

#include "lib/stack.h"
#include "lib/linked_list.h"


int main(){

	std::fstream testFile("n_testes.txt");
	std::fstream tst1("push_teste.txt");
	std::fstream tst2("pop_teste.txt");

	Stack<int> p;
	LinkedList<int> l;
	int i{0},j{0};

	if(testFile.is_open()){
		while(!testFile.eof()){
			testFile >> j;
			auto start4 = std::chrono::steady_clock::now();
			l.push_back(j);
			auto end4 = std::chrono::steady_clock::now();
			auto diff4 = end4 - start4;
			tst1 << j << " " << std::chrono::duration<double, std::milli>(diff4).count() << std::endl;

			auto start3 = std::chrono::steady_clock::now();
			l.pop_back();
			auto end3 = std::chrono::steady_clock::now();
			auto diff3 = end3 - start3;
			tst2 << j << " " << std::chrono::duration<double, std::milli>(diff3).count() << std::endl;
		}
	}
			testFile.close();
			tst2.close();
			tst1.close();
			return 0;

/*			int aux{0};
			auto start = std::chrono::steady_clock::now();
			while(aux < j){
//				p.push(aux);
				l.push_back(aux);
				aux++;
			}
			auto end = std::chrono::steady_clock::now();
			auto diff = end - start;
			tst1 << j << " " << std::chrono::duration<double, std::milli>(diff).count() << std::endl;

			aux = 0;
			auto start2 = std::chrono::steady_clock::now();
			std::cout << j << std::endl;
			while(aux < j){
//				p.pop();
				l.pop_back();
				aux++;
			}
			auto end2 = std::chrono::steady_clock::now();
			auto diff2 = end - start;
			tst2 << j << " " << std::chrono::duration<double, std::milli>(diff).count() << std::endl;
		}
	}

	testFile.close();
	tst2.close();
	tst1.close();

	return 0;*/


/*	while(!p.full()){
		auto start = std::chrono::steady_clock::now();
		p.push(i);
		auto end = std::chrono::steady_clock::now();
		auto diff = end - start;
//		std::cout << std::chrono::duration<double, std::milli>(diff).count() << std::endl;
		i++;
	}
	i = 0;
	while(!p.empty()){
		auto start = std::chrono::steady_clock::now();
		p.pop();
		auto end = std::chrono::steady_clock::now();
		auto diff = end - start;
//		std::cout << std::chrono::duration<double, std::milli>(diff).count() << std::endl;
}
//	std::cout << p.size() << std::endl;

	i = 0;
	while(i < 100){
		l.push_back(i);
		i++;
	}
	l.print();*/


	return 0;
}
