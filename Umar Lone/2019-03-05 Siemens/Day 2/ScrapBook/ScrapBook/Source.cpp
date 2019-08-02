#include "Application.h"
#include <iostream>
#include "Text.h"
#include "Image.h"
#include "DataManager.h"
#include "ThumbnailView.h"

int main() {
	DataManager mgr ;
	ThumbnailView tview{&mgr} ;
	Application app{&mgr, &tview} ;
	app.InputLoop() ;
}
