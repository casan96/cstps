#include "godot_cpp/core/memory.hpp"
#include <memory>
template <typename T>
struct deleter {
	void operator()(T *ptr) {
		godot::memdelete(ptr);
	}
};
template <typename T>
using godot_ptr = std::unique_ptr<T, deleter<T>>;
