//
//  GlobalSettings.h
//  EEtang
//
//  Created by Yiwen on 27/05/2014.
//
//

#ifndef __EEtang__GlobalSettings__
#define __EEtang__GlobalSettings__

#include <iostream>

using namespace ci;
using namespace std;

class GlobalSettings {
    public :
    static GlobalSettings& getInstance() {
        static GlobalSettings settings;
        return settings;
    };
    
    
    Vec2f pos;
    
    private :
    GlobalSettings() {};
};

#endif /* defined(__EEtang__GlobalSettings__) */
