#include "UserConfig.hpp"

// TODO: Decide further User Configuration Options

class UserConfig {
    UserConfig::UserConfig() : looping(false) {}
    bool UserConfig::getLoopStatus() {
        return this->looping;
    }
    void UserConfig::setLoopStatus(bool input) {
        this->looping = input;
    }
}
