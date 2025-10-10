# fltk small stuff
Library with some useful stuff.
function **fl\_check\_access\_nfc** - to check existance of file and offer options regarding rename/overwrite.
widget   **Fl\_Rotated\_Label** - useful for Y axes label, to use with **Fl\_XYPlot3**. It is a modified *"old stuff from the internet"*.
widget   **Fl\_TextSpinner**  - spinner-like widget with text rather then nublers.
widget   **Fl\\_ButtonOutput** - Fl_Output "glued" with button, mainly for file load operatiom. 
struct **Fl\_Cursor\_Wait** is to controls state of the cursor in multi - return functions. In destructor it recover entry state of the cursor.
 
Demo/example can be found in the same CodeBlocks project.
   
Library requires relatively fresh C++ compiler. 
Library can be built using **CodeBlocks IDE**  and **MinGW** compiler. 
Library requires **fmtlib** <https://github.com/fmtlib>. 
Demo requires also **FLTK Generic Form Context** <https://github.com/nenin-sc/FLTK-Generic-Form-Context>
It was not tested out of Windows, so potentially some issues may occure.


