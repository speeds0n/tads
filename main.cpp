#include <iostream>
#include <string>
#include "lib/stack.h"
#include "lib/queue.h"


int main(){

	Stack<std::string> p;
	std::cout << "Stack size: " << p.size() << std::endl;
	p.push("Edson");
	p.push("Cassiano");

	p.pop();
	p.pop();

	return 0;
}
