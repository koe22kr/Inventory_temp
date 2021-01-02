// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	slotWidth = 4;
	slotHeight = 10;
	//viewSlotWidth = 4;
	viewSlotHeight = 4;
	viewOffsetHeight = 0;
	// ...
	slotSize size = slotWidth * slotHeight;
	
	this->slotArray.AddDefaulted(size);
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...
	MyDelegate::TakeItemDelegate.AddUFunction(this, FName("TakeItem"));

	TObjectIterator<AItemManager> im;
	itemManager = *im;
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// ...
}
void UInventoryComponent::TakeItem(FItemInfo info)
{
	for (size_t i = 0; i < slotArray.Num(); i++)
	{
		if (slotArray[i].id == 0)
		{
			slotArray[i] = info;
			MakeTexture(i);
			return;
		}
	}
	int32 idx = MakeNewLine();
	slotArray[idx] = info;
	MakeTexture(idx);
}
int32 UInventoryComponent::MakeNewLine()
{
	int32 firstIdx = slotArray.AddDefaulted(slotWidth);
	
	++slotWidth;
	return firstIdx;
}
void UInventoryComponent::UpButton()
{
	if (0 < viewOffsetHeight)
	{
		--viewOffsetHeight;
	}
}
void UInventoryComponent::DownButton()
{
	if (viewOffsetHeight < slotHeight - viewSlotHeight)
	{
		++viewOffsetHeight;
	}
}
slotSize UInventoryComponent::GetSlotIdx(slotSize viewNum)
{
	return viewOffsetHeight * slotWidth + viewNum;
}
void UInventoryComponent::MakeTexture(slotSize slotNum)
{
	FSoftObjectPath path;
	path.SetPath(slotArray[slotNum].path);

	FStreamableManager& loader = UAssetManager::GetStreamableManager();
	auto handler = loader.RequestSyncLoad(path);
	UObject* obj = handler->GetLoadedAsset();
	UTexture2D* tex = Cast<UTexture2D>(obj);
	texMap.Add(slotArray[slotNum].id, tex);
}
itemId UInventoryComponent::GetId(int viewNum)
{
	slotSize idx = GetSlotIdx(viewNum);
	return slotArray[idx].id;
}


UTexture2D* UInventoryComponent::GetTexture(int viewNum)
{
	auto ret = texMap.Find(GetId(viewNum));
	if (ret == nullptr)
	{
		return nullptr;
	}
	else
	{
		return *ret;
	}
}
