/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QLabel *name_app;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QLabel *label_7;
    QCheckBox *time_checkBox;
    QCheckBox *element_checkBox;
    QLabel *label_11;
    QPushButton *poisk_button;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *otchetButton;
    QComboBox *vibor_table_comBox;
    QCheckBox *error_checkBox;
    QLabel *label_12;
    QCheckBox *checkBox;
    QComboBox *comboBox;
    QCheckBox *checkBox_2;
    QLabel *label_3;
    QDateTimeEdit *dateTimeEditOT;
    QDateTimeEdit *dateTimeEditDO;
    QCheckBox *znachenie_checkBox;
    QLineEdit *lineEdit;
    QTableView *tableView;
    QLabel *kol_strok;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_5;
    QLabel *label_18;
    QLabel *label_10;
    QLabel *label_20;
    QPushButton *pB_meteo;
    QLabel *label_2;
    QComboBox *comboBox_meteo;
    QDateTimeEdit *dateTimeEdit_OT_meteo;
    QDateTimeEdit *dateTimeEdit_DO_meteo;
    QLabel *lb_OT;
    QLabel *lb_DO;
    QLabel *label;
    QLabel *label_9;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_19;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *otchetButton_meteo;
    QGridLayout *gridLayout_7;
    QLabel *label_15;
    QLabel *label_13;
    QLabel *label_17;
    QLabel *label_35;
    QLabel *label_27;
    QLabel *label_31;
    QLabel *label_28;
    QLabel *label_16;
    QLabel *label_23;
    QLabel *label_29;
    QLabel *label_34;
    QLabel *label_14;
    QLabel *label_26;
    QLabel *label_25;
    QLabel *label_24;
    QLabel *label_37;
    QLabel *label_32;
    QLabel *label_30;
    QLabel *label_33;
    QLabel *label_36;
    QLabel *label_38;
    QLabel *label_39;
    QLabel *label_40;
    QTableView *tableView_meteo;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QTextBrowser *textBrowser;
    QPushButton *connectButton;
    QTreeWidget *fileList;
    QLabel *ftpServerLabel;
    QLabel *Name_log;
    QGridLayout *gridLayout_4;
    QDateEdit *poisk_dateEdit;
    QPushButton *poisk_Button;
    QLabel *poisk_label;
    QPushButton *updateButton;
    QTableView *tableView_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_6;
    QLineEdit *ftpServerLineEdit;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1629, 911);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1621, 911));
        MainWindow->setMaximumSize(QSize(100000, 100000));
        QFont font;
        font.setPointSize(11);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/image/images/stats.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(70, 70));
        label_4->setMaximumSize(QSize(70, 70));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/new/image/images/stats.png")));

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        name_app = new QLabel(centralWidget);
        name_app->setObjectName(QStringLiteral("name_app"));
        QFont font1;
        font1.setFamily(QStringLiteral("Arimo"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        name_app->setFont(font1);

        gridLayout_3->addWidget(name_app, 0, 1, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QFont font2;
        font2.setFamily(QStringLiteral("Arimo"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        tabWidget->setFont(font2);
        tabWidget->setStyleSheet(QStringLiteral(""));
        tabWidget->setIconSize(QSize(32, 32));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setVerticalSpacing(0);
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 1, 8, 1, 1);

        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 0, 8, 1, 1);

        time_checkBox = new QCheckBox(tab);
        time_checkBox->setObjectName(QStringLiteral("time_checkBox"));

        gridLayout->addWidget(time_checkBox, 0, 6, 2, 2);

        element_checkBox = new QCheckBox(tab);
        element_checkBox->setObjectName(QStringLiteral("element_checkBox"));

        gridLayout->addWidget(element_checkBox, 0, 13, 1, 1);

        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMaximumSize(QSize(5, 16777215));
        label_11->setStyleSheet(QLatin1String("background-color: rgb(54, 112, 148);\n"
"border-width: 2px;\n"
"border-color: beige;"));

        gridLayout->addWidget(label_11, 0, 12, 2, 1);

        poisk_button = new QPushButton(tab);
        poisk_button->setObjectName(QStringLiteral("poisk_button"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(poisk_button->sizePolicy().hasHeightForWidth());
        poisk_button->setSizePolicy(sizePolicy1);
        poisk_button->setMinimumSize(QSize(95, 75));
        poisk_button->setStyleSheet(QLatin1String("background-color: rgb(54, 112, 148);\n"
"border-width: 2px;\n"
"border-color: beige;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/image/images/databasesearch_basededato_12920.png"), QSize(), QIcon::Normal, QIcon::Off);
        poisk_button->setIcon(icon1);
        poisk_button->setIconSize(QSize(47, 47));
        poisk_button->setFlat(false);

        gridLayout->addWidget(poisk_button, 0, 18, 2, 2);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 21, 2, 1);

        otchetButton = new QPushButton(tab);
        otchetButton->setObjectName(QStringLiteral("otchetButton"));
        otchetButton->setMinimumSize(QSize(98, 75));
        otchetButton->setStyleSheet(QLatin1String("background-color: rgb(113, 210, 255);\n"
"border-width: 2px;\n"
"border-color: beige;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/image/images/icons8-\321\215\320\272\321\201\320\277\320\276\321\200\321\202-\320\262-csv-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        otchetButton->setIcon(icon2);
        otchetButton->setIconSize(QSize(47, 47));

        gridLayout->addWidget(otchetButton, 0, 20, 2, 1);

        vibor_table_comBox = new QComboBox(tab);
        vibor_table_comBox->setObjectName(QStringLiteral("vibor_table_comBox"));
        vibor_table_comBox->setEnabled(false);
        vibor_table_comBox->setMinimumSize(QSize(170, 35));
        vibor_table_comBox->setMaximumSize(QSize(250, 35));

        gridLayout->addWidget(vibor_table_comBox, 1, 3, 1, 2);

        error_checkBox = new QCheckBox(tab);
        error_checkBox->setObjectName(QStringLiteral("error_checkBox"));

        gridLayout->addWidget(error_checkBox, 1, 13, 1, 2);

        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(5, 5));
        label_12->setMaximumSize(QSize(5, 16777215));
        label_12->setStyleSheet(QLatin1String("background-color: rgb(54, 112, 148);\n"
"border-width: 2px;\n"
"border-color: beige;"));

        gridLayout->addWidget(label_12, 0, 2, 2, 1);

        checkBox = new QCheckBox(tab);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setMinimumSize(QSize(350, 0));

        gridLayout->addWidget(checkBox, 0, 0, 1, 2);

        comboBox = new QComboBox(tab);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setEnabled(false);
        comboBox->setMinimumSize(QSize(250, 35));
        comboBox->setMaximumSize(QSize(500, 35));

        gridLayout->addWidget(comboBox, 1, 0, 1, 2);

        checkBox_2 = new QCheckBox(tab);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        gridLayout->addWidget(checkBox_2, 0, 3, 1, 2);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(5, 5));
        label_3->setMaximumSize(QSize(5, 16777215));
        label_3->setStyleSheet(QLatin1String("background-color: rgb(54, 112, 148);\n"
"border-width: 2px;\n"
"border-color: beige;"));

        gridLayout->addWidget(label_3, 0, 5, 2, 1);

        dateTimeEditOT = new QDateTimeEdit(tab);
        dateTimeEditOT->setObjectName(QStringLiteral("dateTimeEditOT"));
        dateTimeEditOT->setEnabled(false);
        dateTimeEditOT->setMinimumSize(QSize(190, 0));

        gridLayout->addWidget(dateTimeEditOT, 0, 9, 1, 2);

        dateTimeEditDO = new QDateTimeEdit(tab);
        dateTimeEditDO->setObjectName(QStringLiteral("dateTimeEditDO"));
        dateTimeEditDO->setEnabled(false);
        dateTimeEditDO->setMinimumSize(QSize(190, 0));

        gridLayout->addWidget(dateTimeEditDO, 1, 9, 1, 2);

        znachenie_checkBox = new QCheckBox(tab);
        znachenie_checkBox->setObjectName(QStringLiteral("znachenie_checkBox"));

        gridLayout->addWidget(znachenie_checkBox, 1, 15, 1, 1);

        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setMinimumSize(QSize(50, 35));
        lineEdit->setMaximumSize(QSize(10000, 35));

        gridLayout->addWidget(lineEdit, 1, 16, 1, 2);


        verticalLayout_2->addLayout(gridLayout);

        tableView = new QTableView(tab);
        tableView->setObjectName(QStringLiteral("tableView"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy2);
        QFont font3;
        font3.setBold(false);
        font3.setWeight(50);
        tableView->setFont(font3);
        tableView->setLayoutDirection(Qt::LeftToRight);
        tableView->setInputMethodHints(Qt::ImhNone);
        tableView->setTextElideMode(Qt::ElideMiddle);
        tableView->setGridStyle(Qt::SolidLine);

        verticalLayout_2->addWidget(tableView);

        kol_strok = new QLabel(tab);
        kol_strok->setObjectName(QStringLiteral("kol_strok"));
        QFont font4;
        font4.setFamily(QStringLiteral("Arimo"));
        font4.setPointSize(11);
        kol_strok->setFont(font4);

        verticalLayout_2->addWidget(kol_strok);

        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/image/images/icons8-\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214-\321\201\320\262\320\276\320\271\321\201\321\202\320\262\320\276-32(1).png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon3, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_18 = new QLabel(tab_3);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setMinimumSize(QSize(200, 0));

        gridLayout_5->addWidget(label_18, 0, 9, 1, 3);

        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(200, 0));

        gridLayout_5->addWidget(label_10, 0, 8, 1, 1);

        label_20 = new QLabel(tab_3);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setMinimumSize(QSize(290, 0));

        gridLayout_5->addWidget(label_20, 1, 8, 1, 1);

        pB_meteo = new QPushButton(tab_3);
        pB_meteo->setObjectName(QStringLiteral("pB_meteo"));
        pB_meteo->setMinimumSize(QSize(95, 75));
        pB_meteo->setStyleSheet(QLatin1String("background-color: rgb(54, 112, 148);\n"
"border-width: 2px;\n"
"border-color: beige;"));
        pB_meteo->setIcon(icon1);
        pB_meteo->setIconSize(QSize(47, 47));

        gridLayout_5->addWidget(pB_meteo, 0, 5, 2, 1);

        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font5;
        font5.setPointSize(13);
        label_2->setFont(font5);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_2, 0, 0, 1, 1);

        comboBox_meteo = new QComboBox(tab_3);
        comboBox_meteo->setObjectName(QStringLiteral("comboBox_meteo"));
        comboBox_meteo->setMinimumSize(QSize(100, 0));

        gridLayout_5->addWidget(comboBox_meteo, 1, 0, 1, 1);

        dateTimeEdit_OT_meteo = new QDateTimeEdit(tab_3);
        dateTimeEdit_OT_meteo->setObjectName(QStringLiteral("dateTimeEdit_OT_meteo"));
        dateTimeEdit_OT_meteo->setMinimumSize(QSize(200, 0));
        dateTimeEdit_OT_meteo->setDateTime(QDateTime(QDate(2020, 1, 1), QTime(0, 0, 0)));

        gridLayout_5->addWidget(dateTimeEdit_OT_meteo, 0, 4, 1, 1);

        dateTimeEdit_DO_meteo = new QDateTimeEdit(tab_3);
        dateTimeEdit_DO_meteo->setObjectName(QStringLiteral("dateTimeEdit_DO_meteo"));
        dateTimeEdit_DO_meteo->setMinimumSize(QSize(200, 0));

        gridLayout_5->addWidget(dateTimeEdit_DO_meteo, 1, 4, 1, 1);

        lb_OT = new QLabel(tab_3);
        lb_OT->setObjectName(QStringLiteral("lb_OT"));
        lb_OT->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(lb_OT, 0, 3, 1, 1);

        lb_DO = new QLabel(tab_3);
        lb_DO->setObjectName(QStringLiteral("lb_DO"));
        lb_DO->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(lb_DO, 1, 3, 1, 1);

        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(150, 0));
        label->setFont(font5);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label, 0, 2, 2, 1);

        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(5, 5));
        label_9->setMaximumSize(QSize(5, 16777215));
        label_9->setStyleSheet(QLatin1String("background-color: rgb(54, 112, 148);\n"
"border-width: 2px;\n"
"border-color: beige;"));

        gridLayout_5->addWidget(label_9, 0, 1, 2, 1);

        label_21 = new QLabel(tab_3);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_5->addWidget(label_21, 0, 12, 1, 1);

        label_22 = new QLabel(tab_3);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setMinimumSize(QSize(230, 0));

        gridLayout_5->addWidget(label_22, 1, 12, 1, 1);

        label_19 = new QLabel(tab_3);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setMinimumSize(QSize(320, 0));

        gridLayout_5->addWidget(label_19, 1, 9, 1, 3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_3, 0, 7, 2, 1);

        otchetButton_meteo = new QPushButton(tab_3);
        otchetButton_meteo->setObjectName(QStringLiteral("otchetButton_meteo"));
        otchetButton_meteo->setMinimumSize(QSize(95, 75));
        otchetButton_meteo->setStyleSheet(QLatin1String("background-color: rgb(113, 210, 255);\n"
"border-width: 2px;\n"
"border-color: beige;"));
        otchetButton_meteo->setIcon(icon2);
        otchetButton_meteo->setIconSize(QSize(47, 47));

        gridLayout_5->addWidget(otchetButton_meteo, 0, 6, 2, 1);


        verticalLayout_4->addLayout(gridLayout_5);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMinimumSize(QSize(200, 0));
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_15, 1, 4, 1, 1);

        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMinimumSize(QSize(0, 30));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_13, 1, 0, 1, 1);

        label_17 = new QLabel(tab_3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_17, 1, 8, 1, 1);

        label_35 = new QLabel(tab_3);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setMinimumSize(QSize(5, 0));
        label_35->setMaximumSize(QSize(5, 16777215));
        label_35->setStyleSheet(QLatin1String("background-color: rgb(54, 112, 148);\n"
"border-width: 2px;\n"
"border-color: beige;"));

        gridLayout_7->addWidget(label_35, 0, 3, 2, 1);

        label_27 = new QLabel(tab_3);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setMinimumSize(QSize(0, 30));
        label_27->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_27, 0, 0, 1, 1);

        label_31 = new QLabel(tab_3);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_31, 0, 8, 1, 1);

        label_28 = new QLabel(tab_3);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_28, 0, 2, 1, 1);

        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_16, 1, 6, 1, 1);

        label_23 = new QLabel(tab_3);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_23, 1, 10, 1, 1);

        label_29 = new QLabel(tab_3);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_29, 0, 4, 1, 1);

        label_34 = new QLabel(tab_3);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_34, 0, 14, 1, 1);

        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMinimumSize(QSize(200, 0));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_14, 1, 2, 1, 1);

        label_26 = new QLabel(tab_3);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setMinimumSize(QSize(5, 0));
        label_26->setMaximumSize(QSize(5, 16777215));
        label_26->setStyleSheet(QLatin1String("background-color: rgb(54, 112, 148);\n"
"border-width: 2px;\n"
"border-color: beige;"));

        gridLayout_7->addWidget(label_26, 0, 1, 2, 1);

        label_25 = new QLabel(tab_3);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_25, 1, 14, 1, 1);

        label_24 = new QLabel(tab_3);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_24, 1, 12, 1, 1);

        label_37 = new QLabel(tab_3);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setMinimumSize(QSize(5, 0));
        label_37->setMaximumSize(QSize(5, 16777215));
        label_37->setStyleSheet(QLatin1String("background-color: rgb(54, 112, 148);\n"
"border-width: 2px;\n"
"border-color: beige;"));

        gridLayout_7->addWidget(label_37, 0, 7, 2, 1);

        label_32 = new QLabel(tab_3);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_32, 0, 10, 1, 1);

        label_30 = new QLabel(tab_3);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_30, 0, 6, 1, 1);

        label_33 = new QLabel(tab_3);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_33, 0, 12, 1, 1);

        label_36 = new QLabel(tab_3);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setMinimumSize(QSize(5, 0));
        label_36->setMaximumSize(QSize(5, 16777215));
        label_36->setStyleSheet(QLatin1String("background-color: rgb(54, 112, 148);\n"
"border-width: 2px;\n"
"border-color: beige;"));

        gridLayout_7->addWidget(label_36, 0, 5, 2, 1);

        label_38 = new QLabel(tab_3);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setMinimumSize(QSize(5, 0));
        label_38->setMaximumSize(QSize(5, 16777215));
        label_38->setStyleSheet(QLatin1String("background-color: rgb(54, 112, 148);\n"
"border-width: 2px;\n"
"border-color: beige;"));

        gridLayout_7->addWidget(label_38, 0, 9, 2, 1);

        label_39 = new QLabel(tab_3);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setMinimumSize(QSize(5, 0));
        label_39->setMaximumSize(QSize(5, 16777215));
        label_39->setStyleSheet(QLatin1String("background-color: rgb(54, 112, 148);\n"
"border-width: 2px;\n"
"border-color: beige;"));

        gridLayout_7->addWidget(label_39, 0, 11, 2, 1);

        label_40 = new QLabel(tab_3);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setMinimumSize(QSize(5, 0));
        label_40->setMaximumSize(QSize(5, 16777215));
        label_40->setStyleSheet(QLatin1String("background-color: rgb(54, 112, 148);\n"
"border-width: 2px;\n"
"border-color: beige;"));

        gridLayout_7->addWidget(label_40, 0, 13, 2, 1);


        verticalLayout_4->addLayout(gridLayout_7);

        tableView_meteo = new QTableView(tab_3);
        tableView_meteo->setObjectName(QStringLiteral("tableView_meteo"));
        tableView_meteo->horizontalHeader()->setDefaultSectionSize(40);
        tableView_meteo->horizontalHeader()->setMinimumSectionSize(20);

        verticalLayout_4->addWidget(tableView_meteo);

        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/image/images/pressure.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_3, icon4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(0, 5));
        label_5->setMaximumSize(QSize(16777215, 5));
        label_5->setStyleSheet(QLatin1String("background-color: rgb(54, 112, 148);\n"
"border-width: 2px;\n"
"border-color: beige;"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 3);

        textBrowser = new QTextBrowser(tab_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setMinimumSize(QSize(0, 30));
        textBrowser->setMaximumSize(QSize(16777215, 30));
        textBrowser->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(textBrowser, 1, 0, 1, 2);

        connectButton = new QPushButton(tab_2);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        QFont font6;
        font6.setBold(true);
        font6.setWeight(75);
        connectButton->setFont(font6);
        connectButton->setStyleSheet(QLatin1String("background-color: rgb(54, 112, 148);\n"
"border-width: 2px;\n"
"border-color: beige;\n"
"color: #ffffff;"));

        gridLayout_2->addWidget(connectButton, 1, 2, 1, 1);

        fileList = new QTreeWidget(tab_2);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(4, QStringLiteral("5"));
        __qtreewidgetitem->setText(3, QStringLiteral("4"));
        __qtreewidgetitem->setText(2, QStringLiteral("3"));
        __qtreewidgetitem->setText(1, QStringLiteral("2"));
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        fileList->setHeaderItem(__qtreewidgetitem);
        fileList->setObjectName(QStringLiteral("fileList"));
        fileList->setMinimumSize(QSize(504, 0));
        fileList->setMaximumSize(QSize(504, 16777215));
        QFont font7;
        font7.setPointSize(11);
        font7.setBold(true);
        font7.setWeight(75);
        fileList->setFont(font7);
        fileList->setStyleSheet(QStringLiteral(""));
        fileList->setLineWidth(1);
        fileList->setColumnCount(5);

        gridLayout_2->addWidget(fileList, 5, 0, 2, 3);


        gridLayout_6->addLayout(gridLayout_2, 1, 0, 1, 1);

        ftpServerLabel = new QLabel(tab_2);
        ftpServerLabel->setObjectName(QStringLiteral("ftpServerLabel"));
        ftpServerLabel->setEnabled(true);
        ftpServerLabel->setMinimumSize(QSize(0, 30));
        ftpServerLabel->setMaximumSize(QSize(16777215, 30));
        QFont font8;
        font8.setPointSize(12);
        ftpServerLabel->setFont(font8);

        gridLayout_6->addWidget(ftpServerLabel, 0, 0, 1, 1);

        Name_log = new QLabel(tab_2);
        Name_log->setObjectName(QStringLiteral("Name_log"));
        Name_log->setMinimumSize(QSize(0, 30));
        Name_log->setMaximumSize(QSize(16777215, 30));
        Name_log->setFont(font8);

        gridLayout_6->addWidget(Name_log, 0, 1, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        poisk_dateEdit = new QDateEdit(tab_2);
        poisk_dateEdit->setObjectName(QStringLiteral("poisk_dateEdit"));
        poisk_dateEdit->setMinimumSize(QSize(110, 0));
        poisk_dateEdit->setMaximumSize(QSize(110, 16777215));
        poisk_dateEdit->setDisplayFormat(QStringLiteral("dd.MM.yyyy"));
        poisk_dateEdit->setCalendarPopup(true);

        gridLayout_4->addWidget(poisk_dateEdit, 1, 2, 1, 1);

        poisk_Button = new QPushButton(tab_2);
        poisk_Button->setObjectName(QStringLiteral("poisk_Button"));
        poisk_Button->setMinimumSize(QSize(80, 0));
        poisk_Button->setMaximumSize(QSize(80, 16777215));
        QFont font9;
        font9.setPointSize(10);
        font9.setBold(true);
        font9.setWeight(75);
        poisk_Button->setFont(font9);
        poisk_Button->setStyleSheet(QLatin1String("background-color: rgb(54, 112, 148);\n"
"border-width: 2px;\n"
"border-color: beige;\n"
"color: #ffffff;"));

        gridLayout_4->addWidget(poisk_Button, 1, 3, 1, 1);

        poisk_label = new QLabel(tab_2);
        poisk_label->setObjectName(QStringLiteral("poisk_label"));

        gridLayout_4->addWidget(poisk_label, 1, 1, 1, 1);

        updateButton = new QPushButton(tab_2);
        updateButton->setObjectName(QStringLiteral("updateButton"));
        updateButton->setMinimumSize(QSize(35, 0));
        updateButton->setMaximumSize(QSize(35, 16777215));
        updateButton->setStyleSheet(QLatin1String("background-color: rgb(54, 112, 148);\n"
"border-width: 2px;\n"
"border-color: beige;\n"
"color: #ffffff;"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/image/images/icons8-\320\277\320\265\321\200\320\265\320\267\320\260\320\277\321\203\321\201\320\272-40.png"), QSize(), QIcon::Normal, QIcon::Off);
        updateButton->setIcon(icon5);
        updateButton->setIconSize(QSize(29, 18));

        gridLayout_4->addWidget(updateButton, 1, 4, 1, 1);

        tableView_2 = new QTableView(tab_2);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setFont(font2);
        tableView_2->setStyleSheet(QStringLiteral("background-color: #dddfe4;"));

        gridLayout_4->addWidget(tableView_2, 2, 1, 1, 5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 1, 5, 1, 1);

        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(0, 5));
        label_6->setMaximumSize(QSize(16777215, 5));
        label_6->setStyleSheet(QLatin1String("background-color: rgb(54, 112, 148);\n"
"border-width: 2px;\n"
"border-color: beige;"));

        gridLayout_4->addWidget(label_6, 0, 1, 1, 5);


        gridLayout_6->addLayout(gridLayout_4, 1, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_6);

        ftpServerLineEdit = new QLineEdit(tab_2);
        ftpServerLineEdit->setObjectName(QStringLiteral("ftpServerLineEdit"));
        ftpServerLineEdit->setEnabled(false);

        verticalLayout_3->addWidget(ftpServerLineEdit);

        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(false);

        verticalLayout_3->addWidget(pushButton);

        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/image/images/icons8-\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214-\321\201\320\262\320\276\320\271\321\201\321\202\320\262\320\276-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_2, icon6, QString());

        gridLayout_3->addWidget(tabWidget, 1, 0, 1, 2);


        verticalLayout->addLayout(gridLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 1629, 32));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(false);
        mainToolBar->setMovable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\222\320\265\321\200\321\201\320\270\321\217 1.0", nullptr));
        label_4->setText(QString());
        name_app->setText(QApplication::translate("MainWindow", "\320\226\320\243\320\240\320\235\320\220\320\233 \320\232\320\236\320\234\320\220\320\235\320\224 ", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\320\224\320\236", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\236\320\242", nullptr));
        time_checkBox->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\270 \320\262\321\200\320\265\320\274\321\217", nullptr));
        element_checkBox->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200", nullptr));
        label_11->setText(QString());
        poisk_button->setText(QString());
        otchetButton->setText(QString());
        error_checkBox->setText(QApplication::translate("MainWindow", "\320\241\320\261\320\276\320\270 \321\201\320\270\321\201\321\202\320\265\320\274\321\213", nullptr));
        label_12->setText(QString());
        checkBox->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\260\320\261\320\276\320\275\320\265\320\275\321\202\320\260", nullptr));
        checkBox_2->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\272\320\276\320\274\320\260\320\275\320\264\321\213", nullptr));
        label_3->setText(QString());
        dateTimeEditOT->setDisplayFormat(QApplication::translate("MainWindow", "dd-MM-yyyy hh:mm:ss", nullptr));
        dateTimeEditDO->setDisplayFormat(QApplication::translate("MainWindow", "dd-MM-yyyy hh:mm:ss", nullptr));
        znachenie_checkBox->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\216", nullptr));
        lineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        tableView->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        kol_strok->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\267\320\260\320\277\320\270\321\201\320\265\320\271: 0", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\237\320\240\320\236\320\241\320\234\320\236\320\242\320\240 \320\224\320\220\320\235\320\235\320\253\320\245", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "\320\232\320\230 - \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\234\320\240 \320\267\320\260 \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\320\224\320\242 - \320\264\320\260\321\202\320\260 \320\270 \320\262\321\200\320\265\320\274\321\217 \320\267\320\260\320\277\320\270\321\201\320\270", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "\320\234\320\240 - \320\274\320\276\320\273\320\275\320\270\320\265\320\262\321\213\320\265 (\320\263\321\200\320\276\320\267\320\276\320\262\321\213\320\265) \321\200\320\260\320\267\321\200\321\217\320\264\321\213", nullptr));
        pB_meteo->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "\320\243\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\276", nullptr));
        dateTimeEdit_OT_meteo->setDisplayFormat(QApplication::translate("MainWindow", "dd-MM-yyyy hh:mm:ss", nullptr));
        dateTimeEdit_DO_meteo->setDisplayFormat(QApplication::translate("MainWindow", "dd-MM-yyyy hh:mm:ss", nullptr));
        lb_OT->setText(QApplication::translate("MainWindow", "\320\236\320\242", nullptr));
        lb_DO->setText(QApplication::translate("MainWindow", "\320\224\320\236", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\270 \320\262\321\200\320\265\320\274\321\217", nullptr));
        label_9->setText(QString());
        label_21->setText(QApplication::translate("MainWindow", "\320\243\320\250 - \321\203\321\200\320\276\320\262\320\265\320\275\321\214 \321\202\320\265\320\275\320\265\320\262\320\276\320\263\320\276 \321\210\321\203\320\274\320\260", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "\320\236\320\250 - \320\272\320\276\320\264 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\321\217 \320\270 \320\276\321\210\320\270\320\261\320\276\320\272", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "\320\232\320\222 - \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\234\320\240 \321\201 \320\274\320\276\320\274\320\265\320\275\321\202\320\260 \320\262\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217", nullptr));
        otchetButton_meteo->setText(QString());
        label_15->setText(QApplication::translate("MainWindow", "\321\2013, \321\20111, \321\20119, \321\20127", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\321\2011, \321\2019, \321\20117, \321\20125 ", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "\321\2015, \321\20113, \321\20121, \321\20129", nullptr));
        label_35->setText(QString());
        label_27->setText(QApplication::translate("MainWindow", "\321\201\320\265\320\272\321\202\320\276\321\200 0\302\260 - 45\302\260 ", nullptr));
        label_31->setText(QApplication::translate("MainWindow", "\321\201\320\265\320\272\321\202\320\276\321\200 180\302\260- 225\302\260 ", nullptr));
        label_28->setText(QApplication::translate("MainWindow", "\321\201\320\265\320\272\321\202\320\276\321\200 45\302\260 - 90\302\260", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "\321\2014, \321\20112, \321\20120, \321\20128", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "\321\2016, \321\20114, \321\20122, \321\20130", nullptr));
        label_29->setText(QApplication::translate("MainWindow", "\321\201\320\265\320\272\321\202\320\276\321\200 90\302\260 - 135\302\260 ", nullptr));
        label_34->setText(QApplication::translate("MainWindow", "\321\201\320\265\320\272\321\202\320\276\321\200 315\302\260 - 360\302\260 ", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\321\2012, \321\20110, \321\20118, \321\20126", nullptr));
        label_26->setText(QString());
        label_25->setText(QApplication::translate("MainWindow", "\321\2018, \321\20116, \321\20124, \321\20132", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "\321\2017, \321\20115, \321\20123, \321\20131", nullptr));
        label_37->setText(QString());
        label_32->setText(QApplication::translate("MainWindow", "\321\201\320\265\320\272\321\202\320\276\321\200  225\302\260 - 270\302\260", nullptr));
        label_30->setText(QApplication::translate("MainWindow", "\321\201\320\265\320\272\321\202\320\276\321\200 135\302\260 - 180\302\260 ", nullptr));
        label_33->setText(QApplication::translate("MainWindow", "\321\201\320\265\320\272\321\202\320\276\321\200 270\302\260 - 315\302\260", nullptr));
        label_36->setText(QString());
        label_38->setText(QString());
        label_39->setText(QString());
        label_40->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\320\234\320\225\320\242\320\225\320\236\320\240\320\236\320\233\320\236\320\223\320\230\320\247\320\225\320\241\320\232\320\230\320\225 \320\224\320\220\320\235\320\235\320\253\320\225", nullptr));
        label_5->setText(QString());
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arimo'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Verdana'; font-size:10pt; font-weight:400;\"><br /></p></body></html>", nullptr));
        connectButton->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\260\321\207\320\260\321\202\321\214 \321\204\320\260\320\271\320\273\321\213", nullptr));
        ftpServerLabel->setText(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273\320\276\320\262\321\213\320\271 \320\272\320\260\321\202\320\260\320\273\320\276\320\263 \320\275\320\260 \321\203\320\264\320\260\320\273\320\265\320\275\320\275\320\276\320\274 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\265:", nullptr));
        Name_log->setText(QApplication::translate("MainWindow", "\320\226\321\203\321\200\320\275\320\260\320\273 \321\204\320\260\320\271\320\273\320\276\320\262\321\213\321\205 \320\276\320\277\320\265\321\200\320\260\321\206\320\270\320\271:", nullptr));
        poisk_Button->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        poisk_label->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\264\320\260\321\202\320\265 \321\201\320\276\320\267\320\264\320\260\320\275\320\270\321\217 \321\204\320\260\320\271\320\273\320\260:", nullptr));
        updateButton->setText(QString());
        label_6->setText(QString());
        ftpServerLineEdit->setText(QApplication::translate("MainWindow", "127.0.0.1", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\224\320\236\320\221\320\220\320\222\320\233\320\225\320\235\320\230\320\225 \320\227\320\220\320\237\320\230\320\241\320\225\320\231", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
