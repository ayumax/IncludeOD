// Fill out your copyright notice in the Description page of Project Settings.


#include "StringObjectConverer.h"
#include "../Private/Utils/ODStringUtil.h"
#include "../Private/Utils/JsonSerializer/ODJsonDeserializer.h"
#include "../Private/Utils/JsonSerializer/ODJsonSerializer.h"

UObject* UStringObjectConverer::String2UObject(FString string, UClass* classType)
{
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(string);
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());

	if (!FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid()) return nullptr;

	UODJsonDeserializer* Deserializer = NewObject<UODJsonDeserializer>();
	UObject* createdObj = Deserializer->JsonObjectToUObject(JsonObject, classType);

	return createdObj;
}

FString UStringObjectConverer::UObject2String(UObject* packet)
{
	UODJsonSerializer* Serializer = NewObject<UODJsonSerializer>();
	auto jsonObject = Serializer->CreateJsonObject(packet);

	FString OutputString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(jsonObject.ToSharedRef(), Writer);

	return OutputString;
}