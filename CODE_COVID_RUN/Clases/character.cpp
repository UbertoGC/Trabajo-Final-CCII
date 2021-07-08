#include "character.h"

character::character()
{
	this->lifePoints = 0;
	this->level = 1;
	this->name = "character";
	this->dialog = "dialog";
	this->type = "type";
	this->desplaza = 2;
	this->mueve = 18;
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

void character::setDesplaza(int _desplaza){
	this->desplaza = _desplaza;
}

void character::setMueve(int _mueve){
	this->mueve = _mueve;
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

int character::getDesplaza()
{
	return desplaza;
}

int character::getMueve()
{
	return mueve;
}

void character::getInfo()
{
	cout << "ES UN PERSONAJE DE TIPO: " << this->getType() << endl;
	cout << "SE ENCUENTRA EN EL NIVEL: " << this->getLevel() << endl;
	cout << this->getName() << " TIENE " << this->getLifePoints() << " PUNTOS DE VIDA" << endl;
}
