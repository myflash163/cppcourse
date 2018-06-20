#include "JWindowBase.h"



JWindowBase::JWindowBase():x_(0),y_(0),width_(0),height_(0)
{
}
JWindowBase::JWindowBase(SHORT x,SHORT y,SHORT width,SHORT height) 
	: x_(x), y_(y), width_(width), height_(height)
{
}


JWindowBase::~JWindowBase()
{
}
