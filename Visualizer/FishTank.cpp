#include <iostream>
#include <unistd.h>
#include <stdlib.h>

#include "Fish.h"
#include "FishTank.h"

using namespace std;

FishTank::FishTank()
{
	height = 0;
	width = 0;
	num_fish = 0;
	
	for (int i=0;i<MAX_HGT;i++){
	    for (int j=0;j<MAX_WID;j++){
		tank_image[i][j] = ' ';
	    }
	}
}

FishTank::FishTank(int hgt, int wid)
{
	if (hgt < MAX_HGT && hgt > 0 &&
	    wid < MAX_WID && wid > 0){
	    height = hgt;
	    width = wid;
	    num_fish = 0;
	    
	    for (int i=0;i<MAX_HGT;i++){
		for (int j=0;j<MAX_WID;j++){
		    tank_image[i][j] = ' ';
		}
	    }
	}
  
}

void FishTank::setHeight(int hgt)
{
	height = hgt;
}

void FishTank::setWidth(int wid)
{
	width = wid;
}

int  FishTank::getHeight()
{
	return height;
}

int  FishTank::getWidth()
{
	return width;
}

int  FishTank::getMaxFish()
{
	return MAX_FISH;
}

int  FishTank::getNumFish()
{
	return num_fish;
}

bool FishTank::addFish(Fish f)
{
	if (num_fish == MAX_FISH){
	    return false;
	}
	fish_holder[num_fish] = f;
	num_fish++;
	return true;
}

void FishTank::clearTank()
{
	for (int i=0;i<MAX_HGT;i++){
	    for (int j=0;j<MAX_WID;j++){
			if (i == height - 3)
				tank_image[i][j] = '=';
			else
				tank_image[i][j] = ' ';
	    }
	} 
}

void FishTank::showTank()
{
	for (int i=0;i<height;i++){
	    if (i==0){
	    	for (int j=0;j<width+2;j++){
	    		cout << "=";
	    	}
	    	cout << endl;
	    }
	   	cout << "|";
	    
	    for (int j=0;j<width;j++){
			cout << tank_image[i][j];
	    }
	    cout << "|" << endl;
	    if (i == height - 1){
	    	for (int j=0;j<width+1;j++){
	    		if (j == 3)
	    			cout << "B";
	    		if (j == 8)
	    			cout << "S";
	    		if (j == 13)
	    			cout << "HH";
	    		if (j == 18)
	    			cout << "R";
	    		else
	    			cout << "=";
	    	}
	    	
	    	cout << endl;
	    }
	} 
}

void FishTank::UpdateAt(int row, int col, char newChar)
{
	tank_image[row][col] = newChar;
}

void FishTank::simulate(bool singleStep, int fps)
{
	clear_screen();
	while (1){
	    home_cursor();
	    clearTank();
	    for (int j=0;j < num_fish; j++){
		fish_holder[j].move(height, width);
		fish_holder[j].draw(this);
	    }
	    showTank();
	    home_cursor();
	    cout.flush();
	    if (singleStep) {
		if (system("read x < /dev/tty") != 0)
                exit(0);
	    } else {
		usleep(fps);
	    }
	}
}

void FishTank::clear_screen()
{
	cout << "\033[2J";
}

void FishTank::home_cursor()
{
	cout << "\33[H";
}


