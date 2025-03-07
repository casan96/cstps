#pragma once

#include <godot_cpp/classes/area2d.hpp>
#include <godot_cpp/classes/timer.hpp>
#include <godot_cpp/variant/node_path.hpp>

using namespace godot;

class Ammo : public Area2D {
	GDCLASS(Ammo, Area2D)

	NodePath timer_path{};
	Timer *timer{};

	float shot_angle{};
	int32_t speed{ 100 };

	NodePath collision{};

protected:
	static void _bind_methods();

public:
	virtual void _process(double delta) override;
	virtual void _ready() override;

	void set_timer_path(NodePath path) { timer_path = path; }
	NodePath get_timer_path() { return timer_path; }

	void set_collision_path(NodePath path) { collision = path; }
	NodePath get_collision_path() { return collision; }

	void time_out();
	void on_body_enter(Node2D *body);
	void set_direction(float dir);
	inline void set_speed(int32_t sp) { speed = sp; }
};
