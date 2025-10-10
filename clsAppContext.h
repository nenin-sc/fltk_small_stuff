#ifndef CLSAPPCONTEX_H
#define CLSAPPCONTEX_H
#include <FL/user/clsGenContext.h>
#include "src/fl_small_stuff.h"
#include "main.h"



class clsAppContext:public clsGenContext
{
    public:
      void init_windows();
      clsAppContext();
      virtual ~clsAppContext();
   void cbAdd();
   void cbNew();
   void cbBtOutTest();
   void cbClose();
    protected:

    private:
};

#endif // CLSAPPCONTEX_H
