#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QPair>
#include "class.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer(new QTimer(this))
    , currentIndex(0)
    , label1(nullptr)
    , label2(nullptr)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    connect(timer, &QTimer::timeout, this, [this]() {
        if (currentIndex < expression.length()) {
            char currentChar = expression[currentIndex].toLatin1();

            // 更新字符底纹颜色
            for (auto rect : charRects)
            {
                rect->setBrush(QBrush(Qt::lightGray));
            }
            charRects[currentIndex]->setBrush(QBrush(Qt::darkGray));

            // 处理左括号的进栈动画
            if (currentChar == '[' || currentChar == '{' || currentChar == '(' || currentChar == '<') {
                auto item = scene->addRect(stack.size() * 30 + 150, 80, 30, 30, QPen(Qt::black), QBrush(Qt::gray));
                auto text = scene->addText(QString(currentChar));
                text->setPos(stack.size() * 30 + 150 + 10, 80);
                stack.push(qMakePair(currentIndex + 1, item));
                charTexts.push_back(text);
                leftBracketIndices.push_back(currentIndex + 1); // 保存左括号的序号
            }
            currentIndex++;
        }
        else
        {
            timer->stop();
        }
    });

    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::on_startButton_clicked);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
    connect(ui->popButton, &QPushButton::clicked, this, &MainWindow::on_popButton_clicked);
    connect(ui->closeButton, &QPushButton::clicked, this, &MainWindow::on_closeButton_clicked);
    connect(ui->convertButton, &QPushButton::clicked, this, &MainWindow::on_convertButton_clicked);
    connect(ui->clearConversionButton, &QPushButton::clicked, this, &MainWindow::on_clearConversionButton_clicked);  // 连接转换清除按钮信号
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    clearBracketMatching();
    expression = ui->lineEdit->text();

    // 添加标签
    label1 = scene->addText("待转换的字符：");
    label1->setPos(0, 30);

    label2 = scene->addText("已进栈的左括号：");
    label2->setPos(0, 80);

    for (int i = 0; i <= expression.length() - 1; i++)
    {
        auto rect = scene->addRect(i * 30 + 150, 30, 30, 30, QPen(Qt::black), QBrush(Qt::lightGray));
        auto text = scene->addText(QString(expression[i]));
        text->setPos(i * 30 + 150 + 10, 30);
        charRects.push_back(rect);
        charTexts.push_back(text);
    }
    currentIndex = 0;
    timer->start(500);
}

