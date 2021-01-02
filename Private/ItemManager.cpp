// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemManager.h"
#include "MyDelegate.h"
// Sets default values
AItemManager::AItemManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItemManager::BeginPlay()
{
	Super::BeginPlay();
	
	//임시 처리
	FItemInfo temp;
	temp.id = 1;
	temp.name = "item1";
	temp.path = "Texture2D'/Game/StarterContent/Textures/T_Burst_M.T_Burst_M'";
	itemMap.Add(temp.id, temp);
	temp.id = 2;
	temp.name = "item2";
	temp.path = "Texture2D'/Game/StarterContent/Textures/T_Bush_D.T_Bush_D'";
	itemMap.Add(temp.id, temp);

	
	APlayerController* pc = GetWorld()->GetFirstPlayerController();
	auto player = pc->GetOwner();
}

// Called every frame
void AItemManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FItemInfo AItemManager::GetItemInfo(itemId id)
{
	auto ret = itemMap.Find(id);
	if (ret == nullptr)
	{
		return FItemInfo();
	}
	else
	{
		return *ret;
	}
}

void AItemManager::GiveItem(itemId id)
{
	FItemInfo info = GetItemInfo(id);
	if (info.id != 0)
	{
		MyDelegate::TakeItemDelegate.Broadcast(info);
	}
}
