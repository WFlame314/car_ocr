/********************************************************************************
** Form generated from reading UI file 'process1.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESS1_H
#define UI_PROCESS1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_process1
{
public:
    QGridLayout *gridLayout;
    QLabel *gray;
    QLabel *label_2;
    QLabel *bin;
    QLabel *label_4;

    void setupUi(QWidget *process1)
    {
        if (process1->objectName().isEmpty())
            process1->setObjectName(QString::fromUtf8("process1"));
        process1->resize(600, 359);
        gridLayout = new QGridLayout(process1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gray = new QLabel(process1);
        gray->setObjectName(QString::fromUtf8("gray"));
        gray->setMaximumSize(QSize(440, 140));

        gridLayout->addWidget(gray, 0, 0, 1, 1);

        label_2 = new QLabel(process1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 40));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        bin = new QLabel(process1);
        bin->setObjectName(QString::fromUtf8("bin"));
        bin->setMaximumSize(QSize(440, 140));

        gridLayout->addWidget(bin, 2, 0, 1, 1);

        label_4 = new QLabel(process1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(16777215, 40));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);


        retranslateUi(process1);

        QMetaObject::connectSlotsByName(process1);
    } // setupUi

    void retranslateUi(QWidget *process1)
    {
        process1->setWindowTitle(QCoreApplication::translate("process1", "Form", nullptr));
        gray->setText(QString());
        label_2->setText(QCoreApplication::translate("process1", "\347\201\260\345\272\246\345\214\226\345\233\276\347\211\207", nullptr));
        bin->setText(QString());
        label_4->setText(QCoreApplication::translate("process1", "\344\272\214\345\200\274\345\214\226\345\233\276\347\211\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class process1: public Ui_process1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESS1_H
