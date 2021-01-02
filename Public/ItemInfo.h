// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "ItemInfo.generated.h"
/**
 * 
 */
using itemId = int;
using itemName = FString;
using itemPath = FString;

USTRUCT(Atomic,BlueprintType)
struct FItemInfo 
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(editAnywhere)
		FString name;
	UPROPERTY(editAnywhere)
		FString path;
	UPROPERTY(editAnywhere)
		uint32 id = 0;
public:

};
