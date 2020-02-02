#include<iostream>
#include<cstdio>

using namespace std;

class GameSetting{

	static GameSetting* _instance;
	int _brightness;
	int _width;
	int _height;


	GameSetting(): _width(786), _height(1300), _brightness(75){

	}


	public:
	static GameSetting* getInstance(){

		if(_instance == NULL)
			_instance = new GameSetting();

		return _instance;
	}

	void setWidth(int width) { _width = width; }
	void setheight(int height){ _height = height; }
	void setBightness( int brightness ){ _brightness; }


	int getWidth(){ return _width; }
	int getheight(){ return _height; }
	int getBrightness(){ return _brightness; }

	void displaySettings(){
		cout<<"Brightness : "<<_brightness<<endl;
		cout<<"Height : "<<_height<<endl;
		cout<<"width : "<<_width<<endl;
	}


};


GameSetting* GameSetting::_instance = NULL;

void someFunction(){

	GameSetting* setting = GameSetting::getInstance();
	setting->displaySettings();

	cout<<setting<<endl;
}


int main(){

	GameSetting *setting = GameSetting::getInstance();
	setting->displaySettings();
	setting->setBightness(100);

	cout<<setting<<endl;

	someFunction();

	return 0;
}
