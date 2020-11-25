#include <iostream>
 
int main(){

	int a{100000};
	int i{0};
	while(i <= a){
		std::cout << i << std::endl;
		i = i + 500;
	}

	return 0;
}
