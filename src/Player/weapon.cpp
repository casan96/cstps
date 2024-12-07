#include "weapon.h"

#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/classes/window.hpp>

void Weapon::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_ammo_path", "path"), &Weapon::set_ammo_path);
    ClassDB::bind_method(D_METHOD("get_ammo_path"), &Weapon::get_ammo_path);

    ADD_PROPERTY(PropertyInfo(Variant::NODE_PATH, "ammo_path_node", PROPERTY_HINT_NODE_PATH_TO_EDITED_NODE), "set_ammo_path", "get_ammo_path");
}

void Weapon::_process(double delta) {
    auto pos = get_tree()->get_root()->get_mouse_position();
    look_at(pos);
}
