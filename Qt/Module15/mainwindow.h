#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QValidator>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);  // добавлен explicit
    ~MainWindow() override;  // добавлен override

private slots:
    void onCurrencyChanged(int index);
    void onAmountChanged(const QString &amount);

private:
    // Указатели на виджеты
    QLineEdit *inputAmount{nullptr};  // инициализация нулевым указателем
    QLineEdit *outputAmount{nullptr};
    QComboBox *currencySelect{nullptr};

    // Методы
    void setupUi();
    double convertCurrency(double amount, int currencyIndex) const;  // добавлен const
};

#endif // MAINWINDOW_H
