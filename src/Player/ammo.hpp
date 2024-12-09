#pragma once

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/timer.hpp>
#include <godot_cpp/variant/node_path.hpp>

using namespace godot;

class Ammo : public Node2D {
	GDCLASS(Ammo, Node2D)

	NodePath timer_path{};
	Timer *timer{};

	float shot_angle{};
	int32_t speed{ 100 };

protected:
	static void _bind_methods();
	void _notification(int32_t what);

public:
	virtual void _process(double delta) override;
	virtual void _ready() override;

	void set_timer_path(NodePath path) { timer_path = path; }
	NodePath get_timer_path() { return timer_path; }

	void time_out();
	void set_direction(float dir);
	inline void set_speed(int32_t sp) { speed = sp; }
};
