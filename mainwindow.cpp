#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  workspace = new WorkSpace();
  ui->graphicsView->setScene(workspace);
  ui->graphicsView->setRenderHint(QPainter::Antialiasing);
  ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  timer = new QTimer();
  connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
  timer->start(100);
}

MainWindow::~MainWindow() {
  delete timer;
  delete workspace;
  delete ui;
}

void MainWindow::saveWorkSpace(const QString &filePath) {
  QVariantList dataList;
  foreach (QGraphicsItem *item, workspace->items()) {
    dataList << itemToVariant(item);
  }
  QFile fileOut(filePath);
  if (fileOut.open(QIODevice::WriteOnly)) {
    QDataStream out(&fileOut);
    out << dataList;
    fileOut.close();
  }
}

void MainWindow::loadWorkSpace(const QString &filePath) {
  workspace->clear();
  workspace->clearConnectingLines();
  QFile fileIn(filePath);
  if (fileIn.open(QIODevice::ReadOnly)) {
    QDataStream in(&fileIn);
    QVariantList dataList;
    in >> dataList;
    fileIn.close();
    foreach (QVariant data, dataList) {
      QGraphicsItem *item = itemFromVariant(data);
      workspace->addItem(item);
      if(ConnectingLine *line = dynamic_cast<ConnectingLine *>(item))
        workspace->addConnectingLine(line);
    }
  }
  //Алгоритм ниже выполянет связывание соединительных линий с объектами класса Figure посредством id этих объетов
  foreach (auto connectingLine, workspace->getConnectingLines()) {
    QLineF currentLine = connectingLine->line();
    QPointF startPoint = currentLine.p1();
    QPointF endPoint = currentLine.p2();
    foreach (auto firstPointItem, workspace->items(startPoint)) {
      if (ConnectingLine *line = dynamic_cast<ConnectingLine *>(firstPointItem))
        continue;
      if(dynamic_cast<Figure*>(firstPointItem)->getId() == connectingLine->getFirstItemId()){
        connectingLine->setFirstItem(firstPointItem);
        break;
      }
    }
    foreach (auto secondPointItem, workspace->items(endPoint)) {
      if (ConnectingLine *line = dynamic_cast<ConnectingLine *>(secondPointItem))
        continue;
      if(dynamic_cast<Figure*>(secondPointItem)->getId() == connectingLine->getSecondItemId()){
        connectingLine->setSecondItem(secondPointItem);
        break;
      }
    }
  }
}
//Преобразование объектов QGraphicsItem в hash который обёрнут в QVariant
QVariant MainWindow::itemToVariant(QGraphicsItem *item) {
  QVariantHash data;
  data["pos"] = item->pos();
  data["rotation"] = item->rotation();
  if (Triangle *triangleItem = dynamic_cast<Triangle *>(item)) {
    data["type"] = "triangle";
    data["startPoint"] = triangleItem->getStartPoint();
    data["endPoint"] = triangleItem->getEndPoint();
    data["id"] = triangleItem->getId();
  } else if (Rectangle *rectangleItem = dynamic_cast<Rectangle *>(item)) {
    data["type"] = "rectangle";
    data["startPoint"] = rectangleItem->getStartPoint();
    data["endPoint"] = rectangleItem->getEndPoint();
    data["id"] = rectangleItem->getId();
  } else if (Ellipse *ellipseItem = dynamic_cast<Ellipse *>(item)) {
    data["type"] = "ellipse";
    data["startPoint"] = ellipseItem->getStartPoint();
    data["endPoint"] = ellipseItem->getEndPoint();
    data["id"] = ellipseItem->getId();
  } else if (ConnectingLine *lineItem = dynamic_cast<ConnectingLine *>(item))
  { data["type"] = "connectingLine";
    data["line"] = lineItem->line();
    data["firstItemId"] = lineItem->getFirstItemId();
    data["secondItemId"] = lineItem->getSecondItemId();
  }
  return data;
}
//Преобразование QVariantHash в объекты QGraphicsItem
QGraphicsItem *MainWindow::itemFromVariant(const QVariant &v) {
  QVariantHash data = v.toHash();
  if (data["type"].toString() == "triangle") {
    Figure *result = new Triangle(data["startPoint"].toPointF());
    result->setEndPoint(data["endPoint"].toPointF());
    result->setId(data["id"].toUInt());
    result->setPos(data["pos"].toPointF());
    result->setRotation(data["rotation"].toDouble());
    return result;
  }
  if (data["type"].toString() == "rectangle") {
    Figure *result = new Rectangle(data["startPoint"].toPointF());
    result->setEndPoint(data["endPoint"].toPointF());
    result->setId(data["id"].toUInt());
    result->setPos(data["pos"].toPointF());
    result->setRotation(data["rotation"].toDouble());
    return result;
  }
  if (data["type"].toString() == "ellipse") {
    Figure *result = new Ellipse(data["startPoint"].toPointF());
    result->setEndPoint(data["endPoint"].toPointF());
    result->setId(data["id"].toUInt());
    result->setPos(data["pos"].toPointF());
    result->setRotation(data["rotation"].toDouble());
    return result;
  }
  if (data["type"].toString() == "connectingLine") {
    ConnectingLine *result = new ConnectingLine(nullptr, nullptr);
    result->setPen(QPen(Qt::black, 2));
    result->setLine(data["line"].toLineF());
    result->setFirstItemId(data["firstItemId"].toUInt());
    result->setSecondItemId(data["secondItemId"].toUInt());
    result->setPos(data["pos"].toPointF());
    result->setRotation(data["rotation"].toDouble());
    return result;
  }
  return nullptr;
}

void MainWindow::slotTimer()
{
    timer->stop();
    workspace->setSceneRect(0, 0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QMainWindow::resizeEvent(event);
}

void MainWindow::on_actionAdd_triangle_triggered()
{
    ActionType::setActionType(ActionType::AddFigure);
    workspace->setFigureType(WorkSpace::FigureTypes::TriangleType);
}

void MainWindow::on_actionAdd_rectangle_triggered()
{
    ActionType::setActionType(ActionType::AddFigure);
    workspace->setFigureType(WorkSpace::FigureTypes::RectangleType);
}

void MainWindow::on_actionAdd_circle_triggered()
{
    ActionType::setActionType(ActionType::AddFigure);
    workspace->setFigureType(WorkSpace::FigureTypes::EllipseType);
}

void MainWindow::on_actionConnect_the_figures_triggered()
{
    ActionType::setActionType(ActionType::ConnectFigures);
}

void MainWindow::on_actionMove_a_figure_triggered()
{
    ActionType::setActionType(ActionType::MoveFigure);
}

void MainWindow::on_actionDelete_a_figure_triggered()
{
    ActionType::setActionType(ActionType::DeleteFigure);
}

void MainWindow::on_actionSave_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this,
                                                    QString("Save File"),
                                                    QString(),
                                                    QString("Text files (*.txt)"));
    saveWorkSpace(filePath);
}

void MainWindow::on_actionOpen_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this,
                                                    QString("Open File"),
                                                    QString(),
                                                    QString("Text files (*.txt)"));
    loadWorkSpace(filePath);
}
