#pragma once

#include <godot_cpp/classes/node.hpp>

using namespace godot;

class Sumator : public Node {
	GDCLASS(Sumator, Node)

	int count{};
	NodePath nodo{};

protected:
	static void _bind_methods();

public:
	virtual void _ready() override;
	void add(int p_value);
	void reset();
	int get_count();

	void set_count(int p_value);

	NodePath get_node() { return nodo; }
	void set_node(NodePath value) { nodo = value; }
};