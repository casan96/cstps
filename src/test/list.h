#pragma once

#include <godot_cpp/classes/node2d.hpp>

using namespace godot;

class Lista : public Node2D {
    GDCLASS(Lista, Node2D)

protected:
    static void _bind_methods();
};
