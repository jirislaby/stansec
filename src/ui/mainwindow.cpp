#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sourcecodeedit.h"

#include "../parser/parser.h"
#include "../codestructures/LazyInternalStructuresIntra.h"
#include "../checker/reachabilitychecker/ReachabilityCheckerCreator.h"
#include "../checker/CheckerProgressMonitor.h"

#include <iostream>
#include <fstream>

#include <QFile>
#include <QFileDialog>
#include <QList>
#include <QMessageBox>
#include <QString>
#include <QStringList>
#include <QTextCodec>

#include "treeerrormodel.h"

MainWindow::MainWindow(const QStringList &sources, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeError->setModel(&treeErrorModel);
    for (auto file: sources)
        open(file);
}

MainWindow::~MainWindow()
{
	for (auto p : parsers)
		delete p;

	delete ui;
}

void MainWindow::about()
{
    QMessageBox::about(this, "Stansec",
                       "<b>Stansec</b><br/>"
                       "Version 1<br/><br/>"
		       "Copyright © 2020-2021 <b>Jiri Slaby</b><br/>"
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

    open(fileName);
}

void MainWindow::open(const QString &fileName)
{
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
    auto text = new Ui::SourceCodeEdit();

    text->setReadOnly(true);
    text->setPlainText(data);
    ui->tabSources->addTab(text, fileName);
}

void MainWindow::on_pbRun_clicked()
{
	auto cur = dynamic_cast<Ui::SourceCodeEdit *>(ui->tabSources->currentWidget());
	if (!cur) {
		QMessageBox::warning(this, "Error", "Open a file first!");
		return;
	}

	if (parsers.contains(cur))
		return;

	checker::QInfoCheckerProgressMonitor monitor;
	checker::CheckerErrorReceiver errReceiver([this](const checker::CheckerError &err) {
		treeErrorModel.addError(err);
	}, []() {
	});
	checker::ReachabilityCheckerCreator reach;

	auto parser = new parser::Parser(&monitor, errReceiver);
	parser->addChecker(&reach);
	parser->parseAndCheck(cur->toPlainText().toStdString());
	parsers.insert(cur, parser);
	cur->setParser(parser);
	//std::cout << getParseTree(cur->toPlainText().toStdString()) << std::endl;
}
