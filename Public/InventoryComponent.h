// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/AssetManager.h"
//
#include "ItemInfo.h"
#include "ItemManager.h"
#include "MyDelegate.h"

//
#include "InventoryComponent.generated.h"

using slotSize = int;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RES_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:
	AItemManager* itemManager;
public:
	slotSize slotWidth;
	slotSize slotHeight;
	//slotSize viewSlotWidth; //세로만 스크롤 가능
	slotSize viewSlotHeight;
	slotSize viewOffsetHeight;
	
	TArray<FItemInfo> slotArray;
	TMap<itemId, UTexture2D*> texMap;
	//TArray<UTexture2D*> texArray;

private:
	slotSize GetSlotIdx(slotSize viewNum);
	void MakeTexture(slotSize slotNum);
	int32 MakeNewLine();
	
public:
	//void Swap();
	//void Reset(slotSize slotNum);
	UFUNCTION(BlueprintCallable)
	void UpButton();
	UFUNCTION(BlueprintCallable)
	void DownButton();
	UFUNCTION(BlueprintCallable)
	void TakeItem(FItemInfo info);
	UFUNCTION(BlueprintCallable)
	int GetId(int viewNum);
	UFUNCTION(BlueprintCallable)
	UTexture2D* GetTexture(int viewNum);
};
