#include <iostream>
#include <string>

#include "Fish.h"
#include "FishTank.h"

using namespace std;

Fish::Fish()
{
    img_hgt = 0;
	img_wid = 0;
	pos_vert = 0.0;
	pos_horz = 0.0;
	speed_vert = 0.0;
	speed_horz = 0.0;
	name = "";

	for (int i=0;i<MAX_HGT;i++){
		for (int j=0;j<MAX_WID;j++){
		    image[i][j] = ' ';
		}
	}
}

bool Fish::readFish()
{
	string test, line, blank_line;
	cin >> test;
	if (test != "fish") {
		return false;
	}

	cin >> img_hgt >> img_wid
	    >> pos_vert >> pos_horz
	    >> speed_vert >> speed_horz
	    >> name;
	getline(cin, blank_line);
	
	for (int i=0;i<img_hgt;i++){
	    getline(cin, line);
	    for (int j=0;j<img_wid;j++){
		if (j >= line.length())
		    image[i][j] = ' ';
		else
		    image[i][j] = line[j];
	    }
	}

	if ((cin.fail()) || (img_hgt < 0) || (img_hgt > MAX_HGT) ||
	    (img_wid < 0) || (img_wid > MAX_WID))
	    return false;
	return true;
}

string Fish::getName()
{
    	return name;
}

void Fish::setName(string new_name)
{
    	name = new_name;
}

void Fish::setHSpeed(float new_speed)
{
	speed_horz = new_speed;
} 

void Fish::setVSpeed(float new_speed)
{
	speed_vert = new_speed;
}

void Fish::setPos(int row, int col)
{
	pos_vert = row;
	pos_horz = col;
}

int Fish::getHeight()
{
    return img_hgt;
}

int Fish::getWidth()
{
    return img_wid;
}

void Fish::move(int tankHeight, int tankWidth)
{
    pos_vert += speed_vert;
    pos_horz += speed_horz;
}

void Fish::draw(FishTank *p_tank)
{
    int tHeight = p_tank->getHeight();
    
    for (int i=0;i<img_hgt;i++){
    	for (int j=0;j<img_wid;j++){

    	    if (pos_vert > 0 && pos_vert < tHeight)
	        	p_tank->UpdateAt(pos_vert,pos_horz,image[i][j]);
		}
	}
}
