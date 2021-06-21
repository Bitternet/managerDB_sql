#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableView>
#include <QtCore>
#include <QtGui>
#include <QtSql>
#include <QMessageBox>
#include <QStringList>
#include <QDebug>
//#include <QFtp>
#include <QProgressDialog>
#include <QFile>
#include <QNetworkConfiguration>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QEventLoop>
#include <QIODevice>
#include <QTextStream>
#include <iostream>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    delete ui->mainToolBar;

    QIcon(":/new/image/images/weby_analytics-statistics-128.png");

    db.setDatabaseName("zenit");
    db.setUserName("uzorky2_0_00");
    db.setHostName("10.1.57.87");
    db.setPassword("uzorky2_0_00");
    db.setPort(6003);

    if(!db.open())
    {
      QMessageBox::warning(this,"Ошибка","Не удалось подключиться к базе данных",QMessageBox::Ok);
    }

    //QSqlQueryModel *box = new QSqlQueryModel(ui->vibor_table_comBox);
    //box->setQuery("SELECT table_name FROM information_schema.tables WHERE table_schema='public' ORDER BY table_name;");
    //ui->vibor_table_comBox->setModel(box);
    //ui->vibor_table_comBox->show();

    QDateTime datTim = QDateTime::currentDateTime();

    ui->dateTimeEditOT->setDateTime(datTim);
    ui->dateTimeEditDO->setDateTime(datTim);

    ui->poisk_dateEdit->setDateTime(datTim);

    ui->fileList->setEnabled(false);
    ui->fileList->setRootIsDecorated(false);

    ui->fileList->setHeaderLabels(QStringList() << tr("Имя файла") << tr("Размер") << tr("Владелец") << tr("Группа") << tr("Время"));
    ui->fileList->header()->setStretchLastSection(false);

    //QNETACCESSMANAGER
    QString nameFile = "test_N.txt";
    ui->ftpServerLineEdit->setText("ftp://localhost/21122018.txt");
     // Создаем объект менеджера
    manager = new QNetworkAccessManager(this);

    ui->pushButton->setVisible(false);
    ui->ftpServerLineEdit->setVisible(false);

    on_pushButton_clicked();
    log_search();

    if(!ui->time_checkBox->checkState()&&!ui->element_checkBox->checkState()&&!ui->error_checkBox->checkState())
    {
    ui->lineEdit->setEnabled(false);
    ui->dateTimeEditOT->setEnabled(false);
    ui->dateTimeEditDO->setEnabled(false);
    }

    insertComBox();

    connect(ui->comboBox, SIGNAL(currentIndexChanged(QString)), SLOT(changeCombo()));

    ui->gridLayout->addWidget(list,0,14,1,4);
    list->setEnabled(false);

    ui->comboBox_meteo->addItem("АМК-ОП3", 0);
    ui->comboBox_meteo->addItem("ГДА-1", 1);

    QDateTime dt = QDateTime::currentDateTime();
    ui->dateTimeEdit_DO_meteo->setDateTime(dt);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeCombo()
{
    ch();
}

void MainWindow::ch()
{
    list->clear();

    QSqlQuery query3 = QSqlQuery(db);

    QString s = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();

    query3.exec("SELECT id_par, name_par FROM parametr_tbl WHERE abonent_par = " + s + " ORDER by id_par");

    while (query3.next())
    {
        list->addCheckItem(query3.value(1).toString(), query3.value(0), Qt::Unchecked);
    }
}

