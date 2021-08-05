#include "base_game_CR.h"

base_game_CR::base_game_CR() {
	gameName = "COVID RUN GAME";
	gameVersion = 1.0;
	gameContacto = "ehuallap@unsa.edu.pe";
}

string base_game_CR::getName() {
	return gameName;
}

string base_game_CR::getContacto() {
	return gameContacto;
}

float base_game_CR::getVersion() {
	return gameVersion;
}

void base_game_CR::getInfoGame() {
	cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "EL VIDEOJUEGO " << this->getName() << " FUE DESARROLLADO POR UN GRUPO DE ESTUDIANTES DE LA UNIVERSIDAD NACIONAL DE SAN AGUSTIN" << endl;
	cout << "EL JUEGO SE ENCUENTRA EN SU VERSION: " << this->getVersion() << endl;
	cout << "PARA MAS INFORMACIÓN ESCIBRIR A " << this->getContacto() << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
}
