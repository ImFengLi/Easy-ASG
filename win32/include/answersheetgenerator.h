#include <string>
#include <hpdf.h>

class AnswerSheetGenerator {
public:
    AnswerSheetGenerator();
    ~AnswerSheetGenerator();
    
    // 新增设置方法
    void setMargin(float margin) { this->margin = margin; }
    void setTitle(const std::string& title) { this->title = title; }
    std::string getTitle() const { return title; }

    // 原有生成方法
    void drawTitle(const std::string& title);
    void drawStudentInfoSection();
    void drawMultipleChoiceSection(int numQuestions, int optionsPerQuestion = 4);
    void drawFillInTheBlankSection(int numLines);
    void saveToFile(const std::string& filename);

private:
    // 修改为可变量
    float margin;
    std::string title;
    
    // 其他成员保持不变...
};