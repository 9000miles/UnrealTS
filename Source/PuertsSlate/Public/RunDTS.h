#pragma once

#include "CoreMinimal.h"
#include "Commandlets/Commandlet.h"
#include "RunDTS.generated.h"

/**
 * $Comment$
 */
 UCLASS()
class URunDTSCommandlet : public UCommandlet
{
	GENERATED_BODY()
public:
	int32 Main(const FString& CmdLineParams) override;
};