void MainWindow::on_startButton_clicked()
{
    currentIndex = 0;

    // 使用另一个QTimer来处理匹配动画
    QTimer *matchTimer = new QTimer(this);
    connect(matchTimer, &QTimer::timeout, this, [this, matchTimer]()
            {
        if (currentIndex < expression.length())
        {
            char currentChar = expression[currentIndex].toLatin1();

            // 更新字符底纹颜色
            for (auto rect : charRects)
            {
                if (rect)
                {
                    rect->setBrush(QBrush(Qt::lightGray));
                }
            }
            if (charRects[currentIndex])
            {
                charRects[currentIndex]->setBrush(QBrush(Qt::darkGray));
            }

            // 处理右括号的匹配和出栈动画
            if (currentChar == ')' || currentChar == '}' || currentChar == ']' || currentChar == '>' )
            {
                bool matched = false;

                // 遍历栈查找匹配的左括号
                for (int i = 0; i < stack.size(); ++i)
                {
                    auto topPair = stack[i];
                    int leftIndex = topPair.first;
                    char leftChar = expression[leftIndex - 1].toLatin1();

                    // 检查左括号是否匹配当前右括号
                    if ((currentChar == ')' && leftChar == '(') ||
                        (currentChar == '}' && leftChar == '{') ||
                        (currentChar == ']' && leftChar == '[') ||
                        (currentChar == '>' && leftChar == '<'))
                    {
                        matched = true;

                        // 删除匹配的左括号动画
                        auto item = topPair.second;
                        if (item)
                        {
                            scene->removeItem(item);
                            delete item;
                        }

                        auto text = charTexts.last();
                        charTexts.pop_back();
                        scene->removeItem(text);
                        delete text;


                        // 从栈中移除这个左括号
                        stack.removeAt(i);

                        // 显示匹配成功信息
                        QString matchLabel = QString("左括号（第%1号）与右括号（第%2号）匹配成功").arg(leftIndex).arg(currentIndex + 1);
                        auto matchText = scene->addText(matchLabel);
                        matchText->setPos(0, results.size() * 30 + 110);
                        results.push_back(matchText);
                        break;
                    }
                }

                // 如果没有找到匹配左括号
                if (!matched)
                {
                    QString unmatchLabel = QString("未匹配的右括号：第%1号").arg(currentIndex + 1);
                    auto unmatchText = scene->addText(unmatchLabel);
                    unmatchText->setPos(0, results.size() * 30 + 110);
                    results.push_back(unmatchText);
                }
            }
            currentIndex++;
        }
        else
        {
            matchTimer->stop();
            matchTimer->deleteLater();

            // 处理未匹配的左括号
            while (!stack.empty())
            {
                auto topPair = stack.top();
                stack.pop();
                int leftIndex = topPair.first;

                auto item = topPair.second;
                if (item)
                {
                    scene->removeItem(item);
                    delete item;
                }

                auto text = charTexts.last();
                charTexts.pop_back();
                scene->removeItem(text);
                delete text;


                QString unmatchLabel = QString("未匹配的左括号：第%1号").arg(leftIndex);
                auto unmatchText = scene->addText(unmatchLabel);
                unmatchText->setPos(0, results.size() * 30 + 110);
                results.push_back(unmatchText);
            }
        }
    });

    matchTimer->start(500);
}

void MainWindow::on_convertButton_clicked()
{
    bool ok;
    double number = ui->numberLineEdit->text().toDouble(&ok);
    int base = ui->baseLineEdit->text().toInt(&ok);
    if (ok && base >= 2 && base <= 36)
    {
        QString result = convertToBase(number, base);
        ui->resultLineEdit->setText(result);
    }
    else
    {
        ui->resultLineEdit->setText("Invalid input");
    }
}

QString MainWindow::convertToBase(long double number, int base)
{
    if (number == 0) return "0";
    const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    linkedStack<char> stack; // 使用自定义栈
    QString result = "";

    // 检查是否为负数
    bool isNegative = number < 0;
    if (isNegative)
    {
        number = -number; // 使用绝对值计算
    }

    // 处理整数部分
    int integerPart = static_cast<int>(number);
    long double fractionalPart = number - integerPart;

    while (integerPart > 0)
    {
        stack.push(digits[integerPart % base]);
        integerPart /= base;
    }

    if (isNegative)
    {
        result += '-'; // 添加负号
    }

    while (!stack.empty())
    {
        result += stack.top();
        stack.pop();
    }

    // 处理小数部分
    if (fractionalPart > 0)
    {
        result += '.';
        int precision = 10; // 设置小数部分的精度
        while (fractionalPart > 0 && precision > 0)
        {
            fractionalPart *= base;
            int fractionalDigit = static_cast<int>(fractionalPart);
            result += digits[fractionalDigit];
            fractionalPart -= fractionalDigit;
            precision--;
        }
    }

    return result;
}



void MainWindow::on_popButton_clicked() {
    clearBracketMatching();
    ui->lineEdit->clear();
}

void MainWindow::on_clearConversionButton_clicked() {
    clearConversionFields();
}

void MainWindow::clearBracketMatching() {
    scene->clear(); // 清除所有场景项

    stack.clear();
    charRects.clear();
    charTexts.clear();
    results.clear();
    leftBracketIndices.clear();
}

void MainWindow::clearConversionFields() {
    ui->numberLineEdit->clear();
    ui->baseLineEdit->clear();
    ui->resultLineEdit->clear();
}

void MainWindow::on_closeButton_clicked() {
    QApplication::quit();
}
