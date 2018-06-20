#pragma once
#include <string>
#include <Windows.h>

namespace JFC
{
	// ��ɫ
	// ��ɫ
	// ��ɫ
	// ��ɫ
	// ��ɫ
	// ���
	// ��ɫ
	// ����
	// ���
	// ����
	// ����
	// ����
	// ����
	// �����
	// ��ɫ
	// ��ɫ
#define FCOLOR_BLACK			0
#define FCOLOR_BLUE				FOREGROUND_BLUE
#define FCOLOR_GREEN			FOREGROUND_GREEN
#define FCOLOR_CYAN				FOREGROUND_BLUE | FOREGROUND_GREEN
#define FCOLOR_RED				FOREGROUND_RED
#define FCOLOR_MAGENTA			FOREGROUND_RED | FOREGROUND_BLUE
#define FCOLOR_BLOWN			FOREGROUND_RED | FOREGROUND_GREEN
#define FCOLOR_GRAY				FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
#define FCOLOR_DARKGRAY			FCOLOR_BLACK + FOREGROUND_INTENSITY
#define FCOLOR_LIGHTBLUE		FCOLOR_BLUE + FOREGROUND_INTENSITY
#define FCOLOR_LIGHTGREEN		FCOLOR_GREEN + FOREGROUND_INTENSITY
#define FCOLOR_LIGHTCYAN		FCOLOR_CYAN + FOREGROUND_INTENSITY
#define FCOLOR_LIGHTRED			FCOLOR_RED + FOREGROUND_INTENSITY
#define FCOLOR_LIGHTMAGENTA		FCOLOR_MAGENTA + FOREGROUND_INTENSITY
#define FCOLOR_YELLO			FCOLOR_BLOWN + FOREGROUND_INTENSITY
#define FCOLOR_WHITE			FCOLOR_GRAY + FOREGROUND_INTENSITY

#define BCOLOR_BLACK			0
#define BCOLOR_BLUE				BACKGROUND_BLUE
#define BCOLOR_GREEN			BACKGROUND_GREEN
#define BCOLOR_CYAN				BACKGROUND_BLUE | BACKGROUND_GREEN
#define BCOLOR_RED				BACKGROUND_RED
#define BCOLOR_MAGENTA			BACKGROUND_RED | BACKGROUND_BLUE
#define BCOLOR_BLOWN			BACKGROUND_RED | BACKGROUND_GREEN
#define BCOLOR_GRAY				BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE
#define BCOLOR_DARKGRAY			BCOLOR_BLACK + BACKGROUND_INTENSITY
#define BCOLOR_LIGHTBLUE		BCOLOR_BLUE + BACKGROUND_INTENSITY
#define BCOLOR_LIGHTGREEN		BCOLOR_GREEN + BACKGROUND_INTENSITY
#define BCOLOR_LIGHTCYAN		BCOLOR_CYAN + BACKGROUND_INTENSITY
#define BCOLOR_LIGHTRED			BCOLOR_RED + BACKGROUND_INTENSITY
#define BCOLOR_LIGHTMAGENTA		BCOLOR_MAGENTA + BACKGROUND_INTENSITY
#define BCOLOR_YELLO			BCOLOR_BLOWN + BACKGROUND_INTENSITY
#define BCOLOR_WHITE			BCOLOR_GRAY + BACKGROUND_INTENSITY
	class JWindowBase
	{
	public:
		JWindowBase();
		JWindowBase(SHORT x, SHORT y, SHORT width, SHORT height);
		~JWindowBase();

		void SetTextColor(WORD fColor) { fColor_ = fColor; }
		WORD GetTextColor() const { return fColor_; }

		void SetBkColor(WORD bColor) { bColor = bColor; }
		WORD GetBkColor() const { return bColor_; }

		SHORT Width() const { return width_; }
		SHORT Height() const { return height_; }
	private:
		class ScreenBuffer 
		{
			ScreenBuffer() {

			}
			~ScreenBuffer() {

			}
			void write(SHORT x, SHORT y, CHAR_INFO ci)
			{
				buffer[y * 25 + x] = ci;
			}
			void write(SHORT x, SHORT y, const std::string & str, WORD fColor, WORD bColor)
			{
				CHAR_INFO ci;
				ci.Attributes = fColor | bColor;
				for (size_t i = 0; i < str.length(); ++i)
				{
					ci.Char.AsciiChar = str[i];
					write(x + i, y, ci);
				}
			}
			/*
			��������̨����API
			GetStdHandle
			SetConsoleOutputCP
			SetConsoleScreenBufferSize
			SetConsoleCursorPosition
			GetConsoleCursorInfo
			WriteConsoleOutput
			ReadConsoleOutput
			*/
			void refresh(SHORT x, SHORT y, SHORT width, SHORT height)
			{

			}
			CHAR_INFO buffer[80 * 25];
		};
	protected:
		WORD fColor_;	//ǰ��ɫ
		WORD bColor_;	//����ɫ
		SHORT x_;	//x����
		SHORT y_;	//y����
		SHORT width_;	//���
		SHORT height_; //�߶�

	};
}


