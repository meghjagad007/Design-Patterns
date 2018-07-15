//Factory pattern 
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

//Interface
class Shapes {
public:
	virtual void draw()=0;
};

//Implementations
class Rectangle: public Shapes {
public:
	void draw() {
		cout << "Drawing a Rectangle"<<endl;
	}
};

class Circle : public Shapes {
public:
	void draw() {
		cout << "Drawing a Circle"<<endl;
	}
};

//Factory
class ShapeFactory {
public:
	static Shapes *getShape(string shapeType) {
		
		if (shapeType.compare("Circle")==0) {
			return new Circle();
		}
		else if (shapeType.compare("Rectangle")==0) {
			return new Rectangle();
		}
	
	}
	
};

int main() {

	ShapeFactory *shapeFactory = new ShapeFactory();
	
	Shapes *shape1 = shapeFactory->getShape("Rectangle");
	shape1->draw();
	Shapes *shape2 = shapeFactory->getShape("Circle");
	shape2->draw();
	cin.ignore();
	return 0;
}
