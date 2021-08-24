#pragma once
#pragma comment(lib, "Msimg32.lib")
#include "Queen.h"

class Game
{
	enum class State { SIMPLE_TURN, ATTACK, IMPOSSIBLE };
	static std::map<Position, Checker*>* BoardPosition;
	static std::map<int, Checker*>* BoardObj;
	static std::map<int, Position>* ID_to_Position;
	static int LengthFigure;
	static Checker::Type* ActivePlayer;
	static HWND MainHWND;
	static int LastIDButton;

	static void RotateDeck();
	static void Swap(const Turn& someTurn);
	static const bool& CheckForPlayer(const Position& pos);
	static void SearchingForWictims();
	static	void NoWictims();
	static const bool& NeedAttack();
	static	const Game::State& GetStateTurn(const Turn& PlayerTurn);
	static const Position& GetWictimPos(const Turn& turn);
	static	const Checker::Type& GetWinner();
	static	void CheckIsQueen(const Position& NodePos);
	static	void ToKill(const Position& Wictim) { (*BoardPosition)[Wictim]->SetType(Checker::Type::OPEN); }
public:
	CHECKERS_API static void MakeTurn(const int& FirstIDNode, const int& SecondIDNode);
	CHECKERS_API static void PrintBaseInfo();
	CHECKERS_API static const HWND& GetButton(const int& ButtonID);
	CHECKERS_API static void Start(HWND hWnd, HINSTANCE hInst);
	CHECKERS_API static void DrawFigures(LPDRAWITEMSTRUCT pDIS);
	CHECKERS_API static const Checker::Type& GetActivePlayer();
	CHECKERS_API static const Checker::Type& GetColourFigure(const int& IDFigure);
	CHECKERS_API static void ClearMemory();
};

