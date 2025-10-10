#include "fl_small_stuff.h"

  Fl_ButtonOutput::Fl_ButtonOutput(int X, int Y, int W, int H, const char *L)
     : Fl_Group(X, Y, W, H, L),
       output_(X, Y, W - H - 2, H),
       button_(X + W - H - 2, Y, H, H, "@file")
{
  end();
  align(FL_ALIGN_LEFT);
  output_.when(FL_WHEN_ENTER_KEY | FL_WHEN_RELEASE);
  output_.value("1");


}
//------------------------------------------------
  int	Fl_ButtonOutput::handle(int event) {
		  switch (event) {
	        case FL_KEYDOWN :
		      return 0;

		    case FL_FOCUS :
		      if (output_.take_focus()) return 1;
		      else return 0;
		  }

		  return Fl_Group::handle(event);
		}

///-------------------------------
 void Fl_ButtonOutput::resize(int X, int Y, int W, int H) {
		  Fl_Group::resize(X,Y,W,H);

         output_.resize(X, Y, W - H, H);
         button_.resize(X + W - H, Y, H, H);

		}

//--------------------------




 void	Fl_ButtonOutput::sb_cb(Fl_Widget *w, Fl_ButtonOutput *sb) {


		}
