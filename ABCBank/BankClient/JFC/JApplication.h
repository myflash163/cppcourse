#ifndef _JAPLLICATION_H_
#define _JAPLLICATION_H_


namespace JFC 
{
	class JWindow;
	/*单利模式*/
	class JApplication
	{
	public:
		JApplication();
		~JApplication();

		static JApplication* Instance() {
			return self_;
		}

		JWindow* GetCurrent() const { return current_; }
		JWindow* SetCurrent(JWindow* win) { current_ = win; }
		JWindow* Root() const { return root_; }

		int Exec(); //消息循环
	private:
		static JApplication* self_;
		JWindow * current_; //当前接收按键的窗口
		JWindow* root_;  //根窗口
	};
#define jApp JApplication::Instance()
}

#endif // _JAPLLICATION_H_
