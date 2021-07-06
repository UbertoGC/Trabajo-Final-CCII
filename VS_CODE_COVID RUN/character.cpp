#include "character.h"

character::character()
{
	this->lifePoints = 0;
	this->level = 1;
	this->name = "character";
	this->dialog = "dialog";
	this->type = "type";
}

void character::setLifePoints(int _life)
{
	this->lifePoints = _life;
}

void character::setLevel(int _level)
{
	this->level = _level;
}

void character::setName(string _name)
{
	this->name = _name;
}

void character::setDialog(string _dialog)
{
	this->dialog = _dialog;
}

void character::setType(string _type) {
	this->type = _type;
}

int character::getLifePoints()
{
	return lifePoints;
}

int character::getLevel()
{
	return level;
}

string character::getName()
{
	return name;
}

string character::getDialog()
{
	return dialog;
}

string character::getType()
{
	return type;
}

void character::getInfo()
{
	cout << "ES UN PERSONAJE DE TIPO: " << this->getType() << endl;
	cout << "SE ENCUENTRA EN EL NIVEL: " << this->getLevel() << endl;
	cout << this->getName() << " TIENE " << this->getLifePoints() << " PUNTOS DE VIDA" << endl;
}