void MainWindow::on_poisk_button_clicked()
{
    model = new QSqlQueryModel(ui->tableView);

    QStandardItemModel* modelCheck = qobject_cast<QStandardItemModel*>(list->model());

    QString uslovie = "(select CASE WHEN parametr = 21572 THEN (select to_char((select to_timestamp(values)),'HH24:MI:SS')) "
                      //Входное устройство - 12
                      "WHEN  (mainlog.id_abonent = 12 AND mainlog.parametr = 17235) AND values = 1 THEN 'Значение: 1 - Установить светофильтр №: 1 (neutral)' "
                      "WHEN  (mainlog.id_abonent = 12 AND mainlog.parametr = 17235) AND values = 2 THEN 'Значение: 2 - Установить светофильтр №: 2 (blue' "
                      "WHEN  (mainlog.id_abonent = 12 AND mainlog.parametr = 17235) AND values = 3 THEN 'Значение: 3 - Установить светофильтр №: 3 (visual)' "
                      "WHEN  (mainlog.id_abonent = 12 AND mainlog.parametr = 17235) AND values = 4 THEN 'Значение: 4 - Установить светофильтр №: 4 (red)' "
                      "WHEN  (mainlog.id_abonent = 12 AND mainlog.parametr = 17235) AND values = 5 THEN 'Значение: 5 - Установить светофильтр №: 5 (infrared)' "
                      "WHEN  (mainlog.id_abonent = 12 AND mainlog.parametr = 17235) AND values = 7 THEN 'Значение: 7 - Производится вращение турели' "
                      "WHEN  (mainlog.id_abonent = 12 AND mainlog.parametr = 17235) AND values = 8 THEN 'Значение: 8 - Турель остановлена' "
                      "WHEN  (mainlog.id_abonent = 12 AND mainlog.parametr = 17235) AND values = 10 THEN 'Значение: 10 - Сбой устройства' "

                      "WHEN  (mainlog.id_abonent = 12 AND mainlog.parametr = 20051) AND values = 1 THEN 'Значение: 1 - Делитель 1:1' "
                      "WHEN  (mainlog.id_abonent = 12 AND mainlog.parametr = 20051) AND values = 2 THEN 'Значение: 2 - Делитель 1:300' "
                      "WHEN  (mainlog.id_abonent = 12 AND mainlog.parametr = 20051) AND values = 10 THEN 'Значение: 10 - Сбой устройства' "

                      "WHEN  (mainlog.id_abonent = 12 AND mainlog.parametr = 18010) AND values = 1 THEN 'Значение: 1 - Введено' "
                      "WHEN  (mainlog.id_abonent = 12 AND mainlog.parametr = 18010) AND values = 2 THEN 'Значение: 2 - Выведено' "
                      "WHEN  (mainlog.id_abonent = 12 AND mainlog.parametr = 18010) AND values = 10 THEN 'Значение: 10 - Сбой выполнения' "

                      "WHEN  (mainlog.id_abonent = 12 AND mainlog.parametr = 21338) AND values = 1 THEN 'Значение: 1 - Открыто' "
                      "WHEN  (mainlog.id_abonent = 12 AND mainlog.parametr = 21338) AND values = 2 THEN 'Значение: 2 - Закрыто' "
                      "WHEN  (mainlog.id_abonent = 12 AND mainlog.parametr = 21338) AND values = 10 THEN 'Значение: 10 - Сбой выполнения' "

                      "WHEN  (mainlog.id_abonent = 12 AND mainlog.parametr = 17990) AND values = 0 THEN 'Положение неизвестно' "
                      "WHEN  (mainlog.id_abonent = 12 AND mainlog.parametr = 17990) AND values > 0 OR values < 0  THEN CAST(values AS text) || ' - Значение шага двигателя' "

                      "WHEN  (mainlog.id_abonent = 12 AND mainlog.parametr = 21318) AND values = 0 THEN 'Положение неизвестно' "
                      "WHEN  (mainlog.id_abonent = 12 AND mainlog.parametr = 21318) AND  values > 0 OR values < 0 THEN CAST(values AS text) || ' - Значение шага двигателя' "

                      "WHEN  (mainlog.id_abonent = 12 AND mainlog.parametr = 18004) THEN 'Температура: ' || CAST((values * 0.625) AS text) || ' C°' "

                      //КСЕВ время - 0
                      "WHEN  (mainlog.id_abonent = 12 AND mainlog.parametr = 21578) AND values = 0 THEN 'Значение: 0 - Не определено' "
                      "WHEN  (mainlog.id_abonent = 12 AND mainlog.parametr = 21578) AND values = 1 THEN 'Значение: 1 - Есть' "
                      "WHEN  (mainlog.id_abonent = 12 AND mainlog.parametr = 21578) AND values = 2 THEN 'Значение: 2 - Нет' "

                      //КЭП ОСИ 9;10 16961
                      "WHEN  (mainlog.id_abonent = 9 OR mainlog.id_abonent = 10) AND (mainlog.parametr = 16961 AND values = 1) THEN 'Значение: 1 - Включить' "
                      "WHEN  (mainlog.id_abonent = 9 OR mainlog.id_abonent = 10) AND (mainlog.parametr = 16961 AND values = 2) THEN 'Значение: 2 - Выключить' "


                      "ELSE CAST(values AS text) END) "
                      "FROM " + table_name +
                      " INNER JOIN abonent_tbl ON mainlog.id_abonent = abonent_tbl.id_ab"
                      " INNER JOIN command_tbl ON mainlog.id_command = command_tbl.id_com"
                      " INNER JOIN status_tbl ON mainlog.status = status_tbl.id_status"
                      " INNER JOIN flag_tbl ON mainlog.flag = flag_tbl.id_flag"
                      " INNER JOIN parametr_tbl ON  mainlog.id_abonent = parametr_tbl.abonent_par AND mainlog.parametr = parametr_tbl.n_par";


    if (!ui->time_checkBox->isChecked() && !ui->element_checkBox->isChecked() && !ui->error_checkBox->isChecked() && !ui->checkBox->isChecked() && !ui->checkBox_2->isChecked() && !ui->znachenie_checkBox->isChecked())//0 0 0 0 0
    {
        /*"SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                   "(select CASE WHEN parametr = 21572 THEN (select to_char((select to_timestamp(values)),'HH24:MI:SS')) "
                   "ELSE CAST(values AS text) END) "
                   "FROM " + table_name +
                   " INNER JOIN abonent_tbl ON mainlog.id_abonent = abonent_tbl.id_ab"
                   " INNER JOIN command_tbl ON mainlog.id_command = command_tbl.id_com"
                   " INNER JOIN status_tbl ON mainlog.status = status_tbl.id_status"
                   " INNER JOIN flag_tbl ON mainlog.flag = flag_tbl.id_flag"
                   " INNER JOIN parametr_tbl ON  mainlog.id_abonent = parametr_tbl.abonent_par AND mainlog.parametr = parametr_tbl.n_par "
                   " ORDER BY datatime;";*/

       /*"SELECT id,datatime,id_abonent, id_command, status, parametr,(select CASE WHEN parametr = 21572 THEN (select CAST((select to_timestamp(values)) AS text))   "WHEN values = 0 THEN 'НЕ ОПРЕДЕЛЕНО' "
        "WHEN values = 1 THEN 'НОРМА/ВКЛ' "
        "WHEN values = 2 THEN 'ОТКАЗ/ВЫКЛ' "
        "WHEN values = 3 THEN 'НЕДОПУСТИМОЕ/СБОЙ' " else CAST(values AS text) END) FROM " + table_name + " ORDER BY datatime;";*/


       QString p1 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                    + uslovie +
                    " ORDER BY datatime;";
       get(p1);
    }

    if(ui->time_checkBox->isChecked()  && !ui->element_checkBox->isChecked() && !ui->error_checkBox->isChecked()  && !ui->checkBox->isChecked() && !ui->checkBox_2->isChecked() && !ui->znachenie_checkBox->isChecked())
    {
      QString tim = ui->dateTimeEditOT->text();
      QString tim2 = ui->dateTimeEditDO->text();

      QString p2 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                    + uslovie +
                   " WHERE datatime BETWEEN '"+tim+"' AND '"+tim2+"' ORDER BY datatime;";
      p2.replace("\""," ");
      get(p2);
    }

    if (ui->element_checkBox->isChecked() && !ui->time_checkBox->isChecked() && !ui->error_checkBox->isChecked()  && !ui->checkBox->isChecked() && !ui->checkBox_2->isChecked() && !ui->znachenie_checkBox->isChecked())
    {
        QStringList str;

        for (int row = 0; row < modelCheck->rowCount(); ++row) {
            if (modelCheck->item(row)->checkState() == (Qt::CheckState::Checked)) {
              str.append(modelCheck->item(row)->data().toString());
            }
          }

        QString s2 = "";

        for(int i = 0; i < str.size(); i++)
        {
            QString g = str.at(i);
            s2 += g;
            if(i !=  str.size()-1)
            s2 += ",";
        }

        QString p3 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                    + uslovie +
                    " WHERE id_par IN ("+s2+") ORDER BY datatime;";

       p3.replace("\""," ");
       get(p3);
    }

    if (!ui->element_checkBox->isChecked() && !ui->time_checkBox->isChecked() && !ui->error_checkBox->isChecked() && ui->checkBox->isChecked() && !ui->checkBox_2->isChecked() && !ui->znachenie_checkBox->isChecked())
    {
       QString s = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();

       QString p4 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                    + uslovie +
                    " WHERE id_abonent = '"+s+"' ORDER BY datatime;";

       p4.replace("\""," ");
       get(p4);
    }

    if (!ui->element_checkBox->isChecked() && !ui->time_checkBox->isChecked() && !ui->error_checkBox->isChecked() && !ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && !ui->znachenie_checkBox->isChecked())
    {
        QString s = ui->vibor_table_comBox->itemData(ui->vibor_table_comBox->currentIndex()).toString();

        QString p5 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                     + uslovie +
                     " WHERE id_command = '"+s+"' ORDER BY datatime;";

       p5.replace("\""," ");
       get(p5);
    }

    if (ui->error_checkBox->isChecked() && !ui->time_checkBox->isChecked() && !ui->element_checkBox->isChecked()&& !ui->checkBox->isChecked() && !ui->checkBox_2->isChecked() && !ui->znachenie_checkBox->isChecked())
    {

        QString p6 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                     + uslovie +
                     " WHERE values = 3 ORDER BY datatime;";

        p6.replace("\""," ");
        get(p6);
    }


    if (!ui->error_checkBox->isChecked() && !ui->time_checkBox->isChecked() && !ui->element_checkBox->isChecked()&& !ui->checkBox->isChecked() && !ui->checkBox_2->isChecked() && ui->znachenie_checkBox->isChecked())
    {
        QString s = ui->lineEdit->text();

        QString p7 =  "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                      + uslovie +
                      " WHERE values = "+s+" ORDER BY datatime;";

        p7.replace("\""," ");
        get(p7);
    }



    if (!ui->error_checkBox->isChecked() && !ui->time_checkBox->isChecked() && ui->element_checkBox->isChecked()&& ui->checkBox->isChecked() && !ui->checkBox_2->isChecked() && !ui->znachenie_checkBox->isChecked())
    {
        QString s1 = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();

        QStringList str;

        for (int row = 0; row < modelCheck->rowCount(); ++row) {
            if (modelCheck->item(row)->checkState() == (Qt::CheckState::Checked)) {
              str.append(modelCheck->item(row)->data().toString());
            }
          }

        QString s2 = "";

        for(int i = 0; i < str.size(); i++)
        {
            QString g = str.at(i);
            s2 += g;
            if(i !=  str.size()-1)
            s2 += ",";
        }


        QString p8  ="SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                             + uslovie +
                             " WHERE id_abonent = '"+s1+"' AND id_par IN ("+s2+") ORDER BY datatime;";

       p8.replace("\""," ");
       get(p8);
    }

    if(!ui->error_checkBox->isChecked() && ui->time_checkBox->isChecked() && ui->element_checkBox->isChecked()&& ui->checkBox->isChecked() && !ui->checkBox_2->isChecked() && !ui->znachenie_checkBox->isChecked())
    {
        QString s1 = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();

        QStringList str;

        for (int row = 0; row < modelCheck->rowCount(); ++row) {
            if (modelCheck->item(row)->checkState() == (Qt::CheckState::Checked)) {
              str.append(modelCheck->item(row)->data().toString());
            }
          }

        QString s2 = "";

        for(int i = 0; i < str.size(); i++)
        {
            QString g = str.at(i);
            s2 += g;
            if(i !=  str.size()-1)
            s2 += ",";
        }


        QString tim = ui->dateTimeEditOT->text();
        QString tim2 = ui->dateTimeEditDO->text();

        QString p9 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                     + uslovie +
                     " WHERE (id_abonent = '"+s1+"' AND id_par IN ("+s2+")) AND datatime BETWEEN '"+tim+"' AND '"+tim2+"'  ORDER BY datatime;";

        p9.replace("\""," ");
        get(p9);
    }

    if(!ui->error_checkBox->isChecked() && ui->time_checkBox->isChecked() && ui->element_checkBox->isChecked()&& ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && !ui->znachenie_checkBox->isChecked())
    {
        QString s1 = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();
        QStringList str;

        for (int row = 0; row < modelCheck->rowCount(); ++row) {
            if (modelCheck->item(row)->checkState() == (Qt::CheckState::Checked)) {
              str.append(modelCheck->item(row)->data().toString());
            }
          }

        QString s2 = "";

        for(int i = 0; i < str.size(); i++)
        {
            QString g = str.at(i);
            s2 += g;
            if(i !=  str.size()-1)
            s2 += ",";
        }
        QString s3 = ui->vibor_table_comBox->itemData(ui->vibor_table_comBox->currentIndex()).toString();

        QString tim = ui->dateTimeEditOT->text();
        QString tim2 = ui->dateTimeEditDO->text();

        QString p10 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE (id_abonent = '"+s1+"' AND id_par IN ("+s2+") AND (datatime BETWEEN '"+tim+"' AND '"+tim2+"' AND id_command = '"+s3+"') ORDER BY datatime;";

        p10.replace("\""," ");
        get(p10);
    }

    if(ui->error_checkBox->isChecked() && ui->time_checkBox->isChecked() && ui->element_checkBox->isChecked()&& ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && !ui->znachenie_checkBox->isChecked())
    {
        QString s1 = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();

        QStringList str;

        for (int row = 0; row < modelCheck->rowCount(); ++row) {
            if (modelCheck->item(row)->checkState() == (Qt::CheckState::Checked)) {
              str.append(modelCheck->item(row)->data().toString());
            }
          }

        QString s2 = "";

        for(int i = 0; i < str.size(); i++)
        {
            QString g = str.at(i);
            s2 += g;
            if(i !=  str.size()-1)
            s2 += ",";
        }

        QString s3 = ui->vibor_table_comBox->itemData(ui->vibor_table_comBox->currentIndex()).toString();

        QString tim = ui->dateTimeEditOT->text();
        QString tim2 = ui->dateTimeEditDO->text();

        QString p11 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE ((id_abonent = '"+s1+"' AND id_par IN ("+s2+")) AND (datatime BETWEEN '"+tim+"' AND '"+tim2+"' AND id_command = '"+s3+"'))  AND values = 3 ORDER BY datatime;";

        p11.replace("\""," ");
        get(p11);
    }

    if(!ui->error_checkBox->isChecked() && ui->time_checkBox->isChecked() && ui->element_checkBox->isChecked()&& ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && ui->znachenie_checkBox->isChecked())
    {
        QString s = ui->lineEdit->text();
        QString s1 = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();
        QStringList str;

        for (int row = 0; row < modelCheck->rowCount(); ++row) {
            if (modelCheck->item(row)->checkState() == (Qt::CheckState::Checked)) {
              str.append(modelCheck->item(row)->data().toString());
            }
          }

        QString s2 = "";

        for(int i = 0; i < str.size(); i++)
        {
            QString g = str.at(i);
            s2 += g;
            if(i !=  str.size()-1)
            s2 += ",";
        }
        QString s3 = ui->vibor_table_comBox->itemData(ui->vibor_table_comBox->currentIndex()).toString();

        QString tim = ui->dateTimeEditOT->text();
        QString tim2 = ui->dateTimeEditDO->text();

        QString p12 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE ((id_abonent = '"+s1+"' AND id_par IN ("+s2+")) AND (datatime BETWEEN '"+tim+"' AND '"+tim2+"' AND id_command = '"+s3+"'))  AND values = "+s+" ORDER BY datatime;";

        p12.replace("\""," ");
        get(p12);
    }

    if(ui->error_checkBox->isChecked() && !ui->time_checkBox->isChecked() && !ui->element_checkBox->isChecked()&& ui->checkBox->isChecked() && !ui->checkBox_2->isChecked() && !ui->znachenie_checkBox->isChecked())
    {
        QString s1 = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();

        QString p13 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE id_abonent = '"+s1+"' AND values = 3 ORDER BY datatime;";

        p13.replace("\""," ");
        get(p13);
    }

    if(ui->error_checkBox->isChecked() && ui->time_checkBox->isChecked() && !ui->element_checkBox->isChecked()&& !ui->checkBox->isChecked() && !ui->checkBox_2->isChecked() && !ui->znachenie_checkBox->isChecked())
    {

        QString tim = ui->dateTimeEditOT->text();
        QString tim2 = ui->dateTimeEditDO->text();

        QString p14 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE datatime BETWEEN '"+tim+"' AND '"+tim2+"' AND values = 3 ORDER BY datatime;";

        p14.replace("\""," ");
        get(p14);
    }

    if( !ui->checkBox->isChecked() && !ui->checkBox_2->isChecked() && !ui->time_checkBox->isChecked() && ui->element_checkBox->isChecked() && ui->error_checkBox->isChecked() && !ui->znachenie_checkBox->isChecked())
    {
        QStringList str;

        for (int row = 0; row < modelCheck->rowCount(); ++row) {
            if (modelCheck->item(row)->checkState() == (Qt::CheckState::Checked)) {
              str.append(modelCheck->item(row)->data().toString());
            }
          }

        QString s2 = "";

        for(int i = 0; i < str.size(); i++)
        {
            QString g = str.at(i);
            s2 += g;
            if(i !=  str.size()-1)
            s2 += ",";
        }

        QString p15 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE id_par IN ("+s2+") AND values = 3 ORDER BY datatime;";

        p15.replace("\""," ");
        get(p15);
    }

    if( ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && ui->time_checkBox->isChecked() && !ui->element_checkBox->isChecked() && ui->error_checkBox->isChecked() && !ui->znachenie_checkBox->isChecked())
    {
        QString s1 = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();
        QString s3 = ui->vibor_table_comBox->itemData(ui->vibor_table_comBox->currentIndex()).toString();

        QString tim = ui->dateTimeEditOT->text();
        QString tim2 = ui->dateTimeEditDO->text();

        QString p16 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE (id_abonent = '"+s1+"' AND id_command = '"+s3+"') AND (datatime BETWEEN '"+tim+"' AND '"+tim2+"' AND values = 3) ORDER BY datatime;";

        p16.replace("\""," ");
        get(p16);
    }

    if( ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && !ui->time_checkBox->isChecked() && !ui->element_checkBox->isChecked() && ui->error_checkBox->isChecked() && !ui->znachenie_checkBox->isChecked())
    {
        QString s1 = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();
        QString s3 = ui->vibor_table_comBox->itemData(ui->vibor_table_comBox->currentIndex()).toString();

        QString p17 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE (id_abonent = '"+s1+"' AND id_command = '"+s3+"') AND values = 3 ORDER BY datatime;";

        p17.replace("\""," ");
        get(p17);
    }

    if( ui->checkBox->isChecked() && !ui->checkBox_2->isChecked() && ui->time_checkBox->isChecked() && !ui->element_checkBox->isChecked() && ui->error_checkBox->isChecked() && !ui->znachenie_checkBox->isChecked())
    {
        QString s1 = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();

        QString tim = ui->dateTimeEditOT->text();
        QString tim2 = ui->dateTimeEditDO->text();

        QString p18 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                       + uslovie +
                        " WHERE (id_abonent = '"+s1+"' AND datatime BETWEEN '"+tim+"' AND '"+tim2+"') AND values = 3 ORDER BY datatime;";

        p18.replace("\""," ");
        get(p18);
    }

    if(!ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && !ui->time_checkBox->isChecked() && ui->element_checkBox->isChecked() && ui->error_checkBox->isChecked() && !ui->znachenie_checkBox->isChecked())
    {
        QString s1 = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();
        QStringList str;

        for (int row = 0; row < modelCheck->rowCount(); ++row) {
            if (modelCheck->item(row)->checkState() == (Qt::CheckState::Checked)) {
              str.append(modelCheck->item(row)->data().toString());
            }
          }

        QString s2 = "";

        for(int i = 0; i < str.size(); i++)
        {
            QString g = str.at(i);
            s2 += g;
            if(i !=  str.size()-1)
            s2 += ",";
        }

        QString p19 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE (id_abonent = '"+s1+"' AND id_par IN ("+s2+")) AND values = 3 ORDER BY datatime;";

        p19.replace("\""," ");
        get(p19);
    }

    if(!ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && ui->time_checkBox->isChecked() && ui->element_checkBox->isChecked() && ui->error_checkBox->isChecked() && !ui->znachenie_checkBox->isChecked())
    {
        QString s1 = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();
        QStringList str;

        for (int row = 0; row < modelCheck->rowCount(); ++row) {
            if (modelCheck->item(row)->checkState() == (Qt::CheckState::Checked)) {
              str.append(modelCheck->item(row)->data().toString());
            }
          }

        QString s2 = "";

        for(int i = 0; i < str.size(); i++)
        {
            QString g = str.at(i);
            s2 += g;
            if(i !=  str.size()-1)
            s2 += ",";
        }
        QString s3 = ui->vibor_table_comBox->itemData(ui->vibor_table_comBox->currentIndex()).toString();

        QString tim = ui->dateTimeEditOT->text();
        QString tim2 = ui->dateTimeEditDO->text();

        QString p20 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                       + uslovie +
                       " WHERE ((id_abonent = '"+s1+"' AND id_par IN ("+s2+")) AND (datatime BETWEEN '"+tim+"' AND '"+tim2+"' AND id_command = '"+s3+"'))  AND values = 3 ORDER BY datatime;";

        p20.replace("\""," ");
        get(p20);
    }

    if(!ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && !ui->time_checkBox->isChecked() && ui->element_checkBox->isChecked() && !ui->error_checkBox->isChecked() && ui->znachenie_checkBox->isChecked())
    {
        QString s = ui->lineEdit->text();
        QStringList str;

        for (int row = 0; row < modelCheck->rowCount(); ++row) {
            if (modelCheck->item(row)->checkState() == (Qt::CheckState::Checked)) {
              str.append(modelCheck->item(row)->data().toString());
            }
          }

        QString s2 = "";

        for(int i = 0; i < str.size(); i++)
        {
            QString g = str.at(i);
            s2 += g;
            if(i !=  str.size()-1)
            s2 += ",";
        }
        QString s3 = ui->vibor_table_comBox->itemData(ui->vibor_table_comBox->currentIndex()).toString();

        QString p21 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                       + uslovie +
                       " WHERE  (id_par IN ("+s2+") AND id_command = '"+s3+"')  AND values = "+s+" ORDER BY datatime;";

        p21.replace("\""," ");
        get(p21);
    }

    if(ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && ui->time_checkBox->isChecked() && ui->element_checkBox->isChecked() && !ui->error_checkBox->isChecked() && ui->znachenie_checkBox->isChecked())
    {
        QString s = ui->lineEdit->text();
        QString s1 = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();
        QStringList str;

        for (int row = 0; row < modelCheck->rowCount(); ++row) {
            if (modelCheck->item(row)->checkState() == (Qt::CheckState::Checked)) {
              str.append(modelCheck->item(row)->data().toString());
            }
          }

        QString s2 = "";

        for(int i = 0; i < str.size(); i++)
        {
            QString g = str.at(i);
            s2 += g;
            if(i !=  str.size()-1)
            s2 += ",";
        }
        QString s3 = ui->vibor_table_comBox->itemData(ui->vibor_table_comBox->currentIndex()).toString();

        QString tim = ui->dateTimeEditOT->text();
        QString tim2 = ui->dateTimeEditDO->text();

        QString p22 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE  id_abonent='"+s1+"' AND ((id_par IN ("+s2+") AND id_command = '"+s3+"') AND (datatime BETWEEN '"+tim+"' AND '"+tim2+"' AND values = "+s+")) ORDER BY datatime;";

        p22.replace("\""," ");
        get(p22);
    }

    if(ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && ui->time_checkBox->isChecked() && !ui->element_checkBox->isChecked() && !ui->error_checkBox->isChecked() && ui->znachenie_checkBox->isChecked())
    {
        QString s = ui->lineEdit->text();
        QString s1 = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();
        QString s3 = ui->vibor_table_comBox->itemData(ui->vibor_table_comBox->currentIndex()).toString();

        QString tim = ui->dateTimeEditOT->text();
        QString tim2 = ui->dateTimeEditDO->text();

        QString p23 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                       + uslovie +
                       " WHERE  (id_abonent='"+s1+"' AND  id_command = '"+s3+"') AND (datatime BETWEEN '"+tim+"' AND '"+tim2+"' AND values = "+s+") ORDER BY datatime;";

        p23.replace("\""," ");
        get(p23);
    }

    if(ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && !ui->time_checkBox->isChecked() && !ui->element_checkBox->isChecked() && !ui->error_checkBox->isChecked() && ui->znachenie_checkBox->isChecked())
    {
        QString s = ui->lineEdit->text();
        QString s1 = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();
        QString s3 = ui->vibor_table_comBox->itemData(ui->vibor_table_comBox->currentIndex()).toString();

        QString p24 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE  (id_abonent='"+s1+"' AND  id_command = '"+s3+"') AND values = "+s+" ORDER BY datatime;";

        p24.replace("\""," ");
        get(p24);
    }

    if(ui->checkBox->isChecked() && !ui->checkBox_2->isChecked() && ui->time_checkBox->isChecked() && !ui->element_checkBox->isChecked() && !ui->error_checkBox->isChecked() && ui->znachenie_checkBox->isChecked())
    {
        QString s = ui->lineEdit->text();
        QString s1 = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();

        QString tim = ui->dateTimeEditOT->text();
        QString tim2 = ui->dateTimeEditDO->text();

        QString p25 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE  (id_abonent='"+s1+"' AND datatime BETWEEN '"+tim+"' AND '"+tim2+"') AND values = "+s+" ORDER BY datatime;";

        p25.replace("\""," ");
        get(p25);
    }

    if(ui->checkBox->isChecked() && !ui->checkBox_2->isChecked() && !ui->time_checkBox->isChecked() && !ui->element_checkBox->isChecked() && !ui->error_checkBox->isChecked() && ui->znachenie_checkBox->isChecked())
    {
        QString s = ui->lineEdit->text();
        QString s1 = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();

        QString p26 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE id_abonent='"+s1+"' AND values = "+s+" ORDER BY datatime;";

        p26.replace("\""," ");
        get(p26);
    }

    if(ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && ui->time_checkBox->isChecked() && !ui->element_checkBox->isChecked() && !ui->error_checkBox->isChecked() && !ui->znachenie_checkBox->isChecked())
    {
        QString s1 = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();
        QString s3 = ui->vibor_table_comBox->itemData(ui->vibor_table_comBox->currentIndex()).toString();

        QString tim = ui->dateTimeEditOT->text();
        QString tim2 = ui->dateTimeEditDO->text();

        QString p27 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE (id_abonent='"+s1+"' AND id_command = '"+s3+"') AND datatime BETWEEN '"+tim+"' AND '"+tim2+"' ORDER BY datatime;";

        p27.replace("\""," ");
        get(p27);
    }

    if(ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && !ui->time_checkBox->isChecked() && !ui->element_checkBox->isChecked() && !ui->error_checkBox->isChecked() && !ui->znachenie_checkBox->isChecked())
    {
        QString s1 = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();
        QString s3 = ui->vibor_table_comBox->itemData(ui->vibor_table_comBox->currentIndex()).toString();

        QString p28 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE id_abonent='"+s1+"' AND id_command = '"+s3+"' ORDER BY datatime;";

        p28.replace("\""," ");
        get(p28);
    }

    if(!ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && ui->time_checkBox->isChecked() && ui->element_checkBox->isChecked() && !ui->error_checkBox->isChecked() && ui->znachenie_checkBox->isChecked())
    {
        QString s = ui->lineEdit->text();
        QStringList str;

        for (int row = 0; row < modelCheck->rowCount(); ++row) {
            if (modelCheck->item(row)->checkState() == (Qt::CheckState::Checked)) {
              str.append(modelCheck->item(row)->data().toString());
            }
          }

        QString s2 = "";

        for(int i = 0; i < str.size(); i++)
        {
            QString g = str.at(i);
            s2 += g;
            if(i !=  str.size()-1)
            s2 += ",";
        }
        QString s3 = ui->vibor_table_comBox->itemData(ui->vibor_table_comBox->currentIndex()).toString();

        QString tim = ui->dateTimeEditOT->text();
        QString tim2 = ui->dateTimeEditDO->text();

        QString p29 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE (id_par IN ("+s2+") AND id_command = '"+s3+"') AND (datatime BETWEEN '"+tim+"' AND '"+tim2+"' AND values = "+s+") ORDER BY datatime;";

        p29.replace("\""," ");
        get(p29);
    }

    if(!ui->checkBox->isChecked() && !ui->checkBox_2->isChecked() && ui->time_checkBox->isChecked() && ui->element_checkBox->isChecked() && !ui->error_checkBox->isChecked() && ui->znachenie_checkBox->isChecked())
    {
        QString s = ui->lineEdit->text();
        QString s3 = ui->vibor_table_comBox->itemData(ui->vibor_table_comBox->currentIndex()).toString();

        QString tim = ui->dateTimeEditOT->text();
        QString tim2 = ui->dateTimeEditDO->text();

        QString p30 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                       + uslovie +
                       " WHERE id_command = '"+s3+"' AND (datatime BETWEEN '"+tim+"' AND '"+tim2+"' AND values = "+s+") ORDER BY datatime;";

        p30.replace("\""," ");
        get(p30);
    }

    if(!ui->checkBox->isChecked() && !ui->checkBox_2->isChecked() && !ui->time_checkBox->isChecked() && ui->element_checkBox->isChecked() && !ui->error_checkBox->isChecked() && ui->znachenie_checkBox->isChecked())
    {
        QString s = ui->lineEdit->text();
        QStringList str;

        for (int row = 0; row < modelCheck->rowCount(); ++row) {
            if (modelCheck->item(row)->checkState() == (Qt::CheckState::Checked)) {
              str.append(modelCheck->item(row)->data().toString());
            }
          }

        QString s2 = "";

        for(int i = 0; i < str.size(); i++)
        {
            QString g = str.at(i);
            s2 += g;
            if(i !=  str.size()-1)
            s2 += ",";
        }


        QString p31 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE id_par IN ("+s2+") AND values = "+s+" ORDER BY datatime;";

        p31.replace("\""," ");
        get(p31);
    }

    if(!ui->checkBox->isChecked() && !ui->checkBox_2->isChecked() && ui->time_checkBox->isChecked() && ui->element_checkBox->isChecked() && !ui->error_checkBox->isChecked() && !ui->znachenie_checkBox->isChecked())
    {
        QStringList str;

        for (int row = 0; row < modelCheck->rowCount(); ++row) {
            if (modelCheck->item(row)->checkState() == (Qt::CheckState::Checked)) {
              str.append(modelCheck->item(row)->data().toString());
            }
          }

        QString s2 = "";

        for(int i = 0; i < str.size(); i++)
        {
            QString g = str.at(i);
            s2 += g;
            if(i !=  str.size()-1)
            s2 += ",";
        }

        QString tim = ui->dateTimeEditOT->text();
        QString tim2 = ui->dateTimeEditDO->text();


        QString p32 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE id_par IN ("+s2+") AND datatime BETWEEN '"+tim+"' AND '"+tim2+"' ORDER BY datatime;";

        p32.replace("\""," ");
        get(p32);
    }

    if(!ui->checkBox->isChecked() && !ui->checkBox_2->isChecked() && ui->time_checkBox->isChecked() && ui->element_checkBox->isChecked() && ui->error_checkBox->isChecked() && !ui->znachenie_checkBox->isChecked())
    {
        QStringList str;

        for (int row = 0; row < modelCheck->rowCount(); ++row) {
            if (modelCheck->item(row)->checkState() == (Qt::CheckState::Checked)) {
              str.append(modelCheck->item(row)->data().toString());
            }
          }

        QString s2 = "";

        for(int i = 0; i < str.size(); i++)
        {
            QString g = str.at(i);
            s2 += g;
            if(i !=  str.size()-1)
            s2 += ",";
        }

        QString tim = ui->dateTimeEditOT->text();
        QString tim2 = ui->dateTimeEditDO->text();


        QString p33 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE (id_par IN ("+s2+") AND datatime BETWEEN '"+tim+"' AND '"+tim2+"') AND values = 3 ORDER BY datatime;";

        p33.replace("\""," ");
        get(p33);
    }

    if(!ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && !ui->time_checkBox->isChecked() && ui->element_checkBox->isChecked() && !ui->error_checkBox->isChecked() && !ui->znachenie_checkBox->isChecked())
    {
        QStringList str;

        for (int row = 0; row < modelCheck->rowCount(); ++row) {
            if (modelCheck->item(row)->checkState() == (Qt::CheckState::Checked)) {
              str.append(modelCheck->item(row)->data().toString());
            }
          }

        QString s2 = "";

        for(int i = 0; i < str.size(); i++)
        {
            QString g = str.at(i);
            s2 += g;
            if(i !=  str.size()-1)
            s2 += ",";
        }
        QString s3 = ui->vibor_table_comBox->itemData(ui->vibor_table_comBox->currentIndex()).toString();

        QString p34 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE id_par IN ("+s2+") AND id_command = '"+s3+"' ORDER BY datatime;";

        p34.replace("\""," ");
        get(p34);
    }

    if(!ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && ui->time_checkBox->isChecked() && ui->element_checkBox->isChecked() && !ui->error_checkBox->isChecked() && !ui->znachenie_checkBox->isChecked())
    {
        QStringList str;

        for (int row = 0; row < modelCheck->rowCount(); ++row) {
            if (modelCheck->item(row)->checkState() == (Qt::CheckState::Checked)) {
              str.append(modelCheck->item(row)->data().toString());
            }
          }

        QString s2 = "";

        for(int i = 0; i < str.size(); i++)
        {
            QString g = str.at(i);
            s2 += g;
            if(i !=  str.size()-1)
            s2 += ",";
        }
        QString s3 = ui->vibor_table_comBox->itemData(ui->vibor_table_comBox->currentIndex()).toString();

        QString tim = ui->dateTimeEditOT->text();
        QString tim2 = ui->dateTimeEditDO->text();

        QString p35 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE (id_par IN ("+s2+") AND id_command = '"+s3+"') AND datatime BETWEEN '"+tim+"' AND '"+tim2+"' ORDER BY datatime;";

        p35.replace("\""," ");
        get(p35);
    }

    if(!ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && ui->time_checkBox->isChecked() && !ui->element_checkBox->isChecked() && !ui->error_checkBox->isChecked() && !ui->znachenie_checkBox->isChecked())
    {
        QString s3 = ui->vibor_table_comBox->itemData(ui->vibor_table_comBox->currentIndex()).toString();

        QString tim = ui->dateTimeEditOT->text();
        QString tim2 = ui->dateTimeEditDO->text();

        QString p36 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE id_command = '"+s3+"' AND datatime BETWEEN '"+tim+"' AND '"+tim2+"' ORDER BY datatime;";

        p36.replace("\""," ");
        get(p36);
    }

    if(!ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && !ui->time_checkBox->isChecked() && !ui->element_checkBox->isChecked() && ui->error_checkBox->isChecked() && !ui->znachenie_checkBox->isChecked())
    {
        QString s3 = ui->vibor_table_comBox->itemData(ui->vibor_table_comBox->currentIndex()).toString();

        QString p37 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE id_command = '"+s3+"' AND values = 3 ORDER BY datatime;";

        p37.replace("\""," ");
        get(p37);
    }

    if(!ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && ui->time_checkBox->isChecked() && !ui->element_checkBox->isChecked() && !ui->error_checkBox->isChecked() && ui->znachenie_checkBox->isChecked())
    {
        QString s = ui->lineEdit->text();
        QString s3 = ui->vibor_table_comBox->itemData(ui->vibor_table_comBox->currentIndex()).toString();

        QString tim = ui->dateTimeEditOT->text();
        QString tim2 = ui->dateTimeEditDO->text();

        QString p38 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE (id_command = '"+s3+"' AND datatime BETWEEN '"+tim+"' AND '"+tim2+"') AND values = "+s+" ORDER BY datatime;";

        p38.replace("\""," ");
        get(p38);
    }

    if(!ui->checkBox->isChecked() && !ui->checkBox_2->isChecked() && ui->time_checkBox->isChecked() && !ui->element_checkBox->isChecked() && !ui->error_checkBox->isChecked() && ui->znachenie_checkBox->isChecked())
    {
        QString s = ui->lineEdit->text();

        QString tim = ui->dateTimeEditOT->text();
        QString tim2 = ui->dateTimeEditDO->text();

        QString p39 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE datatime BETWEEN '"+tim+"' AND '"+tim2+"' AND values = "+s+" ORDER BY datatime;";

        p39.replace("\""," ");
        get(p39);
    }

    if(ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && !ui->time_checkBox->isChecked() && ui->element_checkBox->isChecked() && !ui->error_checkBox->isChecked() && !ui->znachenie_checkBox->isChecked())
    {
        QString s1 = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();
        QStringList str;

        for (int row = 0; row < modelCheck->rowCount(); ++row) {
            if (modelCheck->item(row)->checkState() == (Qt::CheckState::Checked)) {
              str.append(modelCheck->item(row)->data().toString());
            }
          }

        QString s2 = "";

        for(int i = 0; i < str.size(); i++)
        {
            QString g = str.at(i);
            s2 += g;
            if(i !=  str.size()-1)
            s2 += ",";
        }
        QString s3 = ui->vibor_table_comBox->itemData(ui->vibor_table_comBox->currentIndex()).toString();

        QString p40 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE id_abonent='"+s1+"' AND (id_par IN ("+s2+") AND id_command = '"+s3+"') ORDER BY datatime;";

        p40.replace("\""," ");
        get(p40);
    }

    if(!ui->checkBox->isChecked() && ui->checkBox_2->isChecked() && !ui->time_checkBox->isChecked() && !ui->element_checkBox->isChecked() && !ui->error_checkBox->isChecked() && ui->znachenie_checkBox->isChecked())
    {
        QString s = ui->lineEdit->text();
        QString s3 = ui->vibor_table_comBox->itemData(ui->vibor_table_comBox->currentIndex()).toString();

        QString p41 = "SELECT mainlog.id, mainlog.datatime, abonent_tbl.name_ab, command_tbl.name_com, name_flag, name_status, name_par, "
                        + uslovie +
                        " WHERE id_command = '"+s3+"' AND values = "+s+" ORDER BY datatime;";

        p41.replace("\""," ");
        get(p41);
    }

    ui->tableView->setModel(model);
    ui->tableView->show();
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setColumnWidth(1,170);
    ui->tableView->setColumnWidth(2,450);
    ui->tableView->setColumnWidth(3,130);
    ui->tableView->setColumnWidth(4,130);
    ui->tableView->setColumnWidth(5,130);
    ui->tableView->setColumnWidth(6,350);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->horizontalHeader()->setStyleSheet("background-color: grey; color: white;");
    ui->tableView->setItemDelegateForColumn(1,new mDelegate);
}


void MainWindow::on_vibor_table_comBox_currentIndexChanged(const QString &cpu)
{
  /*  if(cpu=="ОЭС5601")
    {
      table_name=" cpu1 ";
    }

    if(cpu=="ОЭС5602")
    {
      table_name=" cpu2 ";
    }

    if(cpu=="ОЭС5603")
    {
      table_name=" cpu3 ";
    }*/
}

void MainWindow::on_connectButton_clicked()
{
      if (nameFile=="")
      {
          nameFile = "test_N.txt";
      }

      QString path = "ftp://localhost/";
    // берем адрес введенный в текстовое поле
      QString str_download= (path+nameFile);
      qDebug()<<str_download;
      QUrl url(str_download);
      //QUrl url(ui->ftpServerLineEdit->text());
      url.setPort(21);
      //url.setUserName("anonymous");
      //url.setPassword("");

      QNetworkRequest request(url);
      QNetworkReply* reply=  manager->get(request);

      // реализуем ожидание конца загрузки
      QEventLoop loop;
      connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));

      loop.exec();

      // выводим содержимое
      if (reply->error() == QNetworkReply::NoError)
      {
        QFile file(nameFile);
        if(file.open(QIODevice::WriteOnly))
        {
          QTextStream out(&file);
          QByteArray content = reply->readAll();
          QTextCodec * codec = QTextCodec::codecForName("cp1251");
          QString cont = codec->toUnicode(content.data());
          out.setCodec("cp1251");
          out<<cont;
          ui->textBrowser->clear();
          ui->textBrowser->setPlainText("Файлы скачаны");
        }
      }
      else // вывод ошибки
      ui->textBrowser->setPlainText(reply->errorString());
      reply->deleteLater();

      //writeFile();
  }

