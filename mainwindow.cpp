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
    QString imagesDir = "/home/brice/GestionEleves/images/";
    QIcon deleteIcon(imagesDir+"poubelle.svg");
    QIcon addIcon(imagesDir+"plus.svg");
    QIcon prevIcon(imagesDir+"previous.svg");
    QIcon nextIcon(imagesDir+"next.svg");
    QIcon searchIcon(imagesDir+"chercher.svg");
    string indexString;
    //ifstream inFile(pathIndex);
    ifstream file{"/home/brice/GestionEleves/index"};
    if(file.is_open()){
         file >> indexString;
    }
    QString drawL1=imagesDir+"photo_L1/"+QString::fromStdString(indexString)+".jpg";
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
     StudentInfo student;
    vector<StudentInfo> students=(student.get_info());
     QString nom=QString::fromStdString(students[std::stoi(indexString)-1].get_nom());
     QString numero=QString::fromStdString(students[std::stoi(indexString)-1].get_numero());
     QString marque=QString::fromStdString(students[std::stoi(indexString)-1].get_marque());
     QString etat=QString::fromStdString(students[std::stoi(indexString)-1].get_etat());
     QString mac_eth=QString::fromStdString(students[std::stoi(indexString)-1].get_mac_eth());
    QString serial=QString::fromStdString(students[std::stoi(indexString)-1].get_serial());
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
    ifstream file{"/home/brice/GestionEleves/index"};
    int i;
    string indexString;
    if(file.is_open()){
         file >> indexString;
         i=std::stoi(indexString);
         file.close();
    }
    if(i>1) i--;
    ofstream outfile{"/home/brice/GestionEleves/index"};
    if(outfile.is_open()){
        outfile << std::to_string(i);
    }
    StudentInfo student;
     vector<StudentInfo> students=(student.get_info());
     QString imagesDir = "/home/brice/GestionEleves/images/";
     QString drawL1=imagesDir+"photo_L1/"+QString::fromStdString(indexString)+".jpg";
     QPixmap pixmap(drawL1);
     ui->imageLabel->setPixmap(pixmap);
     QString nom=QString::fromStdString(students[i-1].get_nom());
    QString numero=QString::fromStdString(students[i-1].get_numero());
    QString marque=QString::fromStdString(students[i-1].get_marque());
    QString etat=QString::fromStdString(students[i-1].get_etat());
    QString mac_eth=QString::fromStdString(students[i-1].get_mac_eth());
   QString serial=QString::fromStdString(students[i-1].get_serial());
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

    ifstream file{"/home/brice/GestionEleves/index"};
    int i;
    string indexString;
    if(file.is_open()){
         file >> indexString;
         i=std::stoi(indexString);
         file.close();
    }

    if(i<75) i++;
    ofstream outfile{"/home/brice/GestionEleves/index"};
    if(outfile.is_open()){
        outfile << std::to_string(i);
    }
    StudentInfo student;
     vector<StudentInfo> students=(student.get_info());
     QString imagesDir = "/home/brice/GestionEleves/images/";
     QString drawL1=imagesDir+"photo_L1/"+QString::fromStdString(indexString)+".jpg";
     QPixmap pixmap;
     pixmap.load(drawL1);
     update();
     QString nom=QString::fromStdString(students[i-1].get_nom());
    QString numero=QString::fromStdString(students[i-1].get_numero());
    QString marque=QString::fromStdString(students[i-1].get_marque());
    QString etat=QString::fromStdString(students[i-1].get_etat());
    QString mac_eth=QString::fromStdString(students[i-1].get_mac_eth());
   QString serial=QString::fromStdString(students[i-1].get_serial());
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


/*void MainWindow::on_lineEdit_20_cursorPositionChanged(int arg1, int arg2)
{

}*/


void MainWindow::on_searchButton_clicked()
{
    StudentInfo student;
   QString  resultSearch = ui->lineEdit->text();
   if(resultSearch.isEmpty()){
        QMessageBox::critical(this,"Erreur","Champ Obligatoire");
   }
   else{
      // vector<int> intResultSearch=student.search(resultSearch.toStdString());
       int i=1;//intResultSearch[0];
       //if(i<75) i++;
       ofstream outfile{"/home/brice/GestionEleves/index"};
       if(outfile.is_open()){
           outfile << std::to_string(i);
       }
       StudentInfo student;
        vector<StudentInfo> students=(student.get_info());
        QString imagesDir = "/home/brice/GestionEleves/images/";
        QString drawL1=imagesDir+"photo_L1/"+QString::number(i)+".jpg";
        QPixmap pixmap(drawL1);
        ui->imageLabel->setPixmap(pixmap);
        //pixmap.load(drawL1);
        update();
        QString nom=QString::fromStdString(students[i-1].get_nom());
       QString numero=QString::fromStdString(students[i-1].get_numero());
       QString marque=QString::fromStdString(students[i-1].get_marque());
       QString etat=QString::fromStdString(students[i-1].get_etat());
       QString mac_eth=QString::fromStdString(students[i-1].get_mac_eth());
      QString serial=QString::fromStdString(students[i-1].get_serial());
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

