#include <iostream>
#include <vector>
using namespace std;

template<typename T> T sumVec(vector<T> vec);
template<typename T> int VectorElementCount(vector<T> vec);
template<typename T> T MaxInVector(vector<T> vec);
template<typename T> int RecBinarySearch(const vector<T> vec, T target, int left, int right);

int main() {
	vector<double> myVec = { 1.1, 2.2, 3.3, 4.4 };
	cout << RecBinarySearch(myVec, 3.3, 0, myVec.size()-1);

	return 0;
}

// 4.1
template<typename T> T sumVec(vector<T> vec) {
	static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
	
	if (vec.empty()) {
		return 0;
	}
	T first = vec[0];
	vec.erase(vec.begin());
	return first + sumVec(vec);
}

// 4.2
template<typename T> int VectorElementCount(vector<T> vec) {
	if (vec.empty()) {
		return 0;
	}

	if (vec.size() == 1) {
		return 1;
	}
	vec.erase(vec.begin());
	return 1 + VectorElementCount(vec);
}


// 4.3
template<typename T> T MaxInVector(vector<T> vec) {
	static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
	
	if (vec.empty()) {
		cout << "Vector is empty!\n";
		return -1;
	}

	if (vec.size() == 1) {
		return vec[0];
	}

	T maxelem = vec[0];
	vec.erase(vec.begin());
	T newMax = MaxInVector(vec);

	return max(maxelem, newMax);
}

// 4.4
template<typename T> int RecBinarySearch(const vector<T> vec, T target, int left, int right) {
	static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
	
	if (vec.empty()) {
		return -1;
	}

	if (left > right) {
		return -1;
	}

	int mid = (left + right) / 2;

	if (vec[mid] == target) {
		return mid;
	}

	if (vec[mid] < target) {
		return RecBinarySearch(vec, target, mid + 1, right);
	}
	else if (vec[mid] > target)
	{
		return RecBinarySearch(vec, target, left, mid - 1);
	}
	return -1;
}