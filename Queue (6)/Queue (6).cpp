#include <iostream>
#include <vector>
using namespace std;



template<typename T> class Queue {
	vector<T> vec;

public:
	Queue(initializer_list<T> list) : vec(list) {}
		Queue() {};
		void printQ() const {
			if (vec.empty()) {
				cout << "Queue is empty!" << endl;
				return;
			}
			for (T val : vec) {
				cout << val << ' ';
			}
			cout << endl;
		}
		void removeElement() {
			if (vec.empty()) {
				cout << "Queue is empty!" << endl;
				return;
			}
			vec.erase(vec.begin());
		}
		void addElement(T num) {
			vec.push_back(num);
		}
		bool isEmpty() {
			return vec.empty();
		}
		T front() const {
			return vec.at(vec.begin());
		}
		T back() const {
			return vec.at(vec.end());
		}
};



int main() {

	Queue<int> q{1,2,3};

	q.printQ();

	q.addElement(37);

	q.printQ();

	q.removeElement();

	q.printQ();

	return 0;
}