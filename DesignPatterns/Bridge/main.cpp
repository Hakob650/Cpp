#include <iostream>
#include <memory>

#include "include/TV.hpp"
#include "include/Radio.hpp"
#include "include/RemoteControl.hpp"
#include "include/AdvancedRemoteControl.hpp"

int main() 
{
    auto tv = std::make_shared<TV>();
    auto radio = std::make_shared<Radio>();

    RemoteControl simpleTVRemote(tv);
    simpleTVRemote.toggle_power();
    simpleTVRemote.volume_up();

    AdvancedRemoteControl advancedTVRemote(tv);
    advancedTVRemote.mute();

    AdvancedRemoteControl advancedRadioRemote(radio);
    advancedRadioRemote.toggle_power();
    advancedRadioRemote.volume_up();
    advancedRadioRemote.mute();

    return 0;
}
