#include <iostream>
#include<vector>
using namespace std;
//Создать иерархию классов: абстрактный базовый класс Animal с чисто виртуальным методом speak()
// , его наследники - Frog, Dog и Cat. Все животные умеют издавать звуки (метод speak()),
//  но только кот умеет царапаться и мурлыкать. В main() необходимо создать массив указателей
//  на базовый класс и в цикле поочередно вызывать метод speak() для потомков. После этого нужно
//  сделать так, чтобы кот царапался (scratch) и мурлыкал (purr). Метод Scratch() принимает один
//  параметр типа bool (сделал ли хозяин уроки?). Если уроки сделаны, то кот не царапается, если
//  не сделаны, то царапается. Мурлычет кот без всяких условий.

class Animal
{
public:
	virtual void speak() const = 0;
	virtual ~Animal() {}
};

class Frog : public Animal {

public:
	void speak() const override{
		cout << "Frog - Qua qua" << endl;
	}
};

class Dog : public Animal
{
public:
	void speak() const override
	{
		cout << "Dog - Bow-wow" << endl;
	}
};

class Cat : public Animal {
public:
	void speak() const override {
		cout << "Cat - Meow meow" << endl;
	}
	void scratch(bool doHomeWork) {
		if (doHomeWork)
		{
			cout << "Cat - No sratches" << endl;
		}
		else
		{
			cout << "Cat - Sratches" << endl;
		}
	}
	void purr() {
		cout << "Cat - Purrs" << endl;
	}
};

int main()
{
	vector<Animal*> animals;
	animals.push_back(new Frog());
	animals.push_back(new Dog());
	animals.push_back(new Cat());

	for (const auto& animal : animals)
	{
		animal->speak();
	}

	Cat* cat = dynamic_cast<Cat*>(animals[2]);
	if (cat) {
		cat->scratch(false);
		cat->purr();
	}

	for (auto& animal : animals)
	{
		delete animal;
	}
	return 0;
}
