#pragma once

#include <godot_cpp/classes/node2d.hpp>

using namespace godot;

class Weapon: public Node2D {
    GDCLASS(Weapon, Node2D)

    protected:
    static void _bind_methods();
};