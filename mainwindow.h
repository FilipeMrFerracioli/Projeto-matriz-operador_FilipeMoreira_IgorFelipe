#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMessageBox>
#include <Matriz.h>
#include <QInputDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_CriarMatrizA_clicked();

    void on_pushButton_CriarMatrizB_clicked();

    void on_pushButton_Adicao_clicked();

    void on_pushButton_Subtracao_clicked();

    void on_pushButton_Multiplicacao_clicked();

    void on_pushButton_TranspostaA_clicked();

    void on_pushButton_PotenciaMatrizA_clicked();

    void on_pushButton_MultiplicacaoMatrizAPorK_clicked();

    void on_pushButton_ETriangularSuperior_clicked();

    void on_pushButton_ESimetrica_clicked();

    void on_pushButton_EIgual_clicked();

    void on_pushButton_TranspostaB_clicked();

    void on_pushButton_PotenciaMatrizB_clicked();

    void on_pushButton_MultiplicacaoMatrizBPorK_clicked();

    void on_pushButton_ETriangularInferior_clicked();

    void on_pushButton_EIdentidade_clicked();

    void on_pushButton_EDiferente_clicked();

private:
    Ui::MainWindow *ui;
    TP2::Matriz *Matriz1;
    TP2::Matriz *Matriz2;
};
#endif // MAINWINDOW_H
