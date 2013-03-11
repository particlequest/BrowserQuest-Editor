#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::on_actionOpenProject_triggered()
{
	QString str = QFileDialog::getExistingDirectory(this
													,"Select project directory"
													,0
													,QFileDialog::ShowDirsOnly);
	if (!str.isNull()) {
		_project = new Project(str);
	}
}

