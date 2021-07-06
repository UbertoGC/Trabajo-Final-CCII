#include "covid_run_game.h"

covid_run_game::covid_run_game()
{
	this->gameName = "COVID RUN GAME";
	this->gameVersion = 1.0;
	this->gameContacto = "ehuallap@unsa.edu.pe";
}
string covid_run_game::getName(){
	return gameName;
}
string covid_run_game::getContacto() {
	return gameContacto;
}
float covid_run_game::getVersion() {
	return gameVersion;
}
void covid_run_game::getInfoGame() {
	cout << "----------------------------------------------------------" << endl;
	cout << "EL VIDEOJUEGO " << this->getName() << " FUE DESARROLLADO POR UN GRUPO DE ESTUDIANTES DE LA UNIVERSIDAD NACIONAL DE SAN AGUSTIN" << endl;
	cout << "EL JUEGO SE ENCUENTRA EN SU VERSION: " << this->getVersion() << endl;
	cout << "PARA MAS INFORMACIÓN VISITAR ESCIBRIR A " << this->getContacto() << endl;
	cout << "----------------------------------------------------------" << endl;
}
