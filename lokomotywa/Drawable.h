#pragma once
class Drawable {
public:
	virtual ~Drawable() {}
	virtual void load() = 0;
	virtual void draw(float delta, int modelLoc) = 0;
};
