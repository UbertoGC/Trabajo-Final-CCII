#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "base_game_CR.h"
class character : public base_game_CR {
protected:
	int desplazamiento;
	int mueve;
	int lifePoints;
	int level;

	string name;
	string dialog;
	string type;
public:
	//CONSTRUCTOR
	character(int _initDesplaza = 2, int _initMueve = 18, int _initLife = 100, int _initLevel = 1, string _initName = "character",
		string _initDialog = "dialog", string _type = "type") : desplazamiento(_initDesplaza), mueve(_initMueve),
		lifePoints(_initLife), level(_initLevel), name(_initName), dialog(_initDialog), type(_initDialog) {}

	//SET ATRIBUTES
	void setName(string);
	void setDialog(string);
	void setType(string);
	void setDesplaza(int);
	void setMueve(int);
	void setLevel(int);

	//GET ATRIBUTES
	int getLifePoints();
	string getName();
	string getDialog();
	string getType();
	int getDesplaza();
	int getMueve();
	int getLevel();

	//FUNCTIONS
	void getInfo();
};

#endif