void MainWindow::on_pushButton_clicked()
{
  /*   ui->fileList->clear();

     QString Server ="127.0.0.1";
     quint16 port=21;

     //QString FTPUser = "master";
     //QString FTPPass = "Mm30052017";

     QFtp *ftp = new QFtp(this);
     ftp->connectToHost(Server, port);
     ftp->login();
     //ftp->login(FTPUser, FTPPass);
     ftp->setTransferMode(QFtp::Passive);

     if(!ftp)
     {
         ui->textBrowser->append(ftp->errorString());
     }
     ui->textBrowser->clear();
     ui->textBrowser->append("Чтение каталога");

     ftp->list();
     connect(ftp, SIGNAL(listInfo(QUrlInfo)),
             this, SLOT(addToList(QUrlInfo)));

     ftp->close();*/
}

/*void MainWindow::addToList(const QUrlInfo &urlInfo)
{
   /* QTreeWidgetItem *item = new QTreeWidgetItem;
    item->setText(0, urlInfo.name());
    item->setText(1, QString::number(urlInfo.size()));
    item->setText(2, urlInfo.owner());
    item->setText(3, urlInfo.group());
    item->setText(4, urlInfo.lastModified().toString("MMM dd yyyy"));

    ui->fileList->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->fileList->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->fileList->setEditTriggers(QAbstractItemView::NoEditTriggers);


    isDirectory[urlInfo.name()] = urlInfo.isDir();
    ui->fileList->addTopLevelItem(item);
    if (!ui->fileList->currentItem())
    {
    ui->fileList->setCurrentItem(ui->fileList->topLevelItem(0));
    ui->fileList->setEnabled(true);
    }
}*/

