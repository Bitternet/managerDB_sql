#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
//#include <QUrlInfo>
#include <QHash>
#include <QtSql>
#include <QStyledItemDelegate>
#include "qchecklist.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    void on_poisk_button_clicked();

    void on_vibor_table_comBox_currentIndexChanged(const QString &arg1);

    void on_connectButton_clicked();

    void on_pushButton_clicked();

    //void addToList(const QUrlInfo &urlInfo);

    //void writeFile();

    //void findName(const QUrlInfo &urlInfo);

    void log_search();

    void on_poisk_Button_clicked();

    void on_updateButton_clicked();

    void on_otchetButton_clicked();

    void on_time_checkBox_clicked();

    void on_element_checkBox_clicked();

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void changeCombo();

    void on_znachenie_checkBox_clicked();

    void on_error_checkBox_clicked();

    void on_pB_meteo_clicked();

    void on_otchetButton_meteo_clicked();

public:
    QString table_name = "mainlog";
    void insertComBox();
    void ch();
    void get(QString str);

private:
    Ui::MainWindow *ui;
    QHash<QString, bool> isDirectory;
    QNetworkAccessManager* manager;
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    QString nameFile;
    QSqlQueryModel *model;
    QSqlQueryModel *model_meteo;
    QCheckList *list = new QCheckList();

};

class mDelegate: public QStyledItemDelegate
{
    Q_OBJECT
public:
    mDelegate(QWidget *parent=nullptr):QStyledItemDelegate(parent){}
    QString displayText(const QVariant &value, const QLocale &locale) const{
    Q_UNUSED(locale);
    return value.toDateTime().toString("dd-MM-yyyy hh:mm:ss");}
};
#endif // MAINWINDOW_H
