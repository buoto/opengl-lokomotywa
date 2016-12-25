#pragma once
#include "Drawable.h"
#include <vector>

class Scene :
	public Drawable {
public:
	Scene();
	void load();
	void draw();
	void add(Drawable *d);
private:
	std::vector<Drawable*> elements;
};