/*void MainWindow::writeFile()
{
   QString Server ="127.0.0.1";
    quint16 port=21;

    //QString FTPUser = "master";
    //QString FTPPass = "Mm30052017";

    QFtp *ftp = new QFtp(this);
    ftp->connectToHost(Server, port);
    ftp->login();
    //ftp->login(FTPUser, FTPPass);
    ftp->setTransferMode(QFtp::Passive);
    ftp->list();
    connect(ftp, SIGNAL(listInfo(QUrlInfo)),
            this, SLOT(findName(QUrlInfo)));

    QFile inputFile("/root/build-sql-Desktop-Debug/"+nameFile);
    QFileInfo name_data =(inputFile.fileName());

    QString f_data(name_data.fileName());
    f_data.replace(".txt","");
    f_data.insert(2,".");
    f_data.insert(5,".");

    QString data1="отсутствует";
    QString abonent1="отсутствует";
    QString kom1="отсутствует";
    QString m="'";
    QString null="отсутствует";

    QTime time = QTime::currentTime();
    QString tim = time.toString("hh:mm:ss");

    QDate date = QDate::currentDate();
    QString dat = date.toString("dd.MM.yyyy");

    int kol;

    if(nameFile!="test_N.txt")
    {
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       in.setCodec("cp1251");
       while (!in.atEnd())
       {
          QString line = in.readLine();
          {
          QStringList data = line.split(QRegExp("\\-"),QString::SkipEmptyParts);
          kol=data[0].count();
          if(kol<=8)data1 = data[0];

          QStringList abonent = line.split(QRegExp("[\\:\\-]"),QString::SkipEmptyParts);
          int kol1=abonent[3].count();
          if(kol1<=12)abonent1 = abonent[3];

          QStringList kom = line.split(QRegExp("\\: "),QString::SkipEmptyParts);
          int i=kom.count();
          if (i==2) kom1=kom[1];
          }
       if(null!=kom1)
       {
       QString insertSql = QString("INSERT INTO cpu3 (data,time,abonent,message) VALUES ("+m+f_data+m+","+m+data1+m+","+m+abonent1+m+","+m+kom1+m+")");
       insertSql.replace("\""," ");
       QSqlQuery query(insertSql,db);
       query.exec();
       qDebug()<<insertSql;
       }
       }
       QString proverka =  QString("INSERT INTO log (time, data_write, data, name_file) VALUES ("+m+tim+m+","+m+dat+m+","+m+f_data+m+","+m+nameFile+m+")");
       proverka.replace("\""," ");
       QSqlQuery query_proverka(proverka,db);
       query_proverka.exec();
       qDebug()<<proverka;
       qDebug()<<"ЗАПИСЬ ПРОШЛА УСПЕШНО";
       nameFile = "test_N.txt";
       inputFile.close();
       inputFile.remove();
       log_search();
     }
    }
    else
    {
    ui->textBrowser->setPlainText("Записи уже внесены в базу данных");
    qDebug()<<"Записи уже внесены в базу данных";
    }
}*/



