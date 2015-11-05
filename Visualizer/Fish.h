#ifndef FISH_H
#define FISH_H

#include <string>
using std::string;

class FishTank;

class Fish {
	public:
		Fish();
		bool   readFish();
		string getName();
		void   setName(string new_name);
		void   setHSpeed(float new_speed);
		void   setVSpeed(float new_speed);
		void   setPos(int row, int col);
		int    getHeight();
		int    getWidth();
		void   move(int tankHeight, int tankWidth);
		void   draw(FishTank *p_tank);
	
	private:
		static const int MAX_HGT = 30;
        	static const int MAX_WID = 60;

		string name;
		int    img_hgt, img_wid;
		float  pos_horz, pos_vert;
		float  speed_horz, speed_vert;
		char   image[MAX_HGT][MAX_WID];
};

#endif
