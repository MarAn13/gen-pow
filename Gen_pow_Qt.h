#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Gen_pow_main_menu.h"
#include "Gen_pow_Qt_loading.h"
#include "Gen_pow_SFML.h"
#include <climits>
#include <cmath>

class Gen_pow_Qt : public QMainWindow
{
	Q_OBJECT

public:
	Gen_pow_Qt(QWidget* parent = Q_NULLPTR);
	~Gen_pow_Qt();
private:
	Ui::Generate_powClass* ui;
	long long int limit = LLONG_MAX;
	int num;
	int power;
	bool option_sound;
private slots:
	void on_spinBox_valueChanged();
	void on_verticalSlider_valueChanged();
	void on_pushButton_clicked();
};
