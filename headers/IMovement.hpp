#pragma once

class IMovement
{
protected:
	virtual void move_left() = 0;
	virtual void move_right() = 0;
	virtual void move_up() = 0;
	virtual void move_down() = 0;
	virtual void run(int key) = 0;
};

