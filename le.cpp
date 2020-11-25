#include <iostream>

class Node{
	private:
		int m_data;
		Node *m_next;

	public:
		Node(int data){
			this->m_data = data;
			this->m_next = NULL;
		}

		int getData(){ return m_data; }
		Node* getNext(){ return m_next; }
		void setNext(Node* next){ m_next = next; }
};

class List{

	private:
		Node* m_head;
		Node* m_tail;

	public:
		List(){
			m_head = NULL;
			m_tail = NULL;
		}
		List(int data){
			m_head = new Node(data);
			m_tail = m_head;
		}
		~List(){
			delete m_head;
		}
		void print(){
			Node* temp = m_head;
			if(isEmpty()){
				std::cout << "A lista não possue elementos!" << std::endl;
			}else{
				std::cout << "Printing all elements..." << std::endl;
				while(temp){
					std::cout << temp->getData() << std::endl;
					temp = temp->getNext();
				}
			}

		}
		void insert(int data){
			Node* newNode = new Node(data);
			newNode->setNext(m_head);
			m_head = newNode;
		}
		void push_back(int data){
			Node* newNode = new Node(data);
			if(isEmpty()){
				m_head = newNode;
				m_tail = newNode;
			}else{
				m_tail->setNext(newNode);
				m_tail = newNode;
			}
		}
		bool isEmpty(){
			return m_head == NULL;
		}
		int size(){
			if(isEmpty()){
				return 0;
			}

			Node* temp = m_head;
			int tam = 0;

			do{
				temp = temp->getNext();
				tam++;
			}while(temp);

			return tam;
		}
		bool existe(int value){
			Node* temp = m_head;
			while(temp){
				if(temp->getData() == value){
					return true;
				}
				temp = temp->getNext();
			}
			return false;
		}
		void pop_back(){
			if(!isEmpty()){
				if(m_head->getNext() == NULL){
					m_head = NULL;
				}else if(m_head->getNext()->getNext() == NULL){
					m_head->setNext(NULL);
				}else{
					Node* ant_ant = m_head;
					Node* ant = m_head->getNext();
					Node* corrente = m_head->getNext()->getNext();

					while(corrente){
						Node* aux = ant;
						ant = corrente;
						ant_ant = aux;
						corrente = corrente->getNext();
					}
					delete ant_ant->getNext();
					ant_ant->setNext(NULL);
					m_tail = ant_ant;
				}
			}
		}
};

int main(){

	List a;
	std::cout << "size: " << a.size() << std::endl;
	a.print();

	List l;
	if(l.isEmpty()){
		std::cout << "Lista Vazia!" << std::endl;
	}else{
		std::cout << "Lista NÃO vazia!" << std::endl;
	}
	l.print();

	if(l.existe(10)){
		std::cout << "elemento encontrado!" << std::endl;
	}else{
		std::cout << "Elemento nao encontrado!" << std::endl;
	}

	std::cout << "Tamanho da lista:" << l.size() << std::endl;
//	l.push_back(10);
//	l.push_back(20);
//	l.push_back(30);
	l.insert(50);
	l.push_back(30);
	l.print();

	if(l.isEmpty()){
		std::cout << "Lista Vazia!" << std::endl;
	}else{
		std::cout << "Lista NÃO vazia!" << std::endl;
	}
	if(l.existe(10)){
		std::cout << "elemento encontrado!" << std::endl;
	}else{
		std::cout << "Elemento nao encontrado!" << std::endl;
	}
	std::cout << "Tamanho da lista:" << l.size() << std::endl;

	l.pop_back();
	l.print();

	std::cout << "Tamanho da lista:" << l.size() << std::endl;

	return 0;
}
