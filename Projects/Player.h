#pragma once

#include "defines.h"
#include "FrameAnimation.h"
#include "Pos.h"
#include "Config.h"



class Player 
{
public:
	enum AnimationState : int 
	{
		Idle = 0,
		Moving = 1
	};

	static std::map<uint32, std::vector< uint32 >> s_PlayerAnimationTable;
	static std::map<uint32, std::map<uint32, std::vector<uint32>> > s_WeaponAnimationTable;
	
	Player(int PlayerAnimationId,int WeapAnimationId);
	~Player();
	void OnUpdate(double dt);
	
	void ResetDirAll(int dir);
	void ResetDir(int dir);
	void SetDir(int dir);

	void SetAnimationState(int state) { m_AnimationState = state; };
	int GetAnimationState(){ return m_AnimationState; }
	
	void OnDraw(SpriteRenderer * renderer, int px,int py);
	void SetPos(double x, double y);
	double GetX() { return m_Pos.x; }
	double GetY() { return m_Pos.y; }

	int GetBoxX() { return m_Pos.x/20; }
	int GetBoxY() { return m_Pos.y/20; }

	void SetX(double x) { m_Pos.x = x; }
	void SetY(double y) { m_Pos.y = y; }

	void TranslateX(double x) { m_Pos.x += x; }
	void TranslateY(double y) { m_Pos.y += y; }
	

private:
	std::vector<FrameAnimation*> m_WeapAnimation;
	std::vector<FrameAnimation*> m_PlayerAnimation;
	int m_AnimationState;
	int m_Dir;
	Pos m_Pos;
	
};
