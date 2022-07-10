#include "diji.h"

diji::diji()
{
     dijiplan.load(diji_plan);

     diji_x=0;
     diji_y=0;

     diji_s=diji_sudu;

     diji_free=true;

     m_Rect.setWidth(dijiplan.width());
     m_Rect.setHeight(dijiplan.height());
     m_Rect.moveTo(diji_x,diji_y);



}

void diji::updatePosition()
{
    if(diji_free==true)
    {
        return;

    }
    diji_y += diji_s;

    m_Rect.moveTo(diji_x,diji_y);

    if(diji_y >=  GAME_HEIGHT+ m_Rect.height())
    {


        diji_free=true;
    }





}
