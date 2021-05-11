//  Dimension.cpp
//  SchumakerTeam Lab.
//
//  Hudson Schumaker
//

#include "Dimension.h"

Dimension::Dimension() : w(0), h(0) {}
Dimension::Dimension(int w, int h) : w(w), h(h) {}

void Dimension::setDimension(Dimension d) {
	this->w = d.getWidth();
	this->h = d.getHeight();
}

Dimension Dimension::getSize() {
	return Dimension(this->getWidth(), this->getHeight());
}