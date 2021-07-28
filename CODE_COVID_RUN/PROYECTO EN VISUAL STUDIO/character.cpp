#include "character.h"

void character::setLifePoints(int _life) {
	lifePoints = _life;
}

void character::setLevel(int _level) {
	level = _level;
}

void character::setName(string _name) {
	name = _name;
}

void character::setDialog(string _dialog) {
	dialog = _dialog;
}

void character::setType(string _type) {
	type = _type;
}

void character::setDesplaza(int _desplaza) {
	desplazamiento = _desplaza;
}

void character::setMueve(int _mueve) {
	mueve = _mueve;
}

int character::getLifePoints() {
	return lifePoints;
}

int character::getLevel() {
	return level;
}

string character::getName() {
	return name;
}

string character::getDialog() {
	return dialog;
}

string character::getType() {
	return type;
}

int character::getDesplaza() {
	return desplazamiento;
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