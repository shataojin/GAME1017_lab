#include "States.h"
#include "StateManager.h"
#include "Engine.h"
#include <iostream>
using namespace std;

void State::Render()
{
	SDL_RenderPresent(Engine::Instance().GetRenderer());
}


void TitleState::Enter()
{
	cout << "Enter Title State --> " << endl;
	////load music track, add it to map, and  play
	m_pMusic = Mix_LoadMUS("Aud/Turtles.mp3");
	Mix_PlayMusic(m_pMusic, -1);
}

void TitleState::Update()
{
	if (Engine::Instance().KeyDown(SDL_SCANCODE_N))
	{
		cout << "changing to game state" << endl;
		STMA::ChangeState(new GameState);
	}
}

void TitleState::Render()
{
	cout << "rendering  game state" << endl;
	SDL_SetRenderDrawColor(Engine::Instance().GetRenderer(), 0, 0, 255, 255);
	SDL_RenderClear(Engine::Instance().GetRenderer());
	State::Render();
}

void TitleState::Exit()
{
	cout << "exit title state----->" << endl;


}






void GameState::Enter()
{
	cout << "Enter GameState --> " << endl;
	m_pMusic = Mix_LoadMUS("Aud/Turtles.mp3");
	m_pSounds_1 = Mix_LoadWAV("Aud/boom.wav");
	m_pSounds_2 = Mix_LoadWAV("Aud/jump.wav");
	Mix_PlayMusic(m_pMusic, -1);
}

void GameState::Update()
{
	if (Engine::Instance().KeyDown(SDL_SCANCODE_X))
	{
		cout << "changing to TitleState" << endl;
		STMA::ChangeState(new TitleState());
	}

	if (Engine::Instance().KeyDown(SDL_SCANCODE_P))
	{
		cout << "changing to pauseState" << endl;
		STMA::PushState(new PauseState());
	}

}

void GameState::Render()
{
	cout << "rendering gamestate.." << endl;
	SDL_SetRenderDrawColor(Engine::Instance().GetRenderer(), 0, 255, 0, 255);
	SDL_RenderClear(Engine::Instance().GetRenderer());
	if (dynamic_cast<GameState*>(STMA::GetStates().back()))
		State::Render();
}

void GameState::Exit()
{
	cout << "exit game state----->" << endl;
}

void GameState::Resume()
{
	cout << "resuming gamestate----->" << endl;
}






void PauseState::Enter()
{
	cout << "Enter pauseState --> " << endl;

}

void PauseState::Update()
{
	if (Engine::Instance().KeyDown(SDL_SCANCODE_R))
	{
		STMA::PopState();
	}
}

void PauseState::Render()
{
	cout << "rendering pauseState----->" << endl;
	//first render the game state.
	STMA::GetStates().front()->Render();
	// now render ther rest of pasuse state
	SDL_SetRenderDrawBlendMode(Engine::Instance().GetRenderer(), SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(Engine::Instance().GetRenderer(), 255, 0, 0, 126);
	SDL_Rect rect = { 255,128,512,512 };
	SDL_RenderFillRect(Engine::Instance().GetRenderer(), &rect);
	State::Render();
}

void PauseState::Exit()
{
	cout << "exit pauseState----->" << endl;
}
