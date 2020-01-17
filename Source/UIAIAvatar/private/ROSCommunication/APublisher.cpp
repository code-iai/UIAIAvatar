// Copyright 2019, Institute for Artificial Intelligence - University of Bremen

#include "ROSCommunication/APublisher.h"
#include "actionlib_msgs/GoalStatusArray.h"

UAPublisher::UAPublisher()
{
}

void UAPublisher::DeInit()
{
	if (Handler.IsValid()) {
		Handler->Disconnect();
	}
}

void UAPublisher::Init(FString InHostIp, uint32 InPort, UObject* InOwner)
{
	Seq = 0;
	Handler = MakeShareable<FROSBridgeHandler>(new FROSBridgeHandler(InHostIp, InPort));
	Handler->Connect();
	SetMessageType();
	SetOwner(InOwner);
	CreatePublisher();
	Handler->AddPublisher(Publisher);
}

void UAPublisher::Init(UObject* InOwner, TSharedPtr<FROSBridgeHandler> InHandler, FString InRosTopic)
{
	Seq = 0;
	Handler = InHandler;
	if (!InRosTopic.Equals(""))
	{
		Topic = InRosTopic;
	}
	SetMessageType();
	SetOwner(InOwner);
	CreatePublisher();
	Handler->AddPublisher(Publisher);
}

void UAPublisher::CreatePublisher()
{
	Publisher = MakeShareable<FROSBridgePublisher>
		(new FROSBridgePublisher(Topic, MessageType));

	if (Publisher.IsValid())
	{
		UE_LOG(LogTemp, Log, TEXT("Publisher connected to RosBridge"));
	}
}

