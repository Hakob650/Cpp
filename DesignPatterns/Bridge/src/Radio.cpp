#include <algorithm>
#include "../include/Radio.hpp"

bool Radio::is_enabled() const { return on; }

void Radio::enable() { on = true; }

void Radio::disable() { on = false; }

int Radio::get_volume() const { return volume; }

void Radio::set_volume(int volume_) { std::clamp(volume_, 0, 100); }

std::string Radio::get_name() const { return "Radio"; }