#include "JApplication.h"
#include "JWindow.h"
#include "JEvent.h"
#include <conio.h>

using namespace JFC;

JApplication* JApplication::self_ = 0;

JFC::JApplication::JApplication()
{
	if (self_) return;
	self_ = this;
	root_ = new JWindow();
	current_ = root_;
}

JFC::JApplication::~JApplication()
{
	delete root_;
}

int JFC::JApplication::Exec()
{
	while (1)
	{
		int key = _getch();
		if (current_)
		{
			JEvent e(key, current_);
			current_->OnKeyEvent(&e);
		}
	}
	return 0;
}
