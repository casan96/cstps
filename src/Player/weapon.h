#pragma once

#include <godot_cpp/classes/node2d.hpp>

using namespace godot;

class Weapon: public Node2D {
    GDCLASS(Weapon, Node2D)

    NodePath ammo_path{};
protected:
    static void _bind_methods();

public:
    virtual void _process(double delta) override;

    void set_ammo_path(NodePath path) { ammo_path = path; }
    NodePath get_ammo_path() { return ammo_path; }
};