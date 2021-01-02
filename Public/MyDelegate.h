// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemInfo.h"
/**
 * 
 */
DECLARE_MULTICAST_DELEGATE_OneParam(ItemDelegate,FItemInfo);

class RES_API MyDelegate
{
public:
	static ItemDelegate TakeItemDelegate;
	MyDelegate();
	~MyDelegate();
};
