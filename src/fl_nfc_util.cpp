#include <thread>   // for "sleep"
#include <chrono>
#include <FL/Fl.H>
#include <FL/filename.H>
#include  <FL/fl_utf8.h>
#include <FL/fl_ask.H>
#include "fl_small_stuff.h"

const char * fl_check_access_nfc(Fl_Native_File_Chooser &native, const char * ext, const char * fdescr){
  static char buf[2050];
  for(;;){ // "infinit" loop for proper file name
  std::this_thread::sleep_for(std::chrono::milliseconds(5)); // short sleep here found to be useful with network drives
  auto nres=native.show();
  std::this_thread::sleep_for(std::chrono::milliseconds(5));
  switch ( nres ) {
    case -1:  fl_message("%s select error\n, %s.", fdescr,native.errmsg());  return nullptr;	// ERROR
    case  1:  fl_message("%s save canceled.", fdescr ); return nullptr;		// CANCEL
    default: 								// PICKED FILE
      if ( native.filename() ) {

        strncpy(buf,native.filename(),sizeof(buf)-1);
        fl_filename_setext(buf, sizeof(buf), ext);
        break;
         }
        fl_message("empty file name."); return nullptr;		// CANCEL
        return nullptr;

  }

  if(fl_access(buf,F_OK)==0){
   switch(fl_choice("File \"%s\"\n alredy exists. Options:","Overwrite","Change Name","Cancel \"Save\"",buf )){
    case 0:break;
    case 1:continue;
    default: return nullptr;
    }
   }
   break;

};
 return buf;
}
