//Factory pattern 
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

class Coffee {
public:
	virtual string Name() = 0;
};

class Tea {
public:
	virtual string Name() = 0;
};

//Coffee Concrete products
class Latte : public Coffee {
public:
	string Name() {
		return "Making Latte";
	}
};
class Mocha : public Coffee {
	string Name() {
		return "Making Mocha";
	}
};

//Tea Concrete Products
class Chamomile : public Tea {
	string Name() {
		return "Making Chamomile";
	}
};
class Oolong : public Tea {
	string Name() {
		return "Making Oolong";
	}
};


class AbstractFactory {
public:
	enum Dict {
		Starbucks,
		McDonalds
	};
	virtual Coffee* getLatte() = 0;
	virtual Coffee* getMocha() = 0;
	virtual Tea* getOolong() = 0;
	virtual Tea* getChamomile() = 0;
	static AbstractFactory* CreateFactory(Dict factory);
};
class StarbucksFactory : public AbstractFactory {
public:
	Coffee * getLatte() {
	
		return new Latte();
	}
	Coffee * getMocha() {
		
		return new Mocha();
	}
	Tea* getOolong() {
	
		return new Oolong();
	}
	Tea* getChamomile() {
		
		return new Chamomile();
	}
};
class McDonaldsFactory : public AbstractFactory {
public:
	Coffee * getLatte() {
	
		return new Latte();
	}
	Coffee * getMocha() {
		
		return new Mocha();
	}
	Tea* getOolong() {
		
		return new Oolong();
	}
	Tea* getChamomile() {
	
		return new Chamomile();
	}
};
AbstractFactory* AbstractFactory::CreateFactory(Dict factory) {
	if (factory == Dict::Starbucks) {
		return new StarbucksFactory();
	}
	else if (factory == Dict::McDonalds) {
		return new McDonaldsFactory();
	}
}


int main() {
	cout << "Get Latte from Starbucks: \n" << endl;
	AbstractFactory *factory = AbstractFactory::CreateFactory(AbstractFactory::Dict::Starbucks);
	cout << "Going to Starbucks" << endl;
	cout<< factory->getLatte()->Name() << endl;
	delete factory->getLatte();

	cin.ignore();
	return 0;
}


//Output
/*
Get Latte from Starbucks:

Going to Starbucks
Making Latte

*/