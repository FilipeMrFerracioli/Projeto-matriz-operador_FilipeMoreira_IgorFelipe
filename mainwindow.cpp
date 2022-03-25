#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , Matriz1(0)
    , Matriz2(0)
{
    ui->setupUi(this);

    ui->textEdit_MatrizA->setEnabled(false);
    ui->textEdit_MatrizB->setEnabled(false);
    ui->textEdit_ResultadosBool->setEnabled(false);
    ui->textEdit_ResultadosOperacoes->setEnabled(false);

    //ui->pushButton_Adicao->setEnabled(false);
    //ui->pushButton_Subtracao->setEnabled(false);
    //ui->pushButton_Multiplicacao->setEnabled(false);

    /*ui->pushButton_ETriangularSuperior->setEnabled(false);
    ui->pushButton_ESimetrica->setEnabled(false);
    ui->pushButton_EIgual->setEnabled(false);
    ui->pushButton_ETriangularInferior->setEnabled(false);
    ui->pushButton_EIdentidade->setEnabled(false);
    ui->pushButton_EDiferente->setEnabled(false);*/

    // Botões para A
    ui->pushButton_TranspostaA->setEnabled(false);
    ui->pushButton_PotenciaMatrizA->setEnabled(false);
    ui->pushButton_MultiplicacaoMatrizAPorK->setEnabled(false);

    // Botões para B
    ui->pushButton_TranspostaB->setEnabled(false);
    ui->pushButton_PotenciaMatrizB->setEnabled(false);
    ui->pushButton_MultiplicacaoMatrizBPorK->setEnabled(false);
}

MainWindow::~MainWindow()
{
    if(Matriz1) delete[] Matriz1;
    if(Matriz2) delete[] Matriz2;
    delete ui;
}

