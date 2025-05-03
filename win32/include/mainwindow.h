#include <QMainWindow>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void generateAnswerSheet();
    void browseOutputPath();

private:
    // UI控件
    QLineEdit *titleEdit;
    QSpinBox *mcqCountSpin;
    QSpinBox *optionsPerQuestionSpin;
    QSpinBox *fillInCountSpin;
    QDoubleSpinBox *marginSpin;
    QLineEdit *outputPathEdit;
    
    // 初始化UI
    void createUI();
};