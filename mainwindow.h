#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListView>
#include <QStringListModel>
#include <QFile>
#include <QTextStream>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void logSensorData();
private slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_centralwidget_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;

    QListView *listview = nullptr;
    QFile logFile;
    QTextStream logStream;
    QTimer *timer;

};

#endif
