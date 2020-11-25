#ifndef STACK_H
#define STACK_H
#define TAMANHO 100000
#include <iostream>
//#include <vector>

template <class T>
class Stack{

	private:
		T m_list[TAMANHO];
		//std::vector<T> m_list; //!< Stack data List
		int m_top; //!< Count to top of the Stack

	public:
		/// Default Constructor
		Stack(int top = -1): m_top{top}
		{ /* Empty */ }

		/// Default Destructor
		~Stack(){

			//m_list.clear();
			m_top = -1;
		}

		/// Insert element
		/*!
		 * Add an element at the bottom of the Stack
		 * This function make push, adding an template data in the bottom of the Stack.
		 *
		 * \param value Data that will be added to the bottom of the Stack.
		 */
		void push(T value){

			if( !full() ){
				m_list[++m_top] = value;
			}else{
				std::cout << "Stack is full!" << std::endl;
			}
		}

		/// Remove top element
		/*!
		 * This function remove the element on top of Stack, reducing its size by one.
		 * The element removed is the latest element inserted into the Stack.
		 */

		void pop(){

			if( !empty() ){
				m_list[m_top--];
			}else{
				std::cout << "Stack Empty" << std::endl;
			}
		}

		/// Acess next element
		/*!
		 *
		 * This function returns the lastest element inserted into the Stack.
		 *
		 * \return A reference to the top element in the Stack.
		 */
		T top(){
			return m_list[m_top];
		}
		/// Test whether Stack is empty
		/*!
		 * This function check if the Stack is empty and return true or false.
		 *
		 * \return Logical expression, true if Stack is empty and false otherwise. 
		 */
		bool empty(){

			return m_top == -1;
		}

		/// Test whether Stack is full
		/*!
		 * This function check if the Stack is full and return true or false.
		 *
		 * \return Logical expression, true if Stack is full and false otherwise. 
		 */
		bool full(){
			return m_top+1 == TAMANHO;
		}

		/// Return size
		/*!
		 * This function returns the number of elements in the Stack.
		 *
		 * \return The number of elements in the Stack.
		 */
		int size(){
			return m_top + 1;
		}
};

#endif
