//Singleton
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

class Singleton {
private:
	Singleton(){}
public:
	static Singleton& getInstance() {
		static Singleton theInstance;
		return theInstance;
	}
	void print() {
		cout << "This works!";
	}
};
int main() {
	Singleton& s = Singleton::getInstance();
	s.print();
	cin.ignore();
	return 0;
}

//Referred from https://stackoverflow.com/questions/43523509/simple-singleton-example-in-c