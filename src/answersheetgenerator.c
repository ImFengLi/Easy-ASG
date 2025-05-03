#include "answersheetgenerator.h"
#include <cmath>

// 构造函数实现
AnswerSheetGenerator::AnswerSheetGenerator() 
    : pdf(HPDF_New(nullptr, nullptr)),
      page(HPDF_AddPage(pdf)),
      font(HPDF_GetFont(pdf, "Helvetica", nullptr)),
      margin(40.0),
      currentY(pageHeight - margin) 
{
    HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A4, HPDF_PAGE_PORTRAIT);
}

// 析构函数实现
AnswerSheetGenerator::~AnswerSheetGenerator() {
    if (pdf) {
        HPDF_Free(pdf);
    }
}

// 参数设置方法
void AnswerSheetGenerator::setMargin(float margin) {
    this->margin = margin;
    currentY = pageHeight - margin; // 重置绘制起始位置
}

void AnswerSheetGenerator::setTitle(const std::string& title) {
    this->title = title;
}

std::string AnswerSheetGenerator::getTitle() const {
    return title;
}