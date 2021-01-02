// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//
#include "ItemInfo.h"
//
#include "ItemManager.generated.h"

UCLASS()
class RES_API AItemManager : public AActor
{
	GENERATED_BODY()
public:
	TMap<itemId, FItemInfo> itemMap;

public:	
	// Sets default values for this actor's properties
	AItemManager();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable)
	FItemInfo GetItemInfo(int id);
	UFUNCTION(BlueprintCallable)
	void GiveItem(int id);
private:
};
