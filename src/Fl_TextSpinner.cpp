#include "fl_small_stuff.h"

  Fl_TextSpinner::Fl_TextSpinner(int X, int Y, int W, int H, const char *L)
     : Fl_Group(X, Y, W, H, L),
       rbt_style(0),
       output_(X, Y, W - H / 2 - 2, H),
       up_button_(X + W - H / 2 - 2, Y, H / 2 + 2, H / 2, "@-42<"),
       down_button_(X + W - H / 2 - 2, Y + H - H / 2, H / 2 + 2, H / 2, "@-42>")

{
  end();
  svalues={"1","2","The end"};
  value_   = 0;
  minimum_ = 0;
  maximum_ = svalues.size()-1;
  align(FL_ALIGN_LEFT);
  output_.value(svalues.at(0).c_str());
  output_.type(FL_INT_INPUT);
  output_.when(FL_WHEN_ENTER_KEY | FL_WHEN_RELEASE);
  up_button_.callback((Fl_Callback *)sb_cb, this);
  down_button_.callback((Fl_Callback *)sb_cb, this);
}
//------------------------------------------------
  int	Fl_TextSpinner::handle(int event) {
		  switch (event) {
	        case FL_KEYDOWN :
		    case FL_SHORTCUT :
		      if (Fl::event_key() == FL_Up) {
			up_button_.do_callback();
			return 1;
		      } else if (Fl::event_key() == FL_Down) {
			down_button_.do_callback();
			return 1;
		      } else return 0;

		    case FL_FOCUS :
		      if (output_.take_focus()) return 1;
		      else return 0;
		  }

		  return Fl_Group::handle(event);
		}

///-------------------------------
 void Fl_TextSpinner::resize(int X, int Y, int W, int H) {
		  Fl_Group::resize(X,Y,W,H);
		if(rbt_style){
         output_.resize(X, Y, W - 2*H, H);
         up_button_.resize(X + W - H, Y, H, H);
         down_button_.resize(X + W - 2*H , Y, H, H);
		} else {

		  output_.resize(X, Y, W - H / 2 - 2, H);
		  up_button_.resize(X + W - H / 2 - 2, Y, H / 2 + 2, H / 2);
		  down_button_.resize(X + W - H / 2 - 2, Y + H - H / 2,
		                      H / 2 + 2, H / 2);

		 }
		}

//--------------------------


void Fl_TextSpinner::add(const std::vector<std::string> ss){
    svalues=ss;
    maximum_=svalues.size()-1;
    if(value_<0) value_=0;
    update();
    }
void Fl_TextSpinner::add(const char * s){
    svalues.push_back(s);
    maximum_=svalues.size()-1;
    if(value_<0) value_=0;
    update();
    }
 void Fl_TextSpinner::clear(){
    svalues.clear();
    maximum_=-1;
    value_=-1;
    update();
    }


 void	Fl_TextSpinner::sb_cb(Fl_Widget *w, Fl_TextSpinner *sb) {
		  //int v;		// New value

		  if(sb->value_<0){
            sb->do_callback();
            sb->update();
            return;
		  }
		  if (w == &(sb->up_button_)) {
		    // Up button pressed...
		    const int v = sb->value_ + 1;

		    if (v > sb->maximum_) sb->value_ = sb->minimum_;
		    else sb->value_ = v;

		    sb->update();
		  } else if (w == &(sb->down_button_)) {
		    // Down button pressed...
		    const int v = sb->value_ - 1;

		    if (v < sb->minimum_) sb->value_ = sb->maximum_;
		    else sb->value_ = v;

		    sb->update();
		  }

		  sb->set_changed();
		  sb->do_callback();
		}