// Criar matriz A
void MainWindow::on_pushButton_CriarMatrizA_clicked()
{
    try {
        int qtdLinha = ui->lineEdit_QtdLinhasMatrizA->text().toInt();
        int qtdColuna = ui->lineEdit_QtdColunasMatrizA->text().toInt();

        Matriz1 = new TP2::Matriz(qtdLinha, qtdColuna);

        // dialog
        for(int i = 0; i < qtdLinha; i++){
            for(int j = 0; j < qtdColuna; j++){
                int elemento = QInputDialog::getInt(this, "Leitura",
                                                    "Matriz A [ " + QString::number(i) + ", "
                                                    + QString::number(j) + "] = ");
                Matriz1->inserirElemento(elemento, i, j);
            }
        }

        ui->textEdit_MatrizA->setText("Matriz A\n" + Matriz1->getMatriz());

        // LineEdit para A
        ui->lineEdit_QtdLinhasMatrizA->setEnabled(false);
        ui->lineEdit_QtdColunasMatrizA->setEnabled(false);

        // Botões para A
        ui->pushButton_TranspostaA->setEnabled(true);
        ui->pushButton_PotenciaMatrizA->setEnabled(true);
        ui->pushButton_MultiplicacaoMatrizAPorK->setEnabled(true);

        ui->pushButton_CriarMatrizA->setEnabled(false);
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}

// Criar matriz B
void MainWindow::on_pushButton_CriarMatrizB_clicked()
{
    try {
        int qtdLinha = ui->lineEdit_QtdLinhasMatrizB->text().toInt();
        int qtdColuna = ui->lineEdit_QtdColunasMatrizB->text().toInt();

        Matriz2 = new TP2::Matriz(qtdLinha, qtdColuna);

        // dialog
        for(int i = 0; i < qtdLinha; i++){
            for(int j = 0; j < qtdColuna; j++){
                int elemento = QInputDialog::getInt(this, "Leitura",
                                                    "Matriz B [ " + QString::number(i) + ", "
                                                    + QString::number(j) + "] = ");
                Matriz2->inserirElemento(elemento, i, j);
            }
        }

        ui->textEdit_MatrizB->setText("Matriz B\n" + Matriz2->getMatriz());

        // LineEdit para B
        ui->lineEdit_QtdLinhasMatrizB->setEnabled(false);
        ui->lineEdit_QtdColunasMatrizB->setEnabled(false);

        // Botões para B
        ui->pushButton_TranspostaB->setEnabled(true);
        ui->pushButton_PotenciaMatrizB->setEnabled(true);
        ui->pushButton_MultiplicacaoMatrizBPorK->setEnabled(true);

        ui->pushButton_CriarMatrizB->setEnabled(false);
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}

// Adição
void MainWindow::on_pushButton_Adicao_clicked()
{
    try {
        TP2::Matriz *adicao = *Matriz1 + Matriz2;
        ui->textEdit_ResultadosOperacoes->setText(adicao->getMatriz());
        delete adicao;
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}

// Subtração
void MainWindow::on_pushButton_Subtracao_clicked()
{
    try {
        TP2::Matriz *subtracao = *Matriz1 - Matriz2;
        ui->textEdit_ResultadosOperacoes->setText(subtracao->getMatriz());
        delete subtracao;
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}

// Multiplicação
void MainWindow::on_pushButton_Multiplicacao_clicked()
{
    try {
        TP2::Matriz *multiplicacao = *Matriz1 * Matriz2;
        ui->textEdit_ResultadosOperacoes->setText(multiplicacao->getMatriz());
        delete multiplicacao;
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}

// Transposta A
void MainWindow::on_pushButton_TranspostaA_clicked()
{
    try {
        TP2::Matriz *transposta = Matriz1->calcularTransposta();
        ui->textEdit_ResultadosOperacoes->setText(transposta->getMatriz());
        delete transposta;
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}

// Transposta B
void MainWindow::on_pushButton_TranspostaB_clicked()
{
    try {
        TP2::Matriz *transposta = Matriz2->calcularTransposta();
        ui->textEdit_ResultadosOperacoes->setText(transposta->getMatriz());
        delete transposta;
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}

// Potência A
void MainWindow::on_pushButton_PotenciaMatrizA_clicked()
{
    try {
        int expoente = QInputDialog::getInt(this, "Leitura", "Expoente:");

        TP2::Matriz *potencia = Matriz1->calcularPotenciacao(expoente);
        ui->textEdit_ResultadosOperacoes->setText(potencia->getMatriz());

        delete potencia;
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}

// Potência B
void MainWindow::on_pushButton_PotenciaMatrizB_clicked()
{
    try {
        int expoente = QInputDialog::getInt(this, "Leitura", "Expoente:");

        TP2::Matriz *potencia = Matriz2->calcularPotenciacao(expoente);
        ui->textEdit_ResultadosOperacoes->setText(potencia->getMatriz());

        delete potencia;
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}

// Multiplicação por constante A
void MainWindow::on_pushButton_MultiplicacaoMatrizAPorK_clicked()
{
    try {
        int k = QInputDialog::getInt(this, "Leitura", "Constante:");

        TP2::Matriz *constante = Matriz1->calcularMultiplicacaoPorK(k);
        ui->textEdit_ResultadosOperacoes->setText(constante->getMatriz());

        delete constante;
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}

// Multiplicação por constante B
void MainWindow::on_pushButton_MultiplicacaoMatrizBPorK_clicked()
{
    try {
        int k = QInputDialog::getInt(this, "Leitura", "Constante:");

        TP2::Matriz *constante = Matriz2->calcularMultiplicacaoPorK(k);
        ui->textEdit_ResultadosOperacoes->setText(constante->getMatriz());

        delete constante;
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}

// É triangular superior
void MainWindow::on_pushButton_ETriangularSuperior_clicked()
{
    try {
        QString saida = "Matriz A é Triangular Superior? "
                + QString::number(Matriz1->eTriangularSuperior());
        saida += "\n\nMatriz B é Triangular Superior? "
                + QString::number(Matriz2->eTriangularSuperior());

        ui->textEdit_ResultadosBool->setText(saida);
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}

// É triangular inferior
void MainWindow::on_pushButton_ETriangularInferior_clicked()
{
    try {
        QString saida = "Matriz A é Triangular inferior? "
                + QString::number(Matriz1->eTriangularInferior());
        saida += "\n\nMatriz B é Triangular inferior? "
                + QString::number(Matriz2->eTriangularInferior());

        ui->textEdit_ResultadosBool->setText(saida);
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}

// É simetrica
void MainWindow::on_pushButton_ESimetrica_clicked()
{
    try {
        QString saida = "Matriz A é simetrica? "
                + QString::number(Matriz1->eSimetrica());
        saida += "\n\nMatriz B é simetrica? "
                + QString::number(Matriz2->eSimetrica());

        ui->textEdit_ResultadosBool->setText(saida);
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}

// É identidade
void MainWindow::on_pushButton_EIdentidade_clicked()
{
    try {
        QString saida = "Matriz A é identidade? "
                + QString::number(Matriz1->eIdentidade());
        saida += "\n\nMatriz B é identidade? "
                + QString::number(Matriz2->eIdentidade());

        ui->textEdit_ResultadosBool->setText(saida);
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}

// É igual
void MainWindow::on_pushButton_EIgual_clicked()
{
    try {
        QString saida = "Matrizes A e B são iguais? "
                + QString::number(Matriz1 == Matriz2);

        ui->textEdit_ResultadosBool->setText(saida);
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}

// São diferentes
void MainWindow::on_pushButton_EDiferente_clicked()
{
    try {
        QString saida = "Matrizes A e B são diferentes? "
                + QString::number(Matriz1 != Matriz2);

        ui->textEdit_ResultadosBool->setText(saida);
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}
