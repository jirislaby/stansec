#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QStringList &sources, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void about();
    void aboutQt();

    void on_open();
    void on_pbRun_clicked();

private:
    void open(const QString &fileName);

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
