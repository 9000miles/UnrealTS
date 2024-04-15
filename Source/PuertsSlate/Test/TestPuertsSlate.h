// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "JsEnv.h"
#include "TestPuertsSlate.generated.h"

/**
 *Comment
 */
UCLASS(BlueprintType, Blueprintable)
class UTestPuertsSlateGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:



	void Init() override;


	void Shutdown() override;
	virtual void CopyFiles();

public:
	void SetTestWidget(TSharedPtr<SWidget> Widget);
	TSharedPtr<STextBlock> GetTextBlock();

protected:

	void OnStart() override;

	void AddToWidget();

	void StartScript();
private:
	TSharedPtr<STextBlock> MyTextBlock;
	TSharedPtr<SWidget> TestWidget;

protected:
	TSharedPtr<puerts::FJsEnv> JsEnv;
};
