#include "Gen_pow_Qt.h"

Gen_pow_Qt::Gen_pow_Qt(QWidget* parent)
	: QMainWindow(parent), ui(new Ui::Generate_powClass)
{
	ui->setupUi(this);
	num = ui->spinBox->value();
	power = ui->verticalSlider->value();
	ui->label->setText(QString::fromStdString(std::to_string(num) + '^' + std::to_string(power)));
}

Gen_pow_Qt::~Gen_pow_Qt()
{
	delete ui;
}

void Gen_pow_Qt::on_spinBox_valueChanged()
{
	int prev_num = num;
	num = ui->spinBox->value();
	int max_power = log(limit) / log(num);
	power = log(std::pow(prev_num, power)) / log(num);
	ui->verticalSlider->setMaximum(max_power);
	ui->verticalSlider->setValue(power);
	ui->label->setText(QString::fromStdString(std::to_string(num) + '^' + std::to_string(power)));
}

void Gen_pow_Qt::on_verticalSlider_valueChanged()
{
	power = ui->verticalSlider->value();
	ui->lcdNumber->display(power);
	ui->label->setText(QString::fromStdString(std::to_string(num) + '^' + std::to_string(power)));
}

void Gen_pow_Qt::on_pushButton_clicked()
{
	option_sound = ui->checkBox->isChecked();
	Gen_pow_Qt_loading loading;
	this->hide();
	loading.show();
	Gen_pow_SFML app(num, power, option_sound, this);
	loading.hide();
	this->show();
}