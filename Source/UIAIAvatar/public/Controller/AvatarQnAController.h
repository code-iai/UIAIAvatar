// Copyright 2019, Institute for Artificial Intelligence - University of Bremen

#pragma once

#include "CoreMinimal.h"
#include "IAIAvatarCharacter.h"
#include "Controller/AController.h"
#include "UDynamicTimeWarp.h"
#include "AvatarQnAController.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, DefaultToInstanced, collapsecategories, hidecategories = Object, editinlinenew)
class UIAIAVATAR_API UAvatarQnAController : public UAController
{
	GENERATED_BODY()
public:
	UAvatarQnAController();

	virtual void Init(AActor* InModel) override;
	virtual void Tick(float InDeltaTime) override;

	virtual void NotifyQuestion();
	virtual void CheckAnswer();
	virtual void GiveAnswer(FString InAnswer);
	virtual void TimeOut();

	UPROPERTY()
	AIAIAvatarCharacter* Avatar;

	FTimerHandle TimeOutHandle;

	FString Question;
	FString Answer;

	bool bAnswering;
};
