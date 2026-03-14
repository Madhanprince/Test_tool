#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),logFile("touch.txt"),
      logStream(&logFile)
{
    ui->setupUi(this);

    if (logFile.open(QIODevice::WriteOnly |
                        QIODevice::Append |
                        QIODevice::Text))
       {
           qDebug() << "Log file opened";
       }

    timer = new QTimer(this);

    connect(timer, &QTimer::timeout,
               this, &MainWindow::logSensorData);
    connect(ui->pushButton_2, &QPushButton::clicked,
            this, &MainWindow::on_pushButton_2_clicked);
}

MainWindow::~MainWindow()
{
    if (logFile.isOpen())
        logFile.close();

    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if (!listview) {

        listview = new QListView(this);
        listview->setFixedSize(200,200);

        QStringList myFiles;
        myFiles << "robot_model.urdf"
                << "sensor_config.yaml"
                << "world_map.xml";

        QStringListModel *model = new QStringListModel(this);
        model->setStringList(myFiles);

        listview->setModel(model);
        listview->setGeometry(100,100,200,150);

        listview->show();
    }
    else {

        listview->setVisible(!listview->isVisible());
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    timer->start(1000);   // start timer every 1 second
}


//void MainWindow::logSensorData()
//{
//    QString fileName = "touch.txt";

//    QFile file(fileName);

//    if (file.open(QIODevice::WriteOnly |
//                  QIODevice::Append |
//                  QIODevice::Text))
//    {
//        QTextStream stream(&file);

//        QString timestamp =
//            QDateTime::currentDateTime()
//            .toString("yyyy-MM-dd hh:mm:ss");

//        stream << "[" << timestamp
//               << "] Sensor Status: OK. Simulation Running.\n";

//        file.close();
//    }

//    QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
//}

void MainWindow::logSensorData()
{
    QString timestamp =
        QDateTime::currentDateTime()
        .toString("yyyy-MM-dd hh:mm:ss");

    logStream << "[" << timestamp
              << "] Sensor Status: OK\n";

    logStream.flush();   // forces write immediately
}

void MainWindow::on_centralwidget_customContextMenuRequested(const QPoint &pos)
{

}

