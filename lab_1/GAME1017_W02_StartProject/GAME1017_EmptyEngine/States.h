#pragma once
#ifndef _STATES_H_
#define _STATES_H_
#include <SDL_mixer.h>

class State
{
protected:
	State() {}
public:
	//virtual ~State() = default;
	virtual void Enter() = 0;
	virtual void Update() = 0;
	virtual void Render();
	virtual void Exit() = 0;
	virtual void Resume() {};
	virtual ~State() = default;
};


class TitleState : public State
{
private:
	Mix_Music* m_pMusic;

public:
	TitleState()=default;
	 void Enter()override;
	 void Update()override;
	 void Render()override;
	 void Exit()override;
};



class GameState : public State
{
private:

	Mix_Music* m_pMusic;
	Mix_Chunk* m_pSounds_1;
	Mix_Chunk* m_pSounds_2;

public:
	GameState()=default;
	 void Enter()override;
	 void Update()override;
	 void Render()override;
	 void Exit()override;
	 void Resume()override;
};

class PauseState : public State
{
private:

public:
	PauseState() = default;
	 void Enter()override;
	 void Update()override;
	 void Render()override;
	 void Exit()override;
};

class EndState : public State
{
private:

public:
	EndState() = default;
	 void Enter()override;
	 void Update()override;
	 void Render()override;
	 void Exit()override;
};

#endif