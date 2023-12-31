#pragma once
#include "Actor.h"
#include "DataSheet.h"
class Player;
class Monster : public Actor
{
public:
	Monster();
	virtual ~Monster();

public:
	virtual void Initialize() override;
	virtual void Update(float deltaTime) override;
	virtual void OnDamaged(std::shared_ptr<Actor> attacker, int32 damage) override;
	virtual void OnDead(std::shared_ptr<Actor> attacker) override;

public:
	void		ModifyMoveInfo();
	void		UseSkill();

protected:
	virtual void UpdateIdle();
	virtual void UpdateMove();
	virtual void UpdateSkill();
	virtual void UpdateDeath();

private:
	void					BroadCastChangeState(const Protocol::AIState& state);
	GameData::RewardData	GetRandomRewardData();

public:
	std::shared_ptr<Player>	GetTargetPlayer() { return _target.lock(); }

	bool					GetNeedToMove() const { return _needToMove; }
	bool					GetNeedUseSkill() const { return _needUseSkill; }

private:
	//	TEMP
	uint64					_nextSearchTick = 0;
	int32					_numberOfTilesToSearch = 8;

	uint64					_nextMoveTick = 0;
	int32					_numberOfTilesToChase = 8;

	int32					_numberOfTilesToSkill = 1;

	uint64					_nextUseSkillTick = 0;

	int32					_dataSheetId = 0;

	bool					_needToMove = false;
	bool					_needUseSkill = false;
	Vector2					_movePath{};

	std::weak_ptr<Player>	_target;
};

