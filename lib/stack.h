#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>

template <class T>
class Stack{

	private:
		std::vector<T> m_list; //!< Stack List
		int m_top;

	public:
		/// Default Constructor
		Stack(int top = -1): m_top{ top }{

		}
		/// Default Destructor
		~Stack(){

			m_list.clear();
			m_top = -1;
		}

		/// Insert element
		/*!
		 * Add an element at the bottom of the Stack
		 * This function make push, adding an template data in the bottom of the Stack
		 *
		 * \param value Data that will be added to the bottom of the Stack
		 */
		void push(T value){

			m_list.push_back(value);
			m_top++;
		}

		/// Remove top element
		/*!
		 * This function remove the element on top of Stack, reducing its size by one.
		 * The element removed is the latest element inserted into the Stack.
		 */
		void pop(){

			if(isEmpty()){
				std::cout << "Stack Empty" << std::endl;
			}else{
				m_list.pop_back();
				m_top--;
			}
		}

		/// Acess next element
		/*!
		 *
		 * This function returns the lastest element inserted into the Stack
		 *
		 * \return A reference to the top element in the Stack
		 */
		T top(){
			return m_list.back();
		}

		bool isEmpty(){

			return m_top == -1;
		}
};

#endif
