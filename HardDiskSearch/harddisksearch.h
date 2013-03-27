#ifndef HARDDISKSEARCH_H
#define HARDDISKSEARCH_H

#include <QtWidgets/QMainWindow>
#include "ui_harddisksearch.h"

class HardDiskSearch : public QMainWindow
{
	Q_OBJECT

public:
	HardDiskSearch(QWidget *parent = 0);
	~HardDiskSearch();

private:
	Ui::HardDiskSearchClass ui;
};

#endif // HARDDISKSEARCH_H
