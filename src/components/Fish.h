//
//  Fish.h
//  EEtang
//
//  Created by Yiwen on 03/06/2014.
//
//

#ifndef __EEtang__Fish__
#define __EEtang__Fish__

#include <iostream>
#include "cinder/Perlin.h"

using namespace std;
using namespace cinder;
using namespace ci::app;

class Fish {
public :
    Fish();
    Fish(Vec3f);
    
    
    void            update();
    
    Vec3f           location;
    Vec3f           preLocation;
    Vec3f           velocity;
    Vec3f           acceleration;
    float           mass = 1.0;
    float           maxSpeed = 5;
    float           maxForce = 2;
    float           arriveThreshold = 100;
    float           inSightDist = 200;
    float           tooCloseDist = 15;
    float           rotation;
    
    
    
    //              BEHAVIORS
    void            seek(Vec3f);
    void            arrive(Vec3f);
    void            flee(Vec3f);
    void            flock(vector<Fish*>);
    void            wonder();
    bool            tooClose(Fish*);
    bool            inSight(Fish*);
    
    
private :
    void            _bounce();
    Perlin          _perlin;
};

#endif /* defined(__EEtang__Fish__) */
