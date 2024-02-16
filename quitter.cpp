#include "quitter.h"
#include "ui_quitter.h"

Quitter::Quitter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Quitter)
{
    ui->setupUi(this);
}

Quitter::~Quitter()
{
    delete ui;
}

void Quitter::on_buttonBox_accepted()
{
    this->close();
}
