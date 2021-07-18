/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QGridLayout *gridLayout;
    QPushButton *Button_open;
    QLineEdit *lineEdit_filepath;
    QPushButton *Button_start;
    QSpacerItem *horizontalSpacer;
    QLabel *carimage;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QString::fromUtf8("MyWidget"));
        MyWidget->resize(600, 355);
        gridLayout = new QGridLayout(MyWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Button_open = new QPushButton(MyWidget);
        Button_open->setObjectName(QString::fromUtf8("Button_open"));
        Button_open->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(Button_open, 0, 3, 1, 1);

        lineEdit_filepath = new QLineEdit(MyWidget);
        lineEdit_filepath->setObjectName(QString::fromUtf8("lineEdit_filepath"));
        lineEdit_filepath->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEdit_filepath, 0, 0, 1, 3);

        Button_start = new QPushButton(MyWidget);
        Button_start->setObjectName(QString::fromUtf8("Button_start"));
        Button_start->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(Button_start, 0, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(92, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        carimage = new QLabel(MyWidget);
        carimage->setObjectName(QString::fromUtf8("carimage"));
        carimage->setMinimumSize(QSize(400, 140));
        carimage->setMaximumSize(QSize(458, 140));
        carimage->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(carimage, 1, 1, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(72, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 4, 1, 1);

        lineEdit = new QLineEdit(MyWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(500, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(20);
        lineEdit->setFont(font);
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit->setReadOnly(true);

        gridLayout->addWidget(lineEdit, 2, 0, 1, 5);


        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QCoreApplication::translate("MyWidget", "MyWidget", nullptr));
        Button_open->setText(QCoreApplication::translate("MyWidget", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        Button_start->setText(QCoreApplication::translate("MyWidget", "\350\257\206\345\210\253", nullptr));
        carimage->setText(QCoreApplication::translate("MyWidget", "\350\275\246\347\211\214\346\226\207\344\273\266", nullptr));
        lineEdit->setText(QCoreApplication::translate("MyWidget", "\350\275\246\347\211\214\345\217\267\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
