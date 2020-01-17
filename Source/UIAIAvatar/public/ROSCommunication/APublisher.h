// Copyright 2019, Institute for Artificial Intelligence - University of Bremen

#pragma once

#include "ROSBridgeHandler.h"
#include "ROSBridgePublisher.h"
#include "ROSCommunication/AROSClient.h"
#include "Conversions.h"
#include "APublisher.generated.h"

UCLASS(Blueprintable, DefaultToInstanced, collapsecategories, hidecategories = Object, editinlinenew)
class UIAIAVATAR_API UAPublisher : public UObject
{
	GENERATED_BODY()
public:


	UAPublisher();
	virtual void DeInit();
	virtual void Publish() {};

	virtual void Init(UObject* InOwner, TSharedPtr<FROSBridgeHandler> InHandler, FString InRosTopic);
	virtual void Init(FString InHostIp, uint32 InPort, UObject* InOwner);

	TSharedPtr<FROSBridgePublisher> Publisher;
	int Seq;

	UPROPERTY()
		FString ControllerName;
protected:


	UPROPERTY(EditAnywhere)
		FString Topic;

	UPROPERTY()
		FString MessageType;

	TSharedPtr<FROSBridgeHandler> Handler;

	virtual void SetMessageType() {};
	virtual void SetOwner(UObject* InOwner) {};
	virtual void CreatePublisher();
};

