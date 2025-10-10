#include "clsAppContext.h"

void clsAppContext::cbClose(){
 Win()->hide();
};



void clsAppContext::cbAdd(){
 std::vector<std::string> ts={"1","two","3","end."};
GetWg<Fl_TextSpinner>("txsp_Test",ERR_PLACE)->add(ts);
};
void clsAppContext::cbNew(){
GetWg<Fl_TextSpinner>("txsp_Test",ERR_PLACE)->clear();
};
void clsAppContext::cbBtOutTest(){
  const auto wg=GetWg<Fl_ButtonOutput>("btout_Test",ERR_PLACE);
  const auto s0=wg->value();
  std::string s=s0;
  s+="1";
  GetWg<Fl_ButtonOutput>("btout_Test",ERR_PLACE)->value(s);

};
