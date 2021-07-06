#ifndef __CHARACTER_H__
#define __CHARACTER_H__

//CLASE HEREDADORA
#include "covid_run_game.h"

class character : public covid_run_game
{
protected:
	int lifePoints;
	int level;
	string name;
	string dialog;
	string type;
public:
	//CONSTRUCTOR
	character();

	//SET ATRIBUTES
	void setLifePoints(int);
	void setLevel(int);
	void setName(string);
	void setDialog(string);
	void setType(string);

	//GET ATRIBUTES
	int getLifePoints();
	int getLevel();
	string getName();
	string getDialog();
	string getType();

	//GET INFO
	void getInfo();
};

#endif
