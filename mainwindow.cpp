#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->openFile, SIGNAL(clicked()),this,SLOT(openFile()));
    connect(ui->checkFile, SIGNAL(clicked()),this,SLOT(checkFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::checkFile(){
    try {
        std::shared_ptr<char> json = logic.fileExamination(this->pathToFile);
        ui->label->setText(json.get());
        logic.Examination(json);
        ui->correct->setText("File correct");
        ui->error->setText("");
    }
    catch (JsonException& error){
        ui->error->setText(error.what());
        ui->correct->setText("File incorrect");
    }
    catch (FileException& error){
        ui->correct->setText("File incorrect");
    }

}

//get преобразовывает в char*

void MainWindow::openFile(){
    QString filePosition = QFileDialog::getOpenFileName(this, "Выберите файл", QDir::currentPath(), "*.json");
    this -> pathToFile = QstringToCharArray(filePosition);
    ui->pathToFile->setText(filePosition);
}

std::shared_ptr<char> MainWindow::QstringToCharArray(QString qstring){
    std::shared_ptr<char> str(new char[qstring.size()]);
    int i;
    for (i = 0; i < qstring.size(); i++){
        str.get()[i] = qstring.at(i).unicode();
    }
    str.get()[i] = 0;
    return str;
}
