#pragma once
#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/rigid_body2d.hpp>

using namespace godot;
class Player : public CharacterBody2D {
	GDCLASS(Player, CharacterBody2D)

	int speed{100};

	NodePath gun{};
protected:
	static void _bind_methods();
	void _notification(int what);

public:
	virtual void _ready() override;
	virtual void _process(double delta) override;

	void set_speed(int p_speed) { speed = p_speed; }
	int get_speed() { return speed; }

	void set_gun(NodePath path) { gun = path; }
	NodePath get_gun() { return gun; }
};
