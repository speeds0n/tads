#include <iostream>
#include <cassert>

#include "../lib/tad.h"

// Stack functions

Stack::Stack(){
	m_list = new int[10];
	m_top = -1;
}

void Stack::push(int value){

	if(isFull()){
		std::cout << "Stack Full" << std::endl;
	}else{
		m_top++;
		m_list[m_top] = value;
	}
}

int Stack::pop(){

	int aux;

	if(isEmpty()){
		std::cout << "Stack Empty" << std::endl;
	}else{
		aux = m_list[m_top];
		m_top--;
	}
	return aux;
}

int Stack::top(){
	return m_list[m_top];
}

bool Stack::isEmpty(){
	return m_top == -1;
}

bool Stack::isFull(){
	return m_top == 9;
}
// Queue functions
Queue::Queue(){
	m_list = new int[10];
	m_first = 0;
	m_last = 0;
	m_total = 0;
}

void Queue::insert(int value){
	if(isFull()){
		std::cout << "Queue is Full, cant insert elements" << std::endl;
	}else{
		m_list[m_last] = value;
	//	m_last = (m_last + 1) % (sizeof(m_list)/sizeof(m_list[0]));
		m_last = (m_last + 1) % 10;
		m_total++;
	}
}

int Queue::pop(){
	if(isEmpty()){
		std::cout << "Queue is Empty, cant pop elements" << std::endl;
	}else{
		int aux = m_list[m_first];
	//	m_first = (m_first + 1) % (sizeof(m_list)/sizeof(m_list[0]));
		m_first = (m_first + 1) % 10;
		m_total --;
		return aux;
	}

}

bool Queue::isEmpty(){
	return m_total == 0;
}

bool Queue::isFull(){
//	return m_total == sizeof(m_list)/sizeof(m_list[0]);
	return m_total == 10;
}
