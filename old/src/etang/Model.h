//
//  Model.h
//  Etang
//
//  Created by Yiwen on 05/07/2014.
//
//

#ifndef __Etang__Model__
#define __Etang__Model__

#include <iostream>
#include "GlobalSettings.h"
#include "ParticleController.h"

namespace etang {
    
    class Model {
        public :
        static Model& getInstance() {
            static Model settings;
            return settings;
        };
        
        GlobalSettings*         settings;
        ParticleController*     controller;
        
        
        private :
        Model() {
            _init();
        };
        void                    _init();
    };
}


#endif /* defined(__Etang__Model__) */
