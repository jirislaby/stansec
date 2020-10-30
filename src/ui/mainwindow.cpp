#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "../parser/main.h"

#include <iostream>
#include <fstream>

#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::about()
{
    QMessageBox::about(this, "Stansec",
                       "<b>Stansec</b><br/>"
                       "Version 1<br/><br/>"
                       "Copyright © 2020 <b>Jiri Slaby</b><br/>"
                       "Licensed under GPLv2<br/>"
                       "Web: <a href=\"http://consultctl.eu\">http://consultctl.eu</a><br/>"
                       "E-mail: <a href=\"mailto:jirislaby@gmail.com\">jirislaby@gmail.com</a>");
}

void MainWindow::aboutQt()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_open()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open C File"), ".", tr("C Sources (*.c)"));
    if (fileName.isEmpty())
        return;

    QFile f(fileName);
    if (!f.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Open Failed",
                             "Cannot open<br/>" + fileName +
                             "<br/>due to error<br/><b>" +
                             f.errorString() + "</b>");
        return;
    }
    auto codec = QTextCodec::codecForName("UTF-8");
    const auto data = codec->toUnicode(f.readAll());
    f.close();
    auto text = new QTextEdit();
    text->setReadOnly(true);
    text->setPlainText(data);
    ui->tabSources->addTab(text, fileName);
}

void MainWindow::on_pbRun_clicked()
{
    auto cur = dynamic_cast<QTextEdit *>(ui->tabSources->currentWidget());
    if (!cur) {
        QMessageBox::warning(this, "Error", "Open a file first!");
        return;
    }

    std::cout << getParseTree(cur->toPlainText().toStdString()) << std::endl;
}
