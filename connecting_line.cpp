#include "connecting_line.h"

ConnectingLine::ConnectingLine(QGraphicsItem *firstItem,
                               QGraphicsItem *secondItem)
    : firstItem_(firstItem), secondItem_(secondItem) {}

ConnectingLine::~ConnectingLine() {
  delete firstItem_;
  delete secondItem_;
}

QGraphicsItem *ConnectingLine::getFirstItem() { return firstItem_; }

QGraphicsItem *ConnectingLine::getSecondItem() { return secondItem_; }
