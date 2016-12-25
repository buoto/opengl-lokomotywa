#include "Scene.h"


Scene::Scene() {
}

void Scene::load() {
	for (Drawable *d : elements) {
		d->load();
	}
}

void Scene::draw() {
	for (Drawable *d : elements) {
		d->draw();
	}
}

void Scene::add(Drawable *d) {
	if (d != nullptr) {
		elements.push_back(d);
	}
}