// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StringObjectConverer.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class INCLUDEOD_API UStringObjectConverer : public UObject
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "IncludeOD")
	static UObject* String2UObject(FString string, UClass* classType);

	UFUNCTION(BlueprintCallable, Category = "IncludeOD")
	static FString UObject2String(UObject* obj);
};
