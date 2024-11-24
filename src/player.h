#pragma once
#include <godot_cpp/classes/character_body2d.hpp>

using namespace godot;

class Player : public CharacterBody2D {
	GDCLASS(Player, CharacterBody2D)

	int speed{100};
protected:
	static void _bind_methods();

public:
	virtual void _ready() override;
	virtual void _process(double delta) override;

	void set_speed(int p_speed) { speed = p_speed; }

	int get_speed() { return speed; }
};
