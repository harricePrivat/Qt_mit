#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "StudentInfo.h"
#include <vector>
#include <QString>
#include <QMessageBox>
#include <string>
#include <fstream>
using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString imagesDir = "/home/brice/dhcpMIT/images/";
    QIcon deleteIcon(imagesDir+"poubelle.svg");
    QIcon addIcon(imagesDir+"plus.svg");
    QIcon prevIcon(imagesDir+"previous.svg");
    QIcon nextIcon(imagesDir+"next.svg");
    QIcon searchIcon(imagesDir+"chercher.svg");
     StudentInfo student;
    QString drawL1=imagesDir+"photo_L1/"+QString::number(student.index)+".jpg";
    QPixmap pixmap(drawL1);
   pixmap = pixmap.scaled(241,321,Qt::KeepAspectRatio);
    ui->imageLabel->setPixmap(pixmap);

    ui->addStudentButton->setIcon(addIcon);
    ui->addStudentButton->setIconSize(QSize(70,70));

    ui->deleteStudentButton->setIcon(deleteIcon);
    ui->deleteStudentButton->setIconSize(QSize(70,70));

    ui->previousButton->setIcon(prevIcon);
    ui->previousButton->setIconSize(QSize(70,70));

    ui->nextButton->setIcon(nextIcon);
    ui->nextButton->setIconSize(QSize(70,70));

    ui->searchButton->setIcon(searchIcon);
    ui->searchButton->setIconSize(QSize(40,40));
    vector<StudentInfo> students=(student.get_info());
     QString nom=QString::fromStdString(students[student.index-1].get_nom());
     QString numero=QString::fromStdString(students[student.index-1].get_numero());
     QString marque=QString::fromStdString(students[student.index-1].get_marque());
     QString etat=QString::fromStdString(students[student.index-1].get_etat());
     QString mac_eth=QString::fromStdString(students[student.index-1].get_mac_eth());
    QString serial=QString::fromStdString(students[student.index-1].get_serial());
     ui->lineEdit_20->setText(nom);
     ui->lineEdit_29->setText("L1");
     ui->lineEdit_22->setText(numero);
     ui->lineEdit_23->setText(marque);
     ui->lineEdit_24->setText(etat);
     ui->lineEdit_25->setText(mac_eth);
     ui->lineEdit_26->setText(serial);
     ui->lineEdit_27->setText(numero);
     ui->lineEdit_28->setText(numero);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addImageButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Ajouter une image");
    QPixmap pixmap(path);
    pixmap = pixmap.scaled(241,321,Qt::KeepAspectRatio);
    ui->newImageLabel->setPixmap(pixmap);
}


void MainWindow::on_quitAddStudentButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_addStudentButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_previousButton_clicked()
{

   /* StudentInfo student;
    if(student.index>1) student.index--;
     vector<StudentInfo> students=(student.get_info());
     QString imagesDir = "/home/brice/GestionEleves/images/";
     QString drawL1=imagesDir+"photo_L1/"+QString::number(student.index)+".jpg";
     QPixmap pixmap(drawL1);
     ui->imageLabel->setPixmap(pixmap);
     QString nom=QString::fromStdString(students[student.index-1].get_nom());
    QString numero=QString::fromStdString(students[student.index-1].get_numero());
    QString marque=QString::fromStdString(students[student.index-1].get_marque());
    QString etat=QString::fromStdString(students[student.index-1].get_etat());
    QString mac_eth=QString::fromStdString(students[student.index-1].get_mac_eth());
   QString serial=QString::fromStdString(students[student.index-1].get_serial());
    ui->lineEdit_20->setText(nom);
    ui->lineEdit_29->setText("L1");
    ui->lineEdit_22->setText(numero);
    ui->lineEdit_23->setText(marque);
    ui->lineEdit_24->setText(etat);
    ui->lineEdit_25->setText(mac_eth);
    ui->lineEdit_26->setText(serial);
    ui->lineEdit_27->setText(numero);
    ui->lineEdit_28->setText(numero);*/
    StudentInfo student;
    if(student.index>1) student.index--;
     vector<StudentInfo> students=(student.get_info());
     QString imagesDir = "/home/brice/GestionEleves/images/";
     QString drawL1=imagesDir+"photo_L1/"+QString::number(student.index)+".jpg";
     QPixmap pixmap(drawL1);
     pixmap = pixmap.scaled(241,321,Qt::KeepAspectRatio);
     ui->imageLabel->setPixmap(pixmap);
     QString nom=QString::fromStdString(students[student.index-1].get_nom());
    QString numero=QString::fromStdString(students[student.index-1].get_numero());
    QString marque=QString::fromStdString(students[student.index-1].get_marque());
    QString etat=QString::fromStdString(students[student.index-1].get_etat());
    QString mac_eth=QString::fromStdString(students[student.index-1].get_mac_eth());
   QString serial=QString::fromStdString(students[student.index-1].get_serial());
    ui->lineEdit_20->setText(nom);
    ui->lineEdit_29->setText("L1");
    ui->lineEdit_22->setText(numero);
    ui->lineEdit_23->setText(marque);
    ui->lineEdit_24->setText(etat);
    ui->lineEdit_25->setText(mac_eth);
    ui->lineEdit_26->setText(serial);
    ui->lineEdit_27->setText(numero);
    ui->lineEdit_28->setText(numero);
}

