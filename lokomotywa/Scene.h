#pragma once
#include "Drawable.h"
#include <vector>

class Scene :
	public Drawable {
public:
	Scene();
	void load();
	void draw(float delta, int modelLoc);
	void add(Drawable *d);
private:
	float ratio = 13.0f;
	const float RATIO_STEP = 0.01f;
	std::vector<Drawable*> elements;
};