/*void MainWindow::findName(const QUrlInfo &urlInfo)
{
   QString path = "/root/build-sql-Desktop-Debug/";
   QString nam = urlInfo.name();
   QString m="'";

   QString inSql = QString("SELECT * FROM log WHERE name_file LIKE "+m+nam+m+"");
   inSql.replace("\""," ");
   //qDebug()<<inSql;
   QSqlQuery sql = QSqlQuery();
   sql.exec(inSql);
   if(sql.isActive())
   {
           QSqlRecord rec=sql.record();
           //qDebug()<<"в таблице" << rec.count() << "строк";
           int sql_size = sql.size();

           if(sql_size==0)
           {
              nameFile = urlInfo.name();
              //qDebug()<<nameFile;
              on_connectButton_clicked();
           }*/
           /*
           else
           {
              QMessageBox::warning(this,"Ошибка","Ошибка поиска имени",QMessageBox::Ok);
           }

   while(sql.next())
   {
       int id = sql.value(0).toInt();
       QString  s = sql.value(1).toString();
       QString  str= sql.value(2).toString();
       QString  strName = sql.value(3).toString();
       qDebug()<<inSql;
       qDebug()<<id<<s<<str<<strName;
   }

   }
   else
   {
       QMessageBox::warning(this,"Ошибка","Невозможно получить данные",QMessageBox::Ok);
   }
}*/