void MainWindow::on_nextButton_clicked()
{
   /* StudentInfo student;
    if(student.index<75) student.index++;
     vector<StudentInfo> students=(student.get_info());
     QString imagesDir = "/home/brice/GestionEleves/images/";
     QString drawL1=imagesDir+"photo_L1/"+QString::number(student.index)+".jpg";
     QPixmap pixmap(drawL1);
     ui->imageLabel->setPixmap(pixmap);
     QString nom=QString::fromStdString(students[student.index-1].get_nom());
    QString numero=QString::fromStdString(students[student.index-1].get_numero());
    QString marque=QString::fromStdString(students[student.index-1].get_marque());
    QString etat=QString::fromStdString(students[student.index-1].get_etat());
    QString mac_eth=QString::fromStdString(students[student.index-1].get_mac_eth());
   QString serial=QString::fromStdString(students[student.index-1].get_serial());
    ui->lineEdit_20->setText(nom);
    ui->lineEdit_29->setText("L1");
    ui->lineEdit_22->setText(numero);
    ui->lineEdit_23->setText(marque);
    ui->lineEdit_24->setText(etat);
    ui->lineEdit_25->setText(mac_eth);
    ui->lineEdit_26->setText(serial);
    ui->lineEdit_27->setText(numero);
    ui->lineEdit_28->setText(numero);*/
    StudentInfo student;
    if(student.index<student.nbrLineInscriptionL1()) student.index++;
     vector<StudentInfo> students=(student.get_info());
     QString imagesDir = "/home/brice/GestionEleves/images/";
     QString drawL1=imagesDir+"photo_L1/"+QString::number(student.index)+".jpg";
     QPixmap pixmap(drawL1);
     pixmap = pixmap.scaled(241,321,Qt::KeepAspectRatio);
     ui->imageLabel->setPixmap(pixmap);
     QString nom=QString::fromStdString(students[student.index-1].get_nom());
    QString numero=QString::fromStdString(students[student.index-1].get_numero());
    QString marque=QString::fromStdString(students[student.index-1].get_marque());
    QString etat=QString::fromStdString(students[student.index-1].get_etat());
    QString mac_eth=QString::fromStdString(students[student.index-1].get_mac_eth());
   QString serial=QString::fromStdString(students[student.index-1].get_serial());
    ui->lineEdit_20->setText(nom);
    ui->lineEdit_29->setText("L1");
    ui->lineEdit_22->setText(numero);
    ui->lineEdit_23->setText(marque);
    ui->lineEdit_24->setText(etat);
    ui->lineEdit_25->setText(mac_eth);
    ui->lineEdit_26->setText(serial);
    ui->lineEdit_27->setText(numero);
    ui->lineEdit_28->setText(numero);

}


void MainWindow::on_lineEdit_20_cursorPositionChanged(int arg1, int arg2)
{

}


void MainWindow::on_searchButton_clicked()
{
    StudentInfo student;
   QString  resultSearch = ui->lineEdit->text();
   if(resultSearch.isEmpty()){
        QMessageBox::critical(this,"Erreur","Champ Obligatoire");
   }
   else{
       vector<int> intResultSearch=student.search(resultSearch.toStdString());
       if(intResultSearch.size()==0){
           QMessageBox::critical(this,"Erreur","RESULTAT INTROUVABLE");
       }else{
      intResultSearch.push_back(5);
       StudentInfo student;
       //if(student.index<75) student.index++;
        vector<StudentInfo> students=(student.get_info());
        QString imagesDir = "/home/brice/GestionEleves/images/";
        QString drawL1=imagesDir+"photo_L1/"+QString::number(intResultSearch[0])+".jpg";
        QPixmap pixmap(drawL1);
        pixmap = pixmap.scaled(241,321,Qt::KeepAspectRatio);
        ui->imageLabel->setPixmap(pixmap);
        QString nom=QString::fromStdString(students[intResultSearch[0]-1].get_nom());
       QString numero=QString::fromStdString(students[intResultSearch[0]-1].get_numero());
       QString marque=QString::fromStdString(students[intResultSearch[0]-1].get_marque());
       QString etat=QString::fromStdString(students[intResultSearch[0]-1].get_etat());
       QString mac_eth=QString::fromStdString(students[intResultSearch[0]-1].get_mac_eth());
      QString serial=QString::fromStdString(students[intResultSearch[0]-1].get_serial());
       ui->lineEdit_20->setText(nom);
       ui->lineEdit_29->setText("L1");
       ui->lineEdit_22->setText(numero);
       ui->lineEdit_23->setText(marque);
       ui->lineEdit_24->setText(etat);
       ui->lineEdit_25->setText(mac_eth);
       ui->lineEdit_26->setText(serial);
       ui->lineEdit_27->setText(numero);
       ui->lineEdit_28->setText(numero);

   }
       }

}


