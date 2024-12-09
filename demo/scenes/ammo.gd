extends Ammo

@export var time:Timer

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	time.start()

func _on_timer_timeout() -> void:
	queue_free()