void MainWindow::log_search()
{
    QSqlQueryModel * model_log = new QSqlQueryModel(ui->tableView_2);

    model_log ->setQuery("SELECT * FROM log ORDER BY data_write,time;");
    model_log ->setHeaderData(1,Qt::Horizontal,"ВРЕМЯ");
    model_log ->setHeaderData(2,Qt::Horizontal,"ДАТА ЗАПИСИ");
    model_log ->setHeaderData(3,Qt::Horizontal,"ДАТА СОЗДАНИЯ");
    model_log ->setHeaderData(4,Qt::Horizontal,"ИМЯ ФАЙЛА");
    ui->tableView_2->setModel(model_log);
    ui->tableView_2->show();
    ui->tableView_2->setColumnHidden(0,true);
    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_2->setColumnWidth(1,100);
    ui->tableView_2->setColumnWidth(2,110);
    ui->tableView_2->setColumnWidth(3,130);
    ui->tableView_2->horizontalHeader()->setStretchLastSection(true);
    ui->tableView_2->horizontalHeader()->setStyleSheet("background-color: grey; color: white;");
}



void MainWindow::on_poisk_Button_clicked()
{
    QSqlQueryModel * model_log = new QSqlQueryModel(ui->tableView_2);
    QString data_poisk = ui->poisk_dateEdit->text();

    QString query_poisk = ("SELECT * FROM log WHERE data_write LIKE '%"+data_poisk+"%' ORDER BY time;");
    query_poisk.replace("\""," ");
    model_log->setQuery(query_poisk);

    model_log ->setHeaderData(1,Qt::Horizontal,"ВРЕМЯ");
    model_log ->setHeaderData(2,Qt::Horizontal,"ДАТА ЗАПИСИ");
    model_log ->setHeaderData(3,Qt::Horizontal,"ДАТА СОЗДАНИЯ");
    model_log ->setHeaderData(4,Qt::Horizontal,"ИМЯ ФАЙЛА");

    ui->tableView_2->setModel(model_log);
    ui->tableView_2->show();

}

