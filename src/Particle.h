//
//  Particle.h
//  Etang
//
//  Created by Yiwen on 05/07/2014.
//
//

#ifndef __Etang__Particle__
#define __Etang__Particle__

#include <iostream>

using namespace std;
using namespace ci;

namespace etang {
    class Particle {
        public :
        Particle();
        Particle(float, float, float);
        
        Vec3f               location;
        Vec3f               velocity;
        Vec3f               acceleration;
        
        void                update(vector<Particle*>);
        
        private :
        void                _pullToCenter();
    };
}


#endif /* defined(__Etang__Particle__) */
