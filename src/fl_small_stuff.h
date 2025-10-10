#ifndef FL_SMALL_STUFF_H
#define FL_SMALL_STUFF_H
#include <string>
#  include <vector>
#include <FL/fl_draw.H>
#include <FL/Fl_Box.H>
#  include <FL/Enumerations.H>
#  include <FL/Fl_Group.H>
#  include <FL/Fl_Output.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Native_File_Chooser.H>
#  include <FL/Fl_Repeat_Button.H>



/// Check if file exists to control overwrite
extern const char * fl_check_access_nfc(Fl_Native_File_Chooser &native, const char * ext, const char * fdescr);


/// Rotated label- mainly for plots
class Fl_Rotated_Label :public Fl_Box{
  int rt_angle;
  std::string rt_text;
  Fl_Align rt_align;
public:


 // ~Fl_Rotated_Label();
   public:
  Fl_Rotated_Label(int X, int Y, int W, int H, const char*L=0):
    Fl_Box(X,Y,W,H,L),rt_angle(0),rt_align((Fl_Align)0){
     rt_text="test";
    };
 void text(const char * t){rt_text=t;};
 const char *  text() {return rt_text.c_str();  };
 int  angle() {return rt_angle;  };
 void angle(const int a) {rt_angle=a;  };
 protected:
 virtual void draw();

};

/// Trap for cursor WAIT in multi-return function
/// simpe usage: Fl_Cursor_Wait CurW(true,Win());
struct Fl_Cursor_Wait{
   bool isStarted;
   Fl_Double_Window *win;
   Fl_Cursor_Wait() {isStarted=false;
                     win=nullptr;};
   Fl_Cursor_Wait(const bool swc,Fl_Double_Window *w=nullptr) {
        isStarted=swc;
        win=w;
        if(swc) { fl_cursor(FL_CURSOR_WAIT);
           if(win!=nullptr) win->deactivate(); }
       };
   void Start() {isStarted=true; fl_cursor(FL_CURSOR_WAIT);
                 if(win!=nullptr) win->deactivate(); }
   void Stop() {if(isStarted) {isStarted=false;fl_cursor(FL_CURSOR_DEFAULT);
                               if(win!=nullptr) win->activate(); };};
  ~Fl_Cursor_Wait() {Stop();};

};
///====================================================================================================
// Fl_Repeat_Button with blocked FL_DRAG - for Fl_TextSpinner

class  Fl_Repeat_Button_NDRG:public Fl_Repeat_Button{
  public:
    Fl_Repeat_Button_NDRG(int X, int Y, int W, int H, const char *L)
    : Fl_Repeat_Button(X, Y, W, H, L){};
   int handle(int e){
     if(e==FL_DRAG) return 0; // To avoid glitches in Tebles
   return Fl_Repeat_Button::handle(e);
   }
};

//  Fl_TextSpinner - spinner with text in Optput
class  Fl_TextSpinner : public Fl_Group {

  int	value_,maximum_,minimum_;			// Current value


#if FLTK_ABI_VERSION >= 10301
// NEW
protected:
#endif
  Fl_Output	output_;			// Output field for the text
  Fl_Repeat_Button_NDRG

		up_button_,		// Up button
		down_button_;		// Down button
  std::vector<std::string> svalues;
  int rbt_style;
private:
  static void sb_cb(Fl_Widget *w, Fl_TextSpinner *sb);
  void update() {
          if(value_<0 || svalues.size()==0) {
            output_.value("<Empty>");
            }
            else
		      output_.value(svalues.at(value_).c_str());
		}

  public:

  Fl_TextSpinner(int X, int Y, int W, int H, const char *L);

 void add(const std::vector<std::string> ss);
 void add(const char * s);
 void clear();
 int  handle(int event);
 void resize(int X, int Y, int W, int H) ;

  /** Gets the maximum value of the widget. */
  int	maximum() const { return maximum_; }
  /** Sets the maximum value of the widget. */
  int	minimum() const { return (minimum_); }
  /** Sets the minimum value of the widget. */

  int	value() const { return (value_); }

  const char * text() const {
                  if(value_<0) return output_.value();
                    return svalues.at(value_).c_str(); }

  void		value(int v) { if(v<=maximum_||v>=minimum_) value_ = v; update(); }

 inline Fl_Button & up_button(){return up_button_;};
 inline Fl_Button & down_button(){return down_button_;};
 inline Fl_Output & output(){return output_;}
};

///====================================================================================================

//  Fl_Output with glued button
class  Fl_ButtonOutput : public Fl_Group {


#if FLTK_ABI_VERSION >= 10301
// NEW
protected:
#endif
  Fl_Output	output_;			// Output field for the text
  Fl_Button button_;		// Button


private:
  static void sb_cb(Fl_Widget *w, Fl_ButtonOutput *sb);

  public:

  Fl_ButtonOutput(int X, int Y, int W, int H, const char *L);

 int  handle(int event);
 void resize(int X, int Y, int W, int H) ;



  inline void		  value(const char* s) { output_.value(s); }
  inline void		  value(const std::string & s) { output_.value(s.c_str()); }
  inline const char* value() { return output_.value(); }

  void		  callback(Fl_Callback *cb, void * v)
     { Fl_Group::callback(cb,v);
      button_.callback(Fl_Group::callback(),v);
      }
 inline Fl_Button & button(){return button_;};
 inline Fl_Output & output(){return output_;}
};
#endif //FL_SMALL_STUFF_H
