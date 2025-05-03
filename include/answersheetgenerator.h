#ifndef ANSWERSHEETGENERATOR_H
#define ANSWERSHEETGENERATOR_H

#include <string>
#include <hpdf.h>

class AnswerSheetGenerator {
public:
    // 构造函数和析构函数声明
    AnswerSheetGenerator();
    ~AnswerSheetGenerator();
    
    // 参数设置接口
    void setMargin(float margin);
    void setTitle(const std::string& title);
    std::string getTitle() const;

    // 核心生成方法
    void drawTitle();
    void drawStudentInfoSection();
    void drawMultipleChoiceSection(int numQuestions, int optionsPerQuestion = 4);
    void drawFillInTheBlankSection(int numLines);
    void saveToFile(const std::string& filename);

private:
    // PDF相关对象
    HPDF_Doc  pdf;
    HPDF_Page page;
    HPDF_Font font;
    
    // 布局参数
    float margin;
    std::string title;
    float currentY;
    
    // 辅助方法
    void drawLabelWithUnderline(const std::string& label, float x, float y, float underlineLength);
    
    // 页面尺寸常量
    static constexpr float pageWidth = 595.0;   // A4宽度（单位：点）
    static constexpr float pageHeight = 842.0;  // A4高度
};

#endif