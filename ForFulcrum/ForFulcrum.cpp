#include "pch.h"
#include <iostream>
#include <string>


class Unit { //Абстрактный класс персонажа

public:
	void setHp(int hp) { this->hitPoints = hp; } // сеттер хп
	int getHp() { return this->hitPoints; } //геттер хп
	std::string getType() { return this->type; } //геттер типа персонажа
	virtual void baseAttack(Unit *target) = 0; //базовая атака
	void showHp() { std::cout << "Current " << getType() << " health " << getHp() << std::endl; } //выводим хп
protected:
	std::string type; //тип персонажа
	int hitPoints; //здоровье
	
};
class Warrior :public Unit { //Класс воина
public:

	Warrior() {
		type = "Warrior";
		hitPoints = 200;
		std::cout << "Warrior has been created" << std::endl;
	}

	~Warrior() {};

	void baseAttack(Unit *target){
		target->setHp(target->getHp() - 50);
		std::cout << "Warrior has dealed 50 damage to " << target->getType() << std::endl;
	}
};

class Mage :public Unit { //Класс мага

public:
	Mage() {
		type = "Mage";
		hitPoints = 130;
		std::cout << "Mage has been created" << std::endl;
	}
	~Mage() {};

	void baseAttack(Unit *target) override{
		target->setHp(target->getHp() - 80);
		std::cout << "Mage has dealed 80 damage to " << target->getType() << std::endl;

	}

	void swapHp(Unit *target) {
		int tmp = target->getHp();
		target->setHp(this->getHp());
		this->setHp(tmp);		
		std::cout << "Mage has swapped health with " << target->getType() << std::endl;
	}
};
int main()
{
	Warrior Groot;
	Mage Necr;
	Groot.baseAttack(&Necr);
	Necr.showHp();
	Necr.baseAttack(&Groot);
	Groot.showHp();
	Necr.swapHp(&Groot);
	Necr.showHp();
	Groot.showHp();
}

