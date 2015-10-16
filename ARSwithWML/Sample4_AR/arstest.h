#pragma once

#ifndef _DEBUG
#pragma comment(lib, "../lib/ARS.lib")
#pragma comment(lib, "../lib/WML.lib")
#else
#pragma comment(lib, "../lib/ARSd.lib")
#pragma comment(lib, "../lib/WMLd.lib")
#endif



#define _CRT_SECURE_NO_WARNINGS

#define CLASSNAME "ARSTEST"
#define APPNAME "ARSTEST"




class Touchable : public Mesh{
// private:
protected:
   float vx,vy;	

   bool overlappingOnce;

   bool get_overlapping_center(Texture* hitArea, int *gx, int *gy, unsigned int threshold);
   void state_action(bool condition);
public:   
   static enum {ACTIVE,INACTIVE};
   int state;

   Touchable(ARSG* _g, wchar_t fln[]) : Mesh(_g,fln), vx(0.2f),vy(-0.2f),state(ACTIVE),overlappingOnce(false){ }
   Touchable(void) : vx(0.2f),vy(-0.2f),state(ACTIVE){ }
   void react(Texture *hitArea);
   void move(void);
   void setOverlappingOnce(bool tf){
	   overlappingOnce = tf;
   }

   void global_move(float vx, float vy);
   
};

class Dart : public Touchable {
protected:
	bool hitDartBoard;

public:
	Dart(ARSG* _g, wchar_t fln[]) :Touchable(_g, fln),hitDartBoard(false){}
	void react(Texture* hitArea);
	void move(void);
};

class DartBoard : public Touchable {
protected:
	bool hitDart;

public:
	DartBoard(ARSG* _g, wchar_t fln[]) : Touchable(_g, fln), hitDart(false) {}
	void react(Texture* hitArea);
	void move(void);

};