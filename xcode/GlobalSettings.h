//
//  GlobalSettings.h
//  Etang
//
//  Created by Yiwen on 05/07/2014.
//
//

#ifndef __Etang__GlobalSettings__
#define __Etang__GlobalSettings__

#include <iostream>
#include "View.h"

using namespace std;
using namespace ci;

namespace etang {

    class GlobalSettings {
    public:
        GlobalSettings();
        
        int     numParticles    = 250;
        float   maxDistance     = 50.0f;
    private:
        void                    _init();
    };
}

#endif /* defined(__Etang__GlobalSettings__) */
