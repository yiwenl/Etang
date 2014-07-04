//
//  FishController.cpp
//  EEtang
//
//  Created by Yiwen on 03/06/2014.
//
//

#include "FishController.h"
#include "GlobalSettings.h"
#include "MathUtils.h"
using namespace bongiovi::utils;

FishController::FishController() {
    _init();
}

void FishController::_init() {
    int numFishes = 10;
    _fishes.clear();
    _fishes.empty();
    Vec3f loc;
    
    for(int i=0; i<numFishes; i++) {
        loc.x               = MathUtils::random(getWindowWidth());
        loc.y               = MathUtils::random(getWindowHeight());
        Fish* f             = new Fish(loc);
        f->mass             = MathUtils::random(30, 20);
        f->velocity.x       = MathUtils::random(-1, 1);
        f->velocity.y       = MathUtils::random(-1, 1);
        _fishes.push_back(f);
        
        cout << f->location << endl;
    }
}


void FishController::update() {
    Vec3f center(GlobalSettings::getInstance().pos, 0.0);
    vector<Fish*>::iterator it;
    for( it = _fishes.begin() ; it!= _fishes.end(); it++) {
        if(GlobalSettings::getInstance().isMouseDown){
            (*it)->flock(_fishes);
            (*it)->arrive(center);
        }
        else (*it)->wonder();
        (*it)->update();
    }
}


vector<Fish*> FishController::getFishes() {
    return _fishes;
}
