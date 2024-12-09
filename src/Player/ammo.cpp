#include "ammo.hpp"
#include "godot_cpp/variant/callable_method_pointer.hpp"
#include "godot_cpp/variant/vector2.hpp"

#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/core/class_db.hpp>

#include <godot_cpp/variant/utility_functions.hpp>

void Ammo::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_timer_path", "path"), &Ammo::set_timer_path);
	ClassDB::bind_method(D_METHOD("get_timer_path"), &Ammo::get_timer_path);

	ADD_PROPERTY(PropertyInfo(Variant::NODE_PATH, "timer", godot::PROPERTY_HINT_NODE_PATH_VALID_TYPES, "Timer"), "set_timer_path", "get_timer_path");
}

void Ammo::_notification(int32_t what) {
	switch (what) {
		default:
			break;
	}
}

void Ammo::_process(double delta) {
	Vector2 pos = get_global_position();
	set_global_position(Vector2(pos.x + UtilityFunctions::cos(shot_angle) * speed * delta, pos.y + UtilityFunctions::sin(shot_angle) * speed * delta));
}

void Ammo::_ready() {
	if (!timer_path.is_empty()) {
		timer = get_node<Timer>(timer_path);
		if (timer) {
			timer->connect("timeout", callable_mp(this, &Ammo::time_out));
			timer->start();
		}
	}
}

void Ammo::time_out() {
	queue_free();
}

void Ammo::set_direction(float dir) {
	shot_angle = dir;
}
