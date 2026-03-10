#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListView>
#include <QStringListModel>
#include <QStringList>
#include <QVBoxLayout>
#include <QTimer>
#include <QPlainTextEdit>
#include <QToolBar>
#include <QComboBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showList();
    void readSensor();
    void toggle();

    QListView *listView = nullptr;
    QPlainTextEdit *sensorLog;
    QTimer *timer;


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
