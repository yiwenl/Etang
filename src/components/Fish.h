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

using namespace std;
using namespace cinder;
using namespace ci::app;

class Fish {
public :
    Fish();
    Fish(Vec3f);
    
    
    void            update();
    
    Vec3f           location;
    Vec3f           velocity;
    Vec3f           acceleration;
    float           mass = 1.0;
    float           maxSpeed = 10;
    float           maxForce = 3;
    float           arriveThreshold = 100;
    
    
    
    //              BEHAVIORS
    void            seek(Vec3f);
    void            arrive(Vec3f);
    
    
private :
    void            _bounce();
};

#endif /* defined(__EEtang__Fish__) */
