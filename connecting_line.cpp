#include "connecting_line.h"

ConnectingLine::ConnectingLine(QGraphicsItem *firstItem,
                               QGraphicsItem *secondItem)
    : firstItem_(firstItem), secondItem_(secondItem) {}

ConnectingLine::~ConnectingLine() {}

QGraphicsItem *ConnectingLine::getFirstItem() const { return firstItem_; }

QGraphicsItem *ConnectingLine::getSecondItem() const { return secondItem_; }

void ConnectingLine::setFirstItem(QGraphicsItem *firstItem) {
  firstItem_ = firstItem;
}

void ConnectingLine::setSecondItem(QGraphicsItem *secondItem) {
  secondItem_ = secondItem;
}

unsigned int ConnectingLine::getFirstItemId() const { return firstItemId; }

unsigned int ConnectingLine::getSecondItemId() const { return secondItemId; }

void ConnectingLine::setFirstItemId(const unsigned int &id) {
  firstItemId = id;
}

void ConnectingLine::setSecondItemId(const unsigned int &id) {
  secondItemId = id;
}
