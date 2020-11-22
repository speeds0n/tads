#include <iostream>
#include <string>
#include "lib/stack.h"


int main(){

	Stack<std::string> p;
	p.push("Edson");
	p.push("Cassiano");

//	auto aux = p.pop();
//	std::cout << "p: " << aux << std::endl;
	std::cout << "top: " << p.top() << std::endl;
	p.pop();
	std::cout << "top: " << p.top() << std::endl;
	p.pop();

/*	Stack p;

	p.push(1);

	while(!p.isEmpty()){
		int aux = p.pop();
		std::cout << "p: " << aux << std::endl;
	}

	int aux = p.pop();

	Queue q;

	q.insert(1);
	
	while(! q.isEmpty()){
		int aux2 = q.pop();
		std::cout << "retirei: " << aux2 << std::endl;
	}
	q.pop();*/

	return 0;
}
