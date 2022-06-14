#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "entrypoint.h"
#include <QMainWindow>
#include "checkjson.h"
#include "checkjsonexcepcion.h"
#include <QFileDialog>
#include "filework.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openFile();
    void checkFile();
private:
    Ui::MainWindow *ui;
    Entrypoint logic;
    std::shared_ptr<char> pathToFile;
    std::shared_ptr<char> QstringToCharArray(QString qstring);
};
#endif // MAINWINDOW_H
