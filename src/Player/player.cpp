#include "player.h"
#include "godot_cpp/classes/global_constants.hpp"
#include "weapon.h"

#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/classes/window.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

void Player::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_speed", "speed"), &Player::set_speed);
	ClassDB::bind_method(D_METHOD("get_speed"), &Player::get_speed);

	ADD_PROPERTY(PropertyInfo(Variant::INT, "speed"), "set_speed", "get_speed");

	ClassDB::bind_method(D_METHOD("set_gun", "path"), &Player::set_gun);
	ClassDB::bind_method(D_METHOD("get_gun"), &Player::get_gun);

	ADD_PROPERTY(PropertyInfo(Variant::NODE_PATH, "gun_node", PROPERTY_HINT_NODE_PATH_VALID_TYPES, "Weapon"), "set_gun", "get_gun");
}

void Player::_notification(int what) {
	if (what == NOTIFICATION_WM_WINDOW_FOCUS_OUT) {
		get_tree()->set_pause(true);
		Input::get_singleton()->set_mouse_mode(Input::MOUSE_MODE_VISIBLE);
	} else if (what == NOTIFICATION_WM_WINDOW_FOCUS_IN) {
		get_tree()->set_pause(false);
		Input::get_singleton()->set_mouse_mode(Input::MOUSE_MODE_CONFINED);
	}
}

void Player::_ready() {
	Input *input = Input::get_singleton();
	input->set_mouse_mode(Input::MOUSE_MODE_CONFINED);

	if (!gun.is_empty()) {
		gun_node = get_node<Weapon>(gun);
	}
}

void Player::_process(double delta) {
	auto m_pos = get_tree()->get_root()->get_mouse_position();

	Input *input = Input::get_singleton();

	Vector2 position{};
	position.x = input->get_axis("Left", "Right");
	position.y = input->get_axis("Up", "Down");
	
	if (input->is_action_pressed("exit")) {
		get_tree()->quit();
	}
	if (input->is_action_just_pressed("shot")) {
		gun_node->shoot(get_parent());
	}
	set_velocity(position * speed);
	move_and_slide();
}
