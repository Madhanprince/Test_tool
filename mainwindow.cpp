#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QComboBox *combo = new QComboBox(this);
    ui->toolBar->addWidget(combo);

    connect(ui->pushButton, &QPushButton::clicked,
            this, &MainWindow::showList);

    connect(ui->pushButton_2, &QPushButton::clicked,
            this, &MainWindow::toggle);

    QVBoxLayout *layout = new QVBoxLayout;

//    layout->addWidget(ui->pushButton);
//    layout->addWidget(listView);
//    layout->addWidget(ui->graphicsView);

    centralWidget()->setLayout(layout);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::toggle(){
    if (!sensorLog) {
        sensorLog = new QPlainTextEdit(this);
        sensorLog->setGeometry(200,200,300,200);
        sensorLog->setReadOnly(true);
    }

    if (!timer) {
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MainWindow::readSensor);
    }

    if (!timer->isActive()) {
        timer->start(1000);
    } else {
        timer->stop();
    }
}

void MainWindow::readSensor(){
     sensorLog->appendPlainText("Temperature: 26C");
}

void MainWindow::showList()
{
    if(!listView)
      {
          listView = new QListView(this);

          QStringList items;
          items << "Camera" << "Sensor" << "Robot";

          QStringListModel *model = new QStringListModel(items);
          listView->setModel(model);
          listView->setGeometry(100,100,200,150);
          listView->show();
      }
      else
      {
          listView->setVisible(!listView->isVisible());
      }
}


