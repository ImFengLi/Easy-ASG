#include "mainwindow.h"
#include "answersheetgenerator.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    createUI();
    setWindowTitle("答题卡生成器");
    resize(400, 300);
}

void MainWindow::createUI() {
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // 标题输入
    layout->addWidget(new QLabel("标题："));
    titleEdit = new QLineEdit("期末考试答题卡");
    layout->addWidget(titleEdit);

    // 选择题设置
    QHBoxLayout *mcqLayout = new QHBoxLayout();
    mcqLayout->addWidget(new QLabel("选择题数量："));
    mcqCountSpin = new QSpinBox();
    mcqCountSpin->setRange(1, 100);
    mcqCountSpin->setValue(20);
    mcqLayout->addWidget(mcqCountSpin);
    
    mcqLayout->addWidget(new QLabel("选项数："));
    optionsPerQuestionSpin = new QSpinBox();
    optionsPerQuestionSpin->setRange(2, 8);
    optionsPerQuestionSpin->setValue(4);
    mcqLayout->addWidget(optionsPerQuestionSpin);
    layout->addLayout(mcqLayout);

    // 填空题设置
    QHBoxLayout *fillLayout = new QHBoxLayout();
    fillLayout->addWidget(new QLabel("填空题数量："));
    fillInCountSpin = new QSpinBox();
    fillInCountSpin->setRange(0, 50);
    fillInCountSpin->setValue(5);
    fillLayout->addWidget(fillInCountSpin);
    layout->addLayout(fillLayout);

    // 边距设置
    layout->addWidget(new QLabel("页面边距(mm)："));
    marginSpin = new QDoubleSpinBox();
    marginSpin->setRange(10, 50);
    marginSpin->setValue(40);
    layout->addWidget(marginSpin);

    // 输出路径
    QHBoxLayout *pathLayout = new QHBoxLayout();
    outputPathEdit = new QLineEdit("AnswerSheet.pdf");
    QPushButton *browseBtn = new QPushButton("浏览...");
    connect(browseBtn, &QPushButton::clicked, this, &MainWindow::browseOutputPath);
    pathLayout->addWidget(outputPathEdit);
    pathLayout->addWidget(browseBtn);
    layout->addLayout(pathLayout);

    // 生成按钮
    QPushButton *generateBtn = new QPushButton("生成答题卡");
    connect(generateBtn, &QPushButton::clicked, this, &MainWindow::generateAnswerSheet);
    layout->addWidget(generateBtn);

    setCentralWidget(centralWidget);
}

void MainWindow::browseOutputPath() {
    QString path = QFileDialog::getSaveFileName(
        this, "保存文件", "", "PDF文件 (*.pdf)");
    if (!path.isEmpty()) {
        outputPathEdit->setText(path);
    }
}

void MainWindow::generateAnswerSheet() {
    AnswerSheetGenerator generator;
    
    // 设置参数
    generator.setTitle(titleEdit->text().toStdString());
    generator.setMargin(marginSpin->value());
    
    try {
        generator.drawTitle(generator.getTitle());
        generator.drawStudentInfoSection();
        generator.drawMultipleChoiceSection(
            mcqCountSpin->value(),
            optionsPerQuestionSpin->value()
        );
        generator.drawFillInTheBlankSection(fillInCountSpin->value());
        
        generator.saveToFile(outputPathEdit->text().toStdString());
        QMessageBox::information(this, "成功", "答题卡生成成功！");
    } catch (...) {
        QMessageBox::critical(this, "错误", "生成答题卡时发生错误");
    }
}