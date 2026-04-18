#ifndef USERCONFIG_HPP
#define USERCONFIG_HPP

class UserConfig {
private:
    bool looping;
    // Load Default Key Config

public:
    UserConfig();
    bool getLoopStatus();
    void setLoopStatus();
}


#endif