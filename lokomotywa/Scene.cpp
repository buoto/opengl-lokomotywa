#include "Scene.h"


Scene::Scene() {
}

void Scene::load() {
	for (Drawable *d : elements) {
		d->load();
	}
}

void Scene::draw(float delta, int modelLoc) {
	if (ratio > 0) ratio -= RATIO_STEP; else ratio = 0;
	delta *= ratio;
	for (Drawable *d : elements) {
		d->draw(delta, modelLoc);
	}
}

void Scene::add(Drawable *d) {
	if (d != nullptr) {
		elements.push_back(d);
	}
}
