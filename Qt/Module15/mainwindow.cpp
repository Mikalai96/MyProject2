#include "mainwindow.h"
#include <QVBoxLayout>
#include <QDoubleValidator>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi();
}
MainWindow::~MainWindow()
{
    // Освобождение ресурсов, если необходимо
}

void MainWindow::setupUi()
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Создание элементов интерфейса
    inputAmount = new QLineEdit(this);
    outputAmount = new QLineEdit(this);
    currencySelect = new QComboBox(this);

    // Настройка валидации ввода
    QDoubleValidator *validator = new QDoubleValidator(0.0, 999999.99, 2, this);
    validator->setNotation(QDoubleValidator::StandardNotation);
    inputAmount->setValidator(validator);

    // Настройка ComboBox
    currencySelect->addItem("USD");
    currencySelect->addItem("EUR");
    currencySelect->addItem("GBP");

    outputAmount->setReadOnly(true);

    // Создание меток
    QLabel *inputLabel = new QLabel("Введите сумму:", this);
    QLabel *currencyLabel = new QLabel("Выберите валюту:", this);
    QLabel *resultLabel = new QLabel("Результат:", this);

    // Добавление виджетов в layout
    layout->addWidget(inputLabel);
    layout->addWidget(inputAmount);
    layout->addWidget(currencyLabel);
    layout->addWidget(currencySelect);
    layout->addWidget(resultLabel);
    layout->addWidget(outputAmount);

    setCentralWidget(centralWidget);

    // Подключение сигналов (современный синтаксис)
    connect(currencySelect, &QComboBox::currentIndexChanged,
            this, &MainWindow::onCurrencyChanged);
    connect(inputAmount, &QLineEdit::textChanged,
            this, &MainWindow::onAmountChanged);
}
void MainWindow::onCurrencyChanged(int /*index*/)
{
    onAmountChanged(inputAmount->text());
}

void MainWindow::onAmountChanged(const QString &amount)
{
    bool ok;
    double value = amount.toDouble(&ok);

    if (ok) {
        double result = convertCurrency(value, currencySelect->currentIndex());
        outputAmount->setText(QString::number(result, 'f', 2));
    } else {
        outputAmount->clear();
    }
}
double MainWindow::convertCurrency(double amount, int currencyIndex) const
{
    // Примерные курсы валют (в реальном приложении нужно получать актуальные)
    const double rates[] = {
        1.0,    // USD to USD
        0.96,   // USD to EUR
        0.79    // USD to GBP
    };

    return amount * rates[currencyIndex];
}
