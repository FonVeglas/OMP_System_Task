#include "work_space.h"
#include <iostream>

WorkSpace::WorkSpace(QObject *parent) : QGraphicsScene(parent) {
  connect(this, &WorkSpace::movedFigure, this, &WorkSpace::redrawLines);
  connect(this, &WorkSpace::deletedFigure, this, &WorkSpace::deleteLines);
}

WorkSpace::~WorkSpace() {
  delete tempItem;
  delete pressedItem;
  delete releasedItem;
}

void WorkSpace::addConnectingLine(ConnectingLine *line) {
  connectingLines.append(line);
}

QList<ConnectingLine *> WorkSpace::getConnectingLines() {
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
  }
}

//int WorkSpace::typeFigure() const { return typeFigure; }
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
  std::cout << "Start point x: " << tempItem->getStartPoint().x() << ' '
            << "start point y: " << tempItem->getStartPoint().y() << std::endl;

  std::cout << "End point x: " << tempItem->getEndPoint().x() << ' '
            << "end point y: " << tempItem->getEndPoint().y() << std::endl;

  this->update(QRectF(0, 0, this->width(), this->height()));
}

void WorkSpace::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  switch (ActionType::getActionType()) {
  case ActionType::AddFigure: {
    std::cout << "Graphics scene press" << std::endl;
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
    std::cout << "Graphics scene press" << std::endl;
    auto itemToRemove = this->itemAt(event->scenePos(), QTransform());
    emit deletedFigure(itemToRemove);
    removeItem(itemToRemove);
    break;
  }
  }
}

void WorkSpace::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
  switch (ActionType::getActionType()) {
  case ActionType::AddFigure: {
    std::cout << "Graphics scene move" << std::endl;
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
    std::cout << "Graphics scene release" << std::endl;
    break;
  }
  case ActionType::MoveFigure: {
    QGraphicsScene::mouseReleaseEvent(event);
    break;
  }
  case ActionType::ConnectFigures: {
    releasedItem = itemAt(event->scenePos(), QTransform());
    if (QGraphicsLineItem *check =
            dynamic_cast<QGraphicsLineItem *>(pressedItem))
      break;
    if (QGraphicsLineItem *check =
            dynamic_cast<QGraphicsLineItem *>(releasedItem))
      break;
    if ((pressedItem != nullptr && releasedItem != nullptr) &&
        pressedItem != releasedItem) {
      ConnectingLine *lineBetween =
          new ConnectingLine(pressedItem, releasedItem);
      QLineF line(pressedItem->sceneBoundingRect().center(),
                  releasedItem->sceneBoundingRect().center());
      lineBetween->setPen(QPen(Qt::black, 2));
      lineBetween->setLine(line);
      this->addItem(lineBetween);
      this->addConnectingLine(lineBetween);
    }
    break;
  }
  case ActionType::DeleteFigure: {
    break;
  }
  }
}
