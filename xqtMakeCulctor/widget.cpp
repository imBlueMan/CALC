#include "widget.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Make buttons greate again
    QStringList buttonList;
    buttonList << "7" << "8" << "9" << "4" << "5" << "6" << "1" << "2" << "3" << "0";

    QStringList buttonFunctions;
    buttonFunctions << "/" << "x" << "-" << "+";

    QLabel *displayLbl = new QLabel();

    QVBoxLayout *vb0 = new QVBoxLayout();
    QVBoxLayout *vb1 = new QVBoxLayout();
    QHBoxLayout *hb0 = nullptr;
    QHBoxLayout *hb1 = new QHBoxLayout();

    for (int m = 0; m < buttonList.size(); ++m) {
        if (m % 3 == 0) {
            hb0 = new QHBoxLayout();
            vb0->addLayout(hb0);
        }
        QPushButton *numBee = new QPushButton(buttonList.at(m));

        connect(numBee, &QPushButton::clicked, [numBee, displayLbl]() {
            // qDebug() << numBee->text();
            displayLbl->setText(displayLbl->text() + numBee->text());
        });

        hb0->addWidget(numBee);
    }

    for (int k = 0; k < buttonFunctions.size(); ++k) {
        vb1->addWidget(new QPushButton(buttonFunctions.at(k)));
    }
    hb1->addLayout(vb0);
    hb1->addLayout(vb1);

    ui->verticalLayout->addWidget(displayLbl);
    ui->verticalLayout->addLayout(hb1);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::addition()
{

}

void Widget::subtraction()
{

}

void Widget::multiplay()
{

}

void Widget::equals()
{

}