void MainWindow::on_updateButton_clicked()
{
    log_search();
}

void MainWindow::on_otchetButton_clicked()
{
         QString filenam = QFileDialog::getSaveFileName(this,
           tr("Сохранить файл"),  QDir::currentPath(), tr("Табличный файл CSV (*.csv)"));

         QFile csvFile(filenam);

         QString shapka = "Отчет\n№$ДАТА И ВРЕМЯ$АБОНЕНТ$ТИП КОМАНДЫ$ФЛАГ$СТАТУС$ПАРАМЕТР$СООБЩЕНИЕ$\n";

         QString str;

         int column = model->columnCount();
         int row = model->rowCount();

         for (int i=0;i<row;i++)
         {
         for (int j = 0;j<column;j++)
         {
             str += model->data(model->index(i,j)).toString();
             str += "$ ";
         }
         str += "\n";
         }

         if(csvFile.open(QIODevice::WriteOnly | QIODevice::Text))
         {
             QTextStream out(&csvFile);
             qDebug()<<str;
             out<<shapka+str;
             csvFile.close();
         }
}



void MainWindow::on_time_checkBox_clicked()
{
    if(ui->time_checkBox->isChecked())
    {
        ui->dateTimeEditOT->setEnabled(true);
        ui->dateTimeEditDO->setEnabled(true);
        ui->dateTimeEditOT->setFocus(Qt::MouseFocusReason);
    }
    else
    {
        ui->dateTimeEditOT->setEnabled(false);
        ui->dateTimeEditDO->setEnabled(false);
    }

}

void MainWindow::on_element_checkBox_clicked()
{
    if(ui->element_checkBox->isChecked())
    {
        list->setEnabled(true);
    }
    else
    {
        list->setEnabled(false);
    }
}

void MainWindow::insertComBox()
{
    ui->comboBox->clear();
    ui->vibor_table_comBox->clear();
    list->clear();

    QSqlQuery query1 = QSqlQuery(db);
    query1.exec("SELECT id_ab,name_ab FROM abonent_tbl ORDER by id_ab");

    while (query1.next())
    {
        ui->comboBox->addItem(query1.value(1).toString(), query1.value(0));
    }

    QSqlQuery query2 = QSqlQuery(db);
    query2.exec("SELECT id_com,name_com FROM command_tbl ORDER by id_com");

    while (query2.next())
    {
        ui->vibor_table_comBox->addItem(query2.value(1).toString(), query2.value(0));
    }


    if(ui->checkBox->isChecked())
    {
    QSqlQuery query3 = QSqlQuery(db);

    QString s = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();

    query3.exec("SELECT id_par, name_par FROM parametr_tbl WHERE abonent_par = "+s+" ORDER by id_par");

    while (query3.next())
    {
        list->addCheckItem(query3.value(1).toString(), query3.value(0), Qt::Unchecked);
    }
    }
    else
    {
        QSqlQuery query3 = QSqlQuery(db);
        query3.exec("SELECT id_par, name_par FROM parametr_tbl ORDER by id_par");

        while (query3.next())
        {
            list->addCheckItem(query3.value(1).toString(), query3.value(0), Qt::Unchecked);
        }
    }

}

 void MainWindow::get(QString str)
 {
     model->setQuery(str);
     qDebug() << str;
     model->setHeaderData(1,Qt::Horizontal,"ДАТА");
     model->setHeaderData(2,Qt::Horizontal,"АБОНЕНТ");
     model->setHeaderData(3,Qt::Horizontal,"ТИП КОМАНДЫ");
     model->setHeaderData(4,Qt::Horizontal,"ФЛАГ");
     model->setHeaderData(5,Qt::Horizontal,"СТАТУС");
     model->setHeaderData(6,Qt::Horizontal,"ПАРАМЕТР");
     model->setHeaderData(7,Qt::Horizontal,"ЗНАЧЕНИЕ");

     int ks = model->rowCount();
     QString sks = QString::number(ks);
     ui->kol_strok->setText("Количество записей: "+sks);
 }

void MainWindow::on_checkBox_clicked()
{
    list->clear();
    list->addItem("НЕ ВЫБРАН ТИП АБОНЕНТА");

    if(ui->checkBox->isChecked())
    {
        ui->comboBox->setEnabled(true);
        ui->comboBox->setFocus(Qt::MouseFocusReason);
        //insertComBox();
    }
    else
    {
        ui->comboBox->setEnabled(false);
        insertComBox();
    }
}


void MainWindow::on_checkBox_2_clicked()
{
    if(ui->checkBox_2->isChecked())
    {
        ui->vibor_table_comBox->setEnabled(true);
        ui->vibor_table_comBox->setFocus(Qt::MouseFocusReason);
    }
    else
    {
        ui->vibor_table_comBox->setEnabled(false);
    }
}

