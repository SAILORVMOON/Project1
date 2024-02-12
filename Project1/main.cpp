#include <SFML/Graphics.hpp>


class Node {
public:
	Node() {
		next = nullptr;
		prev = nullptr;
	}
	Node(std::string str) {
		value = str;
		next = nullptr;
		prev = nullptr;
	}
	~Node() {
		delete sh;
	}

	std::string getValue() {
		return value;
	}

	sf::Shape* sh;
	Node* next;
	Node* prev;
private:
	std::string value;
};

class LinkedList {
public:
	LinkedList() {
		first = nullptr;
		last = nullptr;
	}
	LinkedList(Node* n) {
		first = n;
		last = n;
		empty = false;
		counter = 1;
	}

	void add(Node* ins, int index) {
		if (index == 0) {
			addFirst(ins);
		} else if (index == counter) {
			addLast(ins);
		} else {
			Node* near = get(index);
			(*ins).next = near;
			(*ins).prev = (*near).prev;
			(*(*ins).prev).next = ins;
			(*(*ins).next).prev = ins;
			counter++;
		}
	}

	void addFirst(Node* ins) {
		if (counter == 0) {
			(*ins).prev = nullptr;
			(*ins).next = nullptr;
			first = ins;
			last = ins;
		} else {
			(*first).prev = ins;
			(*ins).next = first;
			first = ins;
		}
		counter++;
	}

	void addLast(Node* ins) {
		if (counter == 0) {
			(*ins).prev = nullptr;
			(*ins).next = nullptr;
			first = ins;
			last = ins;
		} else {
			(*last).next = ins;
			(*ins).prev = last;
			last = ins;
		}

		counter++;
	}

	void del(int index) {
		if (index == 0) {
			delFirst();
		} else if (index == counter - 1) {
			delLast();
		} else {
			Node* current = get(index);
			(*(*current).next).prev = (*current).prev;
			(*(*current).prev).next = (*current).next;
			delete current;
			counter--;
		}
	}

	void delFirst() {
		if (counter == 1) {
			last = nullptr;
			first = nullptr;
		} else {
			first = (*first).next;
			delete (*first).prev;
			(*first).prev = nullptr;
		}
		counter--;
	}

	void delLast() {
		if (counter == 1) {
			last = nullptr;
			first = nullptr;
		} else {
			last = (*last).prev;
			delete (*last).next;
			(*last).next = nullptr;
		}
		counter--;
	}

	Node* get(int i) {
		Node* n = first;
		for (int j = 0; j < i; j++) {
			n = (*n).next;
		}
		return n;
	}

	int getCounter() const {
		return counter;
	}

	

private:
	bool empty = true;
	int counter = 0;
	Node* first;
	Node* last;
};

//class Player {
//	sf::Shape* sh;
//	void m() {
//		(*sh).getSize();
//	}
//};



sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!", sf::Style::Default);

















int main() {
	
	window.setFramerateLimit(60);
	window.clear(sf::Color::Black);
}