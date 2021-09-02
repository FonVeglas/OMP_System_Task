#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "action_type.h"
#include "work_space.h"
#include <QMainWindow>
#include <QSettings>
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
  //Methods for save and load
  QVariant itemToVariant(QGraphicsItem* item);
  QGraphicsItem* itemFromVariant(QVariant v);
  void saveWorkSpace();
  void restoreState();


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

  Ui::MainWindow *ui;
  WorkSpace *workspace;
  QTimer *timer;
};
#endif // MAINWINDOW_H
