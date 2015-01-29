//
//  ParticleController.h
//  Etang
//
//  Created by Yiwen on 09/07/2014.
//
//

#ifndef __Etang__ParticleController__
#define __Etang__ParticleController__

#include <iostream>
#include "Particle.h"
#include "GlobalSettings.h"

namespace etang {
    class ParticleController {
        public :
        ParticleController(int, GlobalSettings*);
        vector<Particle*>       getParticles();
        void                    update();
        
        
        private :
        int                     _numParticles;
        void                    _init();
        vector<Particle*>       _particles;
        GlobalSettings*         _settings;
    };
}


#endif /* defined(__Etang__ParticleController__) */
