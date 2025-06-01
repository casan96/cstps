#pragma once

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/packed_scene.hpp>

using namespace godot;

class Weapon : public Node2D {
	GDCLASS(Weapon, Node2D)

	NodePath ammo_path{};
	Ref<PackedScene> ammo_scene{};
	Node2D *ammo_spawn_point{};
	int32_t ammo_speed{ 1000 };

protected:
	static void _bind_methods();

public:
	virtual void _process(double delta) override;
	virtual void _ready() override;

	void set_ammo_path(NodePath path) { ammo_path = path; }
	NodePath get_ammo_path() { return ammo_path; }

	void set_ammo_scene(Ref<PackedScene> ps) { ammo_scene = ps; }
	Ref<PackedScene> get_ammo_scene() { return ammo_scene; }

	void set_ammo_speed(int32_t sp) { ammo_speed = sp; }
	int32_t get_ammo_speed() { return ammo_speed; }

	void shoot(Node *spawn);
};
