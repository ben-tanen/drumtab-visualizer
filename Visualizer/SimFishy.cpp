#include <iostream>
#include "Fish.h"
#include "FishTank.h"

using namespace std;

const bool singleStep = false;
const int  fps = 31250;

int main()
{
    string tank_test;
    int    tank_height, tank_width;
    cin >> tank_test >> tank_height >> tank_width;
    
    if (tank_test != "tank"){
	return 1;
    }
  
    Fish fishy;
    FishTank tanky(tank_height, tank_width);
    
    while(fishy.readFish()){
	tanky.addFish(fishy);
	fishy.draw(&tanky);
    }
    
    tanky.simulate(singleStep, fps);
    return 0;
}
