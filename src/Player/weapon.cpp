#include "weapon.h"
#include "ammo.hpp"
#include "godot_cpp/classes/global_constants.hpp"
#include "godot_cpp/classes/node.hpp"
#include "godot_cpp/classes/node2d.hpp"
#include "godot_cpp/classes/object.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/core/object.hpp"
#include "godot_cpp/variant/vector2.hpp"

#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/classes/window.hpp>

void Weapon::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_ammo_path", "path"), &Weapon::set_ammo_path);
	ClassDB::bind_method(D_METHOD("get_ammo_path"), &Weapon::get_ammo_path);

	ADD_PROPERTY(PropertyInfo(Variant::NODE_PATH, "ammo_path_node", godot::PROPERTY_HINT_NODE_PATH_VALID_TYPES, "Node2D"), "set_ammo_path", "get_ammo_path");

	ClassDB::bind_method(D_METHOD("set_ammo_scene", "path"), &Weapon::set_ammo_scene);
	ClassDB::bind_method(D_METHOD("get_ammo_scene"), &Weapon::get_ammo_scene);

	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "ammo_scene", godot::PROPERTY_HINT_RESOURCE_TYPE, "PackedScene"), "set_ammo_scene", "get_ammo_scene");

	ClassDB::bind_method(D_METHOD("set_ammo_speed", "sp"), &Weapon::set_ammo_speed);
	ClassDB::bind_method(D_METHOD("get_ammo_speed"), &Weapon::get_ammo_speed);

	ADD_PROPERTY(PropertyInfo(Variant::INT, "ammo_speed"), "set_ammo_speed", "get_ammo_speed");
}

void Weapon::_process(double delta) {
	auto pos = get_global_mouse_position();
	look_at(pos);
}

void Weapon::_ready() {
	if (!ammo_path.is_empty()) {
		ammo_spawn_point = get_node<Node2D>(ammo_path);
	}
}

void Weapon::shoot(Node *spawn) {
	if (ammo_scene->can_instantiate() && ammo_spawn_point) {
		Ammo *bullet = Object::cast_to<Ammo>(ammo_scene->instantiate());
		Vector2 s_pos = ammo_spawn_point->get_global_position();
		bullet->set_direction(get_global_position().angle_to_point(s_pos));
		bullet->set_global_position(s_pos);
		bullet->set_speed(ammo_speed);
		spawn->add_child(bullet);
	}
}
