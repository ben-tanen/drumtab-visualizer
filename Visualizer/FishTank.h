#ifndef FISHTANK_H
#define FISHTANK_H

#include <string>
using std::string;

class FishTank {
	public:
		FishTank();
		FishTank(int hgt, int wid);
		void setHeight(int hgt);
		void setWidth(int wid);
		int  getHeight();
		int  getWidth();
		int  getMaxFish();
		int  getNumFish();
		bool addFish(Fish f);
		void clearTank();
		void showTank();
		void UpdateAt(int row, int col, char newChar);
		void simulate(bool singleStep, int fps);
	
	private:
		static const int  MAX_FISH = 500;
		static const int  MAX_HGT = 50;
		static const int  MAX_WID = 200;
		
		int height, width;
		int num_fish;
		Fish fish_holder[MAX_FISH];
		char tank_image[MAX_HGT][MAX_WID];
		void clear_screen();
		void home_cursor();
};

#endif
