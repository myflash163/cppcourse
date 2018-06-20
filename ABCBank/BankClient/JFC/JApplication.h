#ifndef _JAPLLICATION_H_
#define _JAPLLICATION_H_


namespace JFC 
{
	class JWindow;
	/*����ģʽ*/
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

		int Exec(); //��Ϣѭ��
	private:
		static JApplication* self_;
		JWindow * current_; //��ǰ���հ����Ĵ���
		JWindow* root_;  //������
	};
#define jApp JApplication::Instance()
}

#endif // _JAPLLICATION_H_
