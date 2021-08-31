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

void MainWindow::slotTimer()
{

  timer->stop();
  workspace->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
  timer->start(100);
  QMainWindow::resizeEvent(event);
}

void MainWindow::on_actionAdd_triangle_triggered() {
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

