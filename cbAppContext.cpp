#include "clsAppContext.h"
#include <FL/Fl_Native_File_Chooser.H>
#include <FL/Fl_ask.H>

//-----------------------------------------
void clsAppContext::cbClose(){
 Win()->hide();
};
//---------------


void clsAppContext::cbAdd(){
 std::vector<std::string> ts={"1","two","3","end."};
GetWg<Fl_TextSpinner>("txsp_Test",ERR_PLACE)->add(ts);
};
//-----------------------

void clsAppContext::cbNew(){
GetWg<Fl_TextSpinner>("txsp_Test",ERR_PLACE)->clear();
};
//---------------------------
void clsAppContext::cbBtOutTest(){
  const auto wg=GetWg<Fl_ButtonOutput>("btout_Test",ERR_PLACE);
  Fl_Native_File_Chooser native;
  std::string fname;
  native.title("Select a file");
  native.type(Fl_Native_File_Chooser::BROWSE_SAVE_FILE);
  native.filter("Export XLSX\t*.xlsx\n");
  const char *buf=fl_check_access_nfc(native, ".xlsx", "XLSX report");
  if (buf==nullptr){
        wg->value("Nothing was done");
       return;
  }
  wg->value(buf);

};
