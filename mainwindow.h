#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "action_type.h"
#include "work_space.h"
#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QVariant>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  //Методы сохранения и загрузки рабочей области
  void saveWorkSpace(const QString &filePath);
  void loadWorkSpace(const QString &filePath);


private slots:
  void on_actionAdd_triangle_triggered();
  void on_actionAdd_rectangle_triggered();
  void on_actionAdd_circle_triggered();
  void on_actionConnect_the_figures_triggered();
  void on_actionMove_a_figure_triggered();
  void on_actionDelete_a_figure_triggered();
  void on_actionSave_triggered();
  void on_actionOpen_triggered();
  void slotTimer();

  private:
  void resizeEvent(QResizeEvent * event);
  QVariant itemToVariant(QGraphicsItem* item);
  QGraphicsItem* itemFromVariant(const QVariant &v);

  Ui::MainWindow *ui;
  WorkSpace *workspace;
  QTimer *timer;
};
#endif // MAINWINDOW_H
