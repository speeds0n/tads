#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <vector>
template <class T>
class Queue{

	private:
		std::vector<T> m_list; //!< Queue data list.
		int m_front; //!< Count to the first element in the Queue.
		int m_back; //!< Count to the last element in the Queue.
		int m_total; //!< Number of element in the Queue.

	public:
		/// Default Constructor
		Queue(int first = 0, int last = 0, int total = 0)
		: m_front{first}, m_back{last}, m_total{total}
		{ /* Empty */ }

		/// Default Destructor
		~Queue(){
			m_list.clear();
			m_front = 0;
			m_back = 0;
			m_total = 0;
		}

		void insert(T value){
			m_list.assign(1, value);
		}
};

#endif
