#include <algorithm>
#include "../include/TV.hpp"

bool TV::is_enabled() const { return on; }

void TV::enable() { on = true; }

void TV::disable() { on = false; }

int TV::get_volume() const { return volume; }

void TV::set_volume(int volume_) { std::clamp(volume_, 0, 100); }

std::string TV::get_name() const { return "TV"; }