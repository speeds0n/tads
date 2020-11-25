#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

template<class T>
class Node{

	private:
		T m_data; ///!< Data Node.
		Node *m_next; ///!< Pointer to next node, if exist.

	public:
		/// Default Constructor.
		Node(T data){
			m_data = data;
			m_next = NULL;
		}
		T getData(){ return m_data; }; ///!< Return data of current Node.
		Node* getNext(){ return m_next; } /// !< Return the next Node.
		void setNext(Node* next){ m_next = next; } ///!< Change the value of the next Node.
};

template<class T>
class LinkedList{
	private:
		Node<T> *m_head;
		Node<T> *m_tail;
		int m_size;

	public:
		/// Constructor.
		LinkedList(){
			m_head = NULL;
			m_tail = NULL;
			m_size = 0;
		}
		/// Constructor with arguments.
		LinkedList(T data){
			m_head = new Node<T>(data);
			m_tail = m_head;
			m_size = 1;
		}
		/// Destructor.
		~LinkedList(){
			delete m_head;
		}
		bool isEmpty(){
			return m_head == NULL;
		}
		int size(){
			return m_size;
		}
		/// Print all elements in the list.
		void print(){
			Node<T> *tmp = m_head;

			if(isEmpty()){
				std::cout << "The list doesn't have elements!" << std::endl;
			}else{
				while(tmp){
					std::cout << tmp->getData() << std::endl;
					tmp = tmp->getNext();
				}
			}

		}

		void push_front(T data){
			Node<T> *newNode = new Node<T>(data);

			if(isEmpty()){
				m_head = newNode;
				m_tail = newNode;
			}else{
				newNode->setNext(m_head);
				m_head = newNode;
			}
			m_size++;
		}

		void push_back(T data){

			Node<T> *newNode = new Node<T>(data);

			if(isEmpty()){
				m_head = newNode;
				m_tail = newNode;
			}else{
				m_tail->setNext(newNode);
				m_tail = newNode;
			}
			m_size++;
		}

		T acess( int position){
			Node<T> *tmp = m_head;
			int count = 0;
			while(tmp){
				if(count == position-1){
					return tmp->getData();
				}
				tmp = tmp->getNext();
				count++;
			}
			std::cout << "Don't find the position" << std::endl;
			return -1;
		}

		void remove(int position){

			Node<T> *prev = m_head;
			Node<T> *current = m_head->getNext();
			int count = 0;

			if(isEmpty()){
				std::cout << "Empty list" << std::endl;
			}else{
				while(current != NULL){
					if(count == position-1){
						break;
					}else{
						prev = current;
						current = current->getNext();
					}
					count++;
				}
				if(current == NULL){
					std::cout << "Can't remove the element, no found!" << std::endl;
				}else{
					prev->setNext(current->getNext());
					delete current;
				}
			}
		}

		void pop_back(){
			if(!isEmpty()){
				if(m_head->getNext() == NULL){
					m_head = NULL;
				}else if(m_head->getNext()->getNext() == NULL){
					m_head->setNext(NULL);
				}else{
					Node<T> *first = m_head;
					Node<T> *second = m_head->getNext();
					Node<T> *third = m_head->getNext()->getNext();

					while(third){
					 Node<T> *aux = first;
					 first = third;
					 second = aux;
					 third = third->getNext();
					}

					delete first->getNext();
					first->setNext(NULL);
					m_tail = first;
					m_size--;
				}
			}
		}
};

#endif
