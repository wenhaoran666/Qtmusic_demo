#include "statepushbutton.h"
#include "qboxlayout.h"

StatePushbutton::StatePushbutton(QWidget *parent): QPushButton(parent),_curstate(ClickLbState::Normal)

{
    this->setCheckable(true);//允许有选中和未选中两种状态
   this->setChecked(false);
}

ClickLbState StatePushbutton::GetCurState()
{
    return _curstate;
}

void StatePushbutton::ClearState()
{
     _curstate = ClickLbState::Normal;
    this->setChecked(false);
}

void StatePushbutton::SetSelected(bool bselected)
{
    if(bselected){
        _curstate = ClickLbState::Selected;
        this->setChecked(true);
        return;
    }
    _curstate = ClickLbState::Normal;
    this->setChecked(false);
    return;
}


