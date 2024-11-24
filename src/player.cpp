#include "player.h"

#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

void Player::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_speed", "speed"), &Player::set_speed);
    ClassDB::bind_method(D_METHOD("get_speed"), &Player::get_speed);

    ADD_PROPERTY(PropertyInfo(Variant::INT, "speed"), "set_speed", "get_speed");
}

void Player::_ready() {
}

void Player::_process(double delta) {

    Input *input = Input::get_singleton();

    Vector2 position{};
    position.x = input->get_axis("Left", "Right");
    position.y = input->get_axis("Up", "Down");

    set_velocity(position * speed);
    move_and_slide();
}
