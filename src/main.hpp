#pragma once

#include <godot_cpp/classes/node2D.hpp>

using namespace godot;

class Main : public Node2D {
	GDCLASS(Main, Node2D)

protected:
	static void _bind_methods();
};
