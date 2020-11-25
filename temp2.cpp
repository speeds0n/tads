

template<class T>
class LinkedList{
	private:
		Node<T> *m_head;
		Node<T> *m_tail;
		int m_size;

	public:
		LinkedList(T data);
		~LinkedList();
		bool isEmpty();
		int size();
		void push_front(T data);
		void push_back(T data);
		T acess( int position);
		void remove(int position);
};