void MainWindow::on_pushButton_clicked()
{
    StudentInfo student;
    QString nom=ui->lineEdit_2->text();
        QString prenom=ui->lineEdit_3->text();
        int num=student.nbrLineInscriptionL1()+1;
        QString numero=QString::number(num);
        QString niveau=ui->lineEdit_30->text();
        QString marque=ui->lineEdit_5->text();
        QString etat=ui->lineEdit_6->text();
        QString mac_ethernet=ui->lineEdit_7->text();
        QString ip_ethernet=ui->lineEdit_8->text();
        QString mac_wireless=ui->lineEdit_9->text();
        QString ip_wireless=ui->lineEdit_10->text();
        string insertFile;
        if(nom.isEmpty()||prenom.isEmpty()||numero.isEmpty()||niveau.isEmpty()||marque.isEmpty()||mac_ethernet.isEmpty()||mac_wireless.isEmpty()){
             QMessageBox::critical(this,"BANGA","FENOY DAHOLO AZAFADY");
        }
        else{
            insertFile=numero.toStdString()+","+(nom+" "+prenom).toStdString()+","+mac_ethernet.toStdString()+","+mac_wireless.toStdString()+","+etat.toStdString()+","+marque.toStdString();
            ofstream file("/home/brice/dhcpMIT/inscription_L1.csv",std::ios::app);
            if(file.is_open()){
                file << insertFile << endl;
                file.close();
                QMessageBox msgBox;
                msgBox.setWindowTitle("REUSSI");
                msgBox.setText("Votre personne a bien été inséré");
                msgBox.setStandardButtons(QMessageBox::Yes);
                msgBox.setIcon(QMessageBox::Critical);
                int feedBack=msgBox.exec();
                if(feedBack==QMessageBox::Yes){
                    ui->lineEdit_Numero->clear();
                    ui->lineEdit_2->clear();
                    ui->lineEdit_3->clear();
                    ui->lineEdit_30->clear();
                    ui->lineEdit_5->clear();
                    ui->lineEdit_6->clear();
                    ui->lineEdit_7->clear();
                    ui->lineEdit_8->clear();
                    ui->lineEdit_9->clear();
                    ui->lineEdit_10->clear();
                }
            }
        }
}


void MainWindow::on_deleteStudentButton_clicked()
{
    StudentInfo student;
    QMessageBox msgBox;
    msgBox.setWindowTitle("Effacer student");
    msgBox.setText("Etes vous sure de effacer cet élève?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setIcon(QMessageBox::Critical);
    int feedBack=msgBox.exec();
    if(feedBack==QMessageBox::Yes){
        student.supprimerStudent(student.index);

    student.index=1;
    vector<StudentInfo> students=(student.get_info());
    QString imagesDir = "/home/brice/GestionEleves/images/";
    QString drawL1=imagesDir+"photo_L1/"+QString::number(student.index)+".jpg";
    QPixmap pixmap(drawL1);
    pixmap = pixmap.scaled(241,321,Qt::KeepAspectRatio);
    ui->imageLabel->setPixmap(pixmap);
    QString nom=QString::fromStdString(students[student.index-1].get_nom());
   QString numero=QString::fromStdString(students[student.index-1].get_numero());
   QString marque=QString::fromStdString(students[student.index-1].get_marque());
   QString etat=QString::fromStdString(students[student.index-1].get_etat());
   QString mac_eth=QString::fromStdString(students[student.index-1].get_mac_eth());
  QString serial=QString::fromStdString(students[student.index-1].get_serial());
   ui->lineEdit_20->setText(nom);
   ui->lineEdit_29->setText("L1");
   ui->lineEdit_22->setText(numero);
   ui->lineEdit_23->setText(marque);
   ui->lineEdit_24->setText(etat);
   ui->lineEdit_25->setText(mac_eth);
   ui->lineEdit_26->setText(serial);
   ui->lineEdit_27->setText(numero);
   ui->lineEdit_28->setText(numero);
    }
}

