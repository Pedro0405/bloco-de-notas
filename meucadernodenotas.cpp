#include "meucadernodenotas.h"
#include "ui_meucadernodenotas.h"
#include "QMessageBox"
#include <QDir>
#include <QFile>
#include <QfileDialog>
#include <QTextStream>
#include <QFontDialog>
#include <QFont>
#include <QColor>
#include <QColorDialog>
#include <QPrinter>
#include <QPrintDialog>

MeuCadernoDeNotas::MeuCadernoDeNotas(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MeuCadernoDeNotas)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MeuCadernoDeNotas::~MeuCadernoDeNotas()
{
    delete ui;
}


void MeuCadernoDeNotas::on_actionNovo_triggered()
{
    local_arquivo="";
    ui->textEdit->clear();
    ui->textEdit->setFocus();
}


void MeuCadernoDeNotas::on_actionAbrir_triggered()
{
    QString nome_arquivo=QFileDialog::getOpenFileName(this,"abrir",QDir::homePath());
        QFile arquivo(nome_arquivo);
        local_arquivo=nome_arquivo;
        if(!arquivo.open(QFile::ReadOnly | QFile::Text)){
            QMessageBox::warning(this,"erro","arquivo não pode ser aberto.");
            return;
        }
        QTextStream entrada(&arquivo);
        QString texto=entrada.readAll();
        ui->textEdit->setText(texto);
        arquivo.close();
}


void MeuCadernoDeNotas::on_actionSalvar_como_triggered()
{
    QString filtro="todos os arquivos  ;;  Arquivs de texto";
        QString nome_arquivo=QFileDialog::getSaveFileName(this,"Salvar como ",QDir::homePath(),filtro);
        local_arquivo=nome_arquivo;
        QFile arquivo(nome_arquivo);
        if(!arquivo.open(QFile::WriteOnly | QFile::Text)){
            QMessageBox::warning(this,"erro","arquivo não pode ser salvo.");
            return;
        }
        QTextStream saida(&arquivo);
        QString texto=ui->textEdit->toPlainText();
        saida << texto;
        arquivo.flush();
        arquivo.close();

}


void MeuCadernoDeNotas::on_actionSalvar_triggered()
{
    QFile arquivo(local_arquivo);
        if(!arquivo.open(QFile::WriteOnly | QFile::Text)){
            QMessageBox::warning(this,"erro","arquivo não pode ser salvo.");
            return;
        }
        QTextStream saida(&arquivo);
        QString texto=ui->textEdit->toPlainText();
        saida << texto;
        arquivo.flush();
        arquivo.close();
}


void MeuCadernoDeNotas::on_actionFechar_triggered()
{
    close();
}


void MeuCadernoDeNotas::on_actionCopiar_triggered()
{
    ui->textEdit->copy();
}


void MeuCadernoDeNotas::on_actionRecortar_triggered()
{
    ui->textEdit->cut();
}


void MeuCadernoDeNotas::on_actionColar_triggered()
{
    ui->textEdit->paste();
}


void MeuCadernoDeNotas::on_actionDesfazer_triggered()
{
    ui->textEdit->undo();
}


void MeuCadernoDeNotas::on_actionRefazer_triggered()
{
    ui->textEdit->redo();
}


void MeuCadernoDeNotas::on_actionFormatar_triggered()
{
    bool fonte_ok;
        QFont fonte=QFontDialog::getFont(&fonte_ok, this);
        if(fonte_ok){
            ui->textEdit->setFont(fonte);
        }
        else
            return;
}


void MeuCadernoDeNotas::on_actionCor_triggered()
{
    QColor cor=QColorDialog::getColor(Qt::black, this, "Escolha ima cor ");
         if(cor,QtPrivate::isValidUtf16){
             ui->textEdit->setTextColor(cor);
         }

}


void MeuCadernoDeNotas::on_actionCor_de_fundo_triggered()
{
    QColor cor=QColorDialog::getColor(Qt::black, this, "Escolha ima cor ");
         if(cor,QtPrivate::isValidUtf16){
             ui->textEdit->setTextBackgroundColor(cor);
         }
}


void MeuCadernoDeNotas::on_actionImprimir_triggered()
{
    QPrinter imp;
        imp.setPrinterName("Impressão");
        QPrintDialog cx_imp(&imp, this);
    if(cx_imp.exec()==QDialog::Rejected);
    return;
    ui->textEdit->print(&imp);

}

