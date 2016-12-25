#pragma once
class Drawable {
public:
	virtual ~Drawable() {}
	virtual void load() = 0;
	virtual void draw() = 0;
};
