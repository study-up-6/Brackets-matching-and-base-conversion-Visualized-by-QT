#pragma once

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QVector>
#include "class.h" // 包含自定义栈类头文件

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
    void on_pushButton_clicked();
    void on_startButton_clicked();
    void on_popButton_clicked();
    void on_closeButton_clicked();
    void on_convertButton_clicked();
    void on_clearConversionButton_clicked();  // 新增槽函数

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    linkedStack<QPair<int, QGraphicsRectItem*>> stack; // 使用自定义栈
    QVector<QGraphicsRectItem*> charRects;
    QVector<QGraphicsTextItem*> charTexts;
    QVector<QGraphicsTextItem*> results;
    QVector<int> leftBracketIndices; // 用于记录左括号的序号
    QTimer *timer;
    QString expression;
    int currentIndex;
    QGraphicsTextItem *label1; // 标签1
    QGraphicsTextItem *label2; // 标签2

    void clearBracketMatching();  // 新增函数声明
    void clearConversionFields();  // 新增函数
    QString convertToBase(long double number, int base);
};
