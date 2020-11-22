#ifndef TAD_H
#define TAD_H

class Stack{

	private:
		int *m_list;
		int m_top;

	public:
		Stack();
			
		void push(int value);
		int pop();
		int top();
		bool isEmpty();
		bool isFull();

};

class Queue{

	private:
		int *m_list;
		int m_first;
		int m_last;
		int m_total;

	public:
		Queue();

		void insert(int value);
		int pop();
		bool isEmpty();
		bool isFull();
};

#endif
