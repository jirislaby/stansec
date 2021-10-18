#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QStringList>

#include "treeerrormodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace parser { class Parser; }

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
    QMap<QWidget *, parser::Parser *> parsers;
    void open(const QString &fileName);

    Ui::MainWindow *ui;
    Ui::TreeErrorModel treeErrorModel;
};
#endif // MAINWINDOW_H
