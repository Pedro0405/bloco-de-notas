#ifndef MEUCADERNODENOTAS_H
#define MEUCADERNODENOTAS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MeuCadernoDeNotas; }
QT_END_NAMESPACE

class MeuCadernoDeNotas : public QMainWindow
{
    Q_OBJECT

public:
    MeuCadernoDeNotas(QWidget *parent = nullptr);
    ~MeuCadernoDeNotas();

private slots:
    void on_actionNovo_triggered();

    void on_actionAbrir_triggered();

    void on_actionSalvar_como_triggered();

    void on_actionSalvar_triggered();

    void on_actionFechar_triggered();

    void on_actionCopiar_triggered();

    void on_actionRecortar_triggered();

    void on_actionColar_triggered();

    void on_actionDesfazer_triggered();

    void on_actionRefazer_triggered();

    void on_actionFormatar_triggered();

    void on_actionCor_triggered();

    void on_actionCor_de_fundo_triggered();

    void on_actionImprimir_triggered();

private:
    Ui::MeuCadernoDeNotas *ui;
    QString local_arquivo;
};
#endif // MEUCADERNODENOTAS_H