void MainWindow::on_znachenie_checkBox_clicked()
{
    if(ui->znachenie_checkBox->isChecked())
    {
        ui->lineEdit->setEnabled(true);
        ui->lineEdit->setFocus(Qt::MouseFocusReason);
        ui->lineEdit->setText("0");
        ui->error_checkBox->setChecked(false);
    }
    else
    {
        ui->lineEdit->setEnabled(false);
    }
}

void MainWindow::on_error_checkBox_clicked()
{
    if(ui->znachenie_checkBox->isChecked())
    {
        ui->lineEdit->clear();
        ui->lineEdit->setEnabled(false);
        ui->znachenie_checkBox->setChecked(false);
    }
    else
    {
        ui->lineEdit->setEnabled(false);
    }
}



void MainWindow::on_pB_meteo_clicked()
{
    model_meteo = new QSqlQueryModel(ui->tableView_meteo);

    QString dt1 = ui->dateTimeEdit_OT_meteo->text();
    QString dt2 = ui->dateTimeEdit_DO_meteo->text();

    if(ui->comboBox_meteo->currentIndex() == 0)
    {
    QString qsql0 = "SELECT datatime_write, v, t, p, w, d FROM amk"
                    " WHERE datatime_write BETWEEN '"+ dt1 +"' AND '"+ dt2 +"' ORDER BY datatime_write;";

    qsql0.replace("\""," ");
    qDebug()<<qsql0;
    model_meteo->setQuery(qsql0);

    model_meteo ->setHeaderData(0,Qt::Horizontal,"Дата записи");
    model_meteo ->setHeaderData(1,Qt::Horizontal,"V(скорость ветра)");
    model_meteo ->setHeaderData(2,Qt::Horizontal,"T(температура)");
    model_meteo ->setHeaderData(3,Qt::Horizontal,"P(давление)");
    model_meteo ->setHeaderData(4,Qt::Horizontal,"W(влажность)");
    model_meteo ->setHeaderData(5,Qt::Horizontal,"D(направление ветра)");

    ui->tableView_meteo->setModel(model_meteo);
    ui->tableView_meteo->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_meteo->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_meteo->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_meteo->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    ui->tableView_meteo->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tableView_meteo->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    ui->tableView_meteo->horizontalHeader()->setSectionResizeMode(3,QHeaderView::Stretch);
    ui->tableView_meteo->horizontalHeader()->setSectionResizeMode(4,QHeaderView::Stretch);
    ui->tableView_meteo->horizontalHeader()->setSectionResizeMode(5,QHeaderView::Stretch);
    ui->tableView_meteo->horizontalHeader()->setStretchLastSection(true);
    ui->tableView_meteo->horizontalHeader()->setStyleSheet("background-color: grey; color: white;");
    ui->tableView_meteo->show();
    }

    else if(ui->comboBox_meteo->currentIndex() == 1)
    {
    QString qsql1 = "SELECT * FROM gda_1"
                    " WHERE datatime_write BETWEEN '"+ dt1 +"' AND '"+ dt2 +"' ORDER BY datatime_write;";

    qsql1.replace("\""," ");
    qDebug()<<qsql1;
    model_meteo->setQuery(qsql1);

    model_meteo ->setHeaderData(1,Qt::Horizontal,"Дата записи");
    model_meteo ->setHeaderData(2,Qt::Horizontal,"ОШ");
    model_meteo ->setHeaderData(3,Qt::Horizontal,"  с1  ");
    model_meteo ->setHeaderData(4,Qt::Horizontal,"  с2  ");
    model_meteo ->setHeaderData(5,Qt::Horizontal,"  с3  ");
    model_meteo ->setHeaderData(6,Qt::Horizontal,"  с4  ");
    model_meteo ->setHeaderData(7,Qt::Horizontal,"с5");
    model_meteo ->setHeaderData(8,Qt::Horizontal,"с6");
    model_meteo ->setHeaderData(9,Qt::Horizontal,"с7");
    model_meteo ->setHeaderData(10,Qt::Horizontal,"с8");
    model_meteo ->setHeaderData(11,Qt::Horizontal,"с9");
    model_meteo ->setHeaderData(12,Qt::Horizontal,"с10");
    model_meteo ->setHeaderData(13,Qt::Horizontal,"с11");
    model_meteo ->setHeaderData(14,Qt::Horizontal,"с12");
    model_meteo ->setHeaderData(15,Qt::Horizontal,"с13");
    model_meteo ->setHeaderData(16,Qt::Horizontal,"с14");
    model_meteo ->setHeaderData(17,Qt::Horizontal,"с15");
    model_meteo ->setHeaderData(18,Qt::Horizontal,"с16");
    model_meteo ->setHeaderData(19,Qt::Horizontal,"с17");
    model_meteo ->setHeaderData(20,Qt::Horizontal,"с18");
    model_meteo ->setHeaderData(21,Qt::Horizontal,"с19");
    model_meteo ->setHeaderData(22,Qt::Horizontal,"с20");
    model_meteo ->setHeaderData(23,Qt::Horizontal,"с21");
    model_meteo ->setHeaderData(24,Qt::Horizontal,"с22");
    model_meteo ->setHeaderData(25,Qt::Horizontal,"с23");
    model_meteo ->setHeaderData(26,Qt::Horizontal,"с24");
    model_meteo ->setHeaderData(27,Qt::Horizontal,"с25");
    model_meteo ->setHeaderData(28,Qt::Horizontal,"с26");
    model_meteo ->setHeaderData(29,Qt::Horizontal,"с27");
    model_meteo ->setHeaderData(30,Qt::Horizontal,"с28");
    model_meteo ->setHeaderData(31,Qt::Horizontal,"с29");
    model_meteo ->setHeaderData(32,Qt::Horizontal,"с30");
    model_meteo ->setHeaderData(33,Qt::Horizontal,"с31");
    model_meteo ->setHeaderData(34,Qt::Horizontal,"с32");
    model_meteo ->setHeaderData(35,Qt::Horizontal,"КИ");
    model_meteo ->setHeaderData(36,Qt::Horizontal,"КВ");
    model_meteo ->setHeaderData(37,Qt::Horizontal,"УШ");

    ui->tableView_meteo->setModel(model_meteo);

    ui->tableView_meteo->setColumnHidden(0,true);

    ui->tableView_meteo->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_meteo->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_meteo->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_meteo->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->tableView_meteo->horizontalHeader()->setSectionResizeMode(2,QHeaderView::ResizeToContents);
    ui->tableView_meteo->horizontalHeader()->setSectionResizeMode(3,QHeaderView::ResizeToContents);
    ui->tableView_meteo->horizontalHeader()->setSectionResizeMode(4,QHeaderView::ResizeToContents);
    ui->tableView_meteo->horizontalHeader()->setSectionResizeMode(5,QHeaderView::ResizeToContents);
    ui->tableView_meteo->horizontalHeader()->setStretchLastSection(true);
    ui->tableView_meteo->horizontalHeader()->setStyleSheet("background-color: grey; color: white;");
    ui->tableView_meteo->show();
    }
}


void MainWindow::on_otchetButton_meteo_clicked()
{
    QString filenam = QFileDialog::getSaveFileName(this,
      tr("Сохранить файл"),  QDir::currentPath(), tr("Табличный файл CSV (*.csv)"));

    QFile csvFile(filenam);

    QString shapka = "";

    if(ui->comboBox_meteo->currentIndex() == 0)
    {
        shapka = "Отчет\nДата записи$V(скорость ветра)$T(температура)$P(давление)$W(влажность)$ПD(направление ветра)$\n";
    }
    else if(ui->comboBox_meteo->currentIndex() == 1)
    {
        shapka = "Отчет\n№$Дата записи$ОШ$с1$с2$с3$с4$с5$с6$с7$с8$с9$с10$с11$с12$с13$с14$с15$с16$с17$с18$с19$с20$с21$с22$с23$с24$с25$с26$с27$с28$с29$с30$с31$c32$КИ$КВ$УШ$\n";
    }

    QString str;

    int column = model_meteo->columnCount();
    int row = model_meteo->rowCount();

    for (int i=0;i<row;i++)
    {
    for (int j = 0;j<column;j++)
    {
        str += model_meteo->data( model_meteo->index(i,j)).toString();
        str += "$ ";
    }
    str += "\n";
    }

    if(csvFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&csvFile);
        qDebug()<<str;
        out<<shapka+str;
        csvFile.close();
    }
}
