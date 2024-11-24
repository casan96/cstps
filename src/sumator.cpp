
#include "sumator.h"
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

void Sumator::_bind_methods() {
	ClassDB::bind_method(D_METHOD("add", "value"), &Sumator::add);
	ClassDB::bind_method(D_METHOD("reset"), &Sumator::reset);
	ClassDB::bind_method(D_METHOD("get_count"), &Sumator::get_count);
	ClassDB::bind_method(D_METHOD("set_count", "value"), &Sumator::set_count);

	ClassDB::bind_method(D_METHOD("get_node"), &Sumator::get_node);
	ClassDB::bind_method(D_METHOD("set_node", "value"), &Sumator::set_node);

	ADD_PROPERTY(PropertyInfo(Variant::INT, "count"), "set_count", "get_count");
	ADD_PROPERTY(PropertyInfo(Variant::NODE_PATH, "nodo", PROPERTY_HINT_NODE_PATH_TO_EDITED_NODE, "Node"), "set_node", "get_node");
}

void Sumator::_ready() {
	UtilityFunctions::print("runtime");
}

void Sumator::add(int p_value) {
	count += p_value;
}

void Sumator::reset() {
	count = 0;
}

int Sumator::get_count() {
	return count;
}

void Sumator::set_count(int p_value) {
	count = p_value;
}
