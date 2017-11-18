#pragma once

#include "game_base_space.h"
#include "script_export_space.h"
#include "alife_space.h"

#pragma pack(push,1)

struct	game_PlayerState;//fw
class	NET_Packet;

struct		RPoint
{
	Fvector	P;
	Fvector A;
	u32		TimeToUnfreeze;
	bool	Blocked;
	u32		BlockedByID;
	u32		BlockTime;
	RPoint(){P.set(.0f,0.f,.0f);A.set(.0f,0.f,.0f); TimeToUnfreeze = 0; Blocked = false; BlockedByID = 0; BlockTime = 0;}
	bool	operator ==		(const u32& ID)	const			{ return (Blocked && BlockedByID == ID);		}
	DECLARE_SCRIPT_REGISTER_FUNCTION_STRUCT
};

add_to_type_list(RPoint)
#undef script_type_list
#define script_type_list save_type_list(RPoint)

struct	game_PlayerState 
{
	string64	name;
	u8			rank;
	u16			flags__;
	u16			ping;
	u16			GameID;
	u32			RespawnTime;
	u32			DeathTime;
	u8			m_bCurrentVoteAgreed;

	DEF_DEQUE	(OLD_GAME_ID, u16);
	OLD_GAME_ID	mOldIDs;

	u32			m_online_time;
public:
					game_PlayerState		();
					~game_PlayerState		();
	virtual void	clear					();
			bool	testFlag				(u16 f) const;
			void	setFlag					(u16 f);
			void	resetFlag				(u16 f);
			LPCSTR	getName					(){return name;}
			void	setName					(LPCSTR s){strcpy(name,s);}
			void	SetGameID				(u16 NewID);
			bool	HasOldID				(u16 ID);
			bool	IsSkip					() const {return testFlag(GAME_PLAYER_FLAG_SKIP);}

#ifndef AI_COMPILER
	virtual void	net_Export				(NET_Packet& P, BOOL Full = FALSE);
	virtual void	net_Import				(NET_Packet& P);
#endif
	//---------------------------------------
	
	DEF_VECTOR(PLAYER_ITEMS_LIST, u16);
	PLAYER_ITEMS_LIST	pItemList;

	DECLARE_SCRIPT_REGISTER_FUNCTION_STRUCT
};

add_to_type_list(game_PlayerState)
#undef script_type_list
#define script_type_list save_type_list(game_PlayerState)

#pragma pack(pop)

class	game_GameState : public DLL_Pure
{
protected:
	s32								m_type;
	u16								m_phase;
	s32								m_round;
	u32								m_start_time;

	u32								m_round_start_time;
	string64						m_round_start_time_str;

protected:
	virtual		void				switch_Phase			(u32 new_phase);
	virtual		void				OnSwitchPhase			(u32 old_phase, u32 new_phase)	{};	

public:
									game_GameState			();
	virtual							~game_GameState			()								{}
				u32					Type					() const						{return m_type;};
				u16					Phase					() const						{return m_phase;};
				s32					Round					() const						{return m_round;};
				u32					StartTime				() const						{return m_start_time;};
	virtual		void				Create					(shared_str& options)				{};
	virtual		LPCSTR				type_name				() const						{return "base game";};
//for scripting enhancement
	static		CLASS_ID			getCLASS_ID				(LPCSTR game_type_name, bool bServer);
	virtual		game_PlayerState*	createPlayerState()		{return xr_new<game_PlayerState>(); };

//moved from game_sv_base (time routines)
private:
	// scripts
	u64								m_qwStartProcessorTime;
	u64								m_qwStartGameTime;
	float							m_fTimeFactor;
	//-------------------------------------------------------
	u64								m_qwEStartProcessorTime;
	u64								m_qwEStartGameTime;
	float							m_fETimeFactor;
	//-------------------------------------------------------
public:

	virtual		ALife::_TIME_ID		GetGameTime				();	
	virtual		float				GetGameTimeFactor		();	
				void				SetGameTimeFactor		(ALife::_TIME_ID GameTime, const float fTimeFactor);
	virtual		void				SetGameTimeFactor		(const float fTimeFactor);
	

	virtual		ALife::_TIME_ID		GetEnvironmentGameTime	();
	virtual		float				GetEnvironmentGameTimeFactor		();
				void				SetEnvironmentGameTimeFactor		(ALife::_TIME_ID GameTime, const float fTimeFactor);
	virtual		void				SetEnvironmentGameTimeFactor		(const float fTimeFactor);

	DECLARE_SCRIPT_REGISTER_FUNCTION
};
add_to_type_list(game_GameState)
#undef script_type_list
#define script_type_list save_type_list(game_GameState)

