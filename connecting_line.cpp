#include "connecting_line.h"

ConnectingLine::ConnectingLine(QGraphicsItem *firstItem,
                               QGraphicsItem *secondItem)
    : firstItem_(firstItem), secondItem_(secondItem) {}

ConnectingLine::~ConnectingLine() {}

QGraphicsItem *ConnectingLine::getFirstItem() { return firstItem_; }

QGraphicsItem *ConnectingLine::getSecondItem() { return secondItem_; }

void ConnectingLine::setFirstItem(QGraphicsItem *firstItem) {
  firstItem_ = firstItem;
}

void ConnectingLine::setSecondItem(QGraphicsItem *secondItem) {
  secondItem_ = secondItem;
}
