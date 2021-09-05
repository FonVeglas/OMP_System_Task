#include "work_space.h"
#include <iostream>

WorkSpace::WorkSpace(QObject *parent) : QGraphicsScene(parent) {
  connect(this, &WorkSpace::movedFigure, this, &WorkSpace::redrawLines);
  connect(this, &WorkSpace::deletedFigure, this, &WorkSpace::deleteLines);
}

WorkSpace::~WorkSpace() {}

void WorkSpace::connectFigures()
{
  //Проверка на то, что pressedItem и releasedItem не являются соединительными линиями
  if (QGraphicsLineItem *check =
          dynamic_cast<QGraphicsLineItem *>(pressedItem))
    return;
  if (QGraphicsLineItem *check =
          dynamic_cast<QGraphicsLineItem *>(releasedItem))
    return;
  if ((pressedItem != nullptr && releasedItem != nullptr) &&
      pressedItem != releasedItem) {
    ConnectingLine *lineBetween =
        new ConnectingLine(pressedItem, releasedItem);
    //Привязка объектов к соеденительной линии посредсвтом id
    lineBetween->setFirstItemId(dynamic_cast<Figure*>(pressedItem)->getId());
    lineBetween->setSecondItemId(dynamic_cast<Figure*>(releasedItem)->getId());
    QLineF line(pressedItem->sceneBoundingRect().center(),
                releasedItem->sceneBoundingRect().center());
    lineBetween->setPen(QPen(Qt::black, 2));
    lineBetween->setLine(line);
    this->addItem(lineBetween);
    this->addConnectingLine(lineBetween);
    this->update(QRectF(0, 0, this->width(), this->height()));
  }
}

void WorkSpace::addConnectingLine(ConnectingLine *line) {
  connectingLines.append(line);
}

void WorkSpace::clearConnectingLines() { connectingLines.clear(); }

QList<ConnectingLine *> WorkSpace::getConnectingLines() const {
  return connectingLines;
}

void WorkSpace::setFigureType(const int &type) { typeFigure = type; }

void WorkSpace::redrawLines() {
  foreach (auto line, connectingLines) {

    QLineF lineUpdate(line->getFirstItem()->sceneBoundingRect().center(),
                      line->getSecondItem()->sceneBoundingRect().center());
    line->setLine(lineUpdate);
    this->update(QRectF(0, 0, this->width(), this->height()));
  }
}

void WorkSpace::deleteLines(QGraphicsItem* item) {
  foreach (auto line, connectingLines) {
    if(line->getFirstItem() == item || line->getSecondItem() == item)
      removeItem(line);
    this->update(QRectF(0, 0, this->width(), this->height()));
  }
}

void WorkSpace::createFigureStart(QGraphicsSceneMouseEvent *event){
  switch (WorkSpace::typeFigure) {
  case WorkSpace::FigureTypes::TriangleType: {
    Figure *item = new Triangle(event->scenePos());
    item->setPos(event->pos());
    tempItem = item;
    break;
  }
  case WorkSpace::FigureTypes::RectangleType: {
    Figure *item = new Rectangle(event->scenePos());
    item->setPos(event->pos());
    tempItem = item;
    break;
  }
  case WorkSpace::FigureTypes::EllipseType: {
    Figure *item = new Ellipse(event->scenePos());
    item->setPos(event->pos());
    tempItem = item;
    break;
  }
  default: {
    Figure *item = new Triangle(event->scenePos());
    item->setPos(event->pos());
    tempItem = item;
    break;
  }
  }
  this->addItem(tempItem);
}

void WorkSpace::createFigureEnd(QGraphicsSceneMouseEvent *event){
  tempItem->setEndPoint(event->scenePos());
  this->update(QRectF(0, 0, this->width(), this->height()));
}

void WorkSpace::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  switch (ActionType::getActionType()) {
  case ActionType::AddFigure: {
    createFigureStart(event);
    break;
  }
  case ActionType::MoveFigure: {
    QGraphicsScene::mousePressEvent(event);
    break;
  }
  case ActionType::ConnectFigures: {
    pressedItem = itemAt(event->scenePos(), QTransform());
    break;
  }
  case ActionType::DeleteFigure: {
    break;
  }
  }
}

void WorkSpace::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
  switch (ActionType::getActionType()) {
  case ActionType::AddFigure: {
    createFigureEnd(event);
    break;
  }
  case ActionType::MoveFigure: {
    QGraphicsScene::mouseMoveEvent(event);
    emit movedFigure();
    break;
  }
  case ActionType::ConnectFigures: {
    break;
  }
  case ActionType::DeleteFigure: {
    break;
  }
  }
}

void WorkSpace::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {

  switch (ActionType::getActionType()) {
  case ActionType::AddFigure: {
    break;
  }
  case ActionType::MoveFigure: {
    QGraphicsScene::mouseReleaseEvent(event);
    break;
  }
  case ActionType::ConnectFigures: {
    releasedItem = itemAt(event->scenePos(), QTransform());
    connectFigures();
    break;
  }
  case ActionType::DeleteFigure: {
    auto itemToRemove = this->itemAt(event->scenePos(), QTransform());
    emit deletedFigure(itemToRemove);
    removeItem(itemToRemove);
    break;
  }
  }
